#ifndef CREDITOS_H
#define CREDITOS_H
#include "colaborador.h"

class creditos
{

private:
    colaborador *productores;   // Arreglo dinámico de productores asociados a la canción
    colaborador *musicos;       // Arreglo dinámico de músicos que participaron en la canción
    colaborador *compositores;  // Arreglo dinámico de compositores de la canción
    int cantProd, cantMus, cantComp; // Contadores de cada tipo de colaborador

public:
    creditos();
};

#endif // CREDITOS_H
