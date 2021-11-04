#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
#include "../SudokuBoard.h"

class SudokuSolver
{
public:
	// Solve a board and return a new one
	[[nodiscard]] static SudokuBoard solve(const SudokuBoard& boardIn);
};

#endif //SUDOKUSOLVER_H
