#ifndef TRABALHOSCONCLUSAO_H
#define TRABALHOSCONCLUSAO_H

#include "Acervo.h"

class TrabalhosConclusao : public Acervo{
	private:
		char tipo;
		int numeroPaginas;
	protected:
		
	public:
		TrabalhosConclusao();
		~TrabalhosConclusao();
		
		char getTipo();
		int getNumeroPaginas();
		
		void setTipo(char tipo);
		void setNumeroPaginas(int numeroPaginas);
		
		void imprimirInformacoes();
};

#endif
