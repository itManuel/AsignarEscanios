//============================================================================
// Name        : AsignarEscanios.cpp
// Author      : Manuel Fernando Aller y Mateo Tozzini.
// Version     :
// Copyright   : (c) la rémora del grupo 114
// Description : Sistema D'Hont para asignación de escanios.
//============================================================================


#include <iostream>
#include <fstream>
using namespace std;

struct VotosAgrupacion
{
	int nroLista;
	int votos;
};

struct EscaniosAgrupacion
{
	int nroLista;
	int escanios;
};

struct Nodo
{
	int nroLista;
	int escanios;
	Nodo *sgte;
};


const int MAX_PARTIDOS = 100;
const char* FILENAME = "buenosaires.bin";
const int ESCANIOS = 128;


float calcularEscanios(int votos, int escanios)
{
	return (votos*1.0) / (escanios + 1.0);
}

void RepartirEscanios(VotosAgrupacion partidos[],int cantEscanios, int cantPartidos, EscaniosAgrupacion escanios[])
{
	// aquí estará la magia de asignar escanios
	int max, i, j, maxInd;
	float tablaAux[100];

	for (i=0; i<cantPartidos; i++)
	{
		escanios[i].escanios = 0;
		escanios[i].nroLista = partidos[i].nroLista;
	}

	for (i=0; i<cantPartidos; i++)
	{
		tablaAux[i] = partidos[i].votos;
	}
	for (i=0; i<cantEscanios; i++)
	{
		//encontrar el mayor
		max = -1;
		for (j=0; j<cantPartidos; j++)
		{
			if (max<tablaAux[j])
			{
				max = tablaAux[j];
				maxInd = j;
			}
		}

		//asignar un escanio al partido encontrado
		escanios[maxInd].escanios++;
		//decrementar en la tabla auxiliar para volver a buscar el mayor
		tablaAux[maxInd] = calcularEscanios(partidos[maxInd].votos, escanios[maxInd].escanios);
	}
	return;
}

void PonerEnLista(Nodo *&puntero,EscaniosAgrupacion partidos[], int cantPartidos)
{
	int i;
	for (i=0; i<cantPartidos; i++){
		Nodo *nodo=new Nodo;
		nodo->nroLista=partidos[i].nroLista;
		nodo->escanios=partidos[i].escanios;
		nodo->sgte=puntero;
		puntero=nodo;
	}
}

void Ordenar(int cantPartidos, EscaniosAgrupacion escanios[]) {
	// ORDENAMIENTO
	int miEscanios, miPartido; // Auxiliares
	int i, j;
	for (i = 1; i < cantPartidos; i++) {
		for (j = 0; j <= cantPartidos - 1; j++) {
			if (escanios[j].escanios > escanios[j + 1].escanios) {
				EscaniosAgrupacion tmp = escanios[j];
				escanios[j]=escanios[j+1];
				escanios[j+1]=tmp;
				//miEscanios = escanios[j].escanios;
				//miPartido = escanios[j].nroLista;
				//escanios[j].escanios = escanios[j + 1].escanios;
				//escanios[j].nroLista = escanios[j + 1].nroLista;
				//escanios[j + 1].escanios = miEscanios;
				//escanios[j + 1].nroLista = miPartido;
			}
		}
	}
}

void AsignarEscanios(const char* &filename, const int &cantEscanios, Nodo *&puntero)
{
	/* abro el archivo al principio, cargo los datos en un array y cierro el archivo.
	 *  Trabajamos con los datos en memoria. */
	VotosAgrupacion partidos [MAX_PARTIDOS];

	int cantPartidos = 0;
	FILE* archivo = fopen(filename, "rb");
	fread(&partidos[cantPartidos],sizeof(VotosAgrupacion),1,archivo);
	while(!feof(archivo))
	{
		cantPartidos++;
		fread(&partidos[cantPartidos],sizeof(VotosAgrupacion),1,archivo);
	}

	fclose(archivo);
	EscaniosAgrupacion escanios [cantPartidos];
	RepartirEscanios(partidos, cantEscanios, cantPartidos, escanios);


	// ORDENAMIENTO
	Ordenar(cantPartidos, escanios);
	PonerEnLista(puntero, escanios, cantPartidos);

}


int main ()
{
	/* main super básico para probar la función */
	//	escanios = AsignarEscanios("capital.bin",50);
	// escanios = AsignarEscanios(FILENAME, ESCANIOS);
	Nodo*puntero;
	AsignarEscanios(FILENAME, ESCANIOS, puntero);

	while(puntero!=NULL)
	{
		cout<<"Lista: "<<puntero->nroLista<<"   escanios: "<<puntero->escanios<<endl;
		puntero=puntero->sgte;
	}


	return 0;
}
