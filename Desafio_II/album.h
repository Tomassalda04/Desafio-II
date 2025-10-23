#ifndef ALBUM_H
#define ALBUM_H

#include "funciones.h"

class artista;
class cancion;

class album {

private:
    string id;
    string nombre;
    string sello;
    string fecha;
    string genero[4];
    int puntuacion;
    int numCanciones;
    cancion* canciones;
    artista* autor;

public:
    album();
    album(string id, string nombre, string sello, string fecha,
          int puntuacion = 0, int numCanciones = 0, artista* autor = nullptr);

    album(const album& other);
    ~album();

    album& operator=(const album& other);

    string getId() const;
    string getNombre() const;
    string getSello() const;
    string getFecha() const;
    int getPuntuacion() const;
    int getNumCanciones() const;
    artista* getAutor() const;
    cancion* getCanciones() const;

    void setId(const string& id);
    void setNombre(const string& nombre);
    void setSello(const string& sello);
    void setFecha(const string& fecha);
    void setPuntuacion(int puntuacion);
    void setAutor(artista* autor);

    void agregarCancion(const cancion& nueva);
    void mostrarInfo() const;
};

#endif // ALBUM_H

