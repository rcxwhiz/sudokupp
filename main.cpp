#include <iostream>

#include "sudoku/SudokuBoard.h"
#include "sudoku/solver/SudokuSolver.h"

int main(int argc, char** argv)
{
	auto board = SudokuBoard::fromFile(argv[1]);

	std::cout << "Starting board" << std::endl << board << std::endl << std::endl;

	auto solvedBoard = SudokuSolver::solve(board);

	std::cout << "Solved Board" << std::endl << solvedBoard << std::endl;

	return 0;
}
