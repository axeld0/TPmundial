#include "listasEquipos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 8

nodoEquipo * inicListaEquipo ()
{
    return NULL;
}

nodoGrupoEquipo * inicListaGrupoEquipo()
{
    return NULL;
}

void agregarEquipo()
{

    Equipo aux;

    FILE * fp = fopen ("ArchivoEquipos.bin", "wb");
    char continuar;
    char nombreEquipo [20];

    do
    {
        printf ("ingrese nombre equipo : \t");
        fflush (stdin);
        gets(&nombreEquipo);

        strcpy(aux.nomEquipo, nombreEquipo);
        aux.ga = 0;
        aux.gf = 0;
        aux.loss = 0;
        aux.mp = 0;
        aux.win = 0;

        fwrite(&aux, sizeof(Equipo), 1, fp);
        printf("desea agregar otro equipo?");
        fflush(stdin);
        scanf("%c", &continuar);

    }
    while (continuar == 's' || continuar == 'S');

    fclose(fp);
}

void verEquipos ()
{
    FILE * fp = fopen("ArchivoEquipos.bin", "rb");

    Equipo aux;

    while (fread(&aux, sizeof(Equipo), 1, fp)> 0)
    {
        visualizarEquipos(aux);
    }
    fclose(fp);
}


void verEquiposLista (nodoEquipo * listaEquipos)
{
    if(listaEquipos)
    {

        while(listaEquipos)
        {
            visualizarEquiposLista(listaEquipos);
            listaEquipos = listaEquipos->siguiente;
        }
    }
}

void visualizarEquiposLista (nodoEquipo * seg)
{
    printf("\n==========================\n");
    printf("\n=========EQUIPO===========\n");
    printf("NOMBRE : %s\n", seg->equipo.nomEquipo);
    printf("PARTIDOS JUGADOS : %i\n", seg->equipo.mp);
    printf("GOLES A FAVOR : %i\n", seg->equipo.gf);
    printf("GOLES EN CONTRA : %i\n", seg->equipo.ga);
    printf("PARTIDOS GANADOS : %i\n", seg->equipo.win);
    printf("PARTIDOS PERDIDOS : %i\n", seg->equipo.loss);
    printf("\n==========================\n");

}
void visualizarEquipos(Equipo aux)
{
    printf("\n==========================\n");
    printf("\n=========EQUIPO===========\n");
    printf("NOMBRE : %s\n", aux.nomEquipo);
    printf("PARTIDOS JUGADOS : %i\n", aux.mp);
    printf("GOLES A FAVOR : %i\n", aux.gf);
    printf("GOLES EN CONTRA : %s\n", aux.ga);
    printf("PARTIDOS GANADOS : %s\n", aux.win);
    printf("PARTIDOS PERDIDOS : %s\n", aux.loss);
    printf("\n==========================\n");

}

void traerListaDeEquiposDesdeArchivos (nodoEquipo ** listaEquipos)
{
    Equipo aux;

    FILE * fp = fopen("ArchivoEquipos.bin", "rb");
    while (fread(&aux, sizeof(Equipo), 1, fp)> 0)
    {
        cargarListaEquipos (&(*listaEquipos), aux);

    }

    fclose(fp);
}

void cargarListaEquipos (nodoEquipo ** listaEquipos, Equipo aux)
{
    nodoEquipo * nuevoNodoEquipo = crearNodoEquipo(aux);

    if(!(*listaEquipos))
    {
        *listaEquipos = nuevoNodoEquipo;
    }
    else
    {
        nodoEquipo * seg = *listaEquipos;
        while(seg->siguiente)
        {
            seg = seg->siguiente;
        }
        seg->siguiente = nuevoNodoEquipo;
    }

}

nodoEquipo * crearNodoEquipo (Equipo aux)
{
    nodoEquipo * nuevoNodoEquipo = (nodoEquipo *)malloc(sizeof(nodoEquipo));

    nuevoNodoEquipo->equipo.ga = aux.ga;
    nuevoNodoEquipo->equipo.gf = aux.gf;
    nuevoNodoEquipo->equipo.loss = aux.loss;
    nuevoNodoEquipo->equipo.mp = aux.mp;
    nuevoNodoEquipo->equipo.win = aux.win;
    strcpy(nuevoNodoEquipo->equipo.nomEquipo, aux.nomEquipo);
    nuevoNodoEquipo->siguiente = NULL;

    return nuevoNodoEquipo;
}

void cargarArregloDeListas (Grupo arrayGrupos [], nodoEquipo * listaEquipos)
{
    arrayGrupos[0].letra = 'A';
    arrayGrupos[0].equipos = NULL;

    arrayGrupos[1].letra = 'B';
    arrayGrupos[1].equipos = NULL;

    arrayGrupos[2].letra = 'C';
    arrayGrupos[2].equipos = NULL;

    arrayGrupos[3].letra = 'D';
    arrayGrupos[3].equipos = NULL;

    arrayGrupos[4].letra = 'E';
    arrayGrupos[4].equipos = NULL;

    arrayGrupos[5].letra = 'F';
    arrayGrupos[5].equipos = NULL;

    arrayGrupos[6].letra = 'G';
    arrayGrupos[6].equipos = NULL;

    arrayGrupos[7].letra = 'H';
    arrayGrupos[7].equipos = NULL;

    for(int i = 0; i < 8 ; i++)
    {
        int j = 0;

        while(j < 4)
        {
            insertarGrupoDeEquipos(&(listaEquipos->equipo), &(arrayGrupos[i].equipos));
            j++;
            listaEquipos = listaEquipos->siguiente;
        }
    }

}

Grupo crearGrupo (Grupo arrayGrupos[TAM_MAX])
{
    Grupo nuevoGrupo;
    nuevoGrupo.letra =  arrayGrupos[TAM_MAX].letra;
    nuevoGrupo.equipos = NULL;

    return nuevoGrupo;
}

void insertarGrupoDeEquipos (Equipo * punteroEquipo, nodoGrupoEquipo ** listaGrupo)
{
    nodoGrupoEquipo * nuevoNodoGrupo = crearNodoGrupoEquipo(punteroEquipo);

    nodoGrupoEquipo * seg;

    if(*listaGrupo == NULL)
    {
        *listaGrupo = nuevoNodoGrupo;
    }
    else
    {
        seg = *listaGrupo;
        while(seg->siguiente)
        {
            seg = seg->siguiente;
        }
        seg->siguiente = nuevoNodoGrupo;
    }
}

void mostrarGrupos (Grupo arrayGrupos [])
{
    for (int i = 0 ; i < 8 ; i++)
    {
        printf("GRUPO %c:\n", arrayGrupos[i].letra);
        mostrarEquiposGrupo (arrayGrupos[i].equipos);
        printf("\n");
    }
}

void mostrarEquiposGrupo (nodoGrupoEquipo * listaGrupo)
{
    if (listaGrupo)
    {
        while (listaGrupo)
        {
            printf("\t");
            puts(listaGrupo->equipo->nomEquipo);
            listaGrupo = listaGrupo->siguiente;
        }
        printf("\n");
    }
}

nodoGrupoEquipo * crearNodoGrupoEquipo(Equipo * equipo)
{
    nodoGrupoEquipo * nuevoNodoGrupo = (nodoGrupoEquipo*)malloc(sizeof(nodoGrupoEquipo));
    nuevoNodoGrupo->siguiente = NULL;
    nuevoNodoGrupo->equipo = equipo;

    return nuevoNodoGrupo;
}
