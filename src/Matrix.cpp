//============================================================================
// Name        : Matrix.cpp
// Author      : Justin Bennett
// Version     :
// Copyright   : Your copyright notice...you notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>     /* srand, rand */
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>
#include "headers/jacobi.h"
#include "headers/operations.h"
#include "headers/gaussSeidel.h"
#include "headers/bisection.h"
#include "headers/rf.h"
#include "headers/newtons.h"
#include "headers/LU.h"
#include "headers/sor.h"
#include "headers/ge.h"
#include "headers/LU2.h"


using namespace std;






int main(int argc,char* argv[]) {

 	 int n,m,choice;

	 string test;

	 //stream variable
	 ifstream fs;
	 ifstream fs2;
	 //is the file found?
	 if(argc != 3){
	 		cout<<"Files not found"<<endl;
	 		return -1;
	 	}
	// cout<<RAND_MAX<<endl;

	//file already open?
	// cerr<<fs.is_open()<<endl;

	//take argument and open file
	 fs.open(argv[1]);

	//should be open now
	// cerr<<fs.is_open()<<endl;

	   if (!fs.is_open())
	   {
	     cout << "Operation not successfully performed\n";
	     fs.close();
	   }

	for(int i=0;i<argc;i++)
		 		printf("Argument %d: %s\n", (i), argv[i]);


		fs2.open(argv[2]);


		//create random matrix
cout<<"1. Use from file\n2. Autogenerate matrix"<<endl;
do{
	cin>>choice;

switch(choice){
case 1:
	cout<<"Matrix from file\n"<<endl;
	break;
case 2:
	randomMatrix();

	break;
default :

	cout<<"Select Valid Option\n"<<endl;
}
}while(choice!=("1"||"2"));

cout<<"chose solver"<<endl;
cout<<"1. Jacobi\n2. Gauss Seidel\n3. SOR\n4. Gaussian Elimination\n5. L-U\n6. Bi-section\n7. Regula Falsi\n8. Newtons\n9. Exit"<<endl;
cin>>choice;
do{

switch(choice){

case 1 :
	cout<<"Jacobi"<<endl;

	jacobi(argc,argv);

	break;

case 2:
	cout<<"Gauss-Seidel"<<endl;

	gaussSeidel(argc,argv);
	break;

case 3:

	cout<<"SOR"<<endl;
	sor(argc,argv);

	break;

case 4:

	cout<<"Gaussian Elimination"<<endl;
	gaussianElim(argc,argv);

	break;

case 5:

	cout<<"LU"<<endl;
	LU2(argc,argv);

	break;

case 6:

	cout<<"Bisection"<<endl;
	bisection();
	break;


case 7:

	cout<<"Regula Falsi"<<endl;
	rf();
	break;

case 8:

	cout<<"Newtons"<<endl;
	newtons();
	break;

default:
	cout<<"Choose valid selection"<<endl;
}
cin>>choice;
}while(choice!=9);

cout<<"All done"<<endl;
}

