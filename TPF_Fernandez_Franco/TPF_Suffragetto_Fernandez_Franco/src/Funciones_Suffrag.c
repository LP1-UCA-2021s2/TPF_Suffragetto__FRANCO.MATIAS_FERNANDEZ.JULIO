#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Esencial_Suffrag.h"
#include "Funciones_Suffrag.h"



/*Funcion para dar una pausa entre impresion e impresion se utilizaron
 * dos getchar() . No hay/existe system("Pause") en Linux. Es mas facil con los getchar() */
void Pausa(){
	printf("\nPresione Enter para continuar...");
	getchar();
	getchar();
}

/*Imprime Mensaje de Bienvenida*/
void mensaje_de_bienvenida(){
	printf("\n\t \t \t SUFFRAGETTO \n \n \n");
	printf("\t Bienvenido al Juego Suffragetto. \n \n");

	Pausa();
}


/*Imprime las Instrucciones del uso del programa*/
void instrucciones(){
	printf("          ----------INSTRUCCIONES PARA USO DEL PROGRAMA---------\n\n");
	printf(" -El usuario puede determinar quién inicia el juego, quién será suffragetto y quién será policía. \n  O bien los turnos y bandos se definen de forma aleatoria.\n\n -Para mover las piezas se deben introducir las coordenadas de la pieza a mover y las de la posicion a moverse.\n\n -Las coordendas del tablero van desde (0) hasta (16) para las filas y las columnas.\n\n -El programa se encargara de advertirle de errores o movimientos invalidos.\n\n -Cada movimiento valido que usted realice, podra ser corroborado en el tablero de juego.\n\n -Al finalizar el juego, el programa indicara cual es el bando ganador y perdedor.\n\n ");
	Pausa();
}



/*Imprime las Reglas del Juego - Informacion sobre las condiciones para ganar*/
void reglas(){
	printf("\n\n\t\t REGLAS: \n\n Atencion Policias y Suffragettes! \n");
	printf("\n SUFFRAGETTES! \n\n Para ganar, deben conquistar todas las casillas marcadas\n con el simbolo 'X'.\n ");
	printf("\n\n POLICIAS! \n\n Para ganar, deben conquistar todas las casillas marcadas\n con el simbolo 'O'.\n ");
	printf("\n\n\n El juego va a comenzar... \n\n \t\tA SUS POSICIONES!! \n\n");

	Pausa();
}


/*Eleccion de bandos. Se utilizaron los numero 1 y 3 para marcar los bandos
 * en la matriz en Esencial.Suffrag.h se utilizan 1s y 2s para los policias
 * y 3s y 4s para las suffragettes
 * La idea de 1 y 3 es: bando = 1 || bando = 3
 * Luego las piezas son: pieza = bando || pieza = bando +1 */
int eleccion_bando(int bandos[2]){
	int computadora, usuario;
	int eleccion1;
	printf("\nElija su bando: \n 1-Suffragettes.  2-Policias.  3-Seleccion aleatoria. \n ");
	scanf("%d",&eleccion1);
	switch(eleccion1){
		case 1:
			usuario = 3;
			computadora = 1;
			printf("\nEl Usuario es equipo Suffragettes. La Computadora es equipo Policias.\n");
			break;
		case 2:
			usuario = 1;
			computadora = 3;
			printf("\nEl Usuario es equipo Policias. La Computadora es equipo Suffragettes.\n");
			break;
		case 3:
			usuario = (rand()%2)+1;  //Seleccion aleatoria junto con un srand(time(NULL)) en el main
			if(usuario==1){
				computadora = 3;
				printf("\nEl Usuario es equipo Policias. La Computadora es equipo Suffragettes.\n");
			}else{
				computadora = 1;
				usuario = 3;
				printf("\nEl Usuario es equipo Suffragettes. La Computadora es equipo Policias.\n");
			}
			break;
	}
	bandos[0] = computadora;	//como solo se puede retornar un entero...
	bandos[1] = usuario;	//al meter los dos valores en un array, se consiguen los
	return bandos;			//dos valores necesitados
}

