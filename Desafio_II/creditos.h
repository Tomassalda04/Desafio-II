#ifndef CREDITOS_H
#define CREDITOS_H

#include "colaborador.h"

class creditos {
private:
    colaborador* productores;
    colaborador* musicos;
    colaborador* compositores;
    int cantProd, cantMus, cantComp;

public:
    creditos();  // Constructor por defecto
    creditos(colaborador* prod, int nProd,
             colaborador* mus, int nMus,
             colaborador* comp, int nComp);  // Constructor con parámetros

    creditos(const creditos& other);          // Constructor de copia
    creditos& operator=(const creditos& other); // Asignación
    ~creditos();                              // Destructor

    void setProductores(colaborador* p, int n);
    void setMusicos(colaborador* m, int n);
    void setCompositores(colaborador* c, int n);

    void setCantProd(int n);
    void setCantMus(int n);
    void setCantComp(int n);

    colaborador* getProductores() const;
    colaborador* getMusicos() const;
    colaborador* getCompositores() const;

    int getCantProd() const;
    int getCantMus() const;
    int getCantComp() const;

    void mostrar() const; // 👈 Faltaba esta
};

#endif // CREDITOS_H

