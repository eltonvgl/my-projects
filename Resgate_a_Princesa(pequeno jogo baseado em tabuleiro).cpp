#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <Windows.h>

using namespace std;
/////////////////////////////////////////////////////////// VARIAVEIS GLOBAIS ///////////////////////////////////////////////////////////////////////////////
int i,opcao[50];
int sangue = 100;
int inicio=0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

typedef struct
{
	char par [300];
	char par1[200];
	char par2[100];
}PARAGRAFO;

PARAGRAFO PAR[500];
/////////////////////////////////////////////////////////// INICIO /////////////////////////////////////////////////////////////////////////////////////////
void comeco(void)
{
		
	
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n					Bem-Vindo ao Resgate a Donzela!\n\n";
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n\n";
	cout<<"Pressione `Enter' para iniciar a sua jornada.\n";
	fflush(stdin);
	while (inicio != '\r' && inicio != '\n')
	inicio = getchar();
	system("cls"); 
	
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n					Resgate a Donzela!\n\n";
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n\n";
	
	SetConsoleTextAttribute(h,FOREGROUND_RED);
	printf("Sangue: %i\n\n",sangue);
	SetConsoleTextAttribute(h,3);
	
	strcpy(PAR[1].par,"Essa � a sua hist�ria, voc� � um cavaleiro que se apaixonou por uma dama...\nPor�m, um belo dia, sua amada foi raptada por um gigante terr�vel e levada para uma caverna. \nDecidido a resgatar a sua donzela, voc� deve escolher uma arma para aniquilar o gigante:");
	for(i=0;i<sizeof(PAR[1].par);i++)
	cout << PAR[1].par[i],Sleep(40/2);
   
	cout<<"\n1 - Espada\n";
    cout<<"2 - Faca\n";
    cout<<"3 - Arco e flecha\n";
    fflush(stdin);
	cin>>opcao[1];
	system("cls");
    
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n					Resgate a Donzela!\n\n";
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n\n";
	
	SetConsoleTextAttribute(h,FOREGROUND_RED);
	printf("Sangue: %i\n\n",sangue);
	SetConsoleTextAttribute(h,3);
    
    switch(opcao[1])
    	{
    		case 1 : strcpy(PAR[2].par2,"\n�tima escolha, a espada � forte e eficiente para atacar inimigos � curta dist�ncia.\n"); 
					for(i=0;i<sizeof(PAR[2].par2);i++)
         			cout << PAR[2].par2[i],Sleep(20);
    			break;
    		case 2: strcpy(PAR[3].par2, "\nExcelente, a faca lhe dar� mobilidade, o que � importante quando se precisa andar mais r�pido.\n");
					for(i=0;i<sizeof(PAR[3].par2);i++)
					cout<< PAR[3].par2[i],Sleep(20);
    			break;
    		case 3: strcpy(PAR[4].par2,"\n�timo! O arco e flecha � muito bom contra inimigos � longa dist�ncia!\n"); 
					for(i=0;i<sizeof(PAR[4].par2);i++)
					cout<< PAR[4].par2[i],Sleep(20);
    			break;
    		default: cout<<"Escolha uma arma valida!\n";
    				system("cls");
					comeco();
    			break;
		}
		fflush(stdin);
		strcpy(PAR[5].par2,"\nAgora voc� deve escolher um caminho a ser seguido:\n");
		for(i=0;i<sizeof(PAR[5].par2);i++)
		cout<< PAR[5].par2[i],Sleep(20);
		
		strcpy(PAR[6].par1,"\n1-Caminho que atravessa a Floresta dos Desesperados. Essa floresta � cheia de mortos-vivos. Para det�-los a melhor arma � a espada.\n");
		for(i=0;i<sizeof(PAR[6].par1);i++)
		cout<< PAR[6].par1[i],Sleep(20);
		
		strcpy(PAR[7].par1,"\n2-Caminho da Savana Leonina. � uma savana cheia de le�es, para atravess�-la � necess�rio muita velocidade.\n");
		for(i=0;i<sizeof(PAR[7].par1);i++)
		cout<< PAR[7].par1[i],Sleep(20);
		
		strcpy(PAR[8].par1,"\n3-Caminho atrav�s da Montanha dos Corvos. Os corvos s�o ferozes e s�o melhor abatidos com arco e flecha.\n");
		for(i=0;i<sizeof(PAR[8].par1);i++)
		cout<< PAR[8].par1[i],Sleep(20);
		cout<<"\n";
		fflush(stdin);
		cin>> opcao[2];
		system("cls");
		
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n					Resgate a Donzela!\n\n";
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n\n";
	
	SetConsoleTextAttribute(h,FOREGROUND_RED);
	printf("Sangue: %i\n\n",sangue);
	SetConsoleTextAttribute(h,3);
	
	strcpy(PAR[9].par2,"Muito bem! Voc� atravessou o caminho ileso!");
	strcpy(PAR[10].par1,"Muito bem! Voc� atravessou o caminho, por�m um pouco ferido, pois a sua arma n�o era a melhor para esse trajeto!");
	if(opcao[1]==opcao[2])
	{
		for(i=0;i<sizeof(PAR[9].par2);i++)
		cout<< PAR[9].par2[i],Sleep(40/2);
	}
	else
	{
		for(i=0;i<sizeof(PAR[10].par1);i++)
		cout<< PAR[10].par1[i],Sleep(40/2);
	}
	if(opcao[1]==opcao[2])
	sangue=sangue;
	else
	sangue= sangue-10;
	
	system("cls");
	
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n					Resgate a Donzela!\n\n";
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n\n";
	
	SetConsoleTextAttribute(h,FOREGROUND_RED);
	printf("Sangue: %i\n\n",sangue);
	SetConsoleTextAttribute(h,3);
	
	strcpy(PAR[11].par2,"Muito bem! Voc� chegou � caverna! Agora � hora de enfrentar o monstro que protege a entrada.");
	for(i=0;i<sizeof(PAR[11].par2);i++)
		cout<< PAR[11].par2[i],Sleep(20);
		
	strcpy(PAR[13].par2,"\nEscolha a forma de atacar o monstro:\n");
	for(i=0;i<sizeof(PAR[13].par2);i++)
		cout<< PAR[13].par2[i],Sleep(20);
		
	strcpy(PAR[14].par2,"\n1 - Ataque � cabe�a.");
	for(i=0;i<sizeof(PAR[14].par2);i++)
		cout<< PAR[14].par2[i],Sleep(20);
	
	strcpy(PAR[15].par2,"\n2 - Ataque ao peito.");
	for(i=0;i<sizeof(PAR[15].par2);i++)
		cout<< PAR[15].par2[i],Sleep(20);
	
	strcpy(PAR[15].par2,"\n3 - Ataque � nuca.\n");
	for(i=0;i<sizeof(PAR[15].par2);i++)
		cout<< PAR[15].par2[i],Sleep(20);
	cout<<"\n";
	fflush(stdin);
	cin>>opcao[3];
	system("cls");
    
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n					Resgate a Donzela!\n\n";
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n\n";
	
	SetConsoleTextAttribute(h,FOREGROUND_RED);
	printf("Sangue: %i\n\n",sangue);
	SetConsoleTextAttribute(h,3);
    
	switch(opcao[3])
    	{
    		case 1 : strcpy(PAR[16].par1,"\nAtaque certeiro, voc� matou o gigante e entrou ileso na caverna!\n"); 
					for(i=0;i<sizeof(PAR[16].par1);i++)
         			cout << PAR[16].par1[i],Sleep(20);
    			break;
    		case 2: strcpy(PAR[17].par1, "\nVoce matou o gigante e entrou na caverna, por�m um pouco ferido ap�s a luta.\n");
					for(i=0;i<sizeof(PAR[17].par1);i++)
					cout<< PAR[17].par1[i],Sleep(20);
    			break;
    		case 3: strcpy(PAR[18].par2,"\nAtaque certeiro! O monstro desmaiou mas n�o morreu.\n"); 
					for(i=0;i<sizeof(PAR[18].par2);i++)
					cout<< PAR[18].par2[i],Sleep(20);
    			break;
    		default: cout<<"Escolha uma arma v�lida!\n";
    				system("cls");
					comeco();
    			break;
		}
	
if(opcao[3]==2)
sangue=sangue-20;
else
{
}
	system("cls");
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n					Resgate a Donzela!\n\n";
	for(i=0;i<110;i++)
	printf("%c",1);
	cout<<"\n\n";
	
	SetConsoleTextAttribute(h,FOREGROUND_RED);
	printf("Sangue: %i\n\n",sangue);
	SetConsoleTextAttribute(h,3);
   
	strcpy(PAR[19].par2,"\nParabens! Voce resgatou a princesa!");
	for(i=0;i<sizeof(PAR[19].par2);i++)
		cout<< PAR[19].par2[i],Sleep(40/2);
	
	system("pause");
}	
void meio (void)
{

	
}
	
void fim(void)
{
	
}	
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTextAttribute(h,3);
	system("mode 110,90");
	comeco();
	meio();
	fim();	
}
