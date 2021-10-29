#include <iostream>
using namespace std;

class VectorDinamico {
private:
	float *m_p;
	int m_size;
	int m_rango;
public:
	VectorDinamico(int size){
		m_p = new float[size];
		m_size = size;
	}
	//sobrecarga para random, este random es para float
	VectorDinamico(int size, int rango){
		m_rango = rango;
		m_p = new float[size];
		m_size = size;
		for(int i=0;i<size;i++) { 
			m_p[i] = (rand()%m_rango)/20.5;
		}
	}
	//no se como sobrecargar para modificar
	float operator[] (int i){
		return *(m_p+i);
	}
	~VectorDinamico() { delete []m_p; }
};

int main() {
	
	VectorDinamico v(10,101);
	float p = v[2];
	cout << p << endl;
	
	return 0;
}

