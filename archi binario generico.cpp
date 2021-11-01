#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

template<typename T>
class ArchiBinario{
private:
	fstream file;
public:
	ArchiBinario(string nombre): file(nombre,ios::binary|ios::in|ios::out) {};
	int CantidadReg() {
		//me voy al final y devuelvo la posicion
		file.seekg(ios::ate);
		return file.tellg()/sizeof(T);
	};
	T VerReg(int i){
		file.seekg(i*sizeof(T));
		T f;
		file.read(reinterpret_cast<char*>(&f),sizeof(T));
		return f;
	};
	void AgregarReg(T x){
		//agrego al final 
		ModReg(CantidadReg(),x);
	};
	void ModReg(int i, T x){
		file.seekp(i*sizeof(T));
		file.write(reinterpret_cast<char*>(&x),sizeof(T));
	};
};

int main() {
	
	//aclaro que tipo de dato uso <float>
	ArchiBinario<float> a("flotantes.dat");
	
	//corregir esto
	for(int i=0;i<20;i++) { 
		float x = (rand()%101)/20.5;
		a.AgregarReg(x);
	}
	
	for(int i=0;i<a.CantidadReg();i++) { 
		cout << a.VerReg(i) << endl;
	}
	
	return 0;
}

