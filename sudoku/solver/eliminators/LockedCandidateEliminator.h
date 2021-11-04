#ifndef LOCKEDCANDIDATEELIMINATOR_H
#define LOCKEDCANDIDATEELIMINATOR_H

#include "SudokuEliminator.h"

class LockedCandidateEliminator : public SudokuEliminator
{
public:
	bool eliminate(SudokuBoard& board) const override;
	[[nodiscard]] std::string name() const override;
	~LockedCandidateEliminator() override = default;
};

#endif //LOCKEDCANDIDATEELIMINATOR_H
