#include "Relatorios.h"

//Inicializando o número de páginas do relatório no construtor:
Relatorios::Relatorios(){
	this->numeroPaginas = 0;
}

//Destrutor:
Relatorios::~Relatorios(){
}

//Método GET e SET:
int Relatorios::getNumeroPaginas(){
	return numeroPaginas;
}

void Relatorios::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo o número de páginas:
void Relatorios::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Número de páginas........: " << numeroPaginas << endl << endl;
}
