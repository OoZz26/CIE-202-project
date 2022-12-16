/*#pragma once
#include "DefS.h"
#include "GUI\GUI.h"

class controller; //forward class declaration

*/
//Base class for all possible operations
//class operation
#include"operation.h"


class opDel : public operation
{
public:
	opDel(controller* pCont);
	virtual ~opDel();


	virtual void Execute();
};
