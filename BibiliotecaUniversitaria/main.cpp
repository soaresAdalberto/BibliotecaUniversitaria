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


/*            MÉTODOS PARA ADICIONAR UM ITEM NO ACERVO              */
void adicionaItem(Acervo *acervo,int numItem)
{
	acervo->setID(numItem+1);
	
	//Variáveis auxiliáres:
	string titulo;
	string local;
	string cdu, isbn;
	string editoraProdutora;
	int ano;
	int tamanho = 0;
	int edicaoVolume;
	int quantidadeTotal;	
	float espessura;
	
	//Solicitando ao usuário o cadastro do CDU e fazendo a validação se ele digitou corretamente:
	do
	{
		cout << "Digite o CDU do item (nnn.nn:nnn.nn): ";
		getline(cin, cdu);
		tamanho = cdu.length();
		
		if(tamanho != 13)
		{
			cout << "O CDU deve possuir 13 caracteres (incluindo pontos e hífen). Por gentileza, informe o número de identificação corretamente." << endl;
		}
		
	} while(tamanho != 13);
	
	acervo->setCDU(cdu);
	cin.clear();
	fflush(stdin);
	
	//Solicitando ao usuário o cadastro do ISBN e fazendo a validação se ele digitou corretamente:
	do
	{
		tamanho = 0;
		cout << "Digite o ISBN do item (nn-nnnn-nnn-n): ";
		getline(cin, isbn);
		tamanho = isbn.length();
		
		if(tamanho != 13)
		{
			cout << "O ISBN deve possuir 13 caracteres (incluindo hífens). Por gentileza, informe o número de identificação corretamente." << endl;
		}
	} while(tamanho != 13);
	
	acervo->setISBN(isbn);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando o título:
	cout << "Digite o título do item: ";
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
		cout << "Digite o nome do " << i+1 << "º autor do item: ";
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
		cout << "Digite a " << i+1 << "ª palavra-chave: ";
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
	
	//Cadastrando a cidade de publicação:
	cout << "Digite a cidade de publicação do item: ";
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
	
	//Cadastrando a edição:
	cout << "Digite a edição do item: ";
	cin >> edicaoVolume;
	acervo->setEdicaoVolume(edicaoVolume);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando o ano de publicação:
	cout << "Digite o ano de publicação do item: ";
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
	
	//Cadastrando os exemplares disponíveis:
	cout << "Digite a quantidade total de exemplares disponíveis: ";
	cin >> quantidadeTotal;
	acervo->setQuantidadeTotal(quantidadeTotal);
	acervo->setQuantidadeDisponivel(quantidadeTotal);
	cin.clear();
	fflush(stdin);
}

