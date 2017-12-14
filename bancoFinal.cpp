#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include<conio.h>

using namespace std;

typedef BOOL (*PlaySoundA_ptr) (char*, HMODULE, DWORD); 
PlaySoundA_ptr fn_PlaySound = 0;

struct cola{
	int dato;
	struct cola *sig;
};
struct columnas{
	int dato;
	struct columnas *sig_col;
};
struct filas{
	int dato;
	struct filas *sig_fila;
	struct columnas *columna;
};
struct matriz{
	int nf, nc;
	struct filas *fila;
};
matriz *crear(matriz *mat,int a);
void imprimir(matriz *mat,cola *cab,int fin,int a);
cola *generar_cliente(cola *cab,int co);
cola *atender(matriz *mat,cola *cab);
void consulta(matriz *mat);
void marco(int a,int b,int c);
void cajas(int x);
void timer(int a);
void musica();

void gotoxy(int x, int y){
	HANDLE pantalla;
	COORD posicion;
	pantalla= GetStdHandle (STD_OUTPUT_HANDLE);
	posicion.X= x;
	posicion.Y=y;
	SetConsoleCursorPosition (pantalla,posicion);
}

void timer(int a){
	int aux=0;
	gotoxy(aux+1,15);
	printf("|____________________________________________________________________________________________________|\n");
	gotoxy(aux+1,16);
	printf("                                                                                   |      TIEMPO     |\n");
	gotoxy(aux+1,17);
	printf("                                                                                   |        %a        \n");
	gotoxy(aux+1,18);
	printf("                                                                                   |_________________|\n");			
	
}

void titulo(int fin){
	SetConsoleTitle("Proyecto\n");
		
	cout<<"             ++++++++++++++++SISTEMA DE SIMULACION DE BANCOS++++++++++++++++  "<<endl;
	cout<<"             +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  "<<endl;
	cout<<"             ++++++++ ____      __               __       __  ++++++++++++++  "<<endl;
	cout<<"             ++++++++ | __| || ||  |__| || |: | |   |__| |__| ++++++++++++++  "<<endl;
	cout<<"             ++++++++ ||    || | _ |  | || | :| |__ |  | |  | ++++++++++++++  "<<endl;
	cout<<"             +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  "<<endl;
	cout<<"             ++++++++  +++++++++  +++++++++   +++++++++  +++++++++  ++++++++  "<<endl;
	cout<<"              +++++     +++++++    +++++++     +++++++    +++++++    ++++++   "<<endl;
	cout<<"                _______                                          _______      "<<endl;
	cout<<"                ||   ||    |__     |  |# #|  |_|  |....|  || - --||   ||      "<<endl;
	cout<<"                || | ||     |__[]|  |   |  |_|  |....|__|| -- -  || | ||      "<<endl;
	cout<<"                || | ||          |__  |# _________ ....          || | ||      "<<endl;
	cout<<"                || | ||           | | |_________|                || | ||      "<<endl;
	cout<<"                || | ||         |__  # ||     ||     __|         || | ||      "<<endl;
	cout<<"                || | ||              |_||     ||_|               || | ||      "<<endl;
	cout<<"                || | ||            _|__||_____||__|_|_           || | ||      "<<endl;
	cout<<"                || | ||           |___________________|          || | ||      "<<endl;
	cout<<"                 __|_________      _______________________|  _______|_____    "<<endl;
	cout<<"              _|_______|_________ |_______________________| ________________  "<<endl;
	cout<<"             |_______________________________________________________________|"<<endl;
	cout<<"             |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout<<"             ||||||||||||||||||||||NOS COMPLACE ATENDERLE ||||||||||||||||||||"<<endl;
	cout<<"             ||||||||||||SISTEMA DE SIMULACION DE COLA DE BANCO|||||||||||||||"<<endl;
	cout<<"             |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout<<"             |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout<<"             |||||||||          Creado por: Andres Guanoluisa         ||||||||"<<endl;
	cout<<"             |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

	musica();	
	if(fin!=0){
			system("cls");
			gotoxy(57,30);cout<<("Sayonara");
	}
} 
 
