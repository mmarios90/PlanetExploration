
#include "Analyser.h"
#include "Robot.h"
#include "Area.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Analyser :: Analyser(int linex, int verty, int damage){




}

int Analyser :: base_pd = 0;
int Analyser :: base_pt = 0;
int Analyser :: base_ir = 0;

void Analyser :: myround(){

	movelinex();
	moveverty();

	tm++;
	cout <<"       total movements"<< tm << endl;

}


void Analyser ::  movelinex() {

	int i=x;
			do
			   x=rand()%6+1;
			while((x!=i-1) && (x!=i+1));

			cout << x;

}


void Analyser :: moveverty() {

	int i=y;
				do
				   y=rand()%6+1;
				while((y!=i-1) && (y!=i+1) && (y!=i) && (x!=i));
	cout << y << "\n";

}

void Analyser:: doing_my_job(Area * p){

	if (broken == false){					//λειτουργία εξόρυσης αν μόνο αν δεν είναι χαλασμένο(broken)
		if (p->flag == false){

			my_pt = my_pt + p->pt;
			my_pd = my_pd + p->pd;
			my_ir = my_ir + p->ir;

			total_load = my_pt + my_pd + my_ir;

			p->pt = 0;
			p->pd = 0;
			p->ir = 0;

			d = d + p->danger;

			cout << "A: I've just collected some materials. Now I have a load of"<< total_load << endl;

			if(total_load >100){

				convey_to_base();

			}

			if(d > 15){

				broken = true;

			}
		}

		else if(broken == true){

			rem++;
			if(rem >= 15){		//εναπομείναντες γύροι

				DisposeObject(); //καταστροφή αντικειμένου

			}

		}


	}


}



void Analyser :: convey_to_base(){

	x = y = 0;

	base_pt = base_pt + my_pt;
	base_pd = base_pd + my_pd;
	base_ir = base_ir + my_ir;

	// άδειασμα φορτίου
	my_pt = 0;
	my_pd = 0;
	my_ir = 0;
	total_load = 0;

}


void Analyser::repairing(Robot * q) {}


void Analyser :: whoami(){

	cout <<"      Analyser ";

}


void Analyser :: mystats(){

	cout <<"\nIt is currently carries: "<<endl;
	cout << "platinum: " << my_pt <<endl;
	cout << "palladium: " << my_pd <<endl;
	cout << "iridium: " << my_ir <<endl;
	cout << "damage: " << d <<endl;
	cout << "total movements: "<< tm <<endl;

}

Analyser :: ~Analyser(){}

