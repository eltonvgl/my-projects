//=============================================================================================================================================================
//===================================================== PROGRAMA MICKEY E DONALD - SISTEMA DRIVE-THRU ========================================================= 
//=============================================================================================================================================================
																																						
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <Windows.h>
#include <locale.h>
using namespace std;


FILE *PRODUTOS;
FILE *PAGAMENTOS;//PONTEIROS
FILE *CARTOES;
char palavra,continua = 's';
int opcao_pagamento,opcao_pedido,i;
float valor_pedido;
int m=254,p;
/////////////////////////////////////////////////////////////////////// STRUCTS ////////////////////////////////////////////////////////////////////////////////
struct PRODUTO
{
	int cod_prod;
	char nome_prod[45];
	float custo_prod;

}PROD[100];



typedef struct
{
	char forma_pagamento[30];
	int cod_pagamento;
	float valor_total;
}PAGAMENTO;

PAGAMENTO REGISTRAR[5];

typedef struct
{
	int cod_pgto;
	char num_cartao[16];
}CARTAO;


CARTAO MASCARAR[5];
////////////////////////////////////////////////////////////////////// FACA SEU PEDIDO /////////////////////////////////////////////////////////////////////////
void FacaSeuPedido(char Lista_Produtos[],char Tipo_Leitura[])//FUNCAO
{
	
	for(p=1;p<50;p++)
	printf("%c",m);
	cout <<"\n\n";
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, FOREGROUND_GREEN|FOREGROUND_RED);
	SetConsoleTextAttribute(h, 2);
	cout << "===== DRIVE THRU";
	SetConsoleTextAttribute(h, 3);//COLOCA COR NO TEXTO
	cout<<" MICKEY & DONALD ======\n";
	SetConsoleTextAttribute(h, 7);
	for(p=1;p<50;p++)
	printf("%c",m);
	cout <<"\n\n";
	int qtd;
		
		PRODUTOS = fopen(Lista_Produtos,Tipo_Leitura); //LEITURA DO ARQUIVO PRODUTOS.DAT

		if(PRODUTOS==NULL)//VERIFICA SE O ARQUIVO EH VALIDO
		{
			cout << "Erro";
		}

		else
		{
			
				fread(PROD,sizeof(struct PRODUTO),100,PRODUTOS);
					
					for(i=1;i<100&&PROD[i].cod_prod!=0;i++)//LEITURA DO ARQUIVO
					{
						printf("%i ",PROD[i].cod_prod);
						printf(" %s ",PROD[i].nome_prod);
						printf("%.2f\n",PROD[i].custo_prod);
					}
		}
			
			cout <<"\nEscolha um lanche: \n";
			cin >> opcao_pedido;// PROD[0].cod_prod;
			//cout << "Lanche escolhido: N"<< opcao_pedido<<"\n";
			while(PROD[opcao_pedido].cod_prod == 00 ||PROD[opcao_pedido].cod_prod == 0)// CRITERIO PARA DECIDIR SE A ESCOLHA E VALIDA
			{
				cout << "Escolha um lanche válido!!\n\n";
				FacaSeuPedido(Lista_Produtos,Tipo_Leitura);//("PRODUTOS.DAT","rb");
			}

			cout << "\nDigite a quantidade: \n";
			cin >> qtd;

			
			cout <<"\nCódigo: "<< PROD[opcao_pedido].cod_prod <<"\n"<<"Lanche: "<< PROD[opcao_pedido].nome_prod << "\nValor: R$"<< PROD[opcao_pedido].custo_prod;
			cout <<"\nQuantidade: "<<qtd <<" unid(s)"<<"\nValor Total: R$"<< PROD[opcao_pedido].custo_prod*qtd<<"\n";
			valor_pedido = PROD[opcao_pedido].custo_prod*qtd;//PROCESSAMENTO DO PEDIDO
			
						
			printf("\nConfirmar escolha? (s/n)...:\n");//CONFIRMAR PEDIDO
			fflush(stdin);
			continua = getch();
			while (continua == 'n' || continua == 'N' )
			{
			system("cls");
			FacaSeuPedido(Lista_Produtos,Tipo_Leitura);//("PRODUTOS.DAT","rb");
			}
}

