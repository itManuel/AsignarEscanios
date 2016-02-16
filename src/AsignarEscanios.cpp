//============================================================================
// Name        : AsignarEscanios.cpp
// Author      : Manuel Fernando Aller y Mateo Tozzini.
// Version     :
// Copyright   : (c) la rémora del grupo 114
// Description : Sistema D'Hont para asignación de escanios.
//============================================================================


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

EscaniosAgrupacion RepartirEscanios(VotosAgrupacion &partidos,int &cantEscanios, int cantPartidos){
	EscaniosAgrupacion escanios [cantPartidos];

	return escanios;
}


EscaniosAgrupacion AsignarEscanios(char* filename, int &cantEscanios){
	/* abro el archivo al principio, cargo los datos en un array y cierro el archivo.
	 *  Trabajamos con los datos en memoria. */
	VotosAgrupacion partidos [MAX_PARTIDOS];
	int cantPartidos =0;
	FILE* archivo = fopen(filename, "rb");
	fread(&partidos[cantPartidos],sizeof(VotosAgrupacion),1,archivo);
	while(!feof(archivo)){
		cantPartidos++;
		fread(&partidos[cantPartidos],sizeof(VotosAgrupacion),1,archivo);
	}

	EscaniosAgrupacion escanios [cantPartidos];
	escanios RepartirEscanios(partidos,cantEscanios,cantPartidos);

	fclose(archivo);

	return escanios;
}


int main (){
	/* main super básico para probar la función */
	EscaniosAgrupacion escanios [MAX_PARTIDOS];
//	escanios AsignarEscanios('capital.bin',50);
	escanios AsignarEscanios('provincia.bin',150);
	return 0;
}
