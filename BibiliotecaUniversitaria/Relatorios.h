#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "Acervo.h"

class Relatorios : public Acervo{
	private:
		int numeroPaginas;
	protected:
	
	public:
		Relatorios();
		~Relatorios();
		
		int getNumeroPaginas();
		float getEspessura();
		
		void setNumeroPaginas(int numeroPaginas);
		
		void imprimirInformacoes();
};

#endif
