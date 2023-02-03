#ifndef PERIODICOS_H
#define PERIODICOS_H

#include "Acervo.h"

class Periodicos : public Acervo{
	private:
		char tipo;
		int numeroPaginas;
	protected:
	
	public:
		Periodicos();
		~Periodicos();
		
		char getTipo();
		int getNumeroPaginas();
		
		void setTipo(char tipo);
		void setNumeroPaginas(int numeroPaginas);
		
		void imprimirInformacoes();
};

#endif
