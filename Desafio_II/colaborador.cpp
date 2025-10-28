#include "colaborador.h"
using namespace std;

colaborador::colaborador() {
    nombre = "";
    apellido = "";
    codigoAfiliacion = "";
}

colaborador::colaborador(const string& codigo, const string& nombre, const string& apellido) {
    this->codigoAfiliacion = codigo;
    this->nombre = nombre;
    this->apellido = apellido;
}

string colaborador::getNombre() const {
    return nombre;
}

string colaborador::getApellido() const {
    return apellido;
}

string colaborador::getCodigoAfiliacion() const {
    return codigoAfiliacion;
}

void colaborador::setNombre(const string& n) {
    nombre = n;
}

void colaborador::setApellido(const string& a) {
    apellido = a;
}

void colaborador::setCodigoAfiliacion(const string& c) {
    codigoAfiliacion = c;
}
