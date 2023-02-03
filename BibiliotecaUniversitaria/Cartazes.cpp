#include "Cartazes.h"

//Inst�nciando o n�mero de p�ginas no construtor:
Cartazes::Cartazes(){
	this->numeroPaginas = 0;
}

//Destrutor:
Cartazes::~Cartazes(){
}

//M�todos GET e SET:
int Cartazes::getNumeroPaginas(){
	return numeroPaginas;
}

void Cartazes::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo a quantidade de p�ginas:	
void Cartazes::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "N�mero de p�ginas........: " << numeroPaginas << endl << endl;
}
