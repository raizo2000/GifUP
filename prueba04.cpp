#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"ubicaxy.h"
#define X 11
#define Y 60
struct NODO{
	char cedula[X];
	char nombre[Y];
	float sueldo;
	NODO *nodosig;
};

struct Vector{
	int pk;
	NODO *sig;
};

int BuscarPrimo(int num);
void CrearTabla(Vector vec[],int num);
void IngresarTablas(Vector vec1[],Vector vec2[],Vector vec3[],int Nprimo);
int CalcularClave1(char palabra[],int tamaniov);
int CalcularClave2(char palabra[],int tamaniov);
int CalcularClave3(char palabra[],int tamaniov);
void AsignarNodo(Vector vec[],int clave,char cedula[],char nombre[],float sueldo,int tamaniov);
void ImprimirVector(Vector vec1[],Vector vec2[],Vector vec3[], int Nump,int auxTabla);
void ImprimirMarco(int num);
void ImprimirTodo(Vector vec[],int inicio,int Nump);
void ImprimirOnlyData(Vector vec[],int inicio,int Nump);
void BuscarEnVector(Vector vec[],int clave,int Nprimo,char buscada[],int pos);
void ImprimirMarco2(int num);
void Buscar(Vector vec1[],Vector vec2[],Vector vec3[],int Nprimo);

int main(){
	int Nprimo,aux,aTabla;
	printf("NUMEROS A DISPERSAR: ");
	scanf("%d",&aux);
	Nprimo=BuscarPrimo(aux);
	Vector tabla1[Nprimo];
	Vector tabla2[Nprimo];
	Vector tabla3[Nprimo];
	CrearTabla(tabla1,Nprimo);
	CrearTabla(tabla2,Nprimo);
	CrearTabla(tabla3,Nprimo);
	
	
	for(int i=0;i<aux;i++){
		IngresarTablas(tabla1,tabla2,tabla3,Nprimo);
	}
	system("cls");
	ImprimirVector(tabla1,tabla2,tabla3,Nprimo,aTabla);
	printf("\n\n");
	Buscar(tabla1,tabla2,tabla3,Nprimo);
	getch();
	return 0;
}

int BuscarPrimo(int num){
	int Nprim,i,a;
	if(num==1){
		num++;
	}
	do{
		a=0;
		for(i=1;i<=num;i++)
		{
   			if(num%i==0){
   				a++;	
			} 
		}
		if(a==2){
			Nprim=num;
		}else{
			num=num+1;
		}
	}while(a>2);
	return Nprim;
}


void CrearTabla(Vector vec[],int num){
	for (int i=0;i<num;i++){
		vec[i].pk=i;
		vec[i].sig=NULL;
	}
}


