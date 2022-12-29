
#include"operation.h"


class opDel : public operation
{
public:
	opDel(controller* pCont);
	
	virtual void ActionParamerers();

	virtual void Execute();
};