/*Seleccion del jugador1. Funciona en conjunto con la variable turno en el main*/
int seleccionar_jugador1(int eleccion){
	printf("\n\nSeleccione quien empieza: \n 1-PC.  2-Usuario.  3-Seleccion aleatoria. \n ");
	scanf("%d",&eleccion);
	switch(eleccion){
		case 1:
			printf("\n\nLa Computadora empieza. \n");
			break;
		case 2:
			printf("\n\nEl Usuario empieza. \n");
			break;
		case 3:
			eleccion = (rand()%2)+1;		//Seleccion aleatoria junto con un srand(time(NULL)) en el main
			if(eleccion == 1){
				printf("\n\nLa Computadora empieza. \n");
			}else{
				printf("\n\nEl Usuario empieza. \n");
			}
	}
	Pausa();
	return eleccion;	// Se retorna eleccion para usar en el juego de la Computadora
}

/*Funcion que recibe dos contadores. Uno para la carcel, otro para el hospital.
 * Esta funcion se utiliza para saber si el numero de fichas habilitadas de ambos bandos es menor o igual a 5
 * puesto que si algun equipo tiene solo 5 fichas, no podra conquistar las seis casillas de la base enemiga.
 * Se alguno de estos dos contadores resulta ser mayor o igual a 16, algun equipo no podra ganar. Luego, su oponente es el ganador.*/
void rev_carcel_hosp(int *num3, int *num4){
	int i,j;

	/*Contar el numero de policias y/o Inspectores en el hospital*/
	for(i=0; i<17; i++){
		j = 0;
		if(tablero[i][j]==1 || tablero[i][j]==2){
			(*num3)++;
		}
	}
	/*Contar el numero de suffragettes y/o Lideres en la carcel*/
	for(i=0; i<17; i++){
		j = 16;
		if(tablero[i][j]==3 || tablero[i][j]==4){
			(*num4)++;
		}
	}

}


/*Limitacion para evitar que los bando entren en sus propias bases*/
int Limitacion_Bases(int x, int y, int pieza){
	int aux = pieza;
	if(aux==3 || aux==4){
		limitacion_Suffrag(x,y);
	}
	if(aux==1 || aux==2){
		limitacion_Polic(x,y);
	}
}


/*Limitacion para evitar que las suffragettes entren en su propia base*/
int limitacion_Suffrag(int x, int y){
	if((x==3 || x==4) && (y>=7 && y<10)){
		if(turno == 2){
			printf("\nNo puede ingresar a esta casilla. \n");
			return 0;
		}else{
			return 0;
		}
	}else{
		return 1;
	}
}

/*Limitacion para evitar que los policias entren en su propia base*/
int limitacion_Polic(int x, int y){
	if((x==12 || x==13) && (y>=7 && y<10)){
		if(turno == 2){
			printf("\nNo puede ingresar a esta casilla. \n");
			return 0;
		}else{
			return 0;
		}
	}else{
		return 1;
	}
}

/*Combinacion con limite_tablero para impedir que las piezas entren en la carcel
 * u hospital*/
int limite_movimiento(int x, int y){
	int aux = limite_tablero(x,y);
	switch(aux){
		case 0:
			return 0;
			break;
		case 1:
			if((y==1 && x<4) || (y==15 && x>12)){
				if(turno == 2){
					printf("\nError. No puede entrar en esta casilla. \n");
					return 0;
				}else{
					return 0;
				}
			}else{
				return 1;
			}
			break;
	}
}

/*Verifica que las coordenadas de movimiento sean las de una casilla adyacentes
 * a la casilla seleccionada*/
int verificar_adyacente(int x, int y, int x2, int y2){
	if((x2==x) && (y2==y)){		//para evitar la misma casilla
		if(turno == 2){
			printf("\nCoordenadas inicial y final coinciden. Vuelva a ingresar las coordenadas. ");
			return 0;
		}else{
			return 0;
		}
	}
	if(abs(x2-x)<=1 && abs(y2-y)<=1){	//abs es una funcion de stdlib.h
		return 1;
	}else{
		if(turno == 2){
			printf("\nCasilla fuera de la adyacencia. \n");
			return 0;
		}else{
			return 0;
		}
	}
}