///////////////////////////////////////////////////////////////////// PAGUE //////////////////////////////////////////////////////////////////////////////////
void Pague(char Nome_Arquivo[], char Nome_Arquivo2[], char Tipo_Adicionar[],char Tipo_Adicionar2[])//FUNCAO PAGUE
{
	char num_cartao[16],temp;
	int i;

	do
	{
		cout << "\nEscolha a forma de pagamento: \n" << "\n1-Dinheiro" <<"\n2-Débito" <<"\n3-Crédito" << "\n4-Cheque\n\n";//OPCOES DE PAGAMENTO
		cin >> opcao_pagamento;


		switch(opcao_pagamento)
			{
				case 1:
						strcpy(REGISTRAR[opcao_pagamento].forma_pagamento,"Dinheiro");
						//MASCARAR[opcao_pagamento].cod_pgto=opcao_pagamento;
						cout << "Opção selecionada: "<<REGISTRAR[opcao_pagamento].forma_pagamento<<"\n";//ARMAZENA VALORES NA STRUCT
						REGISTRAR[opcao_pagamento].valor_total=valor_pedido;
						sleep(4);
						cout << "\nDeseja continuar? <s/n>...:\n";
						fflush(stdin);
				 		continua = getch();
						while(continua == 's'||continua=='S')
						{
							cout << "\nPagamento realizado com sucesso!\n";
							continua = 'a';
						}
						break;
				case 2:
						strcpy(REGISTRAR[opcao_pagamento].forma_pagamento,"Débito");
						MASCARAR[opcao_pagamento].cod_pgto=opcao_pagamento;
						cout << "Opção selecionada: " <<REGISTRAR[opcao_pagamento].forma_pagamento<<"\n";
						REGISTRAR[opcao_pagamento].valor_total=valor_pedido;
						sleep(4);
						
						cout << "Digite o numero do seu cartão...: ";
						fflush(stdin);

						for(i=0;i<4;i++)//MASCARA O NUMERO DO CARTAO
						{
							temp = getche();
							(MASCARAR[opcao_pagamento].num_cartao[i]=temp);
						}cout<<".";
						for(i=4;i<12;i++)
						{
							temp = getche();
							strcpy(&MASCARAR[opcao_pagamento].num_cartao[i],"*");
							if(i==7)
							cout<<".";
						}cout<<".";
						for(i=12;i<16;i++)
						{
							temp = getche();
							MASCARAR[opcao_pagamento].num_cartao[i]=temp;
						}
						cout << "\nDeseja continuar? <s/n>...:\n";
						fflush(stdin);
				 		continua = getch();
						fflush(stdin);
						
						while(continua == 's'||continua=='S')
						{
							cout << "\nPagamento realizado com sucesso!\n";
							continua = 'a';
						}
						//cout <<"\nTEXTO A SER GRAVADO: " <<MASCARAR[opcao_pagamento].num_cartao;

						//cin>> (MASCARAR[opcao_pagamento].num_cartao);

						break;
				case 3: strcpy(REGISTRAR[opcao_pagamento].forma_pagamento,"Crédito");
						MASCARAR[opcao_pagamento].cod_pgto=opcao_pagamento;
						cout << "Opção selecionada: "<<REGISTRAR[opcao_pagamento].forma_pagamento<<"\n";
						REGISTRAR[opcao_pagamento].valor_total=valor_pedido;
						sleep(4);
						
						cout << "Digite o numeros do seu cartão...: ";
						fflush(stdin);
						for(i=0;i<4;i++)
						{
							temp = getche();
							(MASCARAR[opcao_pagamento].num_cartao[i]=temp);
						}cout<<".";
						for(i=4;i<12;i++)
						{
							temp = getche();
							strcpy(&MASCARAR[opcao_pagamento].num_cartao[i],"*");
							if(i==7)
							cout<<".";
						}cout<<".";
						for(i=12;i<16;i++)
						{
							temp = getche();
							MASCARAR[opcao_pagamento].num_cartao[i]=temp;
						}
						cout << "\nDeseja continuar? <s/n>...:\n";
						fflush(stdin);
				 		continua = getch();
						fflush(stdin);
						
						while(continua == 's'||continua=='S')
						{
							cout << "\nPagamento realizado com sucesso!\n";
							continua = 'b';
						}
						break;
						//cout <<"\nTEXTO A SER GRAVADO: " <<MASCARAR[opcao_pagamento].num_cartao;
						//cin>> MASCARAR[opcao_pagamento].num_cartao;

						
				case 4: strcpy(REGISTRAR[opcao_pagamento].forma_pagamento,"Cheque");
						//MASCARAR[opcao_pagamento].cod_pgto=opcao_pagamento;
						cout << "Opção selecionada: "<< REGISTRAR[opcao_pagamento].forma_pagamento<<"\n";
						REGISTRAR[opcao_pagamento].valor_total=valor_pedido;
						sleep(4);
						cout << "\nDeseja continuar? <s/n>...:\n";
						fflush(stdin);
				 		continua = getch();
						while(continua == 's'||continua=='S')
						{
							cout << "\nPagamento realizado com sucesso!\n";
							continua = 'a';
						}
						break;
				default: 
						 cout << "Escolha uma forma de pagamento válida!\n";
						 Pague(Nome_Arquivo,Nome_Arquivo2,Tipo_Adicionar,Tipo_Adicionar2);//("PAGAMENTOS.DAT","CARTOES.DAT", "a+", "a+")//RECURSAO;
						break;
			}
	}while(continua == 'n'||continua == 'N');
	
	
	if(opcao_pagamento == 1)
	{
		PAGAMENTOS = fopen(Nome_Arquivo, Tipo_Adicionar);  //GRAVAR DADOS EM PAGAMENTOS.DAT
		fprintf(PAGAMENTOS, " %i |", REGISTRAR[opcao_pagamento].cod_pagamento=opcao_pagamento);
		fprintf(PAGAMENTOS, " %s |", REGISTRAR[opcao_pagamento].forma_pagamento);
		fprintf(PAGAMENTOS, "R$ %.2f \n", REGISTRAR[opcao_pagamento].valor_total=valor_pedido);
		fclose(PAGAMENTOS);
	}
	if(opcao_pagamento == 2)
	{
		PAGAMENTOS = fopen(Nome_Arquivo, Tipo_Adicionar);  //GRAVAR DADOS EM PAGAMENTOS.DAT
		fprintf(PAGAMENTOS, " %i |", REGISTRAR[opcao_pagamento].cod_pagamento=opcao_pagamento);
		fprintf(PAGAMENTOS, " %s   |", REGISTRAR[opcao_pagamento].forma_pagamento);
		fprintf(PAGAMENTOS, "R$ %.2f \n", REGISTRAR[opcao_pagamento].valor_total=valor_pedido);
		fclose(PAGAMENTOS);

		CARTOES = fopen(Nome_Arquivo2, Tipo_Adicionar2);//	GRAVAR DADOS EM CARTOES.DAT
		fprintf(CARTOES, " %i |", MASCARAR[opcao_pagamento].cod_pgto=opcao_pagamento);
		fprintf(CARTOES, " %s \n", MASCARAR[opcao_pagamento].num_cartao);
		fclose(CARTOES);
	}
	if(opcao_pagamento == 3)
	{
		PAGAMENTOS = fopen(Nome_Arquivo, Tipo_Adicionar);  //GRAVAR DADOS EM PAGAMENTOS.DAT
		fprintf(PAGAMENTOS, " %i |", REGISTRAR[opcao_pagamento].cod_pagamento=opcao_pagamento);
		fprintf(PAGAMENTOS, " %s  |", REGISTRAR[opcao_pagamento].forma_pagamento);
		fprintf(PAGAMENTOS, "R$ %.2f \n", REGISTRAR[opcao_pagamento].valor_total=valor_pedido);
		fclose(PAGAMENTOS);

		CARTOES = fopen(Nome_Arquivo2, Tipo_Adicionar2);//	GRAVAR DADOS EM CARTOES.DAT
		fprintf(CARTOES, " %i |", MASCARAR[opcao_pagamento].cod_pgto=opcao_pagamento);
		fprintf(CARTOES, " %s \n", MASCARAR[opcao_pagamento].num_cartao);
		fclose(CARTOES);

	}
	if(opcao_pagamento == 4)
	{
		PAGAMENTOS = fopen(Nome_Arquivo, Tipo_Adicionar);  //GRAVAR DADOS EM PAGAMENTOS.DAT
		fprintf(PAGAMENTOS, " %i |", REGISTRAR[opcao_pagamento].cod_pagamento=opcao_pagamento);
		fprintf(PAGAMENTOS, " %s   |", REGISTRAR[opcao_pagamento].forma_pagamento);
		fprintf(PAGAMENTOS, "R$ %.2f \n", REGISTRAR[opcao_pagamento].valor_total=valor_pedido);
		fclose(PAGAMENTOS);
	}
	
}
//////////////////////////////////////////////////////////////////////// FILA //////////////////////////////////////////////////////////////////////////////////
void Fila(void)
{
	int flag=0;

	while(opcao_pedido == 1 && flag==0|| opcao_pedido == 2 && flag==0 || opcao_pedido == 3 && flag==0 || opcao_pedido == 4 && flag==0)
	{
		cout << "\n\033" << " Carro do pedido número " << opcao_pedido << " vai para a espera.\n\n"; //CARRO SOMENTE VAI PARA ESPERA SE O LANCHE PEDIDO FOR O NUMERO 1
		sleep(4); // TEMPO DE ESPERA ATE O LANCHE ESTAR PRONTO
		cout <<"\033\033" <<" Carro da espera aguardando o pedido...\n\n";
		sleep(4);
		cout <<"\033\033\033" << " Pedido entregue!\n\n";
		sleep(4);
		flag=1;
	}
	if(flag == 1)
	{
		cout <<"\033\033\033\033" << " Carro da espera liberado.\n"; //APOS O TEMPO DE ESPERA TER TERMINADO O CARRO E LIBERADO
		sleep(4);
		cout << "\n\033\033\033\033"<< " Nenhum carro na espera.\n\n";
	}
	else
	cout << "\n\033\033"<< "Nenhum carro na espera\n\n"; //SE O LANCHE ESCOLHIDO FOR O NUMERO 2 OU 3 O CARRO NAO VAI PARA A ESPERA


}
////////////////////////////////////////////////////////////////////// LEVE ///////////////////////////////////////////////////////////////////////////////
void Leve(void)

