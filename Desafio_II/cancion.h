#ifndef CANCION_H
#define CANCION_H

#include "funciones.h"
#include "creditos.h"
using namespace std;

class album;

class cancion {
private:
    string id;
    string nombre;
    string ruta128;
    string ruta320;
    float duracion;
    int reproducciones;
    creditos* infoCreditos;
    album* alb;

public:
    cancion();
    cancion(string id, string nombre, string ruta128, string ruta320, float duracion, int reproducciones = 0, album* alb = nullptr);
    cancion(const cancion& other);
    cancion& operator=(const cancion& other);
    ~cancion();

    // Getters
    string getId() const;
    string getNombre() const;
    string getRuta128() const;
    string getRuta320() const;
    float getDuracion() const;
    int getReproducciones() const;
    album* getAlbum() const;

    // Setters
    void setId(const string& id);
    void setNombre(const string& nombre);
    void setRuta128(const string& ruta);
    void setRuta320(const string& ruta);
    void setDuracion(float dur);
    void setReproducciones(int rep);
    void setAlbum(album* alb);

    // Mostrar
    void mostrarInfo() const;
};

#endif
