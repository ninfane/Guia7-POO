#include <iostream>
#include <cstdlib>
using namespace std;

struct Fraccion {
	int num, den;
};

//hago distintas rand 
double dbl_rand(){
	return double(rand())/RAND_MAX;
}

int int_rand(){
	return rand()%101;
}	
	
string str_rand(){
	int n = 3+rand()%8; //entre 3 y 10
	string s(n,'a'); 
	//hago una cadena inicial de 'aaaa' y le agrego valores
	//para que me queden distintos valores
	for(char &c : s){
		c += rand()%('z'-'a');
	}
	return s;
}	

Fraccion f_rand(){
	Fraccion f;
	f.num = rand()%101;
	f.den = rand()%100+1;
	return f;
}	
	
template<typename T>
class vectordinamico {
private:
	T *m_p;
	int m_n; //size
	//pablo hace esto porque al hacer new ya no me sirven
	//los constructores por defecto 
	vectordinamico(const vectordinamico &v); //operador de copia
	vectordinamico &operator=(const vectordinamico &v); //operador de asignacion
public:
	//puntero a funcion que no recibe nada y devuelve un T 
	//esta es la redaccion del puntero a funcion, pero debajo 
	//hay una mas facil
	/*
	vectordinamico(int n, T (*func)()): m_n(n), m_p(new T[n]) { 
		for(int i=0;i<m_n;i++) { 
			m_p[i] = func();
		}
	}
	*/
	
	//puntero a funcion que no recibe nada y devuelve un T 
	//generalizo el puntero a funcion y dejo que el compilador decida
	//que funcion debe ser segun lo que recibe
	template<typename Pfunc>
	vectordinamico(int n, Pfunc func): m_n(n), m_p(new T[n]) { 
		for(int i=0;i<m_n;i++) { 
			m_p[i] = func();
		}
	}
	//gralmente se hacen las dos versiones 
	T &operator[](int i){
		return m_p[i];
	}
	const T operator[](int i) const{
		return m_p[i];
	}
	int size() const { return m_n; }
	~vectordinamico() { delete[] m_p; }
};

template<typename T>
void mostrarvector(const vectordinamico<T> &v){
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	
	//le digo que use el random de double 
	vectordinamico<double> v1(10,dbl_rand);
	cout << "Vector dobles: " << endl;
	mostrarvector(v1);
	
	vectordinamico<string> v2(10,str_rand);
	cout << "Vector de string: " << endl;
	mostrarvector(v2);
	
	vectordinamico<int> v3(10,int_rand);
	cout << "Vector de int: " << endl;
	mostrarvector(v3);
	
	return 0;
}

