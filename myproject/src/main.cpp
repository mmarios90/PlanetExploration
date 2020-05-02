//============================================================================
// Name        : myproject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <vector>
#include <new>

#include <unistd.h>
//#include <Windows.h>

#include "Robot.h"
#include "Explorer.h"
#include "Analyser.h"
#include "Repairer.h"

#include "Area.h"

using std::vector;
using namespace std;


int Map[6][6]={};											//απλος πινακας int για απεικονιση των αντικειμένων

int main (int argc, char * const argv[]) {
    // insert code here..

	char a = ' ';



	vector<Robot*> Planet;									//vector για τα robots

	srand (time(0));
	Area MapA[6][6];										// δημιουργία πίνακα αντικειμένων για τα στοιχεία κάθε περιοχής

	int i;

	Area *med;												//δείκτες για αντικείμενα ορίσματα
	Robot *q;

	Explorer* skato = new Explorer(0,0,0);					//δημιουργία αρχικών αντικειμένων
	Explorer* skato1 = new Explorer(0,0,0);

	Analyser* skaftias = new Analyser(0,0,0);
	Analyser* skaftias1 = new Analyser(0,0,0);

	Repairer* mastoras = new Repairer(0,0,0);
	Repairer* mastoras1 = new Repairer(0,0,0);



	Planet.push_back(skato);							//τοποθέτηση σε vector
	Planet.push_back(skato1);

	Planet.push_back(skaftias);
	Planet.push_back(skaftias1);

	Planet.push_back(mastoras);
	Planet.push_back(mastoras1);



	string S;										//επιλογή για ξεκίνημα προσωμοίωσης
	do{
		cout << "\nto start write 'START' and press Enter\n";
		cin >> S;
	}while(S != "START");



	//system("pause");




	for(i=0;i<Planet.size(); i++){	         // κληση συναρτησεων για τοποθέτηση για κάθε robot στην Map για απεικονιση

		Planet[i] ->setpos(Map);

	}


	cout << "\n";
	for(i=1; i<=6; i++){

		int j;
		for(j=1; j<=6; j++){

			if(Map[i][j] != 0){

				cout << "[*]";
				Map[i][j] = 0;
			}

			else{
				cout << "[ ]";
				}

		}

		cout << endl;
	}

	cout << endl;





	while(1){				//while για συνεχή ροή - επανάληψη της προσωοίωσης



		do{
			cout << "press R to run a round or M for menu ";
			cin >> a;
		}while((a != 'R') && (a !='M'));




		if(a == 'R'){

			int k,l;
			int v,m,n;
			int o;

			for(i=0;i<Planet.size(); i++){					//κίνηση και κλήση συνάρτησης για αλληλεπίδραση με το αντικείμενο του Area στο σημειο αυτο

				Planet[i]->myround();

				k = Planet[i]->getX() -1;
				l = Planet[i]->getY() -1;
				med = &MapA[k][l];
				Planet[i]->doing_my_job(med);

			}


			o = Analyser::base_ir + Analyser::base_pd + Analyser::base_pt;
			if(o > 300){														//όριο αποθηκευμένης ποσότητας στην βάση και έλεγχος του για τερματισμό!

				cout << "base has reached its storage limits!\n\n       We are rich!!!\n\n        THE END";
				exit( EXIT_SUCCESS);

			}


			for(i=0;i<Planet.size(); i++){									//έλεγχος αν υπάρχει στην ίδια θέση άλλο robot για κλήση επισκευής

				k = Planet[i]->getX();
				l = Planet[i]->getY();

				for(v=0;v<Planet.size(); v++){

					m = Planet[v]->getX();
					n = Planet[v]->getY();

					if((k==m && l==n) && Planet[v] != Planet[i] ){

						q = Planet[v];
						Planet[i]->repairing(q);

					}

				}

			}

		}




		else if(a=='M'){				//επιλογή menu για διαφορες ενέργειες χρήστη

			char ep;
			do{
				cout << "choose one of the following option:" << endl;
				cout <<"S to show the map and the current position of each robot"<<endl;
				cout <<"I to look at the information about a Robot "<<endl;
				cout <<"P to see the information of a point of map "<<endl;
				cout <<"G to see the basement storage"<<endl;
				cout <<"N to put a new robot"<<endl;
				cout <<"Q to exit from menu"<<endl;
				cin >> ep;
			}while((ep != 'S') && (ep !='I') && (ep !='P') && (ep !='G') && (ep !='N') && (ep !='Q'));


			if(ep == 'S'){	//επιλογή προβολής σημειων των robots

				for(i=1; i<=6; i++){			//καθαρισμός της Map

					int j;
					for(j=1; j<=6; j++){

						Map[i][j] = 0;

					}

				}

				int k,l;
				for(i=0;i<Planet.size(); i++){	// απεικονιση στο χαρτη

					k = Planet[i]->getX();
					l = Planet[i]->getY();

					cout << i <<") " << k << "," << l << endl;

					Planet[i] ->setpos(Map);

				}

				for(i=1; i<=6; i++){

					int j;
					for(j=1; j<=6; j++){

						if(Map[i][j] != 0){

							cout << "[*]";

						}

						else{

							cout << "[ ]";
						}
					}

					cout << endl;

				}
				cout << endl;

			}


			else if(ep == 'I'){				//	επιλέγουμε αντικείμενο βάσει των συντεταγμένων του

				int k,l,m,n;
				for(i=0;i<Planet.size(); i++){	// x,y και κλάση του κάθε αντικειμένου

					k = Planet[i]->getX();
					l = Planet[i]->getY();
					Planet[i]->whoami();
					cout << i <<") " << k << "," << l << endl;

				}

				cout << "choose one from above by its coordinates" << endl;
				cout << "firstly, press a number for the first coordinate and press enter"<< endl;
				cin >> m;
				cout << "and now do the same for the second one"<< endl;
				cin >> n;

				for(i=0;i<Planet.size(); i++){	// x,y και κλάση του κάθε αντικειμένου

					k = Planet[i]->getX();
					l = Planet[i]->getY();

					if((k==m) && (l==n)){

						Planet[i]->whoami();
						cout <<"\nmy coordinates: " << k << "," << l << endl;
						cout << "my stats:"<< endl;
						Planet[i]->mystats();


					}
				}
			}


			else if(ep == 'P'){				//επιλογή για προβολή στοιχείων ενός σημείου

				int m,n;

				cout << "choose one point by its coordinates" << endl;
				cout << "firstly, press a number for the first coordinate and press enter:"<< endl;
				cin >> m;
				cout << "and now do the same for the second one:"<< endl;
				cin >> n;

				MapA[m][n].pointstats();

			}


			else if(ep == 'N'){			//επιλογή εισαγωγής νέου αντικειμένου robot

				char ob;
				do{
					cout << "choose the class of the object you want to add: " << endl;
					cout << "for explorer press E"<<endl;
					cout << "for Analyser press A"<<endl;
					cout << "for Repairer press R"<<endl;
					cout << "to exit press Q"<<endl;
					cin >> ob;

				}while((ob != 'R') && (ob !='A') && (ob !='E')&& (ob !='Q'));

				if(ob == 'E'){

					cout << "You added an explorer with the following coordinates: ";
					Explorer* ex = new Explorer(0,0,0);
					Planet.push_back(ex);
					cout << "\n";

				}

				else if(ob == 'A'){

					cout << "You added an analyser with the following coordinates: ";
					Analyser* an = new Analyser(0,0,0);
					Planet.push_back(an);
					cout << "\n";

				}

				else if(ob == 'R'){

					cout << "You added a Repairer with the following coordinates: ";
					Repairer* rpr = new Repairer(0,0,0);
					Planet.push_back(rpr);
					cout << "\n";

				}


			}

			else if(ep == 'G'){														//	επιλογη εμφάνισης γενικών στοιχείων

				int o;
				cout << "     general info"<<endl;
				cout << "materials stored at base: "<<endl;

				cout <<"palladium: "<< Analyser :: base_pd <<endl;	//εμφάνιση των στοιχείων που αποθηκέυτηκαν στην βαση
				cout <<"platinum: "<< Analyser :: base_pt <<endl;
				cout <<"iridium: "<< Analyser :: base_ir <<endl;
				o = Analyser::base_ir + Analyser::base_pd + Analyser::base_pt;

				cout <<"total in base: "<< o << endl;

				cout << "\nmaterials left: "<<endl;


				int pt_left = 0;
				int pd_left = 0;
				int ir_left = 0;
				int total_left = 0;

				float avpt;
				float avpd;
				float avir;
				float avt;

				int c =  0;
				int j,i;
				for(i=0; i<6; i++){

					for(j=0; j<6; j++){

					pt_left = pt_left + MapA[i][j].getpt();
					pd_left = pd_left + MapA[i][j].getpd();
					ir_left = ir_left + MapA[i][j].getir();

					c++;

					}
				}

				cout<< "\nplatinum left in planet: "<< pt_left <<endl;			//εμφάνιση στοιχείων στον χάρτη
				avpt = pt_left / c;
				cout<< "with a point average: " << avpt << endl;

				cout<< "\npaladium left in planet: "<< pd_left <<endl;
				avpd = pd_left / c;
				cout<< "with a point average: " << avpd << endl;

				cout<< "\npaladium left in planet: "<<ir_left <<endl;
				avir = ir_left / c;
				cout<< "with a point average: " << avir << endl;

				total_left =ir_left + pd_left + pt_left;

				cout<< "\ntotal amount left in planet: "<< total_left <<endl;
				avt = total_left / c;
				cout<< "with a point average: " << avt << endl;

			}

		}



	}

	cout << "Hello, World!\n";		//απο εδώ ξεκίνησα!!!
	return 0;
}
