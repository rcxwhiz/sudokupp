#include "SudokuBoard.h"

#include <fstream>
#include <sstream>

// TODO
#include <iostream>

SudokuBoard SudokuBoard::fromFile(const char* filename)
{
	auto board = SudokuBoard();
	std::ifstream fs;
	fs.open(filename);

	char ch;
	for (unsigned int row = 0; row < BOARD_SIZE; row++)
	{
		for (unsigned int col = 0; col < BOARD_SIZE; col++)
		{
			// discard new lines and spaces
			do
			{
				if (fs.eof())
					throw std::runtime_error("Input file too short");
				ch = (char) fs.get();
			} while (isspace(ch));

			// check if the input is a number 1-9
			if (ch < 58 && ch > 48)
				board.setCellValue(row, col, ch - 48);
			else
				board.setCellValue(row, col, UNSOLVED_VALUE);
		}
	}
	fs.close();
	return board;
}
std::string SudokuBoard::toString() const
{
	std::stringstream ss;
	for (unsigned int row = 0; row < BOARD_SIZE; row++)
	{
		for (unsigned int col = 0; col < BOARD_SIZE; col++)
		{
			if (cellSolved(row, col))
				ss << getCellValue(row, col);
			else
				ss << '.';

			if (col != 0 && (col != BOARD_SIZE - 1) && (col + 1) % BLOCK_SIZE == 0)
				ss << " | ";
		}
		ss << std::endl;
		if (row != 0 && (row != BOARD_SIZE - 1) && (row + 1) % BLOCK_SIZE == 0)
		{
			for (int i = 0; i < BOARD_SIZE + (BOARD_SIZE / BLOCK_SIZE - 1) * 3; i++)
				ss << '-';
			ss << std::endl;
		}
	}

	return ss.str();
}
std::ostream& operator<<(std::ostream& os, const SudokuBoard& board)
{
	os << board.toString();
	return os;
}
unsigned int SudokuBoard::getCellValue(unsigned int row, unsigned int col) const
{
	if (row >= BOARD_SIZE || row < 0 || col >= BOARD_SIZE || col < 0)
		throw std::runtime_error("Cell out of range");
	return cells[row][col].value;
}
void SudokuBoard::setCellValue(unsigned int row, unsigned int col, unsigned int value)
{
	if (row >= BOARD_SIZE || row < 0 || col >= BOARD_SIZE || col < 0)
		throw std::runtime_error("Cell out of range");

	// TODO
	std::cout << "  Setting [" << row << "," << col << "] to " << value << std::endl;

	cells[row][col].value = value;
}
bool SudokuBoard::cellSolved(unsigned int row, unsigned int col) const
{
	if (row >= BOARD_SIZE || row < 0 || col >= BOARD_SIZE || col < 0)
		throw std::runtime_error("Cell out of range");
	return cells[row][col].value != UNSOLVED_VALUE;
}
bool SudokuBoard::solved() const
{
	for (unsigned int row = 0; row < BOARD_SIZE; row++)
		for (unsigned int col = 0; col < BOARD_SIZE; col++)
			if (!cellSolved(row, col))
				return false;
	return true;
}
bool SudokuBoard::getValuePossible(unsigned int row, unsigned int col, unsigned int value) const
{
	if (row >= BOARD_SIZE || row < 0 || col >= BOARD_SIZE || col < 0 || value < MIN_ALLOWED_VALUE || value > MAX_ALLOWED_VALUE)
		throw std::runtime_error("Cell or value out of range");
	return cells[row][col].value == UNSOLVED_VALUE && cells[row][col].possibleValues[value - 1];
}
void SudokuBoard::setValueImpossible(unsigned int row, unsigned int col, unsigned int value)
{
	if (row >= BOARD_SIZE || row < 0 || col >= BOARD_SIZE || col < 0 || value < MIN_ALLOWED_VALUE || value > MAX_ALLOWED_VALUE)
		throw std::runtime_error("Cell or value out of range");

	// TODO
//	std::cout << "  Setting " << value << " impossible at [" << row << "," << col << "]" << std::endl;

	cells[row][col].possibleValues[value - 1] = false;
}
bool SudokuBoard::valid() const
{
	// check rows
	bool valueFound;
	for (unsigned int row = 0; row < BOARD_SIZE; row++)
	{
		for (unsigned int value = MIN_ALLOWED_VALUE; value <= MAX_ALLOWED_VALUE; value++)
		{
			valueFound = false;
			for (unsigned int col = 0; col < BOARD_SIZE; col++)
			{
				if (getCellValue(row, col) == value)
				{
					if (!valueFound)
						valueFound = true;
					else
						return false;
				}
			}
		}
	}

	// check cols
	for (unsigned int col = 0; col < BOARD_SIZE; col++)
	{
		for (unsigned int value = MIN_ALLOWED_VALUE; value <= MAX_ALLOWED_VALUE; value++)
		{
			valueFound = false;
			for (unsigned int row = 0; row < BOARD_SIZE; row++)
			{
				if (getCellValue(row, col) == value)
				{
					if (!valueFound)
						valueFound = true;
					else
						return false;
				}
			}
		}
	}

	// check blocks
	for (unsigned int rowCorner = 0; rowCorner < BOARD_SIZE; rowCorner += BLOCK_SIZE)
	{
		for (unsigned int colCorner = 0; colCorner < BOARD_SIZE; colCorner += BLOCK_SIZE)
		{
			for (unsigned int value = MIN_ALLOWED_VALUE; value <= MAX_ALLOWED_VALUE; value++)
			{
				valueFound = false;
				for (unsigned int row = rowCorner; row < rowCorner + BLOCK_SIZE; row++)
				{
					for (unsigned int col = colCorner; col < colCorner + BLOCK_SIZE; col++)
					{
						if (getCellValue(row, col) == value)
						{
							if (!valueFound)
								valueFound = true;
							else
								return false;
						}
					}
				}
			}
		}
	}

	// check unsolved cells have a possible value
	bool hasAPossibleValue;
	for (unsigned int row = 0; row < BOARD_SIZE; row++)
	{
		for (unsigned int col = 0; col < BOARD_SIZE; col++)
		{
			if (!cellSolved(row, col))
			{
				hasAPossibleValue = false;
				for (unsigned int value = MIN_ALLOWED_VALUE; value <= MAX_ALLOWED_VALUE; value++)
				{
					if (getValuePossible(row, col, value))
					{
						hasAPossibleValue = true;
						break;
					}
				}
				if (!hasAPossibleValue)
					return false;
			}
		}
	}

	return true;
}
