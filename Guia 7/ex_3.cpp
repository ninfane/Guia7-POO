#include <iostream>
using namespace std;

class VectorDinamico {
private:
	float *m_p;
	int m_size;
public:
	VectorDinamico(int size){
		m_p = new float[size];
		m_size = size;
		for(int i=0;i<size;i++) { 
			m_p[i] = (rand()%101)/20.5;
		}
	}
	float operator[] (int i){
		return *(m_p+i);
	}
	~VectorDinamico() { delete []m_p; }
};

int main() {
	
	VectorDinamico v(10);
	float p = v[2];
	cout << p << endl;
	
	return 0;
}

