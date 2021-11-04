#ifndef ROWDETERMINER_H
#define ROWDETERMINER_H

#include "SudokuDeterminer.h"

class RowDeterminer : public SudokuDeterminer
{
public:
	unsigned int determine(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;

	RowDeterminer() = default;
	~RowDeterminer() override = default;
};

#endif //ROWDETERMINER_H
