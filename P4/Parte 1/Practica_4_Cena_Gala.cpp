#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>
#include <errno.h>
#include <list>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <chrono>


using namespace std::chrono;

high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;

int podan=0;
//-------------------------------------QUICKSORT


static void insercion_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      j--;
    };
  };
}


inline static void insercion(int T[], int num_elem)
{
  insercion_lims(T, 0, num_elem);
}



const int UMBRAL_QS = 50;

static void dividir_qs(int T[], int inicial, int final, int & pp)
{
  int pivote, aux;
  int k, l;

  pivote = T[inicial];
  k = inicial;
  l = final;
  do {
    k++;
  } while ((T[k] <= pivote) && (k < final-1));
  do {
    l--;
  } while (T[l] > pivote);
  while (k < l) {
    aux = T[k];
    T[k] = T[l];
    T[l] = aux;
    do k++; while (T[k] <= pivote);
    do l--; while (T[l] > pivote);
  };
  aux = T[inicial];
  T[inicial] = T[l];
  T[l] = aux;
  pp = l;
};



static void quicksort_lims(int T[], int inicial, int final)
{
  int k;
  if (final - inicial < UMBRAL_QS) {
    insercion_lims(T, inicial, final);
  } else {
    dividir_qs(T, inicial, final, k);
    quicksort_lims(T, inicial, k);
    quicksort_lims(T, k + 1, final);
  };
}

inline void quicksort(int T[], int num_elem)
{
  quicksort_lims(T, 0, num_elem);
}



//----------------------------------------------------------FIN QUICKSORT





 //------------------FUNCIÓN MATRIZ
int ** matrizTriangular( int N ) {
 
int **matriz = (int **) malloc (N*sizeof(int *));
 for (int i=0;i<N;i++)
    matriz[i]=(int *) malloc (N*sizeof(int));
 

int cont1=0, cont2=0;
 srand( time( NULL ) );
for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
		if(i==j){
			matriz[i][j]=0;
		}
		else if(i>j){
        matriz[i][j] = matriz[j][i];
          }
		else{
              matriz[i][j] = (1+ rand()%100);
        }
           
    }
}
 

 
return matriz;
 
 
}//--------------Fin matrizTriangular



int* vectorR(int N,int ** matriz,int &tam){
    int *vector;
	size_t size=50,newsize;
    vector = new int[size];
 
    
    
 
    //Rellenamos el vector
 
    int contador = 0;
 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i<j){
                vector[contador] = matriz[i][j];
                contador ++;   
				if(contador==size){
					 newsize = size*2;
   					 int* newArr = new int[newsize];

  					 memcpy( newArr, vector, (size) * sizeof(int) );
					 
					 size=newsize;
  					 delete [] vector;
  					 vector = newArr;					

            }
        }
	}
 }
tam=contador;
    
     
    quicksort(vector, contador);

    int temp;

    for (int i=0;i<tam/2;i++){
   	 temp = vector[i];
   	 vector[i] = vector[tam-1 -i];
   	 vector[tam-1 -i] = temp; 
    }

    return vector;

 
}//Fin vectorResultado
 
//-------------------------------------FUNCION BACKTRACKING

void Swap(int &in, int &fin){
    int aux= in;
    in=fin;
    fin=aux;
}
 
bool poda(int &convT, int convF, const int *vo, int nodo, int &tam ){
    int suma=0;
    for(int i=0; i<tam-nodo;i++){
        suma+=vo[i];
    }
    if (convT+suma<convF){
		podan+=1;
        return true;}
    else
        return false;
}
int VueltaAtras( int *sol, int nodo, int convT, int &convF, const int *vo, int &tam, int **m,int *ts ){
    int tem=0;

    if (nodo==tam-1){
		
        convF= max(convF, convT + m[sol[nodo]][sol[0]]);  
		//cout<<"Hoja"<<endl;
		if(convT + m[sol[nodo]][sol[0]]==convF){
			//cout<<"SOLUCION !!!!"<<endl;
			for(int i=0;i<tam;i++){
				ts[i]=sol[i];
			}}
		 
    }
    else{
        for(int i=nodo; i<tam; i++){
			Swap(sol[nodo+1],sol[i]);
			for(int j=0;j<tam;j++){			
			//cout<<" "<<sol[j];
			}
			//cout<<endl;
			
            if (poda(convT,convF,vo,nodo,tam)){}
            else{

                tem=convT+m[sol[i]][sol[i-1]];
                convF=max(convF, VueltaAtras(sol,nodo+1,tem,convF,vo,tam,m,ts));
            }
            Swap(sol[nodo+1],sol[i]);
        }
		
    }
	return convF;

     
}
 
 






//-------------------------------------*****************************************-----------------------------
 
int main(int argc, char * argv[]){

int tam;
 
 
if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <tamaño_grafo>" << endl;
      return -1;
    }
 
int N = atoi(argv[1]);
/*--------------------------*/
 
//Matriz-----------------------------------------------------------------
int ** matriz = matrizTriangular(N);
 
//-------------------------------------IMPRESION MATRIZ
/*
matriz[0][1]=100 ;
matriz[0][2]=1 ;
matriz[0][3]=1 ;
matriz[0][4]=100 ;
matriz[1][0]=100 ;
matriz[1][2]=100 ;
matriz[1][3]=1 ;
matriz[1][4]=1 ;
matriz[2][0]=1 ;
matriz[2][1]=100 ;
matriz[2][3]=100 ;
matriz[2][4]=1 ;
matriz[3][0]=1 ;
matriz[3][1]=1 ;
matriz[3][2]=100 ;
matriz[3][4]=100 ;
matriz[4][0]=100 ;
matriz[4][1]=1 ;
matriz[4][2]=1 ;
matriz[4][3]=100 ;

cout << "\nMATRIZ RELLENADA: \n";
for (int a=0;a<N;a++){
        for (int b=0;b<N;b++){
            cout << " " << matriz[a][b] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

*/


//Vector-----------------------------------------------------------------

int *vector = vectorR(N,matriz,tam);
 
//-------------------------------------IMPRESION VECTOR
 /*
//Mostramos vector ordenado
for(int b=0; b<tam; b++){
    cout << " " <<vector[b] << " ";
}
 cout << "\n\tNumero de Elementos: "<<tam<<endl;
*/

//-------------------------------------BACKTRACKING
int *sol, nodo=0,convT=0,convF=0,cm=0;
sol=new int[N];
	
	for(int i=0;i<N;i++){
		sol[i]=i;
	}	

int *solucion;
solucion=new int[N];

tantes = high_resolution_clock::now();
cm=VueltaAtras(sol,nodo,convT,convF,vector,N,matriz,solucion );

tdespues = high_resolution_clock::now();
transcurrido = duration_cast<duration<double>>(tdespues - tantes);
cout<<N<<" "<<transcurrido.count()<<" "<<podan<<endl;

//-------------------------------------IMPRESION VECTOR SOLUCION

//Mostramos vector solución
/*
for(int b=0; b<N; b++){
    cout << " " <<solucion[b] << " ";
}


*/



return 0;
} 
