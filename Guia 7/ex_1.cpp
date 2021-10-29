#include <iostream>
#include <vector>
using namespace std;

struct Persona {
	string name, apellido;
	int edad;
};

//hago una sobrecarga de comparacion para poder operar con struct
//y el template de Mayor
bool operator>(Persona p1, Persona p2){
	return p1.edad > p2.edad;
}

template <typename T>
T Mayor(T f1, T f2){
	if (f1>f2) return f1;
	else return f2;
}

//sobrecarga de Mayor para usar con vectores
template <typename T>
T Mayor(const vector<T> &v){
	T may = v[0];
	for(size_t i=1;i<v.size();i++) { 
		if(v[i]>may) may = v[i];
	}
	return may;
}

int main() {
	
	//aclarando data type
	int a = Mayor<int>(2,3);
	cout << "Mayor int: " << a << endl;
	
	//sin aclarar data type
	float b = Mayor(3.14,5.6);
	cout << "Mayor float: " << b << endl;
	
	//si no aclaro el data type, no funciona 
	string c = Mayor<string>("hola","want");
	cout << "Mayor string: " << c << endl;
	
	vector<int> x = {1,2,3,4,5};
	int x2 = Mayor(x);
	cout << "Mayor vector int: " << x2 << endl;
	
	char d = Mayor('a','z');
	cout << "Mayor char: " << d << endl;
	
	vector<string> s = {"gato","perro","find","something"};
	string s2 = Mayor(s);
	cout << "Mayor vector string: " << s2 << endl;
	
	Persona p1 = {"Marina","Crespo",26};
	Persona p2 = {"Lucas","Arismendi",28};
	Persona pm = Mayor(p1,p2);
	cout << "Mayor: " << pm.name << " " << pm.apellido << endl;
	
	return 0;
}

