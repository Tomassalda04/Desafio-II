#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class usuario;
class artista;
class album;
class cancion;
class publicidad;
class colaborador;
class creditos;
class reproductor;

void cargarUsuarios(usuario*& usuarios, int& numUsuarios);
void cargarArtistas(artista*& artistas, int& numArtistas);
void cargarAlbums(album*& albums, int& numAlbums, artista* artistas, int numArtistas);
void cargarCanciones(cancion*& canciones, int& numCanciones, album* albums, int numAlbums);
void cargarPublicidad(publicidad*& mensajes, int& numMensajes);
void cargarColaboradores(colaborador*& lista, int& numColab);
void cargarCreditos(creditos*& listaCreditos, int& numCreditos, colaborador* colaboradores, int numColab);

void guardarUsuarios(usuario* usuarios, int numUsuarios);
void guardarFavoritos(usuario* usuarios, int numUsuarios, const string& filename);
void guardarSeguidos(usuario* usuarios, int numUsuarios, const string& filename);
void agregarUsuario(usuario*& usuarios, int& numUsuarios);

void menuUsuarioPremium(usuario* usr, cancion* canciones, int numCanciones);
void menuUsuarioEstandar(usuario* u, publicidad* anuncios, int numAnuncios);

#endif
