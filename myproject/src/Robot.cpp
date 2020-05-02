
#include "Robot.h"
#include "Explorer.h"
#include "Analyser.h"
#include "Repairer.h"

#include <cstdlib>
#include <iostream>

using namespace std;


Robot :: Robot(int linex, int verty, int damage) : x(linex), y(verty), d(damage)	//constractor
{


	x=linex;																		// αρχικοποίηση μελών του αντικειμένου
	y=verty;
	d = damage;

	tm = 0;
	fl = 0;
	rp = 0;

	total_load = 0;

	setposx();
	setposy();
	d = 0;
	broken = false;


//	cout << "test... you are in robot class"<< endl;


}

Robot :: ~Robot()		//destructor
{
}



void Robot :: setposx(){


	x=rand()%5+1;

	cout << "\n" << x <<", ";

	//return x;

}

void Robot :: setposy(){


	y=rand()%5+1;

	cout << y;

	//return y;

}

int Robot :: setpos(int Map[][6]){


	return Map[x][y]=1;


}


int Robot :: getX(){

	return x;

}

int Robot :: getY(){

	return y;

}

int Robot :: getD(){

	return d;

}

void Robot :: myround() {

}


void Robot :: whoami(){}

void Robot :: mystats(){}


void Robot :: doing_my_job(Area*  p){


}


void Robot:: repairing(class Robot * q){


}

void Robot :: DisposeObject(){


	delete this;
}

