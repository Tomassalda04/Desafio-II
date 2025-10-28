    #include "usuario.h"
    #include "cancion.h"
    #include <iostream>
    using namespace std;
    usuario::usuario() {
        nickname = "";
        ciudad = "";
        pais = "";
        fechaRegistro = "";
        premium = false;
        favoritos = nullptr;
        numFavoritos = 0;
        siguiendo = nullptr;
    }

    usuario::usuario(string nickname, string ciudad, string pais, string fechaRegistro, bool premium) {
        this->nickname = nickname;
        this->ciudad = ciudad;
        this->pais = pais;
        this->fechaRegistro = fechaRegistro;
        this->premium = premium;
        favoritos = nullptr;
        numFavoritos = 0;
        siguiendo = nullptr;
    }

    usuario::~usuario() {
        delete[] favoritos;
    }

    string usuario::getNickname() const { return nickname; }
    string usuario::getCiudad() const { return ciudad; }
    string usuario::getPais() const { return pais; }
    string usuario::getFechaRegistro() const { return fechaRegistro; }
    bool usuario::getPremium() const { return premium; }

    void usuario::setNickname(string n) { nickname = n; }
    void usuario::setCiudad(string c) { ciudad = c; }
    void usuario::setPais(string p) { pais = p; }
    void usuario::setFechaRegistro(string f) { fechaRegistro = f; }
    void usuario::setPremium(bool act) { premium = act; }

    void usuario::agregarFavorito(cancion* c) {
        if (!c) return;
        cancion* temp = new cancion[numFavoritos + 1];
        for (int i = 0; i < numFavoritos; i++) temp[i] = favoritos[i];
        temp[numFavoritos] = *c;
        delete[] favoritos;
        favoritos = temp;
        numFavoritos++;
        cout << "Cancion agregada a favoritos.\n";
    }

    void usuario::eliminarFavorito(const string& idCancion) {
        if (numFavoritos == 0) {
            cout << "No tienes canciones en favoritos.\n";
            return;
        }

        int idx = -1;
        for (int i = 0; i < numFavoritos; i++) {
            if (favoritos[i].getId() == idCancion) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << "Cancion no encontrada en favoritos.\n";
            return;
        }

        cancion* temp = new cancion[numFavoritos - 1];
        for (int i = 0, j = 0; i < numFavoritos; i++) {
            if (i != idx) temp[j++] = favoritos[i];
        }

        delete[] favoritos;
        favoritos = temp;
        numFavoritos--;
        cout << "Cancion eliminada de favoritos.\n";
    }

    void usuario::mostrarFavoritos() const {
        if (numFavoritos == 0) {
            cout << "No tienes canciones en favoritos.\n";
            return;
        }

        cout << "\n=== FAVORITOS DE " << nickname << " ===\n";
        for (int i = 0; i < numFavoritos; i++) {
            cout << "- " << favoritos[i].getNombre() << " (" << favoritos[i].getId() << ")\n";
        }
    }

    void usuario::seguirUsuario(usuario* otro) {
        if (!otro || !otro->getPremium()) {
            cout << "Solo puedes seguir a usuarios Premium.\n";
            return;
        }
        siguiendo = otro;
        cout << "Ahora sigues a " << otro->getNickname() << ".\n";
    }

    void usuario::mostrarFavoritosSeguido() const {
        if (!siguiendo) {
            cout << "No estas siguiendo a ningun usuario.\n";
            return;
        }
        cout << "\nFavoritos de " << siguiendo->getNickname() << ":\n";
        siguiendo->mostrarFavoritos();
    }


    int usuario::getNumFavoritos() const {
        return numFavoritos;
    }

    cancion* usuario::getFavoritos() const {
        return favoritos;
    }

    usuario* usuario::getSeguido() const {
        return siguiendo;
    }
