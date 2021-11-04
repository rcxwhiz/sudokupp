#ifndef ROWELIMINATOR_H
#define ROWELIMINATOR_H

#include "SudokuEliminator.h"

class RowEliminator : public SudokuEliminator
{
public:
	bool eliminate(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;

	~RowEliminator() override = default;
};

#endif //ROWELIMINATOR_H
