//============================================================================
// Name        : AsignarEscanios.cpp
// Author      : Manuel Fernando Aller y Mateo Tozzini.
// Version     :
// Copyright   : (c) la rémora del grupo 114
// Description : Sistema D'Hont para asignación de escanios.
//============================================================================

#include <fstream>


struct VotosAgrupacion {
    int nroLista;
    int votos;
};
struct EscaniosAgrupacion {
    int nroLista;
    int escanios;
};

namespace {

	const int MAX_PARTIDOS = 100;

}

void RepartirEscanios(VotosAgrupacion partidos,int cantEscanios, int cantPartidos, EscaniosAgrupacion escanios){
	// aquí estará la magia de asignar escanios

	return;
}


EscaniosAgrupacion AsignarEscanios(char* filename, int cantEscanios){
	/* abro el archivo al principio, cargo los datos en un array y cierro el archivo.
	 *  Trabajamos con los datos en memoria. */
	VotosAgrupacion partidos [MAX_PARTIDOS];
	int cantPartidos = 0;
	FILE* archivo = fopen(filename, "rb");
	fread(&partidos[cantPartidos],sizeof(VotosAgrupacion),1,archivo);
	while(!feof(archivo)){
		cantPartidos++;
		fread(&partidos[cantPartidos],sizeof(VotosAgrupacion),1,archivo);
	}


	fclose(archivo);
	EscaniosAgrupacion escanios [cantPartidos];
	RepartirEscanios(partidos, cantEscanios, cantPartidos, escanios);
	return escanios;
}


int main (){
	/* main super básico para probar la función */
	EscaniosAgrupacion escanios [MAX_PARTIDOS];
//	escanios = AsignarEscanios("capital.bin",50);
	escanios = AsignarEscanios("provincia.bin", 150);
	return 0;
}
