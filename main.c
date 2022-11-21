#include <stdio.h>
#include <stdlib.h>
#include "listasEquipos.h"
#include "partidos.h"

#define TAM_MAX 8




int main()
{
    nodoEquipo * listaEquipos = inicListaEquipo();
    Grupo arrayGrupos [TAM_MAX];
    nodoGrupoEquipo * listaGrupo = inicListaGrupoEquipo();
    nodoPartido * listaPartidos = inicListaPartidos();
    GrupoPartido PartidosGrupos[TAM_MAX];

    printf("\n");
    printf("\n");
    printf("\n");
    printf("=================================\n\n");
    printf("======SIMULADOR DE MUNDIAL=======\n");
    printf("\n=================================\n");
    printf("\n");
    printf("\n");
    printf("\n");
    system("pause");
    system("cls");


    printf("\n");
    printf("\n");
    printf("\n");
    printf("=================================\n\n");
    printf("=========LISTA DE EQUIPOS==========\n");
    printf("\n=================================\n");
    system("pause");
    traerListaDeEquiposDesdeArchivos(&listaEquipos);
    verEquiposLista(listaEquipos);
    system("pause");
    system("cls");


    printf("\n");
    printf("\n");
    printf("\n");
    printf("=================================\n\n");
    printf("=============GRUPOS===============\n");
    printf("\n=================================\n");
    system("pause");
    cargarArregloDeListas(&arrayGrupos, listaEquipos);
    mostrarGrupos(arrayGrupos);
    system("pause");
    system("cls");


     printf("\n");
    printf("\n");
    printf("\n");
    printf("=================================\n\n");
    printf("=============PARTIDOS===============\n");
    printf("\n=================================\n");
    system("pause");
    traerListaDePartidosDesdeArchivo(&listaPartidos);
    cargarArrayDePartidos(&PartidosGrupos, listaPartidos, arrayGrupos);
    mostrarGruposPartidos(PartidosGrupos);
    system("pause");
    system("cls");


    return 0;
}



