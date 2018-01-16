#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <cassert>

using namespace std::chrono;

high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;

int main(int argc, char * argv[]){

if (argc != 2)
    {
      cerr << "Formato " << argv[0] << "<tamaño_grafo>" << endl;
      return -1;
    }

int n = atoi(argv[1]);

srand(time(NULL));
int **matriz;
matriz =  new int * [n];
assert(matriz);

 for (int i = 0; i < n; i++)
      matriz[i]= new int [n];

int v1, v2;
int vertice[n]; //Subconjunto solución
int t = 0; //Contador que aumentaremos en 2 para meter los datos en vértice

/*--------------------------------------------------*/

//Rellenamos matriz a ceros

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
              matriz[i][j] = 0;
    }
}

while ((v1!=-1 and v2!=-1) and (v1<n or v2<n)){

      cin >> v1 >> v2;
      matriz[v1][v2]=1;
}

/*--------------------------------------------------*/

//Matriz rellenada

cout << "\nMATRIZ RELLENADA: \n";
for (int a=0;a<n;a++){
        for (int b=0;b<n;b++){
            cout << " " << matriz[a][b] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

/*--------------------------------------------------*/

/* Cogemos un arista y sus dos vértices. Posteriormente los quitaremos y volveremos a elegir una arista de manera aleatoria */

tantes = high_resolution_clock::now();

for(int x=0; x<n; x++){
    for(int y=0; y<n; y++){
        if(matriz[x][y]==1){ //Si encuentra la arista
            
            //Mete los dos vértices subconjunto solución
            vertice[t]=x;
            vertice[t+1]=y;
            t = t + 2;            
            
               
            for(int d=0; d<n; d++){ //Borrar las conexiones con esos vértices(FILAS)
                    matriz[x][d]=0;
                    matriz[y][d]=0;        
            }

            //Borramos las Columnas
            for(int d=0; d<n; d++){
                    matriz[d][x]=0;
                    matriz[d][y]=0;        
            }
            
        }
    }
}

tdespues = high_resolution_clock::now();
 
// Matriz resultante

cout << "MATRIZ MODIFICADA: \n";

for (int a=0;a<n;a++){
        for (int b=0;b<n;b++){
            cout << " " << matriz[a][b] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";


cout << "Resultado: [";

for(int g=0; g<t; g++)
    cout << vertice[g] << " ";

cout << "]\n" << endl;

transcurrido = duration_cast<duration<double>>(tdespues - tantes);
cout << n << "    " << transcurrido.count() << endl;

return 0;

}
