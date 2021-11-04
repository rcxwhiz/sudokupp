#ifndef COLUMNDETERMINER_H
#define COLUMNDETERMINER_H

#include "SudokuDeterminer.h"

class ColumnDeterminer : public SudokuDeterminer
{
public:
	unsigned int determine(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;

	ColumnDeterminer() = default;
	~ColumnDeterminer() override = default;
};

#endif //COLUMNDETERMINER_H
