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




//----------------------------------------
pair<int, vector<int> > contarOrdena(vector<int> u, vector<int> v){
	int cont=0,i=0,j=0,min;
	vector<int> z;
	pair<int, vector<int> > sol;
	
	while(i<u.size() && j<v.size()){
		if(u[i]<v[j]){
			z.push_back(u[i]);
			i++;
		}
		else{
			z.push_back(v[j]);
			j++;
			cont+=u.size()-i;
		}
	}
	
	if(i==u.size()){
		while(j<v.size()){
			z.push_back(v[j]);
			j++;
		}
	}
	else{
		while(i<u.size()){
			z.push_back(u[i]);
			i++;
		}
	}
	sol.first=cont;
	sol.second=z;

	return sol;
}


//-----------------------------------------
pair<int,vector<int> > ord_cont(vector<int> &v){
	pair<int,vector<int> > p1;
	pair<int,vector<int> > p2;
	pair<int,vector<int> > p3;
	pair<int,vector<int> > finalp;

	//Comprobamos si estamos en un caso base o no 	
	if (v.size()==1){
		pair <int, vector<int> > mip;
		mip.first=0;
		mip.second=v;
		return mip;
	}
	
	//Division del vector en 2 vectores	
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < v.size()/2; i++)  //size() retorna valores enteros sin decimales, eliminando la parte decimal
		a.push_back(v[i]);

	for (int i =v.size()/2 ;i < v.size(); i++)
		b.push_back(v[i]);
		
	//fin de la division, los vectores resultantes son a y b
	//llamadas recursivas
	p1=ord_cont(a);
	p2=ord_cont(b);
	//a=p1.second;
	//b=p2.second;
	p3=contarOrdena(a,b);
	v=p3.second;
		
	
	finalp.first=p1.first+p2.first+p3.first;
	finalp.second=v;

	return (finalp);

}



int main(int argc, char * argv[]){

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
 
	vector<int> v;
for(int i=0; i<n;i++)
v.push_back(T[i]);

	pair<int,vector<int> > ret;

	tantes = high_resolution_clock::now();
	
	ret=ord_cont(v);


	tdespues = high_resolution_clock::now();
	transcurrido = duration_cast<duration<double>>(tdespues - tantes);
	
	cout << n <<" "<< transcurrido.count()<< endl;

	//cout << "factor de inversion: " << ret.first << endl;
	//Mostrar el vector al final del conteo, es decir, ordenado:
/*	
	for(int i=0; i<ret.second.size(); i++){
		cout << " " << ret.second[i];
	}
	cout << endl;
	*/
	
	return 0;
}