/*Rotar jugadores*/
int rotar_jugador(int turno){
	if(turno==1){		//si antes era turno = 1, ahora sera turno = 2
		turno = 2;
	}else{
		turno = 1;		//turno era = 2, luego pasa a ser 1.
	}
	return turno;
}

/*Mostrar turnos. Imprime un mensaje sobre a quien le toca jugar */
void mostrar_turno(int turno){
	if(turno == 1){
		printf("\nEs el turno de la Computadora. \n");
		Pausa();
	}else{
		printf("\nEs el turno del Usuario. \n");
		Pausa();
	}
}


/*Imprime el Mensaje de fin del juego de acuerdo a las condiciones de fin del juego*/
void fin_del_juego(int num1, int num2, int num3, int num4){
	if(num3>=16){
		if(bandos[0]==1){
			printf("\nEl equipo Policias no tiene suficientes fichas para conquistar la base enemiga.\n\n\t\tVICTORIA DE LAS SUFFRAGETTES! \n");
			printf("\nEl Usuario ha ganado.\n");
		}else{
			printf("\nEl equipo Policias no tiene suficientes fichas para conquistar la base enemiga.\n\n\t\tVICTORIA DE LAS SUFFRAGETTES! \n");
			printf("\nLa Computadora ha ganado.\n");
		}
	}
	if(num4>=16){
		if(bandos[1]==3){
			printf("\nEl equipo Suffragetto no tiene suficientes fichas para conquistar la base enemiga.\n\n\t\tVICTORIA DE LOS POLICIAS! \n");
			printf("\nEl Usuario ha ganado.\n");
		}else{
			printf("\nEl equipo Suffragetto no tiene suficientes fichas para conquistar la base enemiga.\n\n\t\tVICTORIA DE LOS POLICIAS! \n");
			printf("\nLa Computadora ha ganado.\n");
		}
	}
	if(num1==6){
		printf("\n\n\t\t\tALBERT HALL CONQUISTADO! \n\n\t\t\tVICTORIA DE LOS POLICIAS! \n\n");
		if(bandos[0]==1){
			printf("\n\n\n\tLa Computadora ha ganado. ");
		}else{
			printf("\n\n\n\tEl Usuario ha ganado. ");
		}
	}
	if(num2==6){
		printf("\n\n\t\t\tHOUSE OF COMMONERS CONQUISTADO! \n\n\t\t\tVICTORIA DE LAS SUFFRAGETTES! \n\n");
		if(bandos[0]==3){
			printf("\n\n\n\tLa Computadora ha ganado. ");
		}else{
			printf("\n\n\n\tEl Usuario ha ganado. ");
		}
	}
	printf("\n\n\n\n\t\tFIN DEL JUEGO\n");
}




/*Impresion del Tablero*/
void imprimir_tablero(){
	int i,j;

	printf("\n+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+\n");
	printf("     |");
	for(i=0; i<17; i++){
		printf(" %2d │",i);
	}
	printf("\n+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+\n");
	for(i=0; i<17; i++){
		printf("  %2d │",i);
		for(j=0; j<17; j++){
			if(j==3 || j==12){		//A partir del final de la columna j=3 hasta el final de la columna j=12 esta la arena de combate
				if(tablero[i][j]==0){		//Los limites de la arena se marcan/indican con el caracter '║' en la impresion del tablero
					printf("  %c ║",ficha[0]);
				}
				if(tablero[i][j]==1){
					printf("  %c ║",ficha[1]);
				}
				if(tablero[i][j]==2){
					printf("  %c ║",ficha[2]);
				}
				if(tablero[i][j]==3){
					printf("  %c ║",ficha[3]);
				}
				if(tablero[i][j]==4){
					printf("  %c ║",ficha[4]);
				}
				if(tablero[i][j]==5){
					printf("  %c ║",ficha[5]);
				}
				if(tablero[i][j]==6){
					printf("  %c ║",ficha[6]);
				}
				if(tablero[i][j]==7){
					printf("  %c ║",ficha[7]);
				}
				if(tablero[i][j]==8){
					printf("  %c ║",ficha[8]);
				}
			}else{
				if(tablero[i][j]==0){
					printf("  %c │",ficha[0]);
				}
				if(tablero[i][j]==1){
					printf("  %c │",ficha[1]);
				}
				if(tablero[i][j]==2){
					printf("  %c │",ficha[2]);
				}
				if(tablero[i][j]==3){
					printf("  %c │",ficha[3]);
				}
				if(tablero[i][j]==4){
					printf("  %c │",ficha[4]);
				}
				if(tablero[i][j]==5){
					printf("  %c │",ficha[5]);
				}
				if(tablero[i][j]==6){
					printf("  %c │",ficha[6]);
				}
				if(tablero[i][j]==7){
					printf("  %c │",ficha[7]);
				}
				if(tablero[i][j]==8){
					printf("  %c │",ficha[8]);
				}
			}
		}
		printf("\n+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+────+\n");
	}
}