{
	//GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    //saved_attributes = consoleInfo.wAttributes;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(opcao_pagamento==1)
	{
	cout <<"\nPedido pago com ";
	
	SetConsoleTextAttribute(h, FOREGROUND_GREEN);
	cout<<(REGISTRAR[opcao_pagamento].forma_pagamento)<<endl;
	SetConsoleTextAttribute(h, 7);
	cout << "\n";
	}

	if(opcao_pagamento == 2 || opcao_pagamento == 3)
	{
	cout <<"\nPedido pago com ";
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED|FOREGROUND_BLUE);
	cout <<(REGISTRAR[opcao_pagamento].forma_pagamento)<<endl;
	SetConsoleTextAttribute(h, 7);
	cout << "\n";
	}
	if(opcao_pagamento == 4)
	{
	cout <<"\nPedido pago com ";
	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	cout<<(REGISTRAR[opcao_pagamento].forma_pagamento)<<endl;
	SetConsoleTextAttribute(h, 7);
	}
	SetConsoleTextAttribute(h, 48);
	cout << "\nObrigado por escolher o Mickey&Donald!\n\n"; 
	SetConsoleTextAttribute(h, 7);
	m=35;
	for(p=1;p<50;p++)
	printf("%c",m);
	cout <<"\n";
	
	//SetConsoleTextAttribute(hConsole, saved_attributes);

