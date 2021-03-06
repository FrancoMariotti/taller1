#ifndef BOULEVARD_H_
#define BOULEVARD_H_

#include <list>
#include "Elemento.h"
#include "Poligono.h"

class Boulevard: public Poligono {
public:
	explicit Boulevard(const std::list<Coordenada>& coordenadas);
	bool superficieEdificada();
	bool superficieArbolada();
	const char caracter();
	size_t nivel();
};

#endif /* BOULEVARD_H_ */
