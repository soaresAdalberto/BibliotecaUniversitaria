/*                      BIBLIOTECAS UTILIZADAS                      */
#include <iostream>
#include <locale>
#include <vector>
#include <string>

/*                      INCLUINDO AS CLASSES                       */
#include "Acervo.h"
#include "Livros.h"
#include "Mapas.h"
#include "Midias.h"
#include "Leitor.h"
#include "Cartazes.h"
#include "Emprestimo.h"
#include "Relatorios.h"
#include "Periodicos.h"
#include "TrabalhosConclusao.h"

using namespace std;


/*            M�TODOS PARA ADICIONAR UM ITEM NO ACERVO              */
void adicionaItem(Acervo *acervo,int numItem)
{
	acervo->setID(numItem+1);
	
	//Vari�veis auxili�res:
	string titulo;
	string local;
	string cdu, isbn;
	string editoraProdutora;
	int ano;
	int tamanho = 0;
	int edicaoVolume;
	int quantidadeTotal;	
	float espessura;
	
	//Solicitando ao usu�rio o cadastro do CDU e fazendo a valida��o se ele digitou corretamente:
	do
	{
		cout << "Digite o CDU do item (nnn.nn:nnn.nn): ";
		getline(cin, cdu);
		tamanho = cdu.length();
		
		if(tamanho != 13)
		{
			cout << "O CDU deve possuir 13 caracteres (incluindo pontos e h�fen). Por gentileza, informe o n�mero de identifica��o corretamente." << endl;
		}
		
	} while(tamanho != 13);
	
	acervo->setCDU(cdu);
	cin.clear();
	fflush(stdin);
	
	//Solicitando ao usu�rio o cadastro do ISBN e fazendo a valida��o se ele digitou corretamente:
	do
	{
		tamanho = 0;
		cout << "Digite o ISBN do item (nn-nnnn-nnn-n): ";
		getline(cin, isbn);
		tamanho = isbn.length();
		
		if(tamanho != 13)
		{
			cout << "O ISBN deve possuir 13 caracteres (incluindo h�fens). Por gentileza, informe o n�mero de identifica��o corretamente." << endl;
		}
	} while(tamanho != 13);
	
	acervo->setISBN(isbn);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando o t�tulo:
	cout << "Digite o t�tulo do item: ";
	getline(cin, titulo);
	acervo->setTitulo(titulo);
	cin.clear();
	fflush(stdin);
	
	int i = 0;
	char adicionaAutor = 'S';
	string autor[NUM_AUTOR];
	
	//Cadastrando os autores:
	do
	{
		cout << "Digite o nome do " << i+1 << "� autor do item: ";
		getline(cin, autor[i]);
		cin.clear();
		fflush(stdin);
		i++;
		
		cout << "Deseja inserir mais um autor? [S/N] ";
		cin >> adicionaAutor;
		cin.clear();
		fflush(stdin);
	} while(i<5 && (adicionaAutor == 'S' || adicionaAutor == 's'));
	
	acervo->setAutor(autor);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando o assunto:	
	cout << "Digite o assunto do item: ";
	string assunto;
	getline(cin, assunto);
	acervo->setAssunto(assunto);
	cin.clear();
	fflush(stdin);
	
	i = 0;
	char adicionaPalavraChave = 'S';
	string palavraChave[NUM_PALCHAVE];
	
	//Cadastrando as palavras-chave:
	do
	{
		cout << "Digite a " << i+1 << "� palavra-chave: ";
		getline(cin, palavraChave[i]);
		cin.clear();
		fflush(stdin);
		i++;
		
		cout << "Deseja inserir mais uma palavra-chave? [S/N] ";
		cin >> adicionaPalavraChave;
		cin.clear();
		fflush(stdin);
	} while(i<5 && (adicionaPalavraChave == 'S' || adicionaPalavraChave == 's'));
	
	acervo->setPalavraChave(palavraChave);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando a cidade de publica��o:
	cout << "Digite a cidade de publica��o do item: ";
	getline(cin, local);
	acervo->setLocal(local);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando a editora/produtora:
	cout << "Digite a editora/produtora do item: ";
	getline(cin, editoraProdutora);
	acervo->setEditoraProdutora(editoraProdutora);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando a edi��o:
	cout << "Digite a edi��o do item: ";
	cin >> edicaoVolume;
	acervo->setEdicaoVolume(edicaoVolume);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando o ano de publica��o:
	cout << "Digite o ano de publica��o do item: ";
	cin >> ano;
	acervo->setAno(ano);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando a espessura:
	cout << "Digite a espessura (em cm) do item: ";
	cin >> espessura;
	acervo->setEspessura(espessura);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando os exemplares dispon�veis:
	cout << "Digite a quantidade total de exemplares dispon�veis: ";
	cin >> quantidadeTotal;
	acervo->setQuantidadeTotal(quantidadeTotal);
	acervo->setQuantidadeDisponivel(quantidadeTotal);
	cin.clear();
	fflush(stdin);
}

