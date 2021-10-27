#include <iostream>
#include <vector>
using namespace std;

//este template no serviria para string porque necesito 
//getline, puedo hacer una especifica 
template<typename T>
void leer(vector<T> &v){
	cout << "Leyendo un vector generico" << endl;
	for(int x:v)
		cin >> x;
}
	
void leer(vector<string> &v){
	cout << "Leyendo un vector de string" << endl;
	for(string x:v)
		getline(cin,x);
}	

int main() {
	
	vector<int> v(10);
	leer(v);
	
	vector<string> y(5);
	leer(y);
	
	return 0;
}

