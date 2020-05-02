
#ifndef ANALYSER_H
#define ANALYSER_H

#include "Robot.h"
#include "Area.h"


class Analyser : public Robot{

	public : Analyser(int, int, int);

	//friend class Repairer;

	virtual void myround();

	void convey_to_base();		//συνάρτηση μεταφοράς στοιχείων στην βάση

	void movelinex();
	void moveverty();

	virtual void whoami();
	virtual void  mystats();

	virtual void doing_my_job(class Area * p);	// συλλογή στοιχείων-ζημια
	virtual void repairing(class Robot * q);

	virtual ~Analyser();

	static int base_pd;		//στοιχεία βάσης
	static int base_pt;
	static int base_ir;



	protected:

		int my_pt;	//φορτιο λευκόχρυσου
		int my_pd;	//φορτιο παλλαδίου
		int my_ir;	//φορτιο ιριδίου



	private:


};



#endif// ANALYSER_H
