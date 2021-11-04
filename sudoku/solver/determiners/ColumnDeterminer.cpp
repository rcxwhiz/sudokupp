#include "ColumnDeterminer.h"

unsigned int ColumnDeterminer::determine(SudokuBoard& board) const
{
	unsigned int determined = 0;

	unsigned int potentialCell;
	for (unsigned int col = 0; col < SudokuBoard::BOARD_SIZE; col++)
	{
		for (unsigned int value = SudokuBoard::MIN_ALLOWED_VALUE; value <= SudokuBoard::MAX_ALLOWED_VALUE; value++)
		{
			potentialCell = SudokuBoard::BOARD_SIZE;
			for (unsigned int row = 0; row < SudokuBoard::BOARD_SIZE; row++)
			{
				if (board.getCellValue(row, col) == value)
				{
					potentialCell = SudokuBoard::BOARD_SIZE;
					break;
				}
				else if (potentialCell == SudokuBoard::BOARD_SIZE)
				{
					if (board.getValuePossible(row, col, value))
						potentialCell = row;
				}
				else
				{
					if (board.getValuePossible(row, col, value))
					{
						potentialCell = SudokuBoard::BOARD_SIZE;
						break;
					}
				}
			}
			if (potentialCell != SudokuBoard::BOARD_SIZE)
			{
				board.setCellValue(potentialCell, col, value);
				determined++;
			}
		}
	}

	return determined;
}
std::string ColumnDeterminer::name() const
{
	return "Column Determiner";
}