void inicio(int op){
 	if(op==0){		
         titulo(op); 
	 }else
	 titulo(op);
        system("pause");
    
}

void marco(int a,int b,int c){
	int aux=0;

		gotoxy(aux+1,1);
		printf(" ____________________________________________________________________________________________________\n");
		gotoxy(aux+1,2);
		printf("| _____________________________________________________________________     _____________________    |\n");
		gotoxy(aux+1,3);
		printf("||                                                                     |   |__CLIENTES EN COLA___|   |\n");
		gotoxy(aux+1,4);
		printf("|||                                                                   ||   |          %d             \n",a);
		gotoxy(aux+1,5);
		printf("|||                                                                   ||   |_____________________|   |\n");
		gotoxy(aux+1,6);
		printf("|||                                                                   ||    _____________________    |\n");
		gotoxy(aux+1,7);
		printf("|||                                                                   ||   |___SIGUIENTE TURNO___|   |\n");
		gotoxy(aux+1,8);
		printf("|||                                                                   ||   |          %d            \n",b);
		gotoxy(aux+1,9);
		printf("|||                                                                   ||   |_____________________|   |\n");
		gotoxy(aux+1,10);
		printf("|||                                                                   ||    _____________________    |\n");
		gotoxy(aux+1,11);
		printf("|||                                                                   ||   |___ULTIMA ATENCION___|   |\n");
		gotoxy(aux+1,12);
		printf("|||                                                                   ||   |          %d             \n",c);
		gotoxy(aux+1,13);
		printf("||                                                                    ||   |_____________________|   |\n");
		gotoxy(aux+1,14);
		printf("|______________________________________________________________________|                             |\n");
		gotoxy(aux+1,15);
		printf("|____________________________________________________________________________________________________|\n");
}