//verde = dinheiro
//azul = cheque
//lilas = debito/credito
}
/////////////////////////////////////////////////////////////////////// CADASTRO ///////////////////////////////////////////////////////////////////////////////

void Cadastro(char cadastro[],char Tipo_cadastro[],char cadastro_add[],char Tipo_add[])
{
	
	int l=0,i=0,flag;
	PRODUTO PROD[100];
	cout<<"\nDeseja cadastrar um novo produto? <s/n>...:\n";
		fflush(stdin);
		continua = getch();
		while(continua == 'n'||continua =='N')
		{
			exit(0);
		}
		while(continua== 's'||continua=='S')
		{
			char senha[6] = {1,2,3,4,5,6};
			char usuario_acesso[6];
			cout <<"Digite a senha: ";
			fflush(stdin);
			while(i<6)
			{
				usuario_acesso[i]= getch();
				cout << "*";
				i = i + 1;
			}
			
			
			if(usuario_acesso[6] == senha[6])
			{
			cout << "\nAcesso permitido.\n"<<"\nEscolha uma opção de cadastro:\n";
				fflush(stdin);
				int opcao_cadastro;
				cout<< "\n1- Criar uma nova lista de produtos? (Isso apagará o conteúdo da lista atual)\n";
				cout<< "2- Adicionar um item a uma lista já existente?\n";
				cin >> opcao_cadastro;
				
				switch(opcao_cadastro)
				{
					case 1: 
						PRODUTOS = fopen(cadastro,Tipo_cadastro);//CADASTRA UMA NOVA LISTA DE PRODUTOS
						if(PRODUTOS==NULL)
						{
							cout << "Arquivo inválido";
						}
							
						cout << "Insira os produtos...\n";//, i+1;
						fread(PROD,sizeof(struct PRODUTO),100,PRODUTOS);
						for(i=1;i<100&&PROD[i].cod_prod!=0;i++)
						{
							cout << "\nInsira o código...: ";//, i+1;
							fflush(stdin);
							cin >> PROD[i].cod_prod;
							//cout <<"TESTE " << PROD[i].cod_prod;
							//scanf("%i",&PROD[i].cod_prod);
							cout << "\nInsira o nome do lanche...: ";//,i+1;
							fflush(stdin);
							gets(PROD[i].nome_prod);
							//cout <<"TESTE " << PROD[i].nome_prod;
							cout << "\nInsira o preço...: ";//,i+1;
							fflush(stdin);
							scanf("%f",&PROD[i].custo_prod);
							//cout <<"TESTE " << PROD[i].custo_prod;
							memset (&l, 0, sizeof (l) );
							l = l + i ;
							printf("Deseja cadastrar um novo produto? s/n...:\n ");
							fflush(stdin);
							continua = getch();
							while(continua == 'n'||continua =='N')
							{
								fwrite(PROD,sizeof(struct PRODUTO),l+1,PRODUTOS);
								cout << "\nInformações salvas com sucesso!\n";
								fclose(PRODUTOS);
								exit(0);
							}
						}
						fwrite(PROD,sizeof(struct PRODUTO),l+1,PRODUTOS);
						cout << "\nInformações salvas com sucesso!";
						fclose(PRODUTOS);
						break;
					
					case 2: //ADICIONA UM ITEM A UMA LISTA JA EXISTENTE
						
						//PRODUTO PROD[100];
						PRODUTOS = fopen(cadastro_add,Tipo_add);
						if(PRODUTOS==NULL)
						{
							cout << "Arquivo inválido";
						}
							
						cout << "Insira os produtos...\n";//, i+1;
						fread(PROD,sizeof(struct PRODUTO),100,PRODUTOS);
						
						for(i=1;i<100&&PROD[i].cod_prod!=0;i++)
						{
							int m=0;
							cout << "\nInsira o código...: ";//, i+1;
							fflush(stdin);
							memset (&i, 0, sizeof (i) );
							cin >> PROD[i].cod_prod;
							//cout <<"TESTE " << PROD[i].cod_prod;
							//scanf("%i",&PROD[i].cod_prod);
							cout << "\nInsira o nome do lanche...: ";//,i+1;
							fflush(stdin);
							gets(PROD[i].nome_prod);
							//cout <<"TESTE " << PROD[i].nome_prod;
							cout << "\nInsira o preço...: ";//,i+1;
							fflush(stdin);
							scanf("%f",&PROD[i].custo_prod);
							//cout <<"TESTE " << PROD[i].custo_prod;
							memset (&m, 0, sizeof (m) );
							//setbuf(stdin,0);
							m = m + i;
							printf("Deseja cadastrar um novo produto? s/n...:\n ");
							fflush(stdin);
							continua = getch();
							flag=0;
							while(continua=='s'&&flag==0||continua=='S'&&flag==0)
							{
								fwrite(PROD,sizeof(struct PRODUTO),m+1,PRODUTOS);
								flag=1;
							}
							while(continua == 'n'||continua =='N')
							{
								//
								//memset (&m, 0, sizeof (m) );
								fwrite(PROD,sizeof(struct PRODUTO),m+1,PRODUTOS);
								cout << "\nInformações salvas com sucesso!!!";
								fclose(PRODUTOS);
								exit(0);
							}
						}
						
						fwrite(PROD,sizeof(struct PRODUTO),m+1,PRODUTOS);
						cout << "\nInformações salvas com sucesso!";
						fclose(PRODUTOS);
						break;
						default: cout<< "Escolha uma opcao valida!";
								 Cadastro(cadastro,Tipo_cadastro,cadastro_add,Tipo_add);
						break;
				}
			}
			else
			{
				cout<< "Acesso negado.\n"<<"Tentar novamente? <s/n>...:\n";
				fflush(stdin);
				continua = getch();
				while(continua=='s'||continua=='S')
				//Cadastro("PRODUTOS.DAT","wb","PRODUTOS.DAT","ab");
				Cadastro(cadastro,Tipo_cadastro,cadastro_add,Tipo_add);
								
			}	
				
				
		}
				
			
}
///////////////////////////////////////////////////////////////////////////// PRINCIPAL //////////////////////////////////////////////////////////////////////
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	system("color 3");
	system ( "date /t" );
	system ("time /t");
	FacaSeuPedido("PRODUTOS.DAT","rb"); //PARAMETROS DA FUNCAO
	Pague("PAGAMENTOS.DAT","CARTOES.DAT", "a+", "a+");
	Fila();
	Leve();
	Cadastro("PRODUTOS.DAT","wb","PRODUTOS.DAT","ab");
	exit(0);
}

