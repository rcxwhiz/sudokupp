#ifndef SUDOKUELIMINATOR_H
#define SUDOKUELIMINATOR_H

#include <string>
#include "../../SudokuBoard.h"

class SudokuEliminator
{
public:
	virtual bool eliminate(SudokuBoard& board) const = 0;
	[[nodiscard]] virtual std::string name() const = 0;

	virtual ~SudokuEliminator() = default;
};

#endif //SUDOKUELIMINATOR_H
