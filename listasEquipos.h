#ifndef LISTAS_EQUIPOS_H_INCLUDED
#define LISTAS_EQUIPOS_H_INCLUDED
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nomEquipo[40];
    int mp; ///partidos jugados
    int gf;   ///goles a favor
    int ga;  ////goles en contra
    int win;  ///partidos ganados
    int loss;  ////partidos perdidos
} Equipo;

typedef struct
{
    Equipo equipo;
    struct nodoEquipo* siguiente;
} nodoEquipo;

typedef struct
{
    char letra; ///'A','B'....
    struct nodoGrupoEquipo* equipos;
} Grupo;

typedef struct
{
    Equipo* equipo;
    struct nodoGrupoEquipo* siguiente;
} nodoGrupoEquipo;


nodoEquipo * inicListaEquipo();
void agregarEquipo();
void visualizarEquipos(Equipo aux);
void verEquipos ();
void traerListaDeEquiposDesdeArchivos (nodoEquipo ** listaEquipos);
void cargarListaEquipos (nodoEquipo ** listaEquipos, Equipo aux);
nodoEquipo * crearNodoEquipo (Equipo aux);
void verEquiposLista (nodoEquipo * listaEquipos);
void visualizarEquiposLista (nodoEquipo * seg);
nodoEquipo * crearNodoEquipo (Equipo aux);
void cargarArregloDeListas (Grupo arrayGrupos [], nodoEquipo * listaEquipos);
void cargarListasAlArray (Grupo arrayGrupos [], nodoEquipo * listaEquipos);
void mostrarGrupos (Grupo arrayGrupos []);
void mostrarEquiposGrupo (nodoGrupoEquipo * listaGrupo);
void insertarGrupoDeEquipos (Equipo * punteroEquipo, nodoGrupoEquipo ** listaGrupo);
nodoGrupoEquipo * crearNodoGrupoEquipo(Equipo * equipo);
Grupo crearGrupo (Grupo arrayGrupos[]);

#endif // LISTAS_EQUIPOS_H_INCLUDED
