#include "SelfPossibilityDeterminer.h"

unsigned int SelfPossibilityDeterminer::determine(SudokuBoard& board) const
{
	unsigned int determined = 0;

	unsigned int newValue;
	for (unsigned int row = 0; row < SudokuBoard::BOARD_SIZE; row++)
	{
		for (unsigned int col = 0; col < SudokuBoard::BOARD_SIZE; col++)
		{
			newValue = SudokuBoard::UNSOLVED_VALUE;
			if (!board.cellSolved(row, col))
			{
				for (unsigned int potentialValue = SudokuBoard::MIN_ALLOWED_VALUE; potentialValue <= SudokuBoard::MAX_ALLOWED_VALUE; potentialValue++)
				{
					if (board.getValuePossible(row, col, potentialValue))
					{
						if (newValue == SudokuBoard::UNSOLVED_VALUE)
						{
							newValue = potentialValue;
						}
						else
						{
							newValue = SudokuBoard::UNSOLVED_VALUE;
							break;
						}
					}
				}
			}
			if (newValue != SudokuBoard::UNSOLVED_VALUE)
			{
				board.setCellValue(row, col, newValue);
				determined++;
			}
		}
	}

	return determined;
}
std::string SelfPossibilityDeterminer::name() const
{
	return "Self Possibility Determiner";
}
