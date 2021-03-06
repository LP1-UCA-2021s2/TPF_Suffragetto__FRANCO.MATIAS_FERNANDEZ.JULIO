/*Declaracion de Funciones utiles para el proyecto */

#ifndef FUNCIONES_SUFFRAG_H_
#define FUNCIONES_SUFFRAG_H_



/*Variable para determinar el turno.
 * turno = 1 le pertenece a la computadora siempre(no significa que la computadora sea la primera a jugar).
 * turno = 2 le pertenece al usuario(el 2 no quiere decir que el usuario no empiece, dependera de la funcion seleccionar_jugador1). */
int turno;


/*Array que contiene los identificadores del equipo al que el jugador pertenece
 * Este array puede contener solo uno de dos numero posibles: 1 ó 3.
 * 1 representa a los policias y 3 a las suffragettes.
 * bandos[0] pertenece a la computadora
 * bandos[1] pertenece al usuario
 * La variable turno se utiliza como subindice del array bandos en la forma bandos[turno-1].
 * Por ejemplo:
 * si turno = 1 ==> bandos[1-1] = bandos[0]. Luego; juega la computadora... */
int bandos[2];


/*Variable utilizada como bandera/contador para averiguar si existe alguna otra ficha alrededor
 * de una ficha que ha realizado un salto. Esto, junto con la variable cont se usa para determinar
 * si es posible ejecutar un segundo o tercer salto*/
int B;


/*Contador/bandera, utilizado junto con la variable B para determinar si una ficha que realizo un
 * salto puede volver a saltar.
 * Se permiten hasta tres saltos, por lo tanto, cont comienza de cero cuando se realiza una jugada
 * y se incrementa si existe la posibilidad de volver a salta. Esta se incrementa hasta tres.*/
int cont;


/*Array auxiliar creado para guardar las coordenadas finales de una ficha que acaba de realizar
 * un salto. Esto es para, en el caso de que se pueda volver a realizar un salto, utilizar dichas
 * coordenadas como las coordenadas iniciales x,y utilizadas en la funcion Coordenadas_destino*/
int coor[2];








void Pausa();

void mensaje_de_bienvenida();

void instrucciones();

void reglas();

int eleccion_bando(int bandos[2]);

int seleccionar_jugador1(int eleccion);

void rev_carcel_hosp(int *num3, int *num4);

int Limitacion_Bases(int x, int y, int pieza);

int limitacion_Suffrag(int x, int y);

int limitacion_Polic(int x, int y);

int limite_movimiento(int x, int y);

int verificar_adyacente(int x, int y, int x2, int y2);

int rotar_jugador(int turno);

void mostrar_turno(int turno);

void fin_del_juego(int num1, int num2, int num3, int num4);

void imprimir_tablero();

int limite_tablero(int x, int y);

void verificar_conquista(int *num1, int *num2);

int verificar_vacia(int x, int y);

int revisar_vecinos(int x, int y);

int verificar_bando(int x, int y, int bando);

int verificar_arena(int x, int y);

void Pieza_Derrotada(int derrotado);

int aux_salto(int x, int y, int x2, int y2);

int Mov_Salto(int x, int y, int x2, int y2, int pieza);

int Movimiento(int x, int y, int x2, int y2, int pieza);

int Coordenadas_destino(int x, int y, int pieza);

int Jugar(int turno, int bando);






#endif
