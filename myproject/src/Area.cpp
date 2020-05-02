
#include "Area.h"
#include "Explorer.h"

#include <iostream>
#include <ctime>

using namespace std;



Area :: Area()
{
	// constructor

	setpd();			//αρχικοποίηση των μεταβλητών κάθε θέσης αντικειμένου μεσω του constructor
	setir();
	setpt();
	setdanger();
	setflag();


	//call_all();
}

void Area :: setpd(){		//χρησιμοποιούμε rand για επιστροφή μιας ψευφοτυχαίας τιμης με σχετικους φραγμους


	pd =(rand() %10) ;

}

void Area :: setir(){

	ir= (rand() %10);
	//cout << ir<< endl;
}

void Area :: setpt(){

	 pt= (rand() %10);
	 //cout << pt << endl ;

}

void Area :: setdanger(){

	danger=rand() %10;
	danger = danger/10;

}

void Area :: setflag(){

	flag = false;

}


int Area :: getpt() {

return pt ;

}

int Area :: getpd() {

return pd ;

}
int Area :: getir() {

return ir ;

}


void Area :: pointstats(){

	cout <<"platinum: "<< pt << endl;
	cout <<"palladium: "<< pd << endl;
	cout <<"iridium: "<< ir << endl;

	cout << "level of danger: " << danger << endl;

	if(flag ==false){
		cout << "It has not marked as dangerous with flag so far." << endl;
	}
	else{
		cout << "It has marked as dangerous with a flag" << endl;
	}

}


