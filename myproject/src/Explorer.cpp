
#include "Explorer.h"
#include "Robot.h"
#include "Area.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Explorer :: Explorer(int linex, int verty, int damage){



}

void Explorer :: myround(){

 	movelinex();
	moveverty();


	tm++;
	cout <<"       total movements"<< tm << endl;

}


void Explorer ::  movelinex() {


	int i=x;
		do
		   x=rand()%6+1;
		while((x!=-i-2) && (x!=i+2) && (x!=-i-1) && (x!=i+1) && (x!=i)); //έως και x2speed
		cout << x;
}


void Explorer :: moveverty() {

	//int i;
	//do{
		//y=rand()%2+(y-1);
	//}while(y<=0);

	int i=y;
				do
				   y=rand()%6+1;
				while((y!=i-2) && (y!=i+2) && (y!=-i-1) && (y!=i+1)  && (y!=i));
	cout << y << "\n";
	//l=y;
	//return y;
}





 void Explorer :: doing_my_job(Area * p){

	 if (broken == false){					//λειτουργία αν δεν είναι χαλασμένο
		 if (p->danger > 0.5){

			 p->flag = true;

			 fl++;

			 cout << "E: I've just set a danger-flag #" << fl << endl;

		 }


		 d = d + p->danger;

		 if(d > 20){

			 broken = true;

		 }
	 }

	 else if(broken == true){

		rem++;
		if(rem >= 15){		//εναπομείναντες γύροι

				DisposeObject();

		}
	 }
}


void Explorer :: whoami(){

	cout <<"      Explorer ";
}


void Explorer :: mystats(){

	cout << "total flags: " << fl <<endl;
	cout << "damage: " << d <<endl;
	cout << "total movements: "<< tm <<endl;

}


 void Explorer::repairing(Robot * q) {}


Explorer :: ~Explorer(){}

