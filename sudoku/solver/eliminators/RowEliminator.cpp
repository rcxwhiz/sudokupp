#include "RowEliminator.h"

bool RowEliminator::eliminate(SudokuBoard& board) const
{
	bool eliminated = false;

	for (unsigned int row = 0; row < SudokuBoard::BOARD_SIZE; row++)
	{
		for (unsigned int col = 0; col < SudokuBoard::BOARD_SIZE; col++)
		{
			if (board.cellSolved(row, col))
			{
				for (unsigned int otherCol = 0; otherCol < SudokuBoard::BOARD_SIZE; otherCol++)
				{
					if (board.getValuePossible(row, otherCol, board.getCellValue(row, col)))
					{
						board.setValueImpossible(row, otherCol, board.getCellValue(row, col));
						eliminated = true;
					}
				}
			}
		}
	}

	return eliminated;
}
std::string RowEliminator::name() const
{
	return "Row Eliminator";
}
