#ifndef CREDITOS_H
#define CREDITOS_H
#include "colaborador.h"

class creditos
{

private:
    colaborador *productores;
    colaborador *musicos;
    colaborador *compositores;
    int cantProd, cantMus, cantComp;

public:
    creditos();
};

#endif // CREDITOS_H