void cajas(int x){
	int y=2;
	int aux=4,a,aux1=17 ,aux2=30,aux3=43,aux4=57;
	char b,b1,b2,b3,b4;
    int i=254;  
    int as=207;
    b1=b2=b3=b4=b=i;
    switch(x){
		case 1:b1=b2=b3=b4=as;
			gotoxy(aux+1,6);
			break;
		case 2:b2=b3=b4=as;
			break;
		case 3:b3=b4=as;
			break;
		case 4:b4=as;
			break;
		default:
			b1=b2=b3=b4=b=i;
			break;
		}
			    
	for(a=0;a<y;a++){
		
		gotoxy(aux+1,3);
		printf(" _________ \n");
		gotoxy(aux+1,4);
		printf("| CAJA:1  |\n");
		gotoxy(aux+1,5);
		printf("|_________| \n");
		gotoxy(aux+1,6);
		printf("|_________|\n");
		gotoxy(aux+1,7);
		printf("|         |\n");
		gotoxy(aux+1,8);
		printf("|    %c    |\n",b);
		gotoxy(aux+1,9);
		printf("|         |\n");
		gotoxy(aux+1,10);
		printf("|_________|\n");
		gotoxy(aux+1,11);
		printf(" _________\n");
		gotoxy(aux+1,12);
		printf("|   |||   |\n");
		gotoxy(aux+1,13);
		printf("|||     |||\n");
		gotoxy(aux+1,14);
		printf("__________\n");
	}

	for(a=0;a<x;a++){
		
		gotoxy(aux1+1,3);
		printf(" _________ \n");
		gotoxy(aux1+1,4);
		printf("| CAJA:2  |\n");
		gotoxy(aux1+1,5);
		printf("|_________| \n");
		gotoxy(aux1+1,6);
		printf("|_________|\n");
		gotoxy(aux1+1,7);
		printf("|         |\n");
		gotoxy(aux1+1,8);
		printf("|    %c    |\n",b1);
		gotoxy(aux1+1,9);
		printf("|         |\n");
		gotoxy(aux1+1,10);
		printf("|_________|\n");
		gotoxy(aux1+1,11);
		printf(" _________\n");
		gotoxy(aux1+1,12);
		printf("|   |||   |\n");
		gotoxy(aux1+1,13);
		printf("|||     |||\n");
		gotoxy(aux1+1,14);
		printf("__________\n");
	}

	for(a=0;a<x;a++){
		
		gotoxy(aux2+1,3);
		printf(" _________ \n");
		gotoxy(aux2+1,4);
		printf("| CAJA:3  |\n");
 		gotoxy(aux2+1,5);
		printf("|_________| \n");
		gotoxy(aux2+1,6);
		printf("|_________|\n");
		gotoxy(aux2+1,7);
		printf("|         |\n");
		gotoxy(aux2+1,8);
		printf("|    %c    |\n",b2);
		gotoxy(aux2+1,9);
		printf("|         |\n");
		gotoxy(aux2+1,10);
		printf("|_________|\n");
		gotoxy(aux2+1,11);
		printf(" _________\n");
		gotoxy(aux2+1,12);
		printf("|   |||   |\n");
		gotoxy(aux2+1,13);
		printf("|||     |||\n");
		gotoxy(aux2+1,14);
		printf("__________\n");
	}

	for(a=0;a<x;a++){
		
		gotoxy(aux3+1,3);
		printf(" _________ \n");
		gotoxy(aux3+1,4);
		printf("| CAJA:4  |\n");
		gotoxy(aux3+1,5);
		printf("|_________| \n");
		gotoxy(aux3+1,6);
		printf("|_________|\n");
		gotoxy(aux3+1,7);
		printf("|         |\n");
		gotoxy(aux3+1,8);
		printf("|    %c    |\n",b3);
		gotoxy(aux3+1,9);
		printf("|         |\n");
		gotoxy(aux3+1,10);
		printf("|_________|\n");
		gotoxy(aux3+1,11);
		printf(" _________\n");
		gotoxy(aux3+1,12);
		printf("|   |||   |\n");
		gotoxy(aux3+1,13);
		printf("|||     |||\n");
		gotoxy(aux3+1,14);
		printf("__________\n");
	}

	for(a=0;a<x;a++){
		
		gotoxy(aux4+1,3);
		printf(" _________ \n");
		gotoxy(aux4+1,4);
		printf("| CAJA:5  |\n");
		gotoxy(aux4+1,5);
		printf("|_________|\n");
		gotoxy(aux4+1,6);
		printf("|_________|\n");
		gotoxy(aux4+1,7);
		printf("|         |\n");
		gotoxy(aux4+1,8);
		printf("|    %c    |\n",b4);
		gotoxy(aux4+1,9);
		printf("|         |\n");
		gotoxy(aux4+1,10);
		printf("|_________|\n");
		gotoxy(aux4+1,11);
		printf(" _________\n");
		gotoxy(aux4+1,12);
		printf("|   |||   |\n");
		gotoxy(aux4+1,13);
		printf("|||     |||\n");
		gotoxy(aux4+1,14);
		printf("__________\n");
	}

}