/*Maximo y Minimo valores posibles que pueden tomar las coordenadas x e y*/
int limite_tablero(int x, int y){
	if(x>=0 && x<17 && y>=1 && y<16){
		return 1;
	}else{
		if(turno == 2){
			printf("\nCasilla fuera del tablero. \n");
			return 0;
		}else{
			return 0;
		}
	}
}



/*Para verificar si alguna de las bases ha sido conquistada
 * Se utilizan num1 y num2(o mejor dicho sus direcciones), ambos se van incrmentando.
 * Si alguno de estos dos llega a valer seis, quiere decir que una de las bases
 * enemigas ha sido completamente invadida*/
void verificar_conquista(int *num1, int *num2){
	int i,j;
	/*Base de las Suffragettes. ALBERT HALL*/
	for(i=3; i<5; i++){
		for(j=7; j<10; j++){
			if(tablero[i][j]==1 || tablero[i][j]==2){
				(*num1)++;
			}
		}
	}
	/*Base de los Policias. COMMONERS HALL*/
	for(i=12; i<14; i++){
		for(j=7; j<10; j++){
			if(tablero[i][j]==3 || tablero[i][j]==4){
				(*num2)++;
			}
		}
	}
}




/*Verifica si la casilla seleccionada esta vacia o no*/
int verificar_vacia(int x, int y){
	if(tablero[x][y]==0 || tablero[x][y]==5 || tablero[x][y]==6){
		return 1;
	}
	if(tablero[x][y]>0  && turno == 2){
		printf("\nCasilla Ocupada o NO habilitada para su equipo. ");
		return 0;
	}else if(tablero[x][y]>0 && turno!=2){
		return 0;
	}
}



/*Revisa los alrededores de una ficha en busca de otras que esten en su adyacencia
 * Auxiliar para saltos en cadena */
int revisar_vecinos(int x, int y){
	int i,j;
	int aux;

	aux = 0;
	for(i=x-1; i<x+2; i++){
		if(i<0)
			i = i+1;
		if(i>16)
			break;
		for(j=y-1; j<y+2; j++){
			if(j<1)
				j = j+1;
			if(j>15)
				break;
			if(tablero[i][j]!=0 || tablero[i][j]!=5 || tablero[i][j]!=6){
				aux = aux +1;
			}
		}
	}
	if(tablero[x][y]!=0 || tablero[x][y]!=5 || tablero[x][y]!=6){
		aux = aux-1;
	}
	return aux;		//Retorna aux, que es una cantidad que indica que existe al menos una o ninguna ficha en las cercanias
					//Esta funcion es mas que nada para ayudar en la accion de saltos multiples
}



/*Verifica si la pieza que se encuentra en la casilla seleccionada pertenece al bando
 * propio o al bando enemigo*/
int verificar_bando(int x, int y, int bando){
	if(tablero[x][y]==bando || tablero[x][y]==bando+1){
		return 1;
	}
	if(tablero[x][y]!=bando){
		if(turno == 2){
			printf("\nCoordenada no valida. Pieza del bando opuesto o casilla vacia. \n");
			return 0;
		}else{
			return 0;
		}
	}
}

/*Para verificar que la ficha enemiga este dentro de la arena de combate
 * de asi serlo, podra ser incapacitada por sus oponentes a la hora de ser saltada*/
