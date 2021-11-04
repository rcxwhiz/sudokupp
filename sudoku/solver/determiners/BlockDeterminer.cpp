#include "BlockDeterminer.h"

unsigned int BlockDeterminer::determine(SudokuBoard& board) const
{
	unsigned int determined = 0;

	unsigned int potentialRow;
	unsigned int potentialCol;
	bool flag;
	for (unsigned int rowCorner = 0; rowCorner < SudokuBoard::BOARD_SIZE; rowCorner += SudokuBoard::BLOCK_SIZE)
	{
		for (unsigned int colCorner = 0; colCorner < SudokuBoard::BOARD_SIZE; colCorner += SudokuBoard::BLOCK_SIZE)
		{
			for (unsigned int value = SudokuBoard::MIN_ALLOWED_VALUE; value <= SudokuBoard::MAX_ALLOWED_VALUE; value++)
			{
				potentialRow = SudokuBoard::BOARD_SIZE;
				potentialCol = SudokuBoard::BOARD_SIZE;
				flag = true;
				for (unsigned int row = rowCorner; row < rowCorner + SudokuBoard::BLOCK_SIZE && flag; row++)
				{
					for (unsigned int col = colCorner; col < colCorner + SudokuBoard::BLOCK_SIZE && flag; col++)
					{
						if (board.getCellValue(row, col) == value)
						{
							potentialRow = SudokuBoard::BOARD_SIZE;
							potentialCol = SudokuBoard::BOARD_SIZE;

							flag = false;
						}
						else if (potentialRow == SudokuBoard::BOARD_SIZE)
						{
							if (board.getValuePossible(row, col, value))
							{
								potentialRow = row;
								potentialCol = col;
							}
						}
						else
						{
							if (board.getValuePossible(row, col, value))
							{
								potentialRow = SudokuBoard::BOARD_SIZE;
								potentialCol = SudokuBoard::BOARD_SIZE;

								flag = false;
							}
						}
					}
				}
				if (potentialRow != SudokuBoard::BOARD_SIZE)
				{
					board.setCellValue(potentialRow, potentialCol, value);
					determined++;
				}
			}
		}
	}

	return determined;
}
std::string BlockDeterminer::name() const
{
	return "Block Determiner";
}