void musica(){
 HMODULE Lib = LoadLibrary("winmm.dll");
	  if (Lib)
	  {
	    fn_PlaySound =  (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
	    if (fn_PlaySound)
	    {
	      fn_PlaySound("pol.wav", NULL, SND_FILENAME | SND_ASYNC);
	    }
	    else
	    {
	      MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
	    }
	    getch();
	    getch();
	    FreeLibrary(Lib);
	  }
	  else
	  {
	    MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
	  }
}
main(){
	
	int fin=1,cli=1,a,num=0;
	char sNum[20];
	float ge;
	matriz *matriz; 
	cola *cab=NULL,*aux;
	//system("color f1");
	system("color 0c");Beep(400,400);
	system("color 0a");Beep(400,500);
	system("color 1f");Beep(900,500);
	system("color f1");
	
	inicio(0);
	do{
	cout<<"  \nNumero de cajas activas: ";
	cin>>a;
	itoa(a, sNum, 10);	
	num=atoi(sNum);
		if(a==1 || a==2 || a==3 || a==4 || a==5 ){
			matriz=crear(matriz,a);
		}	
		else{
			cout<<"\nIngreso Erroreno\n";
		}
				
	}while(num==0 || a<=0 || a>=6 );

	while(fin!=120){//timer
		system("cls");
		
		imprimir(matriz,cab,fin,a);
		consulta(matriz);
		cab=atender(matriz,cab);
		if(fin%2==0){
			cab=generar_cliente(cab,cli);
			cli++;
		}
		fin++;
		Sleep(1000);
	}
}

matriz *crear(matriz *mat,int a){
	int num=1,i;
	filas *fila=NULL,*aux2;
	mat=(matriz*)malloc(sizeof(matriz));
	mat->nf=a;//CONTROLA LAS CAJAS
	mat->nc=2;
	for( i=1;i<=mat->nf;i++){
		aux2=fila;
		fila=(filas*)malloc(sizeof(filas));
		fila->dato=num;
		fila->sig_fila=NULL;
		fila->columna=NULL;
		if(i==1){
		mat->fila=fila;
		}else{
			aux2->sig_fila=fila;
		}
		num++;
	}
	return mat;
}

cola *generar_cliente(cola *cab,int co){
	cola *nuevo,*ant,*aux;
	nuevo=(cola*)malloc(sizeof(cola));
		nuevo->dato=co;
		nuevo->sig=NULL;
		if(cab!=NULL){
			aux=cab;
			do{
				if(aux->sig==NULL){
						aux->sig=nuevo;	
						aux=aux->sig;
					}
					aux=aux->sig;
			}while(aux!=NULL);
		}else
		 {
		 	cab=nuevo;
		 }
	return cab;
}

void imprimir(matriz *mat,cola *cab,int fin,int a){
	cola *ax;
	filas *aux;
	columnas *aux2;
	aux=mat->fila;
	int numc=0,ulc,prc,contc=1;//controladores
	if(cab!=NULL){
		ax=cab;
		prc=ax->dato;
		while(ax!=NULL){
		ulc=ax->dato;
		ax=ax->sig;
		numc++;
		}
	}else{
		prc=0;
		ulc=0;
		numc=0;
	}
	printf("                                       Sistema de Simulacion de Bancos\n\n");
	
	marco(numc,prc,ulc);//marco del sistema
	//timer(fin);//contador
	cajas(a);
	while(aux!=NULL)
	{
		printf(" |                                                                                                    |\n",aux->dato);
		printf(" |CAJA:%d                                                                                              |\n",aux->dato);
		aux2=aux->columna;
		
		while(aux2!=NULL){
			if(contc==1){
				printf(" |CLIENTE: %d                                                                                          \n",aux2->dato);
				contc++;
			}
			else
			{
				printf(" |TIEMPO: %d s_______________________________________________________________________________________\n ",aux2->dato);
				printf("|____________________________________________________________________________________________________|\n",aux->dato);
				contc=1;
			}
			aux2=aux2->sig_col;
		}
		aux=aux->sig_fila;
		//printf("\n");
	}		
}

cola *atender(matriz *mat,cola *cab){
	cola *cli,*aux;
	filas *fil;
	columnas *nu,*nu2;
	int clie,cont=0,des=0;
	if(cab!=NULL){
		cli=cab;
		clie=cli->dato;
		cab=cli->sig;
		fil=mat->fila;
		while(cont!=mat->nf){
			if(fil->columna==NULL){
				nu=(columnas*)malloc(sizeof(columnas));
				nu->dato=clie;
				nu2=(columnas*)malloc(sizeof(columnas));
				nu2->dato=1+rand()%(20-1);
				nu2->sig_col=NULL;
				nu->sig_col=nu2;
				fil->columna=nu;
				cont=mat->nf-1;
				free(cli);
				des=1;
			}
			fil=fil->sig_fila;
			cont++;
		}
		if(des==0){
				cab=cli;
		}
	}
	return cab;
}

void consulta(matriz *mat){
	filas *fil;
	columnas *col,*eli;
	fil=mat->fila;
	while(fil!=NULL){
		if(fil->columna!=NULL){
			col=fil->columna;
			eli=col->sig_col;
			eli->dato--;
			if(eli->dato==0){
				free(col);
				free(eli);
				fil->columna=NULL;
			}
		}
		fil=fil->sig_fila;
	}	
}