int verificar_arena(int x, int y){
	if(x>=0 && x<17 && y>=4 && y<13){
		return 1;
	}else{
		if(turno == 2){
			printf("\nFuera de la arena de combate.No puede incapacitar a esta pieza. \n");
			return 0;
		}else{
			return 0;
		}
	}
}



/*Funcion encargada de cargar en la carcel/hostpital a las piezas derrotadas*/
void Pieza_Derrotada(int derrotado){
	int i,j;
	int aux = derrotado;
	if(aux==1 || aux==2){		//Inspector(1) o policia(2)
		for(j=0; j<2; j++){
			for(i=0; i<17; i++){
				if(tablero[i][j]==8){
					tablero[i][j] = aux;
					aux = 8;
					break;
				}else{
					tablero[i][j] = tablero[i][j] +0;
				}
			}
		}
	}
	if(aux==3 || aux==4){		//Lider Suffragetto(3) o suffragette(4)
		for(j=16; j>14; j--){
			for(i=16; i>-1; i--){
				if(tablero[i][j]==7){
					tablero[i][j] = aux;
					aux = 7;
					break;
				}else{
					tablero[i][j] = tablero[i][j] +0;
				}
			}
		}
	}
}


/*Auxiliar para la funcion Mov_Salto. Recoge las direcciones del posible salto*/
int aux_salto(int x, int y, int x2, int y2){
	if(x2>x && y2==y){		//Direccion vertical, descendiente
		return 1;
	}
	if(x2>x && y2<y){		//Diagonal derecha descendiente
		return 2;
	}
	if(x2>x && y2>y){		//Diagonal izquierda descendiente
		return 3;
	}
	if(x2==x && y2<y){		//Horizontal, de derecha a izquierda
		return 4;
	}
	if(x2==x && y2>y){		//Horizontal, de izquierda a derecha
		return 5;
	}
	if(x2<x && y2<y){		//Diagonal derecha ascendiente
		return 6;
	}
	if(x2<x && y2>y){		//Diagonal izquierda ascendiente
		return 7;
	}
	if(x2<x && y2==y){		//Vertical ascendiente
		return 8;
	}
}



/*Recoge y verifica las coordenadas de los posibles saltos*/
int Mov_Salto(int x, int y, int x2, int y2, int pieza){
	int x3, y3;
	B = 0;
	int mov = aux_salto(x,y,x2,y2);		//Entra en accion la funcion aux_salto
	if(pieza==1 || pieza==3){	//1 y 3 son piezas especiales. Inspector y Lider suffragetto respectivamente
		switch(mov){			//pueden saltar en 8 direcciones
			case 1:
				x3 = x2 +1;
				y3 = y2 +0;
				break;
			case 2:
				x3 = x2 +1;
				y3 = y2 -1;
				break;
			case 3:
				x3 = x2 +1;
				y3 = y2 +1;
				break;
			case 4:
				x3 = x2 +0;
				y3 = y2 -1;
				break;
			case 5:
				x3 = x2 +0;
				y3 = y2 +1;
				break;
			case 6:
				x3 = x2 -1;
				y3 = y2 -1;
				break;
			case 7:
				x3 = x2 -1;
				y3 = y2 +1;
				break;
			case 8:
				x3 = x2 -1;
				y3 = y2 +0;
				break;
		}
	}
	if(pieza==2 || pieza==4){	//2 y 4 son piezas basicas. Policia y suffragette respectivamente
		switch(mov){			//solo pueden saltar en diagonal
			case 1:
				if(cont>0){
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /n");
					cont = 3;
					return 9;
				}else{
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /nIntente con otras coordenadas. /n");
					return 0;
				}
			case 2:
				x3 = x2 +1;
				y3 = y2 -1;
				break;
			case 3:
				x3 = x2 +1;
				y3 = y2 +1;
				break;
			case 4:
				if(cont>0){
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /n");
					cont = 3;
					return 9;
				}else{
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /nIntente con otras coordenadas. /n");
					return 0;
				}
			case 5:
				if(cont>0){
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /n");
					cont = 3;
					return 9;
				}else{
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /nIntente con otras coordenadas. /n");
					return 0;
				}
			case 6:
				x3 = x2 -1;
				y3 = y2 -1;
				break;
			case 7:
				x3 = x2 -1;
				y3 = y2 +1;
				break;
			case 8:
				if(cont>0){
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /n");
					cont = 3;
					return 9;
				}else{
					printf("\nNo puede saltar en vertical u horizontal con esta ficha. /nIntente con otras coordenadas. /n");
					return 0;
				}
		}
	}
	//Para verificar que las coordenadas del posible salto esten disponibles
	if(!limite_movimiento(x3,y3) || !verificar_vacia(x3,y3)){
		if(turno == 2){
			printf("\n\nLa casilla X2 = %d , Y2 = %d y su adyacente estan ocupadas. \nNo es posible saltar en esa direccion. ",x2,y2);
			printf("\nVuelva a intentarlo con coordenadas diferentes. ");
			return 0;
		}else{
			return 0;
		}
	}
	/*Si la funcion llego hasta aqui, quiere decir que es posible realizar el salto.
	 * Por lo tanto se pregunta si la ficha a ser saltada pertenece al bando propio, sino, es un enemigo y puede ser incapacitada
	 * Se utilizan el vector bandos con turno como subindice*/
	if(tablero[x2][y2] != bandos[turno-1] && tablero[x2][y2] != (bandos[turno-1] +1) && verificar_arena(x2,y2)){
		Pieza_Derrotada(tablero[x2][y2]);	//Entra en accion la funcion Pieza_Derrotada
		tablero[x2][y2] = 0;
	}
	Movimiento(x,y,x3,y3,pieza);
	B = revisar_vecinos(x3,y3);
	/*Se guardan las coordenadas finales despues de la accion salto
	 * esto es por si es posible volver a saltar*/
	coor[0] = x3;
	coor[1] = y3;
	return 1;
}


