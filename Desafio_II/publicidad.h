#ifndef PUBLICIDAD_H
#define PUBLICIDAD_H

#include "funciones.h"
using namespace std;

class publicidad {
private:
    string texto;
    char categoria;

public:
    publicidad();
    publicidad(string texto, char categoria);

    // Getters
    string getTexto() const;
    char getCategoria() const;

    // Setters
    void setTexto(const string& nuevoTexto);
    void setCategoria(char nuevaCategoria);

    void mostrar() const;
};

#endif
