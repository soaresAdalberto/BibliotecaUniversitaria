#include "Midias.h"

//Inicializando a vari�vel tempo de dura��o no construtor:
Midias::Midias(){
	this->tempoDuracao = "";
}

//Destrutor:
Midias::~Midias(){
}

//M�todos GET e SET:
char Midias::getTipo(){
	return tipo;
}

string Midias::getTempoDuracao(){
	return tempoDuracao;
}
	
void Midias::setTipo(char tipo){
	this->tipo = tipo;
}

void Midias::setTempoDuracao(string tempoDuracao){
	this->tempoDuracao = tempoDuracao;
}

//Imprimindo o tipo da m�dia e o tempo de dura��o:
void Midias::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Tipo.....................: " << tipo << endl;
	cout << "Tempo de dura��o.........: " << tempoDuracao << endl << endl;
}
