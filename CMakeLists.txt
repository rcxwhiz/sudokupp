cmake_minimum_required(VERSION 3.16)
project(sudokupp)

set(CMAKE_CXX_STANDARD 17)

add_executable(sudokupp main.cpp
        sudoku/solver/SudokuSolver.cpp
        sudoku/solver/SudokuSolver.h
        sudoku/SudokuBoard.cpp
        sudoku/SudokuBoard.h
        sudoku/solver/eliminators/SudokuEliminator.h
        sudoku/solver/determiners/SudokuDeterminer.h
        sudoku/solver/eliminators/RowEliminator.cpp
        sudoku/solver/eliminators/RowEliminator.h
        sudoku/solver/eliminators/ColumnEliminator.cpp
        sudoku/solver/eliminators/ColumnEliminator.h
        sudoku/solver/eliminators/BlockEliminator.cpp
        sudoku/solver/eliminators/BlockEliminator.h
        sudoku/solver/determiners/SelfPossibilityDeterminer.cpp
        sudoku/solver/determiners/SelfPossibilityDeterminer.h
        sudoku/solver/determiners/RowDeterminer.cpp
        sudoku/solver/determiners/RowDeterminer.h
        sudoku/solver/determiners/ColumnDeterminer.cpp
        sudoku/solver/determiners/ColumnDeterminer.h
        sudoku/solver/determiners/BlockDeterminer.cpp
        sudoku/solver/determiners/BlockDeterminer.h sudoku/solver/eliminators/LockedCandidateEliminator.cpp sudoku/solver/eliminators/LockedCandidateEliminator.h)
