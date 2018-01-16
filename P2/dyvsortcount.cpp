#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int,vector<int> > ord_cont(vector v){
	pair<int,vector<int> > p1;
	pair<int,vector<int> > p2;
	pair<int,vector<int> > p3;
	pair<int,vector<int> > finalp;

	//Comprobamos si estamos en un caso base o no 	
	if (v.size()==1){{
		pair <int, vector<int> > mip;
		mip.first=0;
		mip.second=v;
		return mip;
	}
	
	//Division del vector en 2 vectores	
	vector<string> a;
	vector<string> b;
	for (int i = 0; i < v.size()/2; i++){  //size() retorna valores enteros sin decimales, eliminando la parte decimal
		p1.second.push_back(v[i]);

	for (int i =v.size()/2 ;i < v.size(); i++)
		p2.second.push_back(v[i]);
		
	//fin de la division, los vectores resultantes son a y b
	//llamadas recursivas
	p1=ord_cont(a);
	p2=ord_cont(b);
	p3=contarOrdena(a,b);
		
	
	finalp.first=p1.first+p2.first+p3.first;
	finalp.second=v;

	return (finalp);

}






