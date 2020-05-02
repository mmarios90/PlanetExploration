
#include "Repairer.h"
#include "Robot.h"
#include "Area.h"

#include "Analyser.h"
#include "Explorer.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Repairer::Repairer(int linex, int verty, int damage){


}

void Repairer :: myround(){

 	movelinex();
	moveverty();

	tm++;
	cout <<"       total movements"<< tm << endl;

}

void Repairer::movelinex() {

	int i=x;
			do
			   x=rand()%6+1;
			while((x!=i-1) && (x!=i+1) && (x!=i));
			cout << x;
}

void Repairer::moveverty() {

	int i=y;
				do
				   y=rand()%6+1;
				while((y!=i-1) && (y!=i+1) && (y!=i));
	cout << y << "\n";

}


void Repairer:: doing_my_job(Area * p){

	if (broken == false){
		d = d + p->danger;
		if(d > 20){

			broken = true;

		}

	}
	else if(broken == true){

		rem++;
		if(rem >= 10){		//εναπομείναντες γύροι

			DisposeObject();

		}

	}

}

void Repairer::repairing(Robot * q) {

	q->broken = false;
	q->d = 0;

	rp++;

	cout << "R: I've just repaired #"<< rp << endl;

}


void Repairer :: whoami(){

	cout <<"      Repairer ";

}



void Repairer :: mystats(){

	cout << "number of repairs: " << rp <<endl;
	cout << "damage: " << d <<endl;
	cout << "total movements: "<< tm <<endl;

}


Repairer::~Repairer() {}

