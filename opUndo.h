#include"controller.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include "operations/operation.h"

//Add select operation class
class opUndo : public operation, public Graph
{
public:
	opUndo(controller* pCont);
	virtual ~opUndo();
	void Undo() override;
	void Redo() override;

	//Add Resize to the controller
	virtual void Execute();
};