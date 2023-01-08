//class operation
#include"operations/operation.h"


class opDel : public operation
{
public:
	opDel(controller* pCont);

	virtual void ActionParamerers();
	void Undo() override;
	void Redo() override;
	virtual void Execute();
};
