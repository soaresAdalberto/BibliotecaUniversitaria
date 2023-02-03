#include "Emprestimo.h"

#include <iostream>

//Inicializando a quantidade de leitores e o tamanho do acervo no construtor:
Emprestimo::Emprestimo(){
	leitor = NULL;
	acervo = NULL;
}

//Destrutor:
Emprestimo::~Emprestimo(){
}

//Imprimmindo as informa��es do empr�stimo:
void Emprestimo::imprimirInformacoes(){
	cout << "--------------------------------------------" << endl;
	cout << "Data do empr�stimo.........: " << dataEmprestimo << endl;
	cout << "Data limite para devolu��o.: " << dataLimiteDevolucao << endl;
	cout << "Emprestado para............: " << leitor->getNome() << endl;
	cout << "CDU do item emprestado.....: " << acervo->getCDU() << endl;
	cout << "--------------------------------------------" << endl << endl;
}

//Imprimindo as informa��es da devolu��o do empr�stimo:
void Emprestimo::imprimirInformacoesDevolucao(){
	cout << "--------------------------------------------" << endl;
	cout << "Data do empr�stimo.........: " << dataEmprestimo << endl;
	cout << "Data limite para devolu��o.: " << dataLimiteDevolucao << endl;
	cout << "Data da devolu��o..........: " << dataDevolucao << endl;
	cout << "Emprestado para............: " << leitor->getNome() << endl;
	cout << "CDU do item emprestado.....: " << acervo->getCDU() << endl;
	cout << "--------------------------------------------" << endl << endl;
}

//M�todos GET e SET:
string Emprestimo::getDataEmprestimo(){
	return dataEmprestimo;
}

string Emprestimo::getDataLimiteDevolucao(){
	return dataLimiteDevolucao;
}

string Emprestimo::getDataDevolucao(){
	return dataDevolucao;
}

Leitor* Emprestimo::getLeitor(){
	return leitor;
}

Acervo* Emprestimo::getAcervo(){
	return acervo;
}

void Emprestimo::setDataEmprestimo(string dataEmprestimo){
	this->dataEmprestimo = dataEmprestimo;
}

void Emprestimo::setDataLimiteDevolucao(string dataLimiteDevolucao){
	this->dataLimiteDevolucao = dataLimiteDevolucao;
}

void Emprestimo::setDataDevolucao(string dataDevolucao){
	this->dataDevolucao = dataDevolucao;
}

void Emprestimo::setLeitor(Leitor* leitor){
	if(leitor != NULL){
		this->leitor = leitor;
	}
}

void Emprestimo::setAcervo(Acervo* acervo){
	if(acervo != NULL){
		this->acervo = acervo;
	}
}
