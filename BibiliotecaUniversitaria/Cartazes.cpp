#include "Cartazes.h"

//Instânciando o número de páginas no construtor:
Cartazes::Cartazes(){
	this->numeroPaginas = 0;
}

//Destrutor:
Cartazes::~Cartazes(){
}

//Métodos GET e SET:
int Cartazes::getNumeroPaginas(){
	return numeroPaginas;
}

void Cartazes::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo a quantidade de páginas:	
void Cartazes::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Número de páginas........: " << numeroPaginas << endl << endl;
}
