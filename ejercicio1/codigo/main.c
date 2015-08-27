
#include <stdio.h>
#include "grafo.h"
#include "recorrido.h"

#define CANTIDAD_ARCHIVOS 4

void prueba_grafo(){
	grafo_t grafo_reservado;
	grafo_t *grafo = &grafo_reservado;
	crear_grafo(grafo);
	agregar_relacion(grafo, "A", "B", 100);
	agregar_relacion(grafo, "B", "C", 200);
	agregar_relacion(grafo, "C", "D", 900);
	agregar_relacion(grafo, "D", "E", 400);
	agregar_relacion(grafo, "C", "E", 800);
	destruir_grafo(grafo);
}

void prueba_grafo_archivo(const char *nombre_archivo){
	grafo_t grafo_reservado;
	grafo_t *grafo = &grafo_reservado;
	crear_grafo(grafo);
	armar_grafo_archivo(grafo, nombre_archivo);
	destruir_grafo(grafo);
}

void prueba_recorrido(const char *archivo){
	recorrido_t recorrido_reservado;
	recorrido_t *recorrido = &recorrido_reservado;
	crear_recorrido(recorrido, archivo);
	destruir_recorrido(recorrido);
}


int main(int argc, char *argv[]){
	/*if (argc != CANTIDAD_ARCHIVOS){
		printf("Error, cantidad de archivos invalida\n");
		return 1;
	}
	*/
	prueba_grafo();
	prueba_grafo_archivo(argv[2]);
	prueba_recorrido(argv[3]);
	return 0;
}


