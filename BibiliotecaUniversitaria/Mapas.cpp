#include "Mapas.h"

//Construtor:
Mapas::Mapas(){
}

//Destrutor:
Mapas::~Mapas(){
}


//M�todos GET e SET:
int Mapas::getNumeroPaginas(){
	return numeroPaginas;
}

void Mapas::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo o n�mero de p�ginas do mapa:		
void Mapas::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "N�mero de p�ginas........: " << numeroPaginas << endl << endl;
}
