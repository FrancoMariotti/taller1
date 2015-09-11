
#include <iostream>
#include <stdlib.h>
#include <sstream>

#include "Conector.h"
#include "ClientProxy.h"

using namespace std;
#define ARGUMENTOS_CONECTOR 5
#define ARGUMENTOS_SERVIDOR 2

void cliente(char *argv[]){
	std::string ip = argv[1];
	std::string puerto = argv[2];
	std::string nombreSeccion = argv[3];
	int cantidadMuestras = atoi(argv[4]);

	ServerProxy server(ip, puerto);
	server.informarSeccion(nombreSeccion);

	std::string str = "";
	Conector conector(cantidadMuestras, &server);
	while(getline(cin, str)) {
		Medicion medicion(str);
		conector.tomarMedicion(medicion);
	}
}

void servidorSocketPrueba(char *argv[]){
	Socket socket("127.0.0.1", argv[1], AI_PASSIVE);

	/* Asocio el socket al puerto pasado por parametro */
	socket.bindSocket();
	/* Indico que el socket estara escuchando conexiones */
	socket.listenSocket();
	while (true){
		std::cout << "escuchando conexiones... \n";
		Socket *nuevaConexion = socket.aceptar();
		std::cout << "nuevo cliente!\n";
		std::string mensajeRecibido = nuevaConexion->recibir();
		std::cout << "mensaje leido\n";
		delete nuevaConexion;
		std::cout << "RECIBIDO: " << mensajeRecibido << std::endl;
		if (mensajeRecibido.compare("finish") == 0){
			break;
		}
	}
}

void servidor(char *argv[]){
	ClientProxy proxy(argv[1]);
	proxy.escucharConexiones();
}

int main(int argc, char *argv[]) {

	if ((argc != ARGUMENTOS_CONECTOR) && (argc !=ARGUMENTOS_SERVIDOR)){
		cout << "INVALIDO\n";
		return 1;
	}
	if (argc == ARGUMENTOS_CONECTOR){
		cliente(argv);
	} else {
		servidor(argv);
	}
	return 0;
}