//Método específico para cadastrar livros:
void adicionaLivro(Livros *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Cadastrando o gênero:
	cout << "Digite o gênero do livro: ";
	string genero;
	getline(cin, genero);
	acervo->setGenero(genero);
	cin.clear();
	fflush(stdin);
	
	//Cadastrando o número de páginas:
	cout << "Digite o número de páginas do livro: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//Método específico para cadastrar relatórios:
void adicionaRelatorio(Relatorios *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando o número de páginas:
	cout << "Digite o número de páginas do relatório: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//Método específico para cadastrar cartazes:
void adicionaCartaz(Cartazes *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando o número de páginas:
	cout << "Digite o número de páginas do cartaz: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//Método específico para cadastrar mapas:
void adicionaMapa(Mapas *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando o número de páginas:
	cout << "Digite o número de páginas do mapa: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//Método específico para cadastrar periódicos:
void adicionaPeriodico(Periodicos *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	
	//Solicitando se é revista ou jornal:
	cout << "Digite o tipo do periódico [R: Revista | J: Jornal]: ";
	char tipo;
	do
	{
		cin >> tipo;
		if(tipo != 'R' && tipo != 'r' && tipo != 'J' && tipo != 'j'){
			cout << "Opção inválida! Por gentileza, insira uma opção válida." << endl;
		}
	} while(tipo != 'R' && tipo != 'r' && tipo != 'J' && tipo != 'j');
	
	acervo->setTipo(tipo);
	cin.clear();
	fflush(stdin);
	
	//Solicitando o número de páginas:
	cout << "Digite o número de páginas do períodico: ";
	int numeroPaginas;
	cin >> numeroPaginas;
	acervo->setNumeroPaginas(numeroPaginas);
	cin.clear();
	fflush(stdin);
}

//Método específico para adicionar TCC:
void adicionaTrabalhoDeConclusao(TrabalhosConclusao *acervo,int numItem)
{
	adicionaItem(acervo,numItem);
	char tipo;
	
	//Selecionando qual é a categoria do TCC:
	do
	{
		cout << "Digite o tipo do trabalho de conclusão [M: Monografia | D: Dissertação | T: Tese]: ";
		cin >> tipo;
		
		if(tipo != 'M' && tipo != 'm' && tipo != 'D' && tipo != 'd' && tipo != 'T' && tipo != 't')
		{
			cout << "Opção innválida! Por gentileza, insira uma opção válida." << endl;
		}
		
	} while(tipo != 'M' && tipo != 'm' && tipo != 'D' && tipo != 'd' && tipo != 'T' && tipo != 't');
	
	acervo->setTipo(tipo);
	cin.clear();
	fflush(stdin);
	
	//Solicitando o número de páginas:
	cout << "Digite o número de páginas do trabalho de conclusão: ";
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
	
	//Solicitando qual é a categoria de mídia:
	do
	{
		cout << "Digite o tipo do trabalho de mídia [V: Fita VHS | C: CD | D: DVD]: ";
		cin >> tipo;
		if(tipo != 'C' && tipo != 'c' && tipo != 'D' && tipo != 'd' && tipo != 'V' && tipo != 'v')
		{
			cout << "Opção inválida! Por gentileza, insira uma opção válida." << endl;
		}
		
	}while(tipo != 'C' && tipo != 'c' && tipo != 'D' && tipo != 'd' && tipo != 'V' && tipo != 'v');
	
	acervo->setTipo(tipo);
	cin.clear();
	fflush(stdin);
	
	//Solicitand o tempo de duração:
	cout << "Digite o tempo de duração da mídia: ";
	string tempoDuracao;
	getline(cin, tempoDuracao);
	acervo->setTempoDuracao(tempoDuracao);
	cin.clear();
	fflush(stdin);
}

/*               MÉTODO PARA REALIZAR BUSCA PELO CDU                */
int localizaCDU(vector<Acervo *> &listAcervo,int *contItem)
{
	int encontrouItem = -1;
	
	//Solicitando o CDU:
	cout << "Digite o CDU do item: ";
	string buscaCDU = "";
	getline(cin, buscaCDU);
	cin.clear();
	fflush(stdin);
	
	//Percorrendo o acervo e validando se o CDU informado já foi cadastrado:
	for(int i=0;i<*contItem;i++)
	{
		if(listAcervo[i]->getCDU() == buscaCDU)
		{
			encontrouItem = i;
		}
	}
	
	return encontrouItem;
}

/*               MÉTODO PARA REALIZAR BUSCA PELO CPF                */
int localizaLeitor(vector<Leitor *> &listLeitor,int *contLeitor)
{
	int encontrouLeitor = -1;
	
	//Solictando o CPF do leitor:
	cout << "Digite o CPF do leitor: ";
	string buscaCPF = "";
	getline(cin, buscaCPF);
	cin.clear();
	fflush(stdin);
	
	//Percorrendo o cadastrado de leitores e validando se o leitor informado já foi cadastrado:
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

/*             MÉTODO PARA ALTERAR DADOS DE UM LEITOR               */
void alteraLeitor(vector<Leitor *> &listLeitor, int numLeitor)
{
	system("cls");
	int opcao = 0;
	Leitor *alteraLeitor = listLeitor[numLeitor];
	
	//Solicitando qual dado será atualizado:
	do
	{
		cout << "Insira a opção desejada: ";
		cout << "1. Alterar nome."<< endl;
		cout << "2. Alterar CPF." << endl;
		cin >> opcao;
		cin.clear();
		fflush(stdin);
		
		if(opcao < 1 || opcao > 2)
		{
			cout << "Opção inválida! Por gentileza, insira uma opção válida." << endl << endl;
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
		cout << "Opção inválida, tente novamente." << endl;
	}
}

/*               MÉTODO PARA CADASTRAR UM LEITOR                    */
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

/*               MÉTODO PARA REALIZAR UM EMPRÉSTIMO                 */
void realizarEmprestimo(Emprestimo *emprestimo, int numEmprestimo,vector<Leitor *> &listLeitor,int contLeitor,vector<Acervo *> &listAcervo,int contItem)
{
	cout << "------------------------------------" << endl;
	cout << "      Cadastro de Empréstimos       " << endl;
	cout << "------------------------------------" << endl<< endl;
	
	int tamanho = 0;
	string dataEmprestimo = "", dataLimiteDevolucao = "", diaEmprestimo = "", mesEmprestimo = "", anoEmprestimo = "", diaLimite = "", mesLimite = "", anoLimite = "";
	
	//Cadastrando a data do empréstimo e validando se está dentro dos parâmetros solicitados:
	do
	{
		cout << "Digite a data do empréstimo (dd/mm/aaaa): ";
		getline(cin, dataEmprestimo);
		
		tamanho = dataEmprestimo.length();
		
		if(tamanho != 10)
		{
			cout << "A data deve ser inserida no formato dd/mm/aaaa. Por gentileza, insira a data no formato correto." << endl;
		}
		
	} while(tamanho != 10);
	
	//Se sim, seta a data do empréstimo informada pelo usuário:
	emprestimo->setDataEmprestimo(dataEmprestimo);
	cin.clear();
	fflush(stdin);
	
	//Solicitando a data limite para devolução e validando se está dentro dos parâmetros solicitados:
	do
	{
		tamanho = 0;
		cout << "Digite a data limite para devolução (dd/mm/aaaa): ";
		getline(cin, dataLimiteDevolucao);
		
		tamanho = dataLimiteDevolucao.length();
		
		if(tamanho != 10)
		{
			cout << "A data deve ser inserida no formato dd/mm/aaaa. Por gentileza, insira a data no formato correto." << endl;
		}
		
		//Realiza a validação das datas:
		diaEmprestimo	= dataEmprestimo.substr(0,2);
		diaLimite 		= dataLimiteDevolucao.substr(0,2); 
		mesEmprestimo 	= dataEmprestimo.substr(3,2);
		mesLimite 		= dataLimiteDevolucao.substr(3,2);
		anoEmprestimo 	= dataEmprestimo.substr(6,4);
		anoLimite 		= dataLimiteDevolucao.substr(6,4);
		
		if((anoEmprestimo>anoLimite) || (anoEmprestimo == anoLimite && mesEmprestimo>mesLimite) || (anoEmprestimo == anoLimite && mesEmprestimo == mesLimite && diaEmprestimo>diaLimite))
		{
			cout << "A data limite não pode ser inferior à data do empréstimo. Por gentileza, insira a data limite corretamente." << endl;
		}
		
	} while(tamanho != 10 || (anoEmprestimo>anoLimite) || (anoEmprestimo == anoLimite && mesEmprestimo>mesLimite) || (anoEmprestimo == anoLimite && mesEmprestimo == mesLimite && diaEmprestimo>diaLimite));

	//Se a data de devolução não for inferior à do emprestimo e passar pelas outras validações, ela é salva. 
	emprestimo->setDataLimiteDevolucao(dataLimiteDevolucao);
	cin.clear();
	fflush(stdin);
	
	//Setando o leitor que solicitou o empréstimo e o acervo, com a data de devolução:
	emprestimo->setLeitor(listLeitor[contLeitor]);
	emprestimo->setAcervo(listAcervo[contItem]);
	emprestimo->setDataDevolucao("");
}

/*               MÉTODO PARA REALIZAR UMA DEVOLUÇÃO                 */
void realizarDevolucao(Emprestimo *emprestimo, int numDevolucao)
{
	cout << "------------------------------------" << endl;
	cout << "         Realizar devolução         " << endl;
	cout << "------------------------------------" << endl << endl;
	
	int tamanho = 0;
	string dataDevolucao = "", dataEmprestimo = "", diaEmprestimo = "", mesEmprestimo = "", anoEmprestimo = "", diaDevolucao = "", mesDevolucao = "", anoDevolucao = "";
	
	do
	{
		//Solicitando a data de devolução:
		cout << "Digite a data da devolução (dd/mm/aaaa): ";
		getline(cin, dataDevolucao);
		
		tamanho = dataDevolucao.length();
		
		//Validando se a data foi informada no parâmetro correto:
		if(tamanho != 10)
		{
			cout << "A data deve ser inserida no formato dd/mm/aaaa. Por gentileza, insira a data no formato correto." << endl;
		}
		
		//Faz a validação das datas:
		dataEmprestimo 	= emprestimo->getDataEmprestimo();
		diaEmprestimo 	= dataEmprestimo.substr(0,2);
		diaDevolucao 	= dataDevolucao.substr(0,2); 
		mesEmprestimo 	= dataEmprestimo.substr(3,2);
		mesDevolucao 	= dataDevolucao.substr(3,2);
		anoEmprestimo 	= dataEmprestimo.substr(6,4);
		anoDevolucao 	= dataDevolucao.substr(6,4);
		
		if((anoEmprestimo>anoDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo>mesDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo == mesDevolucao && diaEmprestimo>diaDevolucao)) 
		{
			cout << "A data limite não pode ser inferior à data do empréstimo. Por gentileza, insira a data limite corretamente." << endl;
		}
		
	} while(tamanho != 10 || (anoEmprestimo>anoDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo>mesDevolucao) || (anoEmprestimo == anoDevolucao && mesEmprestimo == mesDevolucao && diaEmprestimo>diaDevolucao));
	
	//Se passar pelos parâmetros, é salva a devolução.
	emprestimo->setDataDevolucao(dataDevolucao);
	cin.clear();
	fflush(stdin);
}

/*                        FUNÇÃO PRINCIPAL                         */
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
	
	//Mensagem inicial para o usuário:
	cout << "                                   ATENÇÃO! \n\
Para utilização deste programa é necessário entrar com login e senha. Você pode utilizar\n\
o usuário criado pelo Eric (disponibilizado no ReadME) ou criar o seu. Por questão de \n\
economia de código, o usuário dele é fixo e o que você está criando é sempre substituível.\n\
Ou seja, quando você cria um novo usuário substitui a posição [1] do array armazenaLogin \n\
e armazenaSenha." << endl << endl;
	system("pause");
	system("cls");
	
	//Validação do login e senha:	
	do 
	{
		inicio:
			
		cout << "----------------------------------------------------" << endl;
		cout << "Seja bem-vindo (a) à nossa Biblioteca Universitária!" << endl;
		cout << "----------------------------------------------------" << endl << endl;
		cout << "Escolha uma opção: " << endl << endl;
		cout << "1. Acessar o sistema." << endl;
		cout << "2. Criar novo cadastro." << endl;
		cout << "3. Sair." << endl;
		cin >> i;
		cin.clear();
		fflush(stdin);
		
		if (i < 1 || i > 3) 
		{
			cout << "Opção inválida, tente novamente." << endl;
			system("pause");
			system("cls");
		}
	} while (i < 1 || i > 3);
	
	//Entrando com o usuário, criando novo usuário ou saindo do sistema:
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
				
				cout << "Usuário cadastrado, faça login novamente." << endl << endl;
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
	
	
	//Após fazer o login, começamos o nosso programa criando a tela inicial:
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
			
/*                          SERVIÇOS OFERECIDOS PELA BIBLIOTECA                          */
			cout << "-------------------------------------------" << endl;
			cout << "Biblioteca Universitária - UEMG Divinópolis" << endl;
			cout << "-------------------------------------------" << endl << endl;
			cout << "Olá, " << nome << ". Escolha uma opção:" << endl << endl;
			cout << "1. Acervo." << endl;
			cout << "2. Cadastros." << endl;
			cout << "3. Empréstimos." << endl;
			cout << "4. Inventário da biblioteca." << endl;
			cout << "5. Sair." << endl;
			cin >> op;
			cin.clear();
			fflush(stdin);
			
			if (op < 1 || op > 5) 
			{
				cout << "Opção inválida, tente novamente." << endl;
				system("pause");
				system("cls");
			}
			
		} while (op < 1 || op > 13);
		
		if (op != 5) 
		{
			system("cls");
			
			switch (op)
			{
				
/*                            TELA DE ACERVO E SUAS OPÇÕES                            */
				case 1:
					do 
					{
						cout << "Bem vindo (a) ao acervo! " << nome << ", escolha uma opção:" << endl << endl;
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
							cout << "Opção inválida, tente novamente." << endl;
							system("pause");
							system("cls");
						}
						
					} while (op < 1 || op > 3);
					
					
					if (op != 4)
					{
						system("cls");
						
						switch(op)
						{
							//Dentro da tela de inserção, ele pode incluir os seguintes itens:
							case 1:
								novoInicio:
						
								cout << nome << ", o que você deseja cadastrar?" << endl << endl;
								cout << "1. Livro." << endl;
								cout << "2. Relatório." << endl;
								cout << "3. Cartaz." << endl;
								cout << "4. Mapa." << endl;
								cout << "5. Periódico." << endl;
								cout << "6. TCC." << endl;
								cout << "7. Mídia." << endl;
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
									cout << "Opção inválida, tente novamente." << endl;
									system("pause");
									system("cls");
									goto novoInicio;
								}
								
								system("pause");
								system("cls");
							break;
							
							//Se ele desejar, também pode excluí-los:
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
										cout << "CDU não encontrado." << endl;
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
							
							//Ainda, há a possibilidade de pesquisar sobre a existência de um item pré-cadastrado:
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
										cout << "Item não encontrado!" << endl;
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
				
/*                            TELA DE CADASTRO E SUAS OPÇÕES                            */
				case 2:
					do 
					{
						cout << "Bem vindo (a) ao cadastro! " << nome << ", escolha uma opção:" << endl << endl;
						cout << "1. Cadastro de leitores." << endl;
						cout << "2. Alteração de dados." << endl;
						cout << "3. Visualização de leitores cadastrados." << endl;
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
							cout << "Opção inválida, tente novamente." << endl;
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
									cout << "Não há leitores cadastrados." << endl;
								}
								else
								{
									int encontrouLeitor = localizaLeitor(listLeitor,&contLeitor);
									
									if(encontrouLeitor < 0)
									{
										cout << "Não há nenhum leitor com esse CPF vinculado." << endl;
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
									cout << "Não há leitores cadastrados." << endl;
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


/*                            TELA DE EMPRÉSTIMOS E SUAS OPÇÕES                            */
				case 3:
					do 
					{
						cout << "Bem vindo (a) ao setor de empréstimos! " << nome << ", escolha uma opção:" << endl << endl;
						cout << "1. Solicitar empréstimo." << endl;
						cout << "2. Devolução de empréstimo." << endl;
						cout << "3. Empréstimos pendentes de devolução." << endl;
						cout << "4. Empréstimos já devolvidos." << endl;
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
							cout << "Opção inválida, tente novamente." << endl;
							system("pause");
							system("cls");
						}
						
					} while (op < 1 || op > 4);
					
					if (op != 5)
					{
						switch(op) 
						{
							//Solicitando empréstimo:
							case 1:
								if(listAcervo.empty())
								{
									cout << "Não existe nenhum item inserido no acervo." << endl;
								}
								else
								{
									int encontrouLeitor = localizaLeitor(listLeitor,&contLeitor);
									
									if(encontrouLeitor < 0)
									{
										cout << "Não há nenhum leitor com esse CPF vinculado! \nPor gentileza, realize o cadastro antes do empréstimo." << endl;
									}
									else
									{
										int encontrouItem = localizaCDU(listAcervo,&contItem);
										
										if(encontrouItem < 0)
										{
											cout << "Não há nenhum item com esse CDU cadastrado! \nPor gentileza, realize o cadastro antes do empréstimo." << endl;
										}
										else
										{
											acervo = listAcervo[encontrouItem];
											int quantidadeDisponivel = acervo->getQuantidadeDisponivel();
											
											if(quantidadeDisponivel <= 0)
											{
												cout << "Todos os exemplares desse livro estão emprestados." << endl;
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
							
							//Devolvendo empréstimo:
							case 2:
								if(listLeitor.empty())
								{
									cout << "Não há leitores cadastrados! \nPor gentileza, realize o cadastro antes de devolver o seu empréstimo." << endl;
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
										cout << "Não há leitor cadastrado vinculado a esse CPF! Por gentileza, realize o cadastro antes de devolver o seu empréstimo." << endl;
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
										cout << "Não há empréstimo em aberto para esse leitor." << endl;
									}
									else
									{
										system("cls");
										cout << "--------------------------------------------" << endl;
										cout << "---------- Empréstimo encontrado! ----------" << endl;
										cout << "--------------------------------------------" << endl << endl;
										
										realizarDevolucao(listEmprestimo[encontrouEmprestimo],(encontrouEmprestimo + 1));
			
										for(int j=0;j<contItem;j++)
										{
											acervo = listAcervo[j];
											emprestimo = listEmprestimo[encontrouEmprestimo];
											if(acervo->getCDU() == emprestimo->getAcervo()->getCDU())
											{
												//Se o empréstimo tiver sido encontrado, aumenta um na quantidade de exemplares disponíveis
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
							
							//Empréstimos aguardando devolução:
							case 3:
								//Se houver pelo menos um empréstimo realizado, mostra os empréstimos pendentes de devolução.
								if(listEmprestimo.empty())
								{
									cout << "Não há empréstimos realizados." << endl;
								}
								else
								{
									system("cls");
									cout << "---- Empréstimos pendentes de devolução ----" << endl;
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
								
														
							//Visualizar empréstimos já devolvidos:
							case 4:
								//Se houver pelo menos um empréstimo realizado, mostra os empréstimos já devolvidos.
								if(listEmprestimo.empty())
								{
									cout << "Não há empréstimos realizados." << endl;
								}
								else
								{
									system("cls");
									cout << "--------- Empréstimos já devolvidos --------" << endl;
									
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
				
/*                            TELA DE INVENTÁRIO E SUAS OPÇÕES                            */
				case 4:
					do 
					{
						cout << "Bem vindo (a) ao inventário! " << nome << ", escolha uma opção:" << endl << endl;
						cout << "1. Visualizar ficha catalográfica." << endl;
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
							cout << "Opção inválida, tente novamente." << endl;
							system("pause");
							system("cls");
						}
						
					} while (op < 1 || op > 2);
					
					if (op != 3) 
					{
						switch (op)
						{
							//Visualizando ficha catalográfica:
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
										cout << "Item não encontrado!" << endl;
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
									cout << "Não existe nenhum item inserido no acervo." << endl;
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
