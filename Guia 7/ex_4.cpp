#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ManejarArchivo {
private:
	fstream m_archi;
	int m_size;
	vector<float> v;
public:
	ManejarArchivo(string name){
		fstream m_archi(name,ios::binary|ios::in|ios::out|ios::ate);
		m_size = m_archi.tellg()/sizeof(float);
		m_archi.seekg(0);
	}
	void CargarArchivo(float x){
		for(int i=0;i<m_size;i++) { 
			m_archi.read(reinterpret_cast<char*>(&x),sizeof(x));
			v.push_back(x);
		}
	}
	string Open() {
		if(m_archi.is_open()) return "Esta abierto";
		else return "No esta abierto";
	}
};

int main() {
	
	ManejarArchivo ain("texto.txt");
	string o = ain.Open(); cout << o << endl;
	
	return 0;
}

