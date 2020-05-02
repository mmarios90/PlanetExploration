
#ifndef EXPLORER_H
#define EXPLORER_H

#include "Robot.h"
#include "Area.h"


class Explorer : public Robot{

	public : Explorer(int, int, int);

	//friend class Repairer;

	virtual void myround();

	void movelinex();
	void moveverty();


	virtual void whoami();
	virtual void  mystats();

	virtual void doing_my_job(class Area * p);
	virtual void repairing(class Robot * q);

	virtual ~Explorer();

};




#endif// EXPLORER_H
