#include <iostream>
using namespace std;

template <typename T>
void Clamp(T &v, T sup, T inf){
	if(v>sup) v = sup;
	if(v<inf) v = inf;
}

int main() {
	
	cout << "Ingrese valor, limite superior e inferior" << endl;
	int val, sup, inf; cin >> val >> sup >> inf;
	cout << "Mi valor: " << val << endl;
	
	Clamp(val,sup,inf);
	cout << "Mi valor: " << val << endl;
	
	return 0;
}

