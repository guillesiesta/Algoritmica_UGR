#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>
#include <errno.h>
#include <list>

int Fac(int x) {
	  return (x == 1 ? 1 : x * Fac(x - 1));
}
int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
 
    pivot = array[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
 
    // La nueva posición del pivot
    return right;
}
void quicksort(int *array, int start, int end)
{
    int pivot;
 
    if (start < end) {
        pivot = divide(array, start, end);
 
        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}



int main(int argc, char * argv[]){

/*--------------------------*/
// ENTRADA INICIAL DE DATOS

if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <tamaño_grafo>" << endl;
      return -1;
    }

int N = atoi(argv[1]);
/*--------------------------*/

int **matriz = (int **) malloc (N*sizeof(int *));
 for (int i=0;i<N;i++)
	matriz[i]=(int *) malloc (N*sizeof(int));

/*--------------------------*/


/*--------------------------*/
// Rellenamos matriz con números aleatorios


int aleatorio = 0;
int cont1=0, cont2=0;

for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
	      aleatorio = (1 + rand() % 100);
              matriz[i][j] = aleatorio;
	      if(i>=j){
		matriz[i][j] = 0;
	      }
	      
    }
}

while(cont1!=N){
	matriz[cont1][cont2]=0;
	cont1++;
	cont2++;
}

/*--------------------------*/


int *vector;
vector = (int *) malloc (N*sizeof(int*));

int *vectorC;
vectorC = (int *) malloc (N*sizeof(int*));

//Rellenamos el vector

int contador = 0;

for(int i=0; i<N; i++){
	for(int j=0; j<N; j++){
		if(matriz[i][j] != 0){
			vector[contador] = matriz[i][j];
			contador ++;			
		}
	}
	
}


/*--------------------------*/
// Matriz rellenada

cout << "\nMATRIZ RELLENADA: \n";
for (int a=0;a<N;a++){
        for (int b=0;b<N;b++){
            cout << " " << matriz[a][b] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
/*
	Funcion para saber el tamaño del vector
	
	n!/(2!*(n-2)!)

	inline int Factorial(int x) {
	  return (x == 1 ? x : x * Factorial(x - 1));
	}


*/


//Mostramos vector sin ordenar
int tam;
tam = Fac(N)/(Fac(2) * (Fac(N-2)));

quicksort(vector, 0 , tam-1);

for(int j=0; j<tam; j++){
	vectorC[tam-j-1] = vector[j];
}

/*for(int b=0; b<tam; b++){
	cout << " " <<vector[b] << " ";
}*/
cout << "\n";


//Mostramos vector ordenado
for(int b=0; b<tam; b++){
	cout << " " <<vectorC[b] << " ";
}
 cout << "\n";





return 0;

}
