/*
 ============================================================================
 Name        : TPF_Suffragetto_Fernandez_Franco.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




#include "Funciones_Suffrag.h"






int main(void){


	/*Las variables num1 y num2 son contadores que sirven para verificar si alguna
	 * de las bases ha sido conquistada. Se emplean en la funcion verificar_conquista().
	 * Cada base esta compuesta por 6 casillas del tablero, por lo tanto, si num1 o num2
	 * llegasen a valer 6, significa que una de las bases ha sido completamente invadida,
	 * luego, uno de los dos equipos ha ganado...*/
	int num1=0, num2=0;

	int num3, num4;


	srand(time(NULL));		//Se utiliza srand(time(NULL)) para la obtencion de numeros aleatorios mas adelante dentro de las funciones con rand()


	mensaje_de_bienvenida();
	instrucciones();
	reglas();

	eleccion_bando(bandos);
	turno = seleccionar_jugador1(turno);

	do{
		num3 = 0;
		num4 = 0;
		imprimir_tablero();
		mostrar_turno(turno);
		Jugar(turno, bandos[turno-1]);
		turno = rotar_jugador(turno);

		verificar_conquista(&num1,&num2); //num1 es el contador de los policias. num2 es el contador de las suffragettes

		rev_carcel_hosp(&num3,&num4);


	}while(num1<6 && num2<6 && num3>=16 && num4>=16);
	/*Si se sale del ciclo do while, quiere decir que alguna de las condiciones de victoria ha sido alcanzada*/


	imprimir_tablero();
	fin_del_juego(num1,num2,num3,num4);




}
