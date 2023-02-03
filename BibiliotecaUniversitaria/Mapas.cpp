#include "Mapas.h"

//Construtor:
Mapas::Mapas(){
}

//Destrutor:
Mapas::~Mapas(){
}


//Métodos GET e SET:
int Mapas::getNumeroPaginas(){
	return numeroPaginas;
}

void Mapas::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo o número de páginas do mapa:		
void Mapas::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Número de páginas........: " << numeroPaginas << endl << endl;
}
