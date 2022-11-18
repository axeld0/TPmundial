#ifndef PARTIDOS_H_INCLUDED
#define PARTIDOS_H_INCLUDED
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "listasEquipos.h"


typedef struct
{
    int id; ///opcional
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


#endif // PARTIDOS_H_INCLUDED


