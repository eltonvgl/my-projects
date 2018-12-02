//+++++++++++++++++++++++++++++++++++++++++++++++++++++TIMER PARA WINDOWS BY ELTON LUZ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <Windows.h>
#include <locale.h>
using namespace std;
int i,ascii=35;
int hora,minutos;
long int timer_hora,timer_minuto;

void soneca (void)
{
	
		
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		for(i=0;i<79;i++)
		printf("%c",ascii);
		SetConsoleTextAttribute(h, 7);
		cout<<"\n"<<"                   BEM-VINDO AO TIMER-SONECA POR: ELTON LUZ\n";
		SetConsoleTextAttribute(h, 7);
		for(i=0;i<79;i++)
		printf("%c",ascii);
		cout<<"\n\n";
		
		SetConsoleTextAttribute(h, 2);
		system("date /T");
		system ("time /T");
		SetConsoleTextAttribute(h, 2);
		cout <<"\n";
		
		char hora[2], minuto[2],temp[4];
		memset(&temp[i],0,sizeof(temp));
		cout<< "Digite a hora desejada: ";
		fflush(stdin);
		for(i=0;i<4;i++)
		{
			temp[i]=getche();
			if(i==0)
			hora[i]=temp[i];	
			if(i==1)
			hora[i]=temp[i];	
			if(i==1)
			cout << ":";	
			if(i==2)
			minuto[0]=temp[i];	
			if(i==3)
			minuto[1]=temp[i];	
			
		}
		int horas = atol(hora);//converte vetor para inteiro
		int minutos = atol(minuto);
		
		cout <<"\nHora selecionada: "<< horas<<":" << minutos;
		timer_hora=horas*3600;
		timer_minuto=minutos*60;
		cout <<"\n\nO seu computador será desligado dentro de: "<<horas<<" hora(s) e "<<minutos<<" minutos.";
		cout<<"\n\nObrigado por utilizar o TIMER-SONECA!";
		cout <<"\n\n\n\n\Para cancelar o desligamento basta fechar o programa.";
		sleep(timer_hora);
		sleep(timer_minuto);
		
		system("C:\\WINDOWS\\System32\\shutdown /s");
		

}


int main(void)
{
	setlocale(LC_ALL, "Portuguese");	
	soneca();
}



	
/*
void soneca(void)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);
	for(i=0;i<79;i++)
	printf("%c",ascii);
	SetConsoleTextAttribute(h, 7);
	cout<<"\n"<<"BEM-VINDO AO TIMER-SONECA POR: ELTON LUZ\n";
	SetConsoleTextAttribute(h, 7);
	for(i=0;i<79;i++)
	printf("%c",ascii);
	cout<<"\n\n";
	
	SetConsoleTextAttribute(h, 2);
	system("date /T");
	system ("time /T");
	SetConsoleTextAttribute(h, 2);
	cout <<"\n";
		
	/*cout<< "Como usar o timer:\n"<<"\n1-Digite a quantidade de horas desejada."<<"\n2-Digite a quantidade de minutos.";	
	cout<<"\n3-Mantenha o programa aberto.";
	cout << "\n\n\nDigite a hora...: ";
	fflush(stdin);
	cin>> hora;
	timer_hora = hora*3600;
	
	cout << "Digite os minutos...: ";
	fflush(stdin);
	cin>> minutos;
	timer_minuto = minutos*60;
	
	
	cout <<"O seu computador será desligado dentro de: "<<hora<<" hora(s) e "<<minutos<<" minutos.";
	cout<<"\n\nObrigado por utilizar o TIMER-SONECA!";
	sleep(timer_hora);
	sleep(timer_minuto);
	
	system("C:\\WINDOWS\\System32\\shutdown /s");
	
	
}*/





