#include "Relatorios.h"

//Inicializando o n�mero de p�ginas do relat�rio no construtor:
Relatorios::Relatorios(){
	this->numeroPaginas = 0;
}

//Destrutor:
Relatorios::~Relatorios(){
}

//M�todo GET e SET:
int Relatorios::getNumeroPaginas(){
	return numeroPaginas;
}

void Relatorios::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo o n�mero de p�ginas:
void Relatorios::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "N�mero de p�ginas........: " << numeroPaginas << endl << endl;
}
