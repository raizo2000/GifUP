#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Columnas{
	int dato;
	struct Columnas *sig_columna;
};
struct Filas{
	struct Filas *sig_fila;
	struct Columnas *columna;
};
struct Matriz{
	int nf,nc;
	struct Filas *fila;
};
int menu(int op);
struct Matriz *crear_matriz(struct Matriz *cab);
void imprimir_matriz(struct Matriz *cab);
void imprimir(struct Matriz *cab);
void imprimir2(struct Filas *aux_fila,Columnas *aux_colu);
struct Matriz *sumar_matriz(struct Matriz *m1,struct Matriz *m2);
struct Matriz *transpuesta(struct Matriz *cab);
int main(){
	int op;
	struct Matriz *m1=NULL,*m2=NULL,*m3=NULL;
	printf("\t\tListas entralazadas (MultiListas) - Matrices\n");
	do{
		op=menu(op);
		switch(op){	
			case 1:{
				m1=(Matriz*)malloc(sizeof(Matriz));
    			printf("Ingrese numero de filas: ");
    			scanf("%d",&m1->nf);
    			printf("Ingrese numero de columnas: ");
    			scanf("%d",&m1->nc);
				
					m1=crear_matriz(m1);
					printf("La matriz 1 es: \n");
					imprimir_matriz(m1);
					system("pause");
					system("cls");

				break;
			}
			case 2:{
					m2=crear_matriz(m1);
					printf("La matriz 2 es: \n");
					imprimir_matriz(m2);
					m3=sumar_matriz(m1,m2);
					//imprimir_matriz(m3);
					system("pause");
					system("cls");
				break;
			}
			case 3:{
				printf("La suma de la Matriz 1 y Matriz 2 es: \n");
				imprimir_matriz(m3);
				break;
			}
			case 4:
				printf("......Bye........");
			break;
		}	
	}while(op!=4);
	
}
int menu(int op){

	printf("\nElija una opcion:\n");
	printf("1.Crear Matriz\n");
	printf("2.Suma de matrices\n");
	printf("3.Imprimir Matriz Resultado\n");
	printf("4.Salir\n");
	scanf("%d",&op);
	return op;
}
struct Matriz *crear_matriz(struct Matriz *cab){
	Filas *nuevafila,*anteriorfil;
    Columnas *nuevacolumna,*anteriorcol;
    nuevafila=NULL;
    nuevacolumna=NULL;
    int filas,columnas,fil,col;
    
    for (fil=1;fil<=cab->nf;fil++){
        anteriorfil=nuevafila;
        nuevafila=(Filas*)malloc(sizeof(Filas));
        if (fil==1){
            cab->fila=nuevafila;
        }else{
        	anteriorfil->sig_fila=nuevafila;
		}
        for(col=1;col<=cab->nc;col++){
            anteriorcol=nuevacolumna;
            nuevacolumna=(Columnas*)malloc(sizeof(Columnas));
            printf("Ingrese dato [%d,%d]: ",fil,col);
            scanf("%d",&nuevacolumna->dato);
            if(col==1){
                nuevafila->columna=nuevacolumna;
            }else{
                anteriorcol->sig_columna=nuevacolumna;
            }
            nuevacolumna->sig_columna=NULL;
        }
  		nuevafila->sig_fila=NULL;
    }
   imprimir(cab);
    return cab;
}
void imprimir(Matriz *cab){
	Filas *aux_fila;
	Columnas *aux_colu;
	aux_fila=cab->fila;
	aux_colu=aux_fila->columna;
	imprimir2(aux_fila,aux_colu);
	return;
}
void imprimir2(Filas *aux_fila,Columnas *aux_colu){
	if(aux_colu!=NULL){
		printf("%d\t",aux_colu->dato);
		aux_colu=aux_colu->sig_columna;
		
	}else{
		printf("\n");
		aux_fila=aux_fila->sig_fila;
		if(aux_fila==NULL){
			return;
		}
		aux_colu=aux_fila->columna;
		imprimir2(aux_fila,aux_colu);
	}
	
}
void imprimir_matriz(struct Matriz *cab){
	Matriz *aux;
	Filas *aux_fil;
	Columnas *aux_col;
	aux=cab;
	aux_fil=aux->fila;
	
	for(int f=1;f<=cab->nf;f++){
		
		for(int c=1;c<=cab->nc;c++){
			if(c==1){
				aux_col=aux_fil->columna;
			}
			else{
				aux_col=aux_col->sig_columna;
			}
			printf("%d \t",aux_col->dato);
		}
		aux_fil=aux_fil->sig_fila;
		printf("\n");
		
	}

}
struct Matriz *sumar_matriz(struct Matriz *m1,struct Matriz *m2){
	Matriz *aux;
	Filas *aux_fil1,*aux_fil2;
	Columnas *aux_col1,*aux_col2;
	
	aux_fil1=m1->fila;
	aux_fil2=m2->fila;
	for(int f=1;f<=m1->nf;f++){
		
		for(int c=1;c<=m1->nc;c++){
			if(c==1){
				aux_col1=aux_fil1->columna;
				aux_col2=aux_fil2->columna;
			}
			else{
				aux_col1=aux_col1->sig_columna;
				aux_col2=aux_col2->sig_columna;
			}
			aux_col2->dato=aux_col1->dato+aux_col2->dato;
		}
		aux_fil1=aux_fil1->sig_fila;
		aux_fil2=aux_fil2->sig_fila;
		
	}
	return m2;
}



