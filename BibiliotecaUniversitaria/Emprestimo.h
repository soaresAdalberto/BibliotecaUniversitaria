#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <string>
#include "Leitor.h"
#include "Acervo.h"

using namespace std;

class Emprestimo{
	private:
		string dataEmprestimo;
		string dataLimiteDevolucao;
		string dataDevolucao;
		
		Leitor *leitor;
		Acervo *acervo;
		
	protected:
		
	public:
		Emprestimo();
		~Emprestimo();
		
		string getDataEmprestimo();
		string getDataLimiteDevolucao();
		string getDataDevolucao();
		
		Leitor* getLeitor();
		Acervo* getAcervo();
		
		void setDataEmprestimo(string dataEmprestimo);
		void setDataLimiteDevolucao(string dataLimiteDevolucao);
		void setDataDevolucao(string dataDevolucao);
		
		void setLeitor(Leitor *leitor);
		void setAcervo(Acervo *acervo);
		
		void imprimirInformacoes();
		void imprimirInformacoesDevolucao();
};

#endif