void IngresarTablas(Vector vec1[],Vector vec2[],Vector vec3[],int Nprimo){
	
	char cedula[X];
	char nombre[Y];
	float sueldo;
	int clave,valida=0;
	printf("\n-------------------------------------------\n");
	do{
		printf("CEDULA: ");
		fflush(stdin);
		gets(cedula);
		valida=strlen(cedula);
		if(valida>10){
			printf("La cedula no es valida\nVuelva a intentar\n");
		}
	}while(valida>10);

	printf("NOMBRE: ");
	gets(nombre);
	fflush(stdin);
	printf("SUELDO: ");
	scanf("%f",&sueldo);
	printf("\n-------------------------------------------\n");
	clave=CalcularClave1(cedula,Nprimo);
	AsignarNodo(vec1,clave,cedula,nombre,sueldo,Nprimo);
	clave=CalcularClave2(cedula,Nprimo);
	AsignarNodo(vec2,clave,cedula,nombre,sueldo,Nprimo);
	clave=CalcularClave3(cedula,Nprimo);
	AsignarNodo(vec3,clave,cedula,nombre,sueldo,Nprimo);
}
int CalcularClave1(char palabra[],int tamaniov){
	int valor,largo;
	valor=0;
	largo=strlen(palabra);
	for(int i=0;i<largo;i++){
		valor=valor+palabra[i];
	}
	if(valor<0){
		valor=valor*(-1);
	}
	return valor%tamaniov;
}
int CalcularClave2(char palabra[],int tamaniov){
	int valor;
	valor=(palabra[0]+27*palabra[1]+729*palabra[2])%tamaniov;
	if(valor<0){
		valor=valor*(-1);
	}
	return valor;
}
int CalcularClave3(char palabra[],int tamaniov){
	int valor,largo;
	valor=0;
	largo=strlen(palabra);
	for(int i=0;i<largo;i++){
		valor=(32*valor+palabra[i])%tamaniov;
	}
	if(valor<0){
		valor=valor*(-1);
	}
	return valor;
}
void AsignarNodo(Vector vec[],int clave,char cedula[],char nombre[],float sueldo,int tamaniov){
	NODO *nuevo,*aux;
	for(int i=0;i<tamaniov;i++){
		if(clave==vec[i].pk){
			nuevo=(NODO*)malloc(sizeof(NODO));
			strcpy(nuevo->cedula,cedula);
			strcpy(nuevo->nombre,nombre);
			nuevo->sueldo=sueldo;
			nuevo->nodosig=NULL;
			if(vec[i].sig==NULL){
				vec[i].sig=nuevo;
			}else{
				aux=vec[i].sig;
				while(aux->nodosig!=NULL){
					
					aux=aux->nodosig;
				}
				aux->nodosig=nuevo;
				nuevo->nodosig=NULL;
			}
		}
	}
}
void ImprimirVector(Vector vec1[],Vector vec2[],Vector vec3[], int Nump,int auxTabla){
	
	if(Nump<=23){
		ImprimirMarco(Nump);
		ImprimirTodo(vec1,4,Nump);
		ImprimirTodo(vec2,44,Nump);
		ImprimirTodo(vec3,88,Nump);
	}else{
		ImprimirMarco(auxTabla+2);
		ImprimirOnlyData(vec1,4,Nump);
		ImprimirOnlyData(vec2,44,Nump);
		ImprimirOnlyData(vec3,84,Nump);
	}

}
void ImprimirMarco(int num){
	int i,j,H,V,cont=1;
	V=120;
	H=num+6;
	for (i=0;i<V;i++){
		for(j=0;j<H;j++){
			if(i==0 || i==V-1 || i==40 || i==80 ){
				ubicaxy(i,j);
				printf("*");
			}else if(j==0 || j==4 ||j==H-1){
				ubicaxy(i,j);
				printf("*");
			}else{
				ubicaxy(i,j);
				printf(" ");
			}
		}
	}
	for(int i=0;i<120;i++){
		if(i==15 ||i==55 ||i==95){
				ubicaxy(i,2);
				printf("FUNCION %d",cont);
				cont++;
		}
	}
	printf("\n");
}
void ImprimirTodo(Vector vec[],int inicio,int Nump){
	NODO *aux;
	for(int i=0;i<Nump;i++){
		ubicaxy(inicio,i+5);
			printf("[%d]",vec[i].pk);
			if(vec[i].sig!=NULL){
				aux=vec[i].sig;
				while(aux!=NULL){
					printf("%s  ",aux->cedula);
					aux=aux->nodosig;
				}
			}
			printf("\n");
	}
}
void ImprimirOnlyData(Vector vec[],int inicio,int Nump){
	NODO *aux;
	int aux1=0;
	for(int i=0;i<Nump;i++){
		if(vec[i].sig!=NULL){
			ubicaxy(inicio,aux1+6);
			printf("[%d]",vec[i].pk);
			aux=vec[i].sig;
			while(aux!=NULL){
				printf("%s",aux->cedula);
				aux=aux->nodosig;
			}
			aux1++;
		}
		printf("\n");
	}
}
void Buscar(Vector vec1[],Vector vec2[],Vector vec3[],int Nprimo){
	NODO *aux;
	int clave=0,cont=0;
	char buscada[X];
	printf("INGRESE CLAVE(CEDULA) A BUSCAR: ");
	fflush(stdin);
	gets(buscada);
	ImprimirMarco2(Nprimo);
	clave=CalcularClave1(buscada,Nprimo);
	BuscarEnVector(vec1,clave,Nprimo,buscada,4);
	clave=CalcularClave2(buscada,Nprimo);
	BuscarEnVector(vec2,clave,Nprimo,buscada,44);
	clave=CalcularClave3(buscada,Nprimo);
	BuscarEnVector(vec3,clave,Nprimo,buscada,84);
	for(int i=0;i<120;i++){
		ubicaxy(i,Nprimo+12);
		printf("*");
	}
}
void ImprimirMarco2(int Nprimo){
	int i,j,V,H;
	V=120;
	H=Nprimo+13;
	for(i=0;i<120;i++){
		ubicaxy(i,Nprimo+8);
		printf("*");
	}
}
void BuscarEnVector(Vector vec[],int clave,int Nprimo,char buscada[],int pos){
	NODO *aux;
	int cont=0;
	int salir=0;
	for(int i=0;i<Nprimo;i++){
		if(vec[i].sig!=NULL){
			aux=vec[i].sig;
			while(aux!=NULL){
				cont++;
				if(strcmp(aux->cedula,buscada)==0){
					ubicaxy(pos,Nprimo+9);
					printf("Encontrado");
					//nombre de casilla de busqueda
					ubicaxy(pos,Nprimo+10);
					printf("%s : %f",aux->nombre,aux->sueldo);
					salir++;
					break;
				}
				aux=aux->nodosig;
			}
		}else{
			cont++;
		}	
		if(salir!=0){
			break;
		}
	}
	ubicaxy(pos,Nprimo+11);
	printf("Veces que se pregunto: %d",cont);
	
}
