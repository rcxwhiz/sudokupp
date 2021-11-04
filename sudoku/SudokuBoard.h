#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <string>

class SudokuBoard
{
public:
	// Possible values of cells
	const static unsigned int MIN_ALLOWED_VALUE = 1;
	const static unsigned int MAX_ALLOWED_VALUE = 9;
	const static unsigned int NUM_VALUES = 1 + (MAX_ALLOWED_VALUE - MIN_ALLOWED_VALUE);

	// Properties of a standard sudoku board
	const static unsigned int BOARD_SIZE = 9;
	const static unsigned int BLOCK_SIZE = 3;
	const static unsigned int UNSOLVED_VALUE = MIN_ALLOWED_VALUE - 1;

	// The cell structure holding the data
	struct Cell
	{
		unsigned int value = UNSOLVED_VALUE;
		bool possibleValues[NUM_VALUES] = {true, true, true, true, true, true, true, true, true};
	};

	// Creates a SudokuBoard object from a file which describes a sudoku game
	static SudokuBoard fromFile(const char* filename);

	// To string function shows current values and if the board is legal
	[[nodiscard]] std::string toString() const;

	// Extraction operator override
	friend std::ostream &operator<<(std::ostream& os, const SudokuBoard& board);

	// Const operation to get the value of a cell
	[[nodiscard]] unsigned int getCellValue(unsigned int row, unsigned int col) const;

	// Operation to set a cell
	void setCellValue(unsigned int row, unsigned int col, unsigned int value);

	// Const operation to see if value is possible for cell
	[[nodiscard]] bool getValuePossible(unsigned int row, unsigned int col, unsigned int value) const;

	// Operation to set a value as not possible for the cell
	void setValueImpossible(unsigned int row, unsigned int col, unsigned int value);

	// Const operation to see if cell is solved
	[[nodiscard]] bool cellSolved(unsigned int row, unsigned int col) const;

	// Const operation to check if board is solved
	[[nodiscard]] bool solved() const;

	// Const operation to check if board is valid
	[[nodiscard]] bool valid() const;

private:
	// Cells member which is a 2D array of Cell structs
	Cell cells[BOARD_SIZE][BOARD_SIZE];
};

#endif //SUDOKUBOARD_H
