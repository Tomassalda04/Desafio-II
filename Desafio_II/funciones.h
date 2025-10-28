#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


class usuario;
class artista;
class album;
class cancion;
class publicidad;
class colaborador;
class creditos;

void cargarUsuarios(usuario*& usuarios, int& numUsuarios);
void agregarUsuario(usuario*& usuarios, int& numUsuarios);
void guardarUsuarios(usuario* usuarios, int numUsuarios);
void cargarArtistas(artista*& artistas, int& numArtistas);
void cargarAlbums(album*& albums, int& numAlbums, artista* artistas, int numArtistas);
void cargarCanciones(cancion*& canciones, int& numCanciones, album* albums, int numAlbums);
void cargarPublicidad(publicidad*& mensajes, int& numMensajes);
void cargarColaboradores(colaborador*& lista, int& numColab);
void cargarCreditos(creditos*& listaCreditos, int& numCreditos, colaborador* colaboradores, int numColab);
colaborador* buscarColaboradorPorCodigo(colaborador* lista, int numColab, const string& codigo);
// en funciones.h (prototipos actualizados)
void menuUsuarioPremium(usuario* u, usuario* usuarios, int numUsuarios,
                        cancion* canciones, int numCanciones,
                        int numArtistas, int numAlbums, int numMensajes);

void menuUsuarioEstandar(usuario* u, cancion* canciones, int numCanciones,
                         publicidad* anuncios, int numAnuncios,
                         int numArtistas, int numAlbums, int numMensajes);

void cargarFavoritos(usuario* usuarios, int numUsuarios, cancion* canciones, int numCanciones, const string& filename);
void guardarFavoritos(usuario* usuarios, int numUsuarios, const string& filename);
void cargarSeguidos(usuario* usuarios, int numUsuarios, const string& filename);
void guardarSeguidos(usuario* usuarios, int numUsuarios, const string& filename);
void medirConsumoRecursos(const string& nombreFuncionalidad, int iteraciones,int numUsuarios, int numArtistas, int numAlbums, int numCanciones, int numMensajes);

#endif
