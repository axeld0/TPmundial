#ifndef PARTIDOS_H_INCLUDED
#define PARTIDOS_H_INCLUDED
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "listasEquipos.h"


typedef struct
{
    char id[5]; ///opcional
    char fecha [10]; /// (DD/MM)
    Equipo* equipo1;
    Equipo* equipo2;
    int golesEq1;
    int golesEq2;
    int penales1; ///en la fase de grupos no hay penales
    int penales2; ///pueden setearlo en 1 y 0 (como un boolean)
} Partido;

typedef struct
{
    Partido partido;
    struct nodoPartido* siguiente;
} nodoPartido;


typedef struct
{
    char letra;
    nodoPartido* partidos;
} GrupoPartido;

typedef struct
{
    int idFase;
    nodoPartido* partidos;
} fase;

typedef struct
{
    float probEquipo1;
    float probEquipo2;

} probabilidad;

typedef struct
{
    char fecha[10];
    int fase;
    char grupo[5];  ///A1 , B3 , C6

} partidoArchivo;


void cargarArchivoFaseDeGrupos ();
nodoPartido * inicListaPartidos ();
void verPartidos();
void cargarArchivoPlayoffs();
void verPartidosPlayoffs();
void traerListaDePartidosDesdeArchivo (nodoPartido ** listaPartidos);
void cargarListaPartidos (nodoPartido ** listaPartidos, partidoArchivo aux);
nodoPartido * crearNodoPartido (partidoArchivo aux);
void cargarArrayDePartidos (GrupoPartido PartidosGrupos[], nodoPartido * listaPartidos, Grupo arrayGrupos[]);
void insertarGrupoPartidos(nodoPartido * listaPartidos , nodoPartido ** partidosDelGrupo, nodoGrupoEquipo * listaGrupos, int j);
void mostrarGruposPartidos (GrupoPartido PartidosGrupos[]);
void mostrarPartidosGrupo (nodoPartido  * partidos );
nodoPartido * crearPartidoGrupo (nodoPartido * listaPartidos);
void sortearEquipos (nodoPartido * nuevoPartido,nodoGrupoEquipo * listaGrupo );
void  sortearEquipos2 (nodoPartido * nuevoPartido,nodoGrupoEquipo * listaGrupo, int contador );

#endif // PARTIDOS_H_INCLUDED


