#ifndef CARTAZES_H
#define CARTAZES_H

#include "Acervo.h"

class Cartazes : public Acervo{
	private:
		int numeroPaginas;
	protected:
	
	public:
		Cartazes();
		~Cartazes();
		
		int getNumeroPaginas();
		
		void setNumeroPaginas(int numeroPaginas);
		
		void imprimirInformacoes();
};

#endif