/*Desplazamiento de piezas
 * Si la casilla de destino esta vacia, se realiza un movimiento simple */
int Movimiento(int x, int y, int x2, int y2, int pieza){
	int p;
	if(verificar_vacia(x2,y2)){		//verificar_vacia() retorna verdadero (1)
		//La casilla del tablero de las coordenadas de destino se llena con la pieza
		tablero[x2][y2] = pieza;
		//La casilla del tablero con las coordenadas iniciales se vacia
		tablero[x][y] = 0;
		return 1;
	}
	/*Si no esta vacia, puede que sea posible saltar */
	if(!verificar_vacia(x2,y2)){	//verificar_vacia() retorna falso (0)
		/*Como puede que sea posible saltar, entra en accion la funcion Mov_Salto*/
		p = Mov_Salto(x,y,x2,y2,pieza);
		cont = cont+1;	//cont se incrementa en 1. Cont se puede incrementar hasta 3, que es el numero maximo de saltos consecutivos.
		return p;
	}
}


/*Coordenadas de destino del desplazamiento*/
int Coordenadas_destino(int x, int y, int pieza){
	int x2=0, y2=0, m;
	if(turno == 2){		//JUEGA EL USUARIO
		do{
			do{		//Se ingresan por teclado las coordenadas de la casilla a donde se desea mover
				printf("\nIngrese las coordenadas de destino: \n");
				printf("\nCoordenada X2: ");
				scanf("%d", &x2);
				printf("\nCoordenada Y2: ");
				scanf("%d", &y2);

				while(!limite_movimiento(x2,y2) || !verificar_adyacente(x,y,x2,y2)){
					printf("\nIngrese las coordenadas de destino: \n");
					printf("\nCoordenada X2: ");
					scanf("%d", &x2);
					printf("\nCoordenada Y2: ");
					scanf("%d", &y2);
				}
				/*En el caso de que ya se haya realizado una accion salto, B!=0, se desea volver a saltar
				 * no se puede volver a saltar si las coordenadas que fueron ingresadas arriba
				 * son las de una casilla vacia.
				 * Por ello, se volvera a preguntar hasta que las coordenadas ingresadas sean
				 * las de una casilla que este llena (se puede saltar)
				*/
				if(B!=0){
					while(verificar_vacia(x2,y2)){
						printf("\nJugada no valida. Intente con otras coordenadas. \n");
						printf("\nCoordenada X2: ");
						scanf("%d", &x2);
						printf("\nCoordenada Y2: ");
						scanf("%d", &y2);
					}
				}
			}while(!Limitacion_Bases(x2,y2,pieza));

		m = Movimiento(x,y,x2,y2,pieza);	//Entra en accion la funcion Movimiento

		}while(m == 0);		//Movimiento retorna 1 o 0 mientras m = 0, se repite el proceso
	}
	if(turno == 1){		//JUEGA LA COMPUTADORA
		do{
			do{		//La COMPUTADORA usa la funcion rand() para seleccionar su destino
				x2 = (rand() % ((x+1)-(x-1)+1))+(x-1);
				y2 = (rand() % ((y+1)-(y-1)+1))+(y-1);

				while(!limite_movimiento(x2,y2)){
					x2 = (rand() % ((x+1)-(x-1)+1))+(x-1);
					y2 = (rand() % ((y+1)-(y-1)+1))+(y-1);
				}
				if(B!=0){		//LA COMPUTADORA VA A VOLVER A SALTAR SI YA LO HIZO UNA VEZ
					while(verificar_vacia(x2,y2)){
						x2 = (rand() % ((x+1)-(x-1)+1))+(x-1);
						y2 = (rand() % ((y+1)-(y-1)+1))+(y-1);
					}
				}


			}while(!Limitacion_Bases(x2,y2,pieza));
			printf("\n x2 = %d \n y2 = %d \n\n",x2,y2);

		m = Movimiento(x,y,x2,y2,pieza);

		}while(m == 0);		//Movimiento retorna 1 o 0 mientras m = 0, se repite el proceso
	}
	return 1;
}



