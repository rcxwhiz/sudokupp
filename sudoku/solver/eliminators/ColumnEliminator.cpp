#include "ColumnEliminator.h"

bool ColumnEliminator::eliminate(SudokuBoard& board) const
{
	bool eliminated = false;

	for (unsigned int col = 0; col < SudokuBoard::BOARD_SIZE; col++)
	{
		for (unsigned int row = 0; row < SudokuBoard::BOARD_SIZE; row++)
		{
			if (board.cellSolved(row, col))
			{
				for (unsigned int otherRow = 0; otherRow < SudokuBoard::BOARD_SIZE; otherRow++)
				{
					if (board.getValuePossible(otherRow, col, board.getCellValue(row, col)))
					{
						board.setValueImpossible(otherRow, col, board.getCellValue(row, col));
						eliminated = true;
					}
				}
			}
		}
	}

	return eliminated;
}
std::string ColumnEliminator::name() const
{
	return "Column Eliminator";
}
