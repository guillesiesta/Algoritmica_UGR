#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

int main(int argc, char * argv[]){

int inversion = 0;
int num;

cout << "argc :" <<argc;

	for(int i=1; i<argc; i++){
		num = atoi(argv[i]);
		for(int j=i; j<argc; j++){
			if(num>atoi(argv[j])){
				inversion++;			
			}
		}	

	}


cout << "\nLa inversión es: "<< inversion << endl;
cout<< endl;

}//FIN DEL MAIN -----------------------------------------------------------------------------