//M�todo espec�fico para cadastrar livros:
void adicionaLivro(Livros *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Cadastrando o g�nero:
	cout << "Digite o g�nero do livro: ";
	string genero;
	getline(cin, genero);
	acervo->setGenero(genero);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando o n�mero de p�ginas:
	cout << "Digite o n�mero de p�ginas do livro: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//M�todo espec�fico para cadastrar relat�rios:
void adicionaRelatorio(Relatorios *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando o n�mero de p�ginas:
	cout << "Digite o n�mero de p�ginas do relat�rio: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//M�todo espec�fico para cadastrar cartazes:
void adicionaCartaz(Cartazes *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando o n�mero de p�ginas:
	cout << "Digite o n�mero de p�ginas do cartaz: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//M�todo espec�fico para cadastrar mapas:
void adicionaMapa(Mapas *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando o n�mero de p�ginas:
	cout << "Digite o n�mero de p�ginas do mapa: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//M�todo espec�fico para cadastrar peri�dicos:
void adicionaPeriodico(Periodicos *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando se � revista ou jornal:
	cout << "Digite o tipo do peri�dico [R: Revista | J: Jornal]: ";
	char tipo;
	do
	{
		cin >> tipo;
		if(tipo != 'R' && tipo != 'r' && tipo != 'J' && tipo != 'j'){
			cout << "Op��o inv�lida! Por gentileza, insira uma op��o v�lida." << endl;
		}
	} while(tipo != 'R' && tipo != 'r' && tipo != 'J' && tipo != 'j');
	
	acervo->setTipo(tipo);
	cin.clear();
	fflush(stdin);
	
	//Solicitando o n�mero de p�ginas:
	cout << "Digite o n�mero de p�ginas do per�odico: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//M�todo espec�fico para adicionar TCC:
void adicionaTrabalhoDeConclusao(TrabalhosConclusao *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	char tipo;
	
	//Selecionando qual � a categoria do TCC:
	do
	{
		cout << "Digite o tipo do trabalho de conclus�o [M: Monografia | D: Disserta��o | T: Tese]: ";
		cin >> tipo;
		
		if(tipo != 'M' && tipo != 'm' && tipo != 'D' && tipo != 'd' && tipo != 'T' && tipo != 't')
		{
			cout << "Op��o innv�lida! Por gentileza, insira uma op��o v�lida." << endl;
		}
		
	} while(tipo != 'M' && tipo != 'm' && tipo != 'D' && tipo != 'd' && tipo != 'T' && tipo != 't');
	
	acervo->setTipo(tipo);
	cin.clear();
	fflush(stdin);
	
	//Solicitando o n�mero de p�ginas:
	cout << "Digite o n�mero de p�ginas do trabalho de conclus�o: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

void adicionaMidia(Midias *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	char tipo;
	
	//Solicitando qual � a categoria de m�dia:
	do
	{
		cout << "Digite o tipo do trabalho de m�dia [V: Fita VHS | C: CD | D: DVD]: ";
		cin >> tipo;
		if(tipo != 'C' && tipo != 'c' && tipo != 'D' && tipo != 'd' && tipo != 'V' && tipo != 'v')
		{
			cout << "Op��o inv�lida! Por gentileza, insira uma op��o v�lida." << endl;
		}
		
	}while(tipo != 'C' && tipo != 'c' && tipo != 'D' && tipo != 'd' && tipo != 'V' && tipo != 'v');
	
	acervo->setTipo(tipo);
	cin.clear();
	fflush(stdin);
	
	//Solicitand o tempo de dura��o:
	cout << "Digite o tempo de dura��o da m�dia: ";
	string tempoDuracao;
	getline(cin, tempoDuracao);
	acervo->setTempoDuracao(tempoDuracao);
	cin.clear();
	fflush(stdin);
}

/*               M�TODO PARA REALIZAR BUSCA PELO CDU                */
int localizaCDU(vector<Acervo *> &listAcervo,int *contItem)
{
	int encontrouItem = -1;
	
	//Solicitando o CDU:
	cout << "Digite o CDU do item: ";
	string buscaCDU = "";
	getline(cin, buscaCDU);
	cin.clear();
	fflush(stdin);
	
	//Percorrendo o acervo e validando se o CDU informado j� foi cadastrado:
	for(int i=0;i<*contItem;i++)
	{
		if(listAcervo[i]->getCDU() == buscaCDU)
		{
			encontrouItem = i;
		}
	}
	
	return encontrouItem;
}

/*               M�TODO PARA REALIZAR BUSCA PELO CPF                */
int localizaLeitor(vector<Leitor *> &listLeitor,int *contLeitor)
{
	int encontrouLeitor = -1;
	
	//Solictando o CPF do leitor:
	cout << "Digite o CPF do leitor: ";
	string buscaCPF = "";
	getline(cin, buscaCPF);
	cin.clear();
	fflush(stdin);
	
	//Percorrendo o cadastrado de leitores e validando se o leitor informado j� foi cadastrado:
	for(int i=0;i<*contLeitor;i++)
	{
		if(listLeitor[i]->getCPF() == buscaCPF)
		{
			encontrouLeitor = i;
			break;
		}
	}
	return encontrouLeitor;
}

/*             M�TODO PARA ALTERAR DADOS DE UM LEITOR               */
void alteraLeitor(vector<Leitor *> &listLeitor, int numLeitor)
{
	system("cls");
	int opcao = 0;
	Leitor *alteraLeitor = listLeitor[numLeitor];
	
	//Solicitando qual dado ser� atualizado:
	do
	{
		cout << "Insira a op��o desejada: ";
		cout << "1. Alterar nome."<< endl;
		cout << "2. Alterar CPF." << endl;
		cin >> opcao;
		cin.clear();
		fflush(stdin);
		
		if(opcao < 1 || opcao > 2)
		{
			cout << "Op��o inv�lida! Por gentileza, insira uma op��o v�lida." << endl << endl;
		}
		
	} while(opcao < 1 || opcao > 2);
	
	//Alterando o nome ou CPF:
	if(opcao == 1)
	{
		string novoNome;
		cout << "Digite o novo nome: ";
		getline(cin, novoNome);
		cin.clear();
		fflush(stdin);
		
		alteraLeitor->setNome(novoNome);
	}
	else if (opcao == 2)
	{
		string novoCPF;
		cout << "Digite o novo CPF: ";
		getline(cin, novoCPF);
		cin.clear();
		fflush(stdin);
		
		alteraLeitor->setCPF(novoCPF);
	}
	else 
	{
		cout << "Op��o inv�lida, tente novamente." << endl;
	}
}

/*               M�TODO PARA CADASTRAR UM LEITOR                    */
void cadastrarPessoa(Leitor *leitor, int numLeitor)
{
	system("cls");
	cout << "------------------------------------" << endl;
	cout << "        Cadastro de Leitores        " << endl;
	cout << "------------------------------------" << endl << endl;
	leitor->setID(numLeitor);
	
	//Solictando o nome do leitor:	
	cout << "Digite o nome da pessoa: ";
	string nome;
	getline(cin, nome);
	leitor->setNome(nome);
	cin.clear();
	fflush(stdin);
	
	//Solicitando o CPF do leitor:
	cout << "Digite o CPF da pessoa: ";
	string cpf;
	getline(cin, cpf);
	leitor->setCPF(cpf);
	cin.clear();
	fflush(stdin);
}

/*               M�TODO PARA REALIZAR UM EMPR�STIMO                 */
void realizarEmprestimo(Emprestimo *emprestimo, int numEmprestimo,vector<Leitor *> &listLeitor,int contLeitor,vector<Acervo *> &listAcervo,int contItem)
{
	cout << "------------------------------------" << endl;
	cout << "      Cadastro de Empr�stimos       " << endl;
	cout << "------------------------------------" << endl<< endl;
	
	int tamanho = 0;
	string dataEmprestimo = "", dataLimiteDevolucao = "", diaEmprestimo = "", mesEmprestimo = "", anoEmprestimo = "", diaLimite = "", mesLimite = "", anoLimite = "";
	
	//Cadastrando a data do empr�stimo e validando se est� dentro dos par�metros solicitados:
	do
	{
		cout << "Digite a data do empr�stimo (dd/mm/aaaa): ";
		getline(cin, dataEmprestimo);
		
		tamanho = dataEmprestimo.length();
		
		if(tamanho != 10)
		{
			cout << "A data deve ser inserida no formato dd/mm/aaaa. Por gentileza, insira a data no formato correto." << endl;
		}
		
	} while(tamanho != 10);
	
	//Se sim, seta a data do empr�stimo informada pelo usu�rio:
	emprestimo->setDataEmprestimo(dataEmprestimo);
	cin.clear();
	fflush(stdin);
	
	//Solicitando a data limite para devolu��o e validando se est� dentro dos par�metros solicitados:
	do
	{
		tamanho = 0;
		cout << "Digite a data limite para devolu��o (dd/mm/aaaa): ";
		getline(cin, dataLimiteDevolucao);
		
		tamanho = dataLimiteDevolucao.length();
		
		if(tamanho != 10)
		{
			cout << "A data deve ser inserida no formato dd/mm/aaaa. Por gentileza, insira a data no formato correto." << endl;
		}
		
		//Realiza a valida��o das datas:
		diaEmprestimo	= dataEmprestimo.substr(0,2);
		diaLimite 		= dataLimiteDevolucao.substr(0,2); 
		mesEmprestimo 	= dataEmprestimo.substr(3,2);
		mesLimite 		= dataLimiteDevolucao.substr(3,2);
		anoEmprestimo 	= dataEmprestimo.substr(6,4);
		anoLimite 		= dataLimiteDevolucao.substr(6,4);
		
		if((anoEmprestimo>anoLimite) || (anoEmprestimo == anoLimite && mesEmprestimo>mesLimite) || (anoEmprestimo == anoLimite && mesEmprestimo == mesLimite && diaEmprestimo>diaLimite))
		{
			cout << "A data limite n�o pode ser inferior � data do empr�stimo. Por gentileza, insira a data limite corretamente." << endl;
		}
		
	} while(tamanho != 10 || (anoEmprestimo>anoLimite) || (anoEmprestimo == anoLimite && mesEmprestimo>mesLimite) || (anoEmprestimo == anoLimite && mesEmprestimo == mesLimite && diaEmprestimo>diaLimite));

	//Se a data de devolu��o n�o for inferior � do emprestimo e passar pelas outras valida��es, ela � salva. 
	emprestimo->setDataLimiteDevolucao(dataLimiteDevolucao);
	cin.clear();
	fflush(stdin);
	
	//Setando o leitor que solicitou o empr�stimo e o acervo, com a data de devolu��o:
	emprestimo->setLeitor(listLeitor[contLeitor]);
	emprestimo->setAcervo(listAcervo[contItem]);
	emprestimo->setDataDevolucao("");
}

/*               M�TODO PARA REALIZAR UMA DEVOLU��O                 */
void realizarDevolucao(Emprestimo *emprestimo, int numDevolucao)
{
	cout << "------------------------------------" << endl;
	cout << "         Realizar devolu��o         " << endl;
	cout << "------------------------------------" << endl << endl;
	
	int tamanho = 0;
	string dataDevolucao = "", dataEmprestimo = "", diaEmprestimo = "", mesEmprestimo = "", anoEmprestimo = "", diaDevolucao = "", mesDevolucao = "", anoDevolucao = "";
	
	do
	{
		//Solicitando a data de devolu��o:
		cout << "Digite a data da devolu��o (dd/mm/aaaa): ";
		getline(cin, dataDevolucao);
		
		tamanho = dataDevolucao.length();
		
		//Validando se a data foi informada no par�metro correto:
		if(tamanho != 10)
		{
			cout << "A data deve ser inserida no formato dd/mm/aaaa. Por gentileza, insira a data no formato correto." << endl;
		}
		
		//Faz a valida��o das datas:
		dataEmprestimo 	= emprestimo->getDataEmprestimo();
		diaEmprestimo 	= dataEmprestimo.substr(0,2);
		diaDevolucao 	= dataDevolucao.substr(0,2); 
		mesEmprestimo 	= dataEmprestimo.substr(3,2);
		mesDevolucao 	= dataDevolucao.substr(3,2);
		anoEmprestimo 	= dataEmprestimo.substr(6,4);
		anoDevolucao 	= dataDevolucao.substr(6,4);
		
		if((anoEmprestimo>anoDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo>mesDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo == mesDevolucao && diaEmprestimo>diaDevolucao)) 
		{
			cout << "A data limite n�o pode ser inferior � data do empr�stimo. Por gentileza, insira a data limite corretamente." << endl;
		}
		
	} while(tamanho != 10 || (anoEmprestimo>anoDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo>mesDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo == mesDevolucao && diaEmprestimo>diaDevolucao));
	
	//Se passar pelos par�metros, � salva a devolu��o.
	emprestimo->setDataDevolucao(dataDevolucao);
	cin.clear();
	fflush(stdin);
}

/*                        FUN��O PRINCIPAL                         */
int main(int argc, char** argv) {
	
	//Aceitando caracteres especiais:
	setlocale(LC_ALL, "Portuguese");
	system("chcp 1252 > nul");
	
	//Criando a tela de login e senha:
	int i = 0;
	string nome;
	string login;
	string senha;
	string armazenaLogin[2];
	string armazenaSenha[2];
	armazenaLogin[0] = "admin";
	armazenaSenha[0] = "1q2w3e";
	
	//Mensagem inicial para o usu�rio:
	cout << "                                   ATEN��O! \n\
Para utiliza��o deste programa � necess�rio entrar com login e senha. Voc� pode utilizar\n\
o usu�rio criado pelo Eric (disponibilizado no ReadME) ou criar o seu. Por quest�o de \n\
economia de c�digo, o usu�rio dele � fixo e o que voc� est� criando � sempre substitu�vel.\n\
Ou seja, quando voc� cria um novo usu�rio substitui a posi��o [1] do array armazenaLogin \n\
e armazenaSenha." << endl << endl;
	system("pause");
	system("cls");
	
	//Valida��o do login e senha:	
	do 
	{
		inicio:
			
		cout << "----------------------------------------------------" << endl;
		cout << "Seja bem-vindo (a) � nossa Biblioteca Universit�ria!" << endl;
		cout << "----------------------------------------------------" << endl << endl;
		cout << "Escolha uma op��o: " << endl << endl;
		cout << "1. Acessar o sistema." << endl;
		cout << "2. Criar novo cadastro." << endl;
		cout << "3. Sair." << endl;
		cin >> i;
		cin.clear();
		fflush(stdin);
		
		if (i < 1 || i > 3) 
		{
			cout << "Op��o inv�lida, tente novamente." << endl;
			system("pause");
			system("cls");
		}
	} while (i < 1 || i > 3);
	
	//Entrando com o usu�rio, criando novo usu�rio ou saindo do sistema:
	if (i != 3) 
	{
		system("cls");
		
		switch (i) 
		{
			case 1: 		
				loginNovamente: 		
				
				cout << "Digite seu nome: " << endl;
				getline(cin, nome);
				
				cout << "Digite o login:" << endl;
				getline(cin, login);
				
				cout << "Digite a senha:" << endl;
				getline(cin, senha);
				
				if ((login == armazenaLogin[0] && senha == armazenaSenha[0]) 
				|| (login == armazenaLogin[1] && senha == armazenaSenha[1]))
				{
					system("cls");
					cout << "Entrando..." << endl << endl;
				}
				else 
				{
					char sn;
					
					system("cls");
					cout << "Senha incorreta, deseja tentar novamente? [S/N]" << endl << endl;
					cin >> sn;
					
					if (sn == 'S' || sn == 's')
					{
						system("cls");
						goto loginNovamente;
					} 
					else if (sn == 'N' || sn == 'n')
					{
						cout << "Obrigado por utilizar nosso programa" << endl;
						return 0;
					}

				}
			break;
			
			case 2:
				cout << "Digite um novo login:" << endl;
				getline(cin, armazenaLogin[1]);
				
				cout << "Digite uma nova senha:" << endl;
				getline(cin, armazenaSenha[1]);
				
				cout << "Usu�rio cadastrado, fa�a login novamente." << endl << endl;
				system("cls");
				
				goto inicio;
			break;
		}
	} 
	else 
	{
		system("cls");
		cout << "Saindo..." << endl << endl;
	}
	
	
	//Ap�s fazer o login, come�amos o nosso programa criando a tela inicial:
	int op = 0;
	int opAux = 0;
	
	vector<Acervo *> listAcervo;
	vector<Leitor *> listLeitor;
	vector<Emprestimo *> listEmprestimo;
	
	Acervo *acervo = NULL;
	Leitor *leitor = NULL;
	Emprestimo *emprestimo = NULL;
	
	int contItem = 0, contLeitor = 0, contEmprestimo = 0, quantidadeDisponivel = 0, encontrouCPF = -1, encontrouEmprestimo = -1;
	string busca = "";
	
	do 
	{
		do 
		{
			inicioNew:
				
			system("cls");
			
/*                          SERVI�OS OFERECIDOS PELA BIBLIOTECA                          */
			cout << "-------------------------------------------" << endl;
			cout << "Biblioteca Universit�ria - UEMG Divin�polis" << endl;
			cout << "-------------------------------------------" << endl << endl;
			cout << "Ol�, " << nome << ". Escolha uma op��o:" << endl << endl;
			cout << "1. Acervo." << endl;
			cout << "2. Cadastros." << endl;
			cout << "3. Empr�stimos." << endl;
			cout << "4. Invent�rio da biblioteca." << endl;
			cout << "5. Sair." << endl;
			cin >> op;
			cin.clear();
			fflush(stdin);
			
			if (op < 1 || op > 5) 
			{
				cout << "Op��o inv�lida, tente novamente." << endl;
				system("pause");
				system("cls");
			}
			
		} while (op < 1 || op > 13);
		
		if (op != 5) 
		{
			system("cls");
			
			switch (op)
			{
				
/*                            TELA DE ACERVO E SUAS OP��ES                            */
				case 1:
					do 
					{
						cout << "Bem vindo (a) ao acervo! " << nome << ", escolha uma op��o:" << endl << endl;
						cout << "1. Inserir." << endl;
						cout << "2. Remover." << endl;
						cout << "3. Pesquisar." << endl;
						cout << "4. Voltar." << endl; 
						cin >> op;
						cin.clear();
						fflush(stdin);
						
						if (op == 4)
						{
							goto inicioNew;
						}
						else if (op < 1 || op > 3) 
						{
							cout << "Op��o inv�lida, tente novamente." << endl;
							system("pause");
							system("cls");
						}
						
					} while (op < 1 || op > 3);
					
					
					if (op != 4)
					{
						system("cls");
						
						switch(op)
						{
							//Dentro da tela de inser��o, ele pode incluir os seguintes itens:
							case 1:
								novoInicio:
						
								cout << nome << ", o que voc� deseja cadastrar?" << endl << endl;
								cout << "1. Livro." << endl;
								cout << "2. Relat�rio." << endl;
								cout << "3. Cartaz." << endl;
								cout << "4. Mapa." << endl;
								cout << "5. Peri�dico." << endl;
								cout << "6. TCC." << endl;
								cout << "7. M�dia." << endl;
								cin >> opAux;
								cin.clear();
								fflush(stdin);
								
								system ("cls");
								
								if (opAux >= 1 && opAux <= 7) 
								{
									if (opAux == 1) 
									{
										acervo = new Livros();
										adicionaLivro(dynamic_cast<Livros*>(acervo),contItem);
										listAcervo.push_back(acervo);
										
										contItem++;
									} 
									else if (opAux == 2) 
									{
										acervo = new Relatorios();
										adicionaRelatorio(dynamic_cast<Relatorios*>(acervo),contItem);
										listAcervo.push_back(acervo);
			
										contItem++;
									}
									else if (opAux == 3)
									{
										acervo = new Cartazes();
										adicionaCartaz(dynamic_cast<Cartazes*>(acervo),contItem);
										listAcervo.push_back(acervo);
			
										contItem++;
									}
									else if (opAux == 4)
									{
										acervo = new Mapas();
										adicionaMapa(dynamic_cast<Mapas*>(acervo),contItem);
										listAcervo.push_back(acervo);
			
										contItem++;
									}
									else if (opAux == 5)
									{
										acervo = new Periodicos();
										adicionaPeriodico(dynamic_cast<Periodicos*>(acervo),contItem);
										listAcervo.push_back(acervo);
			
										contItem++;
									}
									else if (opAux == 6)
									{
										acervo = new TrabalhosConclusao();
										adicionaTrabalhoDeConclusao(dynamic_cast<TrabalhosConclusao*>(acervo),contItem);
										listAcervo.push_back(acervo);
			
										contItem++;
									}
									else if (opAux == 7)
									{
										acervo = new Midias();
										adicionaMidia(dynamic_cast<Midias*>(acervo),contItem);
										listAcervo.push_back(acervo);
			
										contItem++;
									}
									
									system("cls");
									cout << "Cadastro realizado com sucesso!" << endl << endl;
									acervo->imprimirInformacoes();
								}
								else 
								{
									cout << "Op��o inv�lida, tente novamente." << endl;
									system("pause");
									system("cls");
									goto novoInicio;
								}
								
								system("pause");
								system("cls");
							break;
							
							//Se ele desejar, tamb�m pode exclu�-los:
							case 2:
								if (listAcervo.empty())
								{
									cout << "Acervo vazio." << endl;
								}
								else 
								{
									int encontrouItem = localizaCDU(listAcervo,&contItem);
									
									if(encontrouItem < 0)
									{
										cout << "CDU n�o encontrado." << endl;
									}
									else
									{
										listAcervo.erase(listAcervo.begin() + encontrouItem);
										contItem--;
										cout << "Contato removido com sucesso." << endl;
									}
								}
								system("pause");
								system("cls");
							break;
							
							//Ainda, h� a possibilidade de pesquisar sobre a exist�ncia de um item pr�-cadastrado:
							case 3:
								if(listAcervo.empty())
								{
									cout << "Acervo vazio." << endl;
								}
								else
								{
									int encontrouItem = localizaCDU(listAcervo,&contItem);
									
									if(encontrouItem < 0)
									{
										cout << "Item n�o encontrado!" << endl;
									}
									else
									{
										acervo = listAcervo[encontrouItem];
										system("cls");
										cout << "Item encontrado!" << endl << endl;
										acervo->imprimirInformacoes();
									}
								}
								system("pause");
								system("cls");
							break;
							}
						}
						break;
				
/*                            TELA DE CADASTRO E SUAS OP��ES                            */
				case 2:
					do 
					{
						cout << "Bem vindo (a) ao cadastro! " << nome << ", escolha uma op��o:" << endl << endl;
						cout << "1. Cadastro de leitores." << endl;
						cout << "2. Altera��o de dados." << endl;
						cout << "3. Visualiza��o de leitores cadastrados." << endl;
						cout << "4. Voltar." << endl; 
						cin >> op;
						cin.clear();
						fflush(stdin);
						
						if (op == 4)
						{
							goto inicioNew;
						}
						else if (op < 1 || op > 3) 
						{
							cout << "Op��o inv�lida, tente novamente." << endl;
							system("pause");
							system("cls");
						}
						
					} while (op < 1 || op > 3);
					
					if (op != 4)
					{
						system("cls");
						
						switch(op)
						{
							//Cadastrar os leitores:
							case 1:
								leitor = new Leitor();
								cadastrarPessoa(leitor,(contLeitor + 1));
								listLeitor.push_back(leitor);
								
								leitor->imprimirInformacoes();
								
								contLeitor++;	
								system("pause");
								system("cls");
							break;
							
							//Alterar os dados dos leitores:
							case 2:
								if(listLeitor.empty())
								{
									cout << "N�o h� leitores cadastrados." << endl;
								}
								else
								{
									int encontrouLeitor = localizaLeitor(listLeitor,&contLeitor);
									
									if(encontrouLeitor < 0)
									{
										cout << "N�o h� nenhum leitor com esse CPF vinculado." << endl;
									}
									else
									{
										alteraLeitor(listLeitor,encontrouLeitor);
										cout << "Dados alterados com sucesso!" << endl;
									}
								}
								system("pause");
								system("cls");
							break;
							
							//Visualizar os leitores cadastrados:
							case 3:
								if(listLeitor.empty())
								{
									cout << "N�o h� leitores cadastrados." << endl;
								}
								else
								{
									system("cls");
									cout << "--------- Leitores Cadastrados ---------" << endl;
									
									for(int i=0;i<contLeitor;i++)
									{
										leitor = listLeitor[i];
										leitor->imprimirInformacoes();
									}
								}
								system("pause");
								system("cls");
							break;
						}
					}
					break;


/*                            TELA DE EMPR�STIMOS E SUAS OP��ES                            */
				case 3:
					do 
					{
						cout << "Bem vindo (a) ao setor de empr�stimos! " << nome << ", escolha uma op��o:" << endl << endl;
						cout << "1. Solicitar empr�stimo." << endl;
						cout << "2. Devolu��o de empr�stimo." << endl;
						cout << "3. Empr�stimos pendentes de devolu��o." << endl;
						cout << "4. Empr�stimos j� devolvidos." << endl;
						cout << "5. Voltar." << endl;
						cin >> op;
						cin.clear();
						fflush(stdin);
						
						if (op == 5)
						{
							goto inicioNew;
						}
						else if (op < 1 || op > 4) 
						{
							cout << "Op��o inv�lida, tente novamente." << endl;
							system("pause");
							system("cls");
						}
						
					} while (op < 1 || op > 4);
					
					if (op != 5)
					{
						switch(op) 
						{
							//Solicitando empr�stimo:
							case 1:
								if(listAcervo.empty())
								{
									cout << "N�o existe nenhum item inserido no acervo." << endl;
								}
								else
								{
									int encontrouLeitor = localizaLeitor(listLeitor,&contLeitor);
									
									if(encontrouLeitor < 0)
									{
										cout << "N�o h� nenhum leitor com esse CPF vinculado! \nPor gentileza, realize o cadastro antes do empr�stimo." << endl;
									}
									else
									{
										int encontrouItem = localizaCDU(listAcervo,&contItem);
										
										if(encontrouItem < 0)
										{
											cout << "N�o h� nenhum item com esse CDU cadastrado! \nPor gentileza, realize o cadastro antes do empr�stimo." << endl;
										}
										else
										{
											acervo = listAcervo[encontrouItem];
											int quantidadeDisponivel = acervo->getQuantidadeDisponivel();
											
											if(quantidadeDisponivel <= 0)
											{
												cout << "Todos os exemplares desse livro est�o emprestados." << endl;
											}
											else
											{
												system("cls");
												emprestimo = new Emprestimo();
												realizarEmprestimo(emprestimo,(contEmprestimo + 1),listLeitor,encontrouLeitor,listAcervo,encontrouItem);
												listEmprestimo.push_back(emprestimo);
												
												emprestimo->imprimirInformacoes();
												
												acervo = listAcervo[encontrouItem];
												acervo->setQuantidadeDisponivel(quantidadeDisponivel - 1);
												
												contEmprestimo++;
											}
										}
									}
								}
								system("pause");
								system("cls");
							break;
							
							//Devolvendo empr�stimo:
							case 2:
								if(listLeitor.empty())
								{
									cout << "N�o h� leitores cadastrados! \nPor gentileza, realize o cadastro antes de devolver o seu empr�stimo." << endl;
								}
								else
								{
									cout << "Digite o CPF do leitor: ";
									getline(cin, busca);
									cin.clear();
									fflush(stdin);
								
									for(int i = 0;i < contLeitor;i++)
									{
										leitor = listLeitor[i];
										if(leitor->getCPF() == busca)
										{
											encontrouCPF = i;
										}
									}
								
									if(encontrouCPF < 0)
									{
										cout << "N�o h� leitor cadastrado vinculado a esse CPF! Por gentileza, realize o cadastro antes de devolver o seu empr�stimo." << endl;
									}
									else
									{
										for(int i=0;i<contEmprestimo;i++)
										{
											emprestimo = listEmprestimo[i];
											if(emprestimo->getLeitor()->getCPF() == busca && (emprestimo->getDataDevolucao() == ""))
											{
												encontrouEmprestimo = i;
												break;
											}
										}
									}
									
									if(encontrouEmprestimo < 0)
									{
										cout << "N�o h� empr�stimo em aberto para esse leitor." << endl;
									}
									else
									{
										system("cls");
										cout << "--------------------------------------------" << endl;
										cout << "---------- Empr�stimo encontrado! ----------" << endl;
										cout << "--------------------------------------------" << endl << endl;
										
										realizarDevolucao(listEmprestimo[encontrouEmprestimo],(encontrouEmprestimo + 1));
			
										for(int j=0;j<contItem;j++)
										{
											acervo = listAcervo[j];
											emprestimo = listEmprestimo[encontrouEmprestimo];
											if(acervo->getCDU() == emprestimo->getAcervo()->getCDU())
											{
												//Se o empr�stimo tiver sido encontrado, aumenta um na quantidade de exemplares dispon�veis
												quantidadeDisponivel = acervo->getQuantidadeDisponivel();
												acervo->setQuantidadeDisponivel(quantidadeDisponivel+1);
												break;
											}
										}	
									}	
								}
								
								encontrouEmprestimo = -1;
								
								system("pause");
								system("cls");
								break;
							break;
							
							//Empr�stimos aguardando devolu��o:
							case 3:
								//Se houver pelo menos um empr�stimo realizado, mostra os empr�stimos pendentes de devolu��o.
								if(listEmprestimo.empty())
								{
									cout << "N�o h� empr�stimos realizados." << endl;
								}
								else
								{
									system("cls");
									cout << "---- Empr�stimos pendentes de devolu��o ----" << endl;
									for(int i=0;i<contEmprestimo;i++){
										emprestimo = listEmprestimo[i];
										if(emprestimo->getDataDevolucao() == ""){
											emprestimo->imprimirInformacoes();
										}
									}
								}
								system("pause");
								system("cls");
								break;
								
														
							//Visualizar empr�stimos j� devolvidos:
							case 4:
								//Se houver pelo menos um empr�stimo realizado, mostra os empr�stimos j� devolvidos.
								if(listEmprestimo.empty())
								{
									cout << "N�o h� empr�stimos realizados." << endl;
								}
								else
								{
									system("cls");
									cout << "--------- Empr�stimos j� devolvidos --------" << endl;
									
									for(int i=0;i<contEmprestimo;i++)
									{
										emprestimo = listEmprestimo[i];
										
										if(emprestimo->getDataDevolucao() != "")
										{
											emprestimo->imprimirInformacoesDevolucao();
										}
									}
								}
								system("pause");
								system("cls");
							break;
						}
					}
				break;
				
/*                            TELA DE INVENT�RIO E SUAS OP��ES                            */
				case 4:
					do 
					{
						cout << "Bem vindo (a) ao invent�rio! " << nome << ", escolha uma op��o:" << endl << endl;
						cout << "1. Visualizar ficha catalogr�fica." << endl;
						cout << "2. Visualizar listagem do acervo." << endl;
						cout << "3. Voltar." << endl;
						cin >> op;
						cin.clear();
						fflush(stdin);
						
						if (op == 3)
						{
							goto inicioNew;
						}
						else if (op < 1 || op > 2) 
						{
							cout << "Op��o inv�lida, tente novamente." << endl;
							system("pause");
							system("cls");
						}
						
					} while (op < 1 || op > 2);
					
					if (op != 3) 
					{
						switch (op)
						{
							//Visualizando ficha catalogr�fica:
							case 1:
								if(listAcervo.empty())
								{
									cout << "Acervo vazio." << endl;
								}
								else
								{
									int encontrouItem = localizaCDU(listAcervo,&contItem);
									
									if(encontrouItem < 0)
									{
										cout << "Item n�o encontrado!" << endl;
									}
									else
									{
										acervo = listAcervo[encontrouItem];
										system("cls");
										cout << "Item encontrado!" << endl << endl;
										acervo->imprimirFichaCatalografica();
									}	
								}
								system("pause");
								system("cls");
							break;
							
							//Visualizando listagem do acervo:
							case 2:
								if(listAcervo.empty())
								{
									cout << "N�o existe nenhum item inserido no acervo." << endl;
								}
								else
								{		
									system("cls");										
									for(int i=0;i<contItem;i++)
									{
										if(dynamic_cast<Livros*>(listAcervo[i]))
										{
											acervo = dynamic_cast<Livros*>(listAcervo[i]);
											
										}
										else if(dynamic_cast<Relatorios*>(listAcervo[i]))
										{
											acervo = dynamic_cast<Relatorios*>(listAcervo[i]);
										}
										else if(dynamic_cast<Cartazes*>(listAcervo[i]))
										{
											acervo = dynamic_cast<Cartazes*>(listAcervo[i]);
										
										}
										else if(dynamic_cast<Mapas*>(listAcervo[i]))
										{
											acervo = dynamic_cast<Mapas*>(listAcervo[i]);
			
										}
										else if(dynamic_cast<Periodicos*>(listAcervo[i]))
										{
											acervo = dynamic_cast<Periodicos*>(listAcervo[i]);
			
										}
										else if(dynamic_cast<TrabalhosConclusao*>(listAcervo[i]))
										{
											acervo = dynamic_cast<TrabalhosConclusao*>(listAcervo[i]);
											
										}
										else if(dynamic_cast<Midias*>(listAcervo[i]))
										{
											acervo = dynamic_cast<Midias*>(listAcervo[i]);
										}
										acervo->imprimirInformacoes();
									}
								}
								system("pause");
								system("cls");
							break;
						}
					}
				break;
			}
		}
	} while (op != 5);
	
	//Finalizando o programa:	
	system("cls");
	cout << "Obrigado por utilizar nosso programa!" << endl << endl;
	
	listAcervo.clear();
	listLeitor.clear();
	listEmprestimo.clear();
	
	return 0;
}
