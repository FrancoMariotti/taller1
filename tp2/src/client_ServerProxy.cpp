#include "client_ServerProxy.h"
#include <sstream>

ServerProxy::ServerProxy(std::string ip, std::string puerto)
	: socket(ip, puerto, 0) {
	this->socket.conectar();
}

ServerProxy::~ServerProxy() {
}

void ServerProxy::informarSeccion(std::string nombreSeccion){
	std::ostringstream builder;
	builder << "conector seccion " << nombreSeccion << std::endl;
	this->socket.enviar(builder.str());
}

void ServerProxy::informarMediciones(unsigned int nivel, unsigned int caudal){
	std::ostringstream builder;
	builder << "actualizar nivel " << nivel << " caudal " << caudal << "\n";
	this->socket.enviar(builder.str());
}

void ServerProxy::finalizar(){
	this->socket.enviar("fin\n");
	this->socket.cerrar();
}