/*Inicio. Se selecciona la pieza a mover y se guardan sus coordenadas.*/
int Jugar(int turno, int bando){
	int x=0,y=0,pieza,n;	//n es una variable auxiliar para guardar la respuesta a la pregunta: Se desea volver a saltar?; esto es caso sea posible
	B = 0;
	cont = 0;
	if(turno == 2){		//JUEGA EL USUARIO
		do{		//Se ingresan por teclado las coordenadas iniciales
			printf("\nIngrese las coordenadas de la Pieza que desea mover: \n");
			printf("\nCoordenada X: ");
			scanf("%d", &x);
			printf("\nCoordenada Y: ");
			scanf("%d", &y);
			pieza = tablero[x][y];
		}while(!verificar_bando(x,y,bando) || !limite_movimiento(x,y) || !limitacion_Polic(x,y) || !limitacion_Suffrag(x,y));

		Coordenadas_destino(x,y,pieza);		//Entra en accion la funcion Coordenadas_destino
	}
	if(turno == 1){		//JUEGA LA COMPUTADORA
		do{		//La computadora utiliza la funcion rand() para elegir sus fichas a mover

			x = (rand() % (16-0+1));
			y = (rand() % (15-2+1))+2;

			pieza = tablero[x][y];
		}while(!verificar_bando(x,y,bando) || !limite_movimiento(x,y) || !limitacion_Polic(x,y) || !limitacion_Suffrag(x,y));
		printf("\n x = %d \n y = %d \n\n",x,y);
		Coordenadas_destino(x,y,pieza);
	}
	while(B!=0 && cont<3){		//ES POSIBLE VOLVER A SALTAR, ESTO SOLO SE ACTIVA SI YA SE HA REALIZADO UNA ACCION SALTO
		if(turno == 2){
			n = 0;
			imprimir_tablero();
			printf("\n\nEs posible volver a saltar. Desea volver a jugar? 1-SI. 2-NO. \n");
			scanf("%d",&n);
			if(n==1){
				//Se vuelven a repetir los pasos de arriba, pero esta vez con coor[0] y coor[1] como las coordenadas iniciales
				Coordenadas_destino(coor[0],coor[1],tablero[coor[0]][coor[1]]);
			}else{
				break;
			}
		}else{		//JUEGA LA COMPUTADORA
			Coordenadas_destino(coor[0],coor[1],tablero[coor[0]][coor[1]]);
		}
	}
	return 1;

}
