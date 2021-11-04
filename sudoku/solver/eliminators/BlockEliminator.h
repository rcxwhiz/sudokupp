#ifndef BLOCKELIMINATOR_H
#define BLOCKELIMINATOR_H

#include "SudokuEliminator.h"

class BlockEliminator : public SudokuEliminator
{
public:
	bool eliminate(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;

	~BlockEliminator() override = default;
};

#endif //BLOCKELIMINATOR_H
