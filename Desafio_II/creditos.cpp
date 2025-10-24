#include "creditos.h"
#include <iostream>
using namespace std;

creditos::creditos() {
    productores = nullptr;
    musicos = nullptr;
    compositores = nullptr;
    cantProd = cantMus = cantComp = 0;
}

creditos::creditos(colaborador* prod, int nProd,
                   colaborador* mus, int nMus,
                   colaborador* comp, int nComp) {
    cantProd = nProd;
    cantMus = nMus;
    cantComp = nComp;

    productores = (nProd > 0) ? new colaborador[nProd] : nullptr;
    musicos = (nMus > 0) ? new colaborador[nMus] : nullptr;
    compositores = (nComp > 0) ? new colaborador[nComp] : nullptr;

    for (int i = 0; i < nProd; i++) productores[i] = prod[i];
    for (int i = 0; i < nMus; i++) musicos[i] = mus[i];
    for (int i = 0; i < nComp; i++) compositores[i] = comp[i];
}

creditos::creditos(const creditos& other) {
    cantProd = other.cantProd;
    cantMus = other.cantMus;
    cantComp = other.cantComp;

    productores = (cantProd > 0) ? new colaborador[cantProd] : nullptr;
    musicos = (cantMus > 0) ? new colaborador[cantMus] : nullptr;
    compositores = (cantComp > 0) ? new colaborador[cantComp] : nullptr;

    for (int i = 0; i < cantProd; i++)
        productores[i] = other.productores[i];
    for (int i = 0; i < cantMus; i++)
        musicos[i] = other.musicos[i];
    for (int i = 0; i < cantComp; i++)
        compositores[i] = other.compositores[i];
}

creditos& creditos::operator=(const creditos& other) {
    if (this != &other) {
        delete[] productores;
        delete[] musicos;
        delete[] compositores;

        cantProd = other.cantProd;
        cantMus = other.cantMus;
        cantComp = other.cantComp;

        productores = (cantProd > 0) ? new colaborador[cantProd] : nullptr;
        musicos = (cantMus > 0) ? new colaborador[cantMus] : nullptr;
        compositores = (cantComp > 0) ? new colaborador[cantComp] : nullptr;

        for (int i = 0; i < cantProd; i++)
            productores[i] = other.productores[i];
        for (int i = 0; i < cantMus; i++)
            musicos[i] = other.musicos[i];
        for (int i = 0; i < cantComp; i++)
            compositores[i] = other.compositores[i];
    }
    return *this;
}

creditos::~creditos() {
    delete[] productores;
    delete[] musicos;
    delete[] compositores;
}

int creditos::getCantProd() const { return cantProd; }
int creditos::getCantMus() const { return cantMus; }
int creditos::getCantComp() const { return cantComp; }

colaborador* creditos::getProductores() const { return productores; }
colaborador* creditos::getMusicos() const { return musicos; }
colaborador* creditos::getCompositores() const { return compositores; }

void creditos::mostrar() const {
    cout << "Productores: " << cantProd
         << ", Músicos: " << cantMus
         << ", Compositores: " << cantComp << endl;
}
