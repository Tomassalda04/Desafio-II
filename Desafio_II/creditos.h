#ifndef CREDITOS_H
#define CREDITOS_H
#include "colaborador.h"

class creditos
{

private:
    colaborador* productores;   // Arreglo dinámico de productores
    colaborador* musicos;       // Arreglo dinámico de músicos
    colaborador* compositores;  // Arreglo dinámico de compositores
    int cantProd;
    int cantMus;
    int cantComp;

public:
    creditos();

};

#endif // CREDITOS_H
