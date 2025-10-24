#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H

#include "funciones.h"

class publicidad {

private:
    string texto;
    char categoria;

public:
    publicidad();
    publicidad(string texto, char categoria);

    string getTexto() const;
    char getCategoria() const;

    void setTexto(const string& nuevoTexto);
    void setCategoria(char nuevaCategoria);

    void mostrar() const;
};

#endif // PUBLICIDAD_H

