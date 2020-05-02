
#ifndef ROBOT_H
#define ROBOT_H

class Robot{



	public : Robot(int =1, int =1, int =1);


		friend class Repairer;
		void setposx();			//αρχικοποίηση x
		void setposy();			//αρχικοποίηση y

		int setpos(int Map[6][6]);

		int getX();				//επιστροφή της συντεταγμένης x
		int getY();				//επιστροφή της συντεταγμένης y
		int getD();				//επιστροφή της damage

		virtual void whoami(); 		//συναρτηση που εκτυπωνει την κλαση καθε αντικειμένου
		virtual void  mystats();	// συναρτηση για εκτύπωση stats

		virtual void myround(); 						//συνάρτηση για την κίνηση κάθε αντικειμένου
		virtual void doing_my_job(class Area * p);		//συνάρτηση για την σχετική αλληλεπίδραση με το σημείο(αντικείμενο) της Area
		virtual void repairing(class Robot * q);		//συνάρτηση για επισκευή

		void DisposeObject();							// συνάρτηση για καταστροή object

		virtual ~Robot();



	protected:
		int x; //συντεταγμένη x
		int y; //συνταταγμένη y

		int d; //ζημιά
		bool broken;//βλάβη

		int rem; // counter για διαγραφή αντικειμένου

		int tm;  //συνολικές κινήσεις
		int fl; // αριθμος τοποθετησεων flag
		int rp; //αριθμός επισκευών

		int total_load; // συνολικό φορτίο analyser
};



#endif //ROBOT_H
