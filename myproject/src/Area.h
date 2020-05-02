
#ifndef AREA_H
#define AREA_H

#include "Explorer.h"

class Area{


public:
	Area();


	friend class Explorer;
	friend class Robot;
	friend class Analyser;
	friend class Repairer;

//	Area operator+(Area);


	void setpd();	//συναρτήσεις για αρχικοποίηση των στοιχείων
	void setir();
	void setpt();

	void setdanger();	//συνάρτηση για αρχικοποίηση επικινδυνότητας
	void setflag();		//συνάρτηση που θέτει flag να είναι false



	void pointstats();	//συνάρτηση για εκτύπωση στοιχείων μιας θέσης

	int getpt();		//συναρτήσεις για επιδτροφή των τιμών των στοιχείων
	int getpd();
	int getir();

	private:


	int pt;	//λευκόχρυσος
	int pd;	//παλλάδιο
	int ir;	//ιρίδιο



	float danger;//επικινδυνότητα
	bool flag; // σημαια κινδύνου(0 αν δεν υπάρχει, 1 αν υπάρχει)





};



#endif// Area
