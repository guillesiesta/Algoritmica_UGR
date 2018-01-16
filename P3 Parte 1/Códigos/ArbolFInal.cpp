#include <iostream>
using namespace std;
//#include <ctime>
#include <cstdlib>
#include <cassert>
#include <list>
#include <chrono>

using namespace std::chrono;

high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;

list<int> cola;

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C. 
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}


void borrah(int **arbol,int tam, int nodop){

for (int i=0;i<tam;i++)
	arbol[nodop][i]=0;

}

int padre(int **arbol,int tam, int nodoh){

int cont=0;

for (int i=0;i<tam;i++){
	for(int j=0;j<tam; j++){
		if(arbol[i][j]==1)
			cont++;
		if(cont==nodoh)
			return i;
	}
}
return -1;

}

void borracp(int **arbol,int nodo, int tam){

bool control=true;

for (int i=0;i<tam && control;i++){
	if(arbol[i][nodo]==1){
		arbol[i][nodo]=0;
		control=false;
	}
}

}

int ultimahoja(int **arbol,int tam){

int cont=0;

for (int i=0;i<tam;i++){
	for(int j=0; j<tam;j++){
		if(arbol[i][j]==1)
			cont++;
	}
}

return cont;
}

bool arbolvacio(int **arbol, int tam){

for (int i=0;i<tam;i++){
	for(int j=0;j<tam;j++){
		if(arbol[i][j]==1)
			return false;
	}
}
return true;
}



int main(int argc, char * argv[])
{

  if (argc != 3)
    {
      cerr << "Formato " << argv[0] << " <num_nodes>" <<  " <num_hijos_max>" << endl;
      return -1;
    }

  int numnodes = atoi(argv[1]);
  int maxh=atoi(argv[2]);


srand(time(NULL));
int **v;
v =  new int * [numnodes];
  assert(v);

for (int i = 0; i < numnodes; i++)
      v[i]= new int [numnodes];

int n=1; 					//cuenta el número de nodos generados hasta ahora
int i=0; 					//etiqueta del nodo
cola.push_back(i);			 	//es una cola FIFO
while (n < numnodes) {
    i=cola.front();
    cola.pop_front();
    double u=uniforme();
    int ch=1+(int)(maxh*u); 			//entero aleatorio entre 1 y maxh
    if ((ch+n) > numnodes) ch=numnodes-n; 	//para no generar más de numnodes nodos
    	for (int j=n; j<ch+n; j++) {
      		 v[i][j]=1; 			//v es la matriz de adyacencia del árbol
      		 cola.push_back(j);
   	 }
    n=n+ch;
}
  				
if(numnodes<20){
	while (!cola.empty()) cola.pop_front();

		for (int i=0; i<numnodes; i++) {
 			for (int j=0; j<numnodes; j++)
   				cout << v[i][j] << " ";
 				cout << " " << endl;
	}
}


int nodo,npadre;
list<int> sol; //cola FIFO conjunto solución
tantes = high_resolution_clock::now();
while(!arbolvacio(v,numnodes)){

	nodo=ultimahoja(v,numnodes);	//Obtengo la hoja con mayor profundida del arbol
	npadre=padre(v,numnodes,nodo);	//Obtengo el padre del nodo hoja anterior
	sol.push_back(npadre);		//Incluyo el nodo padre anteriormente obtenido en el conjunto solució
	borrah(v,numnodes,npadre);	//Elimino las conexiones con los hijos para le nodo anteriormente incluido en el conjunto solucion
	borracp(v,npadre,numnodes);	//Elimino la conexión del nodo solucion anterior con su padre.

}
tdespues = high_resolution_clock::now();
transcurrido = duration_cast<duration<double>>(tdespues - tantes);

						
cout<<"\n\n\tConjunto Solución: ";

	while (!sol.empty()){		//impresion de resultados
		i=sol.front();
			cout<<i<<" ";
			sol.pop_front();
	}

cout<<endl;

cout << numnodes <<" "<< transcurrido.count()<< endl;

} 
