#ifndef COLABORADOR_H
#define COLABORADOR_H
#include "funciones.h"

class colaborador
{
private:
    string nombre;
    string apellido;
    string codigoAfiliacion;

public:
    colaborador();
    colaborador(const string& codigo, const string& nombre, const string& apellido);

    string getNombre() const;
    string getApellido() const;
    string getCodigoAfiliacion() const;

    void setNombre(const string& n);
    void setApellido(const string& a);
    void setCodigoAfiliacion(const string& c);
};

#endif // COLABORADOR_H
