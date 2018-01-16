#include <windows.h>
void ubicaxy(int x, int y)
{
	//Declaracion de Cabecera para utilizar el posicionamiento 
	HANDLE pantalla; 
	COORD posicion; 
	pantalla = GetStdHandle (STD_OUTPUT_HANDLE); 
	// hasta esta parte se debe dejar fijo 
	// A partir de aqui la sintaxis es la siguiente, como en el gotoxy (x,y): x es para la posicion en horizontal y Y para el vertical 
	posicion.X = x; posicion.Y = y; 
	SetConsoleCursorPosition (pantalla,posicion); 
	//Hasta Aqui 
}	

