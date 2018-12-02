/*
 ======================================== ANOTACOES RAPIDAS POR ELTON LUZ =================================================================							
*/
//changes for the repo
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <Windows.h>
#include <locale.h>
using namespace std;
#define MAX 3

FILE *ANOTACOES;
char anotacoes, user_anotacoes[1000],linha[5]= "\n";
unsigned int i;

void Anotacoes(char Arquivo[],char Tipo_leitura[])
{
	cout <<"BEM-VINDO AO ANOTAÇÕES RÁPIDAS!\n";
	
	ANOTACOES = fopen(Arquivo,Tipo_leitura);
	
	cout<<"\nESCREVA AQUI AS SUAS ANOTAÇÕES!\n\n";
	fflush(stdin);
		for(i=0;i<4,294,967,295;i++)
	{
		cin >> user_anotacoes;
		ANOTACOES = fopen(Arquivo,Tipo_leitura);
		fprintf(ANOTACOES," %s ", user_anotacoes);
		fclose(ANOTACOES);
    }
}

int main(void)
{
	//SetWindow(50,20);
    system("mode 37,35");  
	setlocale(LC_ALL,"Portuguese");
	Anotacoes("anotacoes.txt","a");	
}

/*void SetWindow(int Width, int Height) 
{ 
    _COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
} 
*/
/*if(ANOTACOES!=NULL||ANOTACOES ==NULL)
	{
		while ((anotacoes = getc(ANOTACOES)) != EOF)
		    putchar(anotacoes);
	}*/
//fputs(anotacoes,ANOTACOES);
//scanf("%c",&anotacoes);
//fflush(stdin);
		//ANOTACOES = fopen(Arquivo,Tipo_leitura);
		//n = n + i;
