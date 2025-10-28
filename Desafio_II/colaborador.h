#ifndef COLABORADOR_H
#define COLABORADOR_H

#include "funciones.h"
using namespace std;

class colaborador {
private:
    string nombre;
    string apellido;
    string codigoAfiliacion;

public:
    colaborador();
    colaborador(const string& codigo, const string& nombre, const string& apellido);

    // Getters
    string getNombre() const;
    string getApellido() const;
    string getCodigoAfiliacion() const;

    // Setters
    void setNombre(const string& n);
    void setApellido(const string& a);
    void setCodigoAfiliacion(const string& c);
};

#endif
