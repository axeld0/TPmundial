#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partidos.h"
#include "listasEquipos.h"


nodoPartido * inicListaPartidos ()
{
    return NULL;
}

void cargarArchivoFaseDeGrupos ()
{
    char fechaPartido[10];
    int fasePartido;
    char grupoPartidoAux[5];
    char continuar;
    partidoArchivo aux;


    FILE * fp = fopen ("ArchivoPartidosGrupos.bin", "ab");
    if(fp)
    {
        do
        {
            printf ("ingrese grupo y numero de partido ");
            fflush(stdin);
            gets(&grupoPartidoAux);
            printf ("ingrese fecha del partido (DD/MM)");
            fflush(stdin);
            gets(&fechaPartido);
            printf("ingrese fase partido");
            scanf ("%i", &fasePartido);


            strcpy(aux.fecha, fechaPartido);
            aux.fase = fasePartido;
            strcpy(aux.grupo, grupoPartidoAux);

            fwrite(&aux, sizeof(partidoArchivo), 1, fp);

            printf("desea continuar?");
            fflush(stdin);
            scanf("%c", &continuar);

        }while (continuar == 's' || continuar == 'S');
    }
    fclose(fp);
}

verPartidos()
{
    FILE * fp = fopen ("ArchivoPartidosGrupos.bin", "rb");

    partidoArchivo aux2;
    if(fp)
    {
        while (fread(&aux2,sizeof(partidoArchivo), 1, fp) > 0)
        {
        printf("%s\n", aux2.fecha);
        puts(aux2.grupo);
        printf("FASE %i", aux2.fase);
        printf("\n\n");
        }
    }
    fclose(fp);
}

void cargarArchivoPlayoffs()
{
    char fechaPartido[10];
    int fasePartido;
    char grupoPartidoAux[5];
    char continuar;
    partidoArchivo aux;


    FILE * fp = fopen ("ArchivoPartidosPlayoffs.bin", "ab");
    if(fp)
    {
        do
        {
            printf ("ingrese grupo y numero de partido PLAYOFFS");
            fflush(stdin);
            gets(&grupoPartidoAux);
            printf ("ingrese fecha del partido (DD/MM)");
            fflush(stdin);
            gets(&fechaPartido);
            printf("ingrese fase partido");
            scanf ("%i", &fasePartido);


            strcpy(aux.fecha, fechaPartido);
            aux.fase = fasePartido;
            strcpy(aux.grupo, grupoPartidoAux);

            fwrite(&aux, sizeof(partidoArchivo), 1, fp);

            printf("desea continuar?");
            fflush(stdin);
            scanf("%c", &continuar);

        }while (continuar == 's' || continuar == 'S');
    }
    fclose(fp);
}

void verPartidosPlayoffs()
{
    FILE * fp = fopen ("ArchivoPartidosPlayoffs.bin" , "rb");

    partidoArchivo aux2;
    if(fp)
    {
        while (fread(&aux2,sizeof(partidoArchivo), 1, fp) > 0)
        {
        printf("%s\n", aux2.fecha);
        puts(aux2.grupo);
        printf("FASE %i", aux2.fase);
        printf("\n\n");
        }
    }
    fclose(fp);
}


void traerListaDePartidosDesdeArchivo (nodoPartido ** listaPartidos)
{
    partidoArchivo aux;

    FILE * fp = fopen("ArchivoPartidosGrupos.bin", "rb");
    while (fread(&aux, sizeof(partidoArchivo), 1, fp)> 0)
    {
        cargarListaPartidos (&(*listaPartidos), aux);
    }

    fclose(fp);
}

void cargarListaPartidos (nodoEquipo ** listaPartidos, partidoArchivo aux)
{
    nodoPartido * nuevoNodoPartido = crearNodoPartido(aux);

    if(!(*listaPartidos))
    {
        *listaPartidos = nuevoNodoPartido;
    }
    else
    {
        nodoPartido * seg = *listaPartidos;
        while(seg->siguiente)
        {
            seg = seg->siguiente;
        }
        seg->siguiente = nuevoNodoPartido;
    }
}

nodoPartido * crearNodoPartido (partidoArchivo aux)
{
    nodoPartido * nuevoNodoPartido = (nodoPartido *)malloc(sizeof(nodoPartido));

    strcpy(nuevoNodoPartido->partido.fecha,aux.fecha);
    nuevoNodoPartido->partido.id = aux.grupo;

    nuevoNodoPartido->partido.equipo1 = NULL;
    nuevoNodoPartido->partido.equipo2 = NULL;

    nuevoNodoPartido->siguiente = NULL;
    nuevoNodoPartido->partido.golesEq1 = 0;
    nuevoNodoPartido->partido.equipo2 = 0;
    nuevoNodoPartido->partido.penales1 = 0;
    nuevoNodoPartido->partido.penales2 = 0;


    return nuevoNodoEquipo;
}

void cargarArrayDePartidos (GrupoPartido PartidosGrupos[], nodoPartido * listaPartidos)
{
    inicListasArrayPartidos (PartidosGrupos);

    for(int i = 0; i < 8 ; i++)
    {
        int j = 0;

        while(j < 6)
        {
            insertarGrupoPartidos(&(listaPartidos->partido), &(listaEquipos->equipo));
            j++;
            listaPartidos = listaPartidos>siguiente;
        }
    }


}

void insertarGrupoPartidos(Partdido * punteroPartido, Equipo * punteroEquipo)
{
    nodoPartido * nuevoNodoPartido = crearNodoGrupoEquipo(punteroEquipo);

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


void inicListasArrayPartidos (GrupoPartido PartidosGrupos[])
{
    PartidosGrupos[0].letra = 'A';
    PartidosGrupos[0].partidos = NULL;

      PartidosGrupos[1].letra = 'B';
    PartidosGrupos[1].partidos = NULL;

      PartidosGrupos[2].letra = 'C';
    PartidosGrupos[2].partidos = NULL;

      PartidosGrupos[3].letra = 'D';
    PartidosGrupos[3].partidos = NULL;

      PartidosGrupos[4].letra = 'E';
    PartidosGrupos[4].partidos = NULL;

      PartidosGrupos[5].letra = 'F';
    PartidosGrupos[5].partidos = NULL;

      PartidosGrupos[6].letra = 'G';
    PartidosGrupos[6].partidos = NULL;

      PartidosGrupos[7].letra = 'H';
    PartidosGrupos[7].partidos = NULL;
}
