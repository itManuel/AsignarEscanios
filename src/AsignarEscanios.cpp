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

namespace
{

const int MAX_PARTIDOS = 100;
const char* FILENAME = "buenosaires.bin";
const int ESCANIOS = 128;
EscaniosAgrupacion escanios [MAX_PARTIDOS];

}

void RepartirEscanios(VotosAgrupacion partidos,int cantEscanios, int cantPartidos, EscaniosAgrupacion escanios)
{
	// aquí estará la magia de asignar escanios

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


Nodo* AsignarEscanios(const char* &filename, const int &cantEscanios)
{
	/* abro el archivo al principio, cargo los datos en un array y cierro el archivo.
	 *  Trabajamos con los datos en memoria. */
	VotosAgrupacion partidos [MAX_PARTIDOS];
	Nodo*puntero;
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
	//RepartirEscanios(partidos, cantEscanios, cantPartidos, escanios);
	PonerEnLista(puntero, escanios, cantPartidos);
	return puntero;
}


int main ()
{
	/* main super básico para probar la función */
	//	escanios = AsignarEscanios("capital.bin",50);
	// escanios = AsignarEscanios(FILENAME, ESCANIOS);
	Nodo*puntero;
	puntero = AsignarEscanios(FILENAME, ESCANIOS);

	while(puntero!=NULL)
	{
		cout<<"Lista: "<<puntero->nroLista<<"   escanios: "<<puntero->escanios<<endl;
		puntero=puntero->sgte;
	}

	return 0;
}
