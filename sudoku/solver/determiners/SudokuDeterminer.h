#ifndef SUDOKUDETERMINER_H
#define SUDOKUDETERMINER_H

#include <string>
#include "../../SudokuBoard.h"

class SudokuDeterminer
{
public:
	virtual unsigned int determine(SudokuBoard& board) const = 0;
	[[nodiscard]] virtual std::string name() const = 0;

	virtual ~SudokuDeterminer() = default;
};

#endif //SUDOKUDETERMINER_H
