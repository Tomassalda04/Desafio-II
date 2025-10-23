#include "publicidad.h"
#include <iostream>
using namespace std;

publicidad::publicidad() {
    texto = "";
    categoria = 'C';
}

publicidad::publicidad(string texto, char categoria) {
    this->texto = texto;
    this->categoria = categoria;
}

string publicidad::getTexto() const { return texto; }
char publicidad::getCategoria() const { return categoria; }

void publicidad::setTexto(const string& nuevoTexto) { texto = nuevoTexto; }
void publicidad::setCategoria(char nuevaCategoria) { categoria = nuevaCategoria; }

void publicidad::mostrar() const {
    cout << "[" << categoria << "] " << texto << endl;
}

