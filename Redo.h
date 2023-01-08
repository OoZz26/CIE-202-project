#include"controller.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include "operations/operation.h"

//Add select operation class
class opRedo : public operation, public Graph
{
public:
	opRedo(controller* pCont);
	virtual ~opRedo();
	void Undo() override;
	void Redo() override;

	//Add Resize to the controller
	virtual void Execute();
};
