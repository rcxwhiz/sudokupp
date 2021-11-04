#ifndef BLOCKDETERMINER_H
#define BLOCKDETERMINER_H

#include "SudokuDeterminer.h"

class BlockDeterminer : public SudokuDeterminer
{
public:
	unsigned int determine(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;

	BlockDeterminer() = default;
	~BlockDeterminer() override = default;
};

#endif //BLOCKDETERMINER_H
