#include "LockedCandidateEliminator.h"

#include <set>

bool LockedCandidateEliminator::eliminate(SudokuBoard& board) const
{
	bool eliminated = false;

	std::set<unsigned int> rowsAppearedIn;
	std::set<unsigned int> colsAppearedIn;
	bool valueAlreadyUsed;
	for (unsigned int rowCorner = 0; rowCorner < SudokuBoard::BOARD_SIZE; rowCorner += SudokuBoard::BLOCK_SIZE)
	{
		for (unsigned int colCorner = 0; colCorner < SudokuBoard::BOARD_SIZE; colCorner += SudokuBoard::BLOCK_SIZE)
		{
			for (unsigned int value = SudokuBoard::MIN_ALLOWED_VALUE; value <= SudokuBoard::MAX_ALLOWED_VALUE; value++)
			{
				rowsAppearedIn.clear();
				colsAppearedIn.clear();
				valueAlreadyUsed = false;

				for (unsigned int row = rowCorner; row < rowCorner + SudokuBoard::BLOCK_SIZE && !valueAlreadyUsed; row++)
				{
					for (unsigned int col = colCorner; col < colCorner + SudokuBoard::BLOCK_SIZE && !valueAlreadyUsed; col++)
					{
						if (board.getCellValue(row, col) == value)
						{
							valueAlreadyUsed = true;
						}
						else if (board.getValuePossible(row, col, value))
						{
							rowsAppearedIn.insert(row);
							colsAppearedIn.insert(col);
						}
					}
				}

				if (rowsAppearedIn.size() == 1)
					for (unsigned int col = 0; col < SudokuBoard::BOARD_SIZE; col++)
						if (col < colCorner || col >= colCorner + SudokuBoard::BLOCK_SIZE)
							board.setValueImpossible(*rowsAppearedIn.begin(), col, value);

				if (colsAppearedIn.size() == 1)
					for (unsigned int row = 0; row < SudokuBoard::BOARD_SIZE; row++)
						if (row < rowCorner || row >= rowCorner + SudokuBoard::BLOCK_SIZE)
							board.setValueImpossible(row, *colsAppearedIn.begin(), value);
			}
		}
	}

	return eliminated;
}
std::string LockedCandidateEliminator::name() const
{
	return "Locked Candidate Eliminator";
}
