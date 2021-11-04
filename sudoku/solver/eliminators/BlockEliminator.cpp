#include "BlockEliminator.h"

bool BlockEliminator::eliminate(SudokuBoard& board) const
{
	bool eliminated = false;

	for (unsigned int rowCorner = 0; rowCorner < SudokuBoard::BOARD_SIZE; rowCorner += SudokuBoard::BLOCK_SIZE)
	{
		for (unsigned int colCorner = 0; colCorner < SudokuBoard::BOARD_SIZE; colCorner += SudokuBoard::BLOCK_SIZE)
		{
			for (unsigned int row = rowCorner; row < rowCorner + SudokuBoard::BLOCK_SIZE; row++)
			{
				for (unsigned int col = colCorner; col < colCorner + SudokuBoard::BLOCK_SIZE; col++)
				{
					if (board.cellSolved(row, col))
					{
						for (unsigned int otherRow = rowCorner; otherRow < rowCorner + SudokuBoard::BLOCK_SIZE; otherRow++)
						{
							for (unsigned int otherCol = colCorner; otherCol < colCorner + SudokuBoard::BLOCK_SIZE; otherCol++)
							{
								if (board.getValuePossible(otherRow, otherCol, board.getCellValue(row, col)))
								{
									board.setValueImpossible(otherRow, otherCol, board.getCellValue(row, col));
									eliminated = true;
								}
							}
						}
					}
				}
			}
		}
	}

	return eliminated;
}
std::string BlockEliminator::name() const
{
	return "Block Eliminator";
}
