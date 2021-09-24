

#ifndef ESENCIAL_SUFFRAG_H_
#define ESENCIAL_SUFFRAG_H_






/*Una matriz de enteros para representar el tablero de juego.
 * Se utiliza en conjunto con el array ficha(ver mas abajo) para imprimir el tablero.
 * La idea principal es crear una relacion de correspondencia entre los numeros enteros
 * de la matriz, los caracteres en el array ficha y las fichas en el tablero, tal que al momento de
 * imprimir el tablero, se recorra la matriz tablero(ver abajo) y se impriman los caracteres
 * correspondientes */

int tablero[17][17] = {
	8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,8,0,0,0,0,4,6,6,6,4,0,0,0,0,0,7,
	8,0,0,0,3,4,4,6,6,6,4,4,3,0,0,0,7,
	8,0,3,4,4,4,4,4,3,4,4,4,4,4,3,0,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,
	8,0,1,2,2,2,2,2,1,2,2,2,2,2,1,0,7,
	8,0,0,0,1,2,2,5,5,5,2,2,1,0,0,0,7,
	8,0,0,0,0,0,2,5,5,5,2,0,0,0,0,7,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7
};





char ficha[10]= {' ','I','p','L','s','X','O','▒','H'};


/*Los indices del array ficha[] estan relacionados con los numeros en la matriz tablero[][]
 * El subindice 'i' en ficha[i] representa al entero 'i' en la matriz tablero[][], lo que se imprime es el elemento en esa posicion del array ficha.
 *
 * tablero[i][j] = 0  ==>  ficha[0]  ==>  espacio vacio ' '
 * tablero[i][j] = 1  ==>  ficha[1]  ==>  Inspector "I"
 * tablero[i][j] = 2  ==>  ficha[2]  ==>  policia "p"
 * tablero[i][j] = 3  ==>  ficha[3]  ==>  Lider suffragette "L"
 * tablero[i][j] = 4  ==>  ficha[4]  ==>  suffragette "s"
 * tablero[i][j] = 4  ==>  ficha[5]  ==>  base policias "X"
 * tablero[i][j] = 4  ==>  ficha[6]  ==>  base suffragetto "O"
 * tablero[i][j] = 7  ==>  ficha[7]  ==>  prision "▒"
 * tablero[i][j] = 8  ==>  ficha[8]  ==>  hospital "H"
 *
 * */






#endif
