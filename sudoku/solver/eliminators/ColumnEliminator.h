#ifndef COLUMNELIMINATOR_H
#define COLUMNELIMINATOR_H

#include "SudokuEliminator.h"

class ColumnEliminator : public SudokuEliminator
{
public:
	bool eliminate(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;

	~ColumnEliminator() override = default;
};

#endif //COLUMNELIMINATOR_H
