//
//  ejercicio.cpp
//  Clases
//
//  Created by Emanuel Andrada on 2/14/16.
//

#include <iostream>
#include <fstream>

using namespace std;

struct VotosAgrupacion {
    int nroLista;
    int votos;
};

template <typename T>
void escribir(FILE *archivo, T registro) {
    fwrite(&registro, sizeof(T), 1, archivo);
}

void escribirVotosAgrupacion(FILE *archivo, int nroLista, int votos) {
    VotosAgrupacion registro = { nroLista, votos };
    escribir(archivo, registro);
}

int main() {
    FILE *archivo = fopen("capital.bin", "wb");
    escribirVotosAgrupacion(archivo, 187, 68248);
    escribirVotosAgrupacion(archivo, 502, 437380);
    escribirVotosAgrupacion(archivo, 503, 895391);
    escribirVotosAgrupacion(archivo, 504, 166726);
    escribirVotosAgrupacion(archivo, 505, 280213);
    escribirVotosAgrupacion(archivo, 506, 107038);
    fclose(archivo);
    archivo = fopen("buenosaires.bin", "wb");
    escribirVotosAgrupacion(archivo, 503, 3354619);
    escribirVotosAgrupacion(archivo, 504, 3037552);
    escribirVotosAgrupacion(archivo, 505, 401536);
    escribirVotosAgrupacion(archivo, 506, 1888415);
    escribirVotosAgrupacion(archivo, 507, 317448);
    fclose(archivo);
    return 0;
}
