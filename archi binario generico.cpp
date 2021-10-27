#include <iostream>
#include <fstream>
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
		return file.tellg()/sizeof(float);
	};
	T VerReg(int i){
		file.seekg(i*sizeof(float));
		T f;
		file.read(reinterpret_cast<char*>(&f),sizeof(T));
		return f;
	};
	void AgregarReg(T x){
		//agrego al final 
		ModReg(CantidadReg(),x);
	};
	void ModReg(int i, T x){
		file.seekp(i*sizeof(float));
		file.write(reinterpret_cast<char*>(&x),sizeof(T));
	};
};

int main() {
	
	//aclaro que tipo de dato uso <float>
	ArchiBinario<float> a("flotantes.dat");
	for(int i=0;i<a.CantidadReg();i++) { 
		cout << a.VerReg(i) << endl;
	}
	
	return 0;
}

