#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class usuario;
class artista;
class publicidad;

void cargarUsuarios(usuario*& usuarios, int& numUsuarios);

void cargarArtistas(artista*& artistas, int& numArtistas);

void cargarPublicidad(publicidad*& mensajes, int& numMensajes);

void guardarUsuarios(usuario* usuarios, int numUsuarios);

void agregarUsuario(usuario*& usuarios,int &numUsuarios);

#endif // FUNCIONES_H
