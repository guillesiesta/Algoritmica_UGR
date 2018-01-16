#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <chrono>

using namespace std::chrono;

high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}


int main(int argc, char * argv[]){

int inversion = 0;
int num;

// ----------------------------------------------

if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

srand(time(0));

for (int j=0; j<n; j++) T[j]=j;
//for (int j=0; j<n; j++) {cout << T[j] << " ";}
//algoritmo de random shuffling the Knuth (permutación aleatoria)
for (int j=n-1; j>0; j--) {
   double u=uniforme();
   int k=(int)(j*u);
   int tmp=T[j];
   T[j]=T[k];
   T[k]=tmp;
}
//cout << n << endl;
//for (int j=0; j<n; j++) {cout << T[j] << " ";}
//cout << endl;

// ----------------------------------------------

vector<int> x;
for(int i=0; i<n;i++)
x.push_back(T[i]);

// ----------------------------------------------


tantes = high_resolution_clock::now();

	for(int i=0; i<n; i++){
		num = x[i];
		for(int j=i; j<n; j++){
			if(num>x[j])
				inversion++;			
		}	

	}


tdespues = high_resolution_clock::now();

// ----------------------------------------------

transcurrido = duration_cast<duration<double>>(tdespues - tantes);
cout << n << "	" << transcurrido.count() << endl;

//cout << "\nLa inversión es: "<< inversion << endl;
//cout<< endl;

return 0;	

}
