#ifndef SELFPOSSIBILITYDETERMINER_H
#define SELFPOSSIBILITYDETERMINER_H

#include "SudokuDeterminer.h"

class SelfPossibilityDeterminer : public SudokuDeterminer
{
public:
	unsigned int determine(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;

	SelfPossibilityDeterminer() = default;
	~SelfPossibilityDeterminer() override = default;
};

#endif //SELFPOSSIBILITYDETERMINER_H
