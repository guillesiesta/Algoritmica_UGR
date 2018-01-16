#include <iostream>
#include <utility>
#include <vector>

using namespace std;

pair<int, vector<int> > contarOrdena(vector<int> u, vector<int> v){//recibe las dos mitades ordenadas
	int cont=0,i=0,j=0,min;
	vector<int> z;
	pair<int, vector<int> > sol; //Par solucion

	while(i<u.size() && j<v.size()){ //bucle, hasta que uno de los dos vectores se acabe.
		if(u[i]<v[j]){          //Si el elemento i-esimo de u es menor que el j-esimo
			z.push_back(u[i]);  //Mete el elemento de u en el vector auxiliar
			i++;                //incrementa el contador del vector u
		}
		else{
			z.push_back(v[j]);  //Si no, mete el elemento de v e incrementa v
			j++;
			cont+=u.size()-i;   //Aumenta el contador de intercambios lo equivalente a el tamaño de u menos las posiciones que ya ha sido avanzado.
		}
	}
    //Completamos nuestro vector auxiliar con el resto de elementos que nos queden en alguno de los dos vectores.
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
//MAIN PARA PROBARLO.
int main(){
	vector<int> u,v;
	pair<int,vector<int> > ret;
	u.push_back(1);
	u.push_back(5);
	v.push_back(4);
	//v.push_back(8);

	ret=contarOrdena(u,v);
	cout << "Intercambia: " << ret.first << endl;
	cout << "Vector: ";
	for(int i=0; i<ret.second.size(); i++){
		cout << " " << ret.second[i];
	}
	cout << endl;

	return 0;
}


