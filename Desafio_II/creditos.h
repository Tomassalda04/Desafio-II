#ifndef CREDITOS_H
#define CREDITOS_H

class colaborador;
using namespace std;

class creditos {
private:
    colaborador* productores;
    colaborador* musicos;
    colaborador* compositores;
    int cantProd;
    int cantMus;
    int cantComp;

public:
    creditos();
    creditos(colaborador* prod, int nProd, colaborador* mus, int nMus, colaborador* comp, int nComp);
    creditos(const creditos& other);
    creditos& operator=(const creditos& other);
    ~creditos();

    // Setters
    void setProductores(colaborador* p, int n);
    void setMusicos(colaborador* m, int n);
    void setCompositores(colaborador* c, int n);

    // Getters
    colaborador* getProductores() const;
    colaborador* getMusicos() const;
    colaborador* getCompositores() const;
    int getCantProd() const;
    int getCantMus() const;
    int getCantComp() const;

    // Otros
    void mostrar() const;
};

#endif
