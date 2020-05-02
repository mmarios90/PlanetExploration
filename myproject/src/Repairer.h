
#ifndef REPAIRER_H
#define REPAIRER_H

#include "Robot.h"
#include "Area.h"
#include "Analyser.h"
#include "Explorer.h"

class Repairer: public Robot {

public:
	Repairer(int, int, int);

	virtual void myround();
	void movelinex();
	void moveverty();

	virtual void whoami();
	virtual void  mystats();

	virtual void doing_my_job(class Area * p);
	virtual void repairing(class Robot * q);    // επισκευή

	virtual ~Repairer();
};



#endif// REPAIRER_H
