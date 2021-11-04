#include "SudokuSolver.h"

#include <memory>
#include <stdexcept>
#include <vector>

#include "determiners/BlockDeterminer.h"
#include "determiners/ColumnDeterminer.h"
#include "determiners/RowDeterminer.h"
#include "determiners/SelfPossibilityDeterminer.h"

#include "eliminators/BlockEliminator.h"
#include "eliminators/ColumnEliminator.h"
#include "eliminators/LockedCandidateEliminator.h"
#include "eliminators/RowEliminator.h"

// TODO
#include <iostream>

SudokuBoard SudokuSolver::solve(const SudokuBoard& boardIn)
{
	SudokuBoard board = boardIn;

	if (!board.valid())
		throw std::runtime_error("Given invalid board");

	std::vector<std::unique_ptr<SudokuEliminator>> eliminators;
	eliminators.emplace_back(std::make_unique<BlockEliminator>());
	eliminators.emplace_back(std::make_unique<ColumnEliminator>());
	eliminators.emplace_back(std::make_unique<LockedCandidateEliminator>());
	eliminators.emplace_back(std::make_unique<RowEliminator>());

	std::vector<std::unique_ptr<SudokuDeterminer>> determiners;
	determiners.emplace_back(std::make_unique<BlockDeterminer>());
	determiners.emplace_back(std::make_unique<ColumnDeterminer>());
	determiners.emplace_back(std::make_unique<RowDeterminer>());
	determiners.emplace_back(std::make_unique<SelfPossibilityDeterminer>());

	unsigned int cellsSolved = 0;
	for (unsigned int row = 0; row < SudokuBoard::BOARD_SIZE; row++)
		for (unsigned int col = 0; col < SudokuBoard::BOARD_SIZE; col++)
			if (board.cellSolved(row, col))
				cellsSolved++;

	bool eliminated;
	unsigned int determined;
	bool lastRoundBad = false;

	while (true)
	{
		eliminated = false;
		determined = 0;

		// TODO
		std::cout << "Eliminating..." << std::endl;

		for (const auto& eliminator : eliminators)
		{
			// TODO
			std::cout << "Running " << eliminator->name() << std::endl;

			eliminated |= eliminator->eliminate(board);
		}

		// TODO
		std::cout << std::endl << "Determining..." << std::endl;

		for (const auto& determiner : determiners)
		{
			// TODO
			std::cout << "Running " << determiner->name() << std::endl;

			determined += determiner->determine(board);

			if (determined == SudokuBoard::BOARD_SIZE * SudokuBoard::BOARD_SIZE)
				break;
		}

		cellsSolved += determined;
		if (cellsSolved == SudokuBoard::BOARD_SIZE * SudokuBoard::BOARD_SIZE)
			return board;

		// TODO
		std::cout << std::endl << "Resolving if the last round was bad... eliminated: ";
		if (eliminated)
			std::cout << "true";
		else
			std::cout << "false";
		std::cout << " determined: " << determined << std::endl;
		std::cout << board << std::endl;

		if (lastRoundBad)
		{
			if (!eliminated && determined == 0)
				throw std::runtime_error("Cannot solve board");
			else
				lastRoundBad = false;
		}
		else if (!eliminated && determined == 0)
		{
			lastRoundBad = true;
		}
	}

}
