#ifndef COLABORADOR_H
#define COLABORADOR_H
#include "funciones.h"

class colaborador
{

private:
    string nombre;            // Nombre del colaborador (productor, músico o compositor)
    string apellido;          // Apellido del colaborador
    string codigoAfiliacion;  // Código único (alfanumérico) que identifica al colaborador

public:
    colaborador();
};

#endif // COLABORADOR_H
