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

        }
        while (continuar == 's' || continuar == 'S');
    }
    fclose(fp);
}

void verPartidos()
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

        }
        while (continuar == 's' || continuar == 'S');
    }
    fclose(fp);
}

void verPartidosPlayoffs()
{
    FILE * fp = fopen ("ArchivoPartidosPlayoffs.bin", "rb");

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

void cargarListaPartidos (nodoPartido ** listaPartidos, partidoArchivo aux)
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
    nodoPartido * nuevoNodoPartido = (nodoPartido*)malloc(sizeof(nodoPartido));

    strcpy(nuevoNodoPartido->partido.fecha,aux.fecha);
    strcpy(nuevoNodoPartido->partido.id, aux.grupo);

    nuevoNodoPartido->partido.equipo1 = NULL;
    nuevoNodoPartido->partido.equipo2 = NULL;

    nuevoNodoPartido->siguiente = NULL;
    nuevoNodoPartido->partido.golesEq1 = 0;
    nuevoNodoPartido->partido.equipo2 = 0;
    nuevoNodoPartido->partido.penales1 = 0;
    nuevoNodoPartido->partido.penales2 = 0;


    return nuevoNodoPartido;
}

void cargarArrayDePartidos (GrupoPartido PartidosGrupos[], nodoPartido * listaPartidos, Grupo arrayGrupos[])
{
    inicListasArrayPartidos(PartidosGrupos);

    for(int i = 0; i < 8 ; i++)
    {
        int j = 0;
        while(j < 6)
        {
            insertarGrupoPartidos(listaPartidos, &(PartidosGrupos[i].partidos), arrayGrupos[i].equipos, j );
            j++;
            listaPartidos = listaPartidos->siguiente;
        }

    }
}

void insertarGrupoPartidos(nodoPartido * listaPartidos, nodoPartido ** partidosDelGrupo, nodoGrupoEquipo * listaGrupo, int j)
{
    nodoPartido * nuevoPartido = crearPartidoGrupo(listaPartidos);
    nodoPartido  * seg;

    if(*partidosDelGrupo == NULL)
    {
        *partidosDelGrupo = nuevoPartido;
        sortearEquipos (nuevoPartido,listaGrupo);
    }
    else
    {
        seg = *partidosDelGrupo;
        while(seg->siguiente)
        {
            seg = seg->siguiente;
        }
        sortearEquipos2(nuevoPartido, listaGrupo, j);
        seg->siguiente = nuevoPartido;
    }
}

nodoPartido * crearPartidoGrupo (nodoPartido * listaPartidos)
{
    nodoPartido * nuevo = (nodoPartido*)malloc(sizeof(nodoPartido));
    strcpy(nuevo->partido.id,listaPartidos->partido.id);
    strcpy(nuevo->partido.fecha, listaPartidos->partido.fecha);
    nuevo->partido.golesEq1 = listaPartidos->partido.golesEq1;
    nuevo->partido.golesEq2 = listaPartidos->partido.golesEq2;
    nuevo->partido.equipo1 = NULL;
    nuevo->partido.equipo2 = NULL;
    nuevo->siguiente = NULL;
}

void sortearEquipos (nodoPartido * nuevoPartido,nodoGrupoEquipo * listaGrupo )
{
    nuevoPartido->partido.equipo1 = listaGrupo->equipo;
    listaGrupo = listaGrupo->siguiente;
    nuevoPartido->partido.equipo2 = listaGrupo->equipo;

}

void  sortearEquipos2 (nodoPartido * nuevoPartido,nodoGrupoEquipo * listaGrupo, int contador)
{

    if(contador == 1) /// segundo contra tercero
    {
        listaGrupo = listaGrupo->siguiente;
        nuevoPartido->partido.equipo1 = listaGrupo->equipo;
        listaGrupo= listaGrupo->siguiente;
        nuevoPartido->partido.equipo2 = listaGrupo->equipo;
    }
    else if (contador == 2) /// segundo contra el cuarto
    {
        listaGrupo = listaGrupo->siguiente;
        nuevoPartido->partido.equipo1 = listaGrupo->equipo;
        listaGrupo = listaGrupo->siguiente;
        listaGrupo = listaGrupo->siguiente;
        nuevoPartido->partido.equipo2 = listaGrupo->equipo;
    }
    else if (contador == 3) ///partido 4 : primero contra el tercero
    {
        nuevoPartido->partido.equipo1 = listaGrupo->equipo;
        listaGrupo = listaGrupo->siguiente;
        listaGrupo = listaGrupo->siguiente;
        nuevoPartido->partido.equipo2 = listaGrupo->equipo;

    }
    else if ( contador == 4)///partido 5 : primero contra el cuarto
    {
        nuevoPartido->partido.equipo1 = listaGrupo->equipo;
        listaGrupo = listaGrupo->siguiente;
        listaGrupo = listaGrupo->siguiente;
        listaGrupo = listaGrupo->siguiente;
        nuevoPartido->partido.equipo2 = listaGrupo->equipo;
    }
    else if (contador == 5) ///partido 6 : tercero contra el cuarto
    {
        listaGrupo = listaGrupo->siguiente;
        listaGrupo = listaGrupo->siguiente;
        nuevoPartido->partido.equipo1 = listaGrupo->equipo;
        listaGrupo = listaGrupo->siguiente;
        nuevoPartido->partido.equipo2 = listaGrupo->equipo;
    }

    return nuevoPartido;
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

void mostrarGruposPartidos (GrupoPartido PartidosGrupos[])
{
    for (int i = 0 ; i < 8 ; i++)
    {
        printf("\n=======================================\n");
        printf("=======================================\n");
        printf("GRUPO %c:\n", PartidosGrupos[i].letra);
        mostrarPartidosGrupo (PartidosGrupos[i].partidos);
        printf("\n=======================================\n");
        printf("=======================================\n");
        printf("\n");
    }
}

void mostrarPartidosGrupo (nodoPartido * partidos)
{
    if (partidos)
    {
        nodoPartido * seg = partidos;
        while (seg)
        {
            printf("------------------------------------\n");
            puts(seg->partido.fecha);
            puts(seg->partido.id);
            puts(seg->partido.equipo1);
            printf("vs\n");
            puts(seg->partido.equipo2);
            seg = seg->siguiente;

        }
    }
}
