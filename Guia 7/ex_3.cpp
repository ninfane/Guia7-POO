#include <iostream>
using namespace std;

template<typename T>
class VectorDinamico {
private:
	T *m_p;
	int m_size;
	int m_rango;
public:
	VectorDinamico(int size){
		m_p = new float[size];
		m_size = size;
	}
	//sobrecarga para random, este random es para float
	//hay que hacerlo con un puntero a funcion 
	//para saber que tipo de array aleatorio debo generar
	//paso desde el main la funcion que debe usar mi clase
	VectorDinamico(int size, int rango){
		m_rango = rango;
		m_p = new float[size];
		m_size = size;
		for(int i=0;i<size;i++) { 
			m_p[i] = (rand()%m_rango)/20.5;
		}
	}
	//no se como sobrecargar para modificar
	T operator[] (int i){
		return *(m_p+i);
	}
	~VectorDinamico() { delete []m_p; }
};

int main() {
	
	VectorDinamico<float> v(10,101);
	float p = v[2];
	cout << p << endl;
	
	return 0;
}

