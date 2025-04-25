// Leida, ordenamiento, busqueda de IPs y guardado de un archivo de bitacora
// Autores: Daniela Landin Solis - A00841757 y Omar Andres Garcia Rivera - A00838296
// Modificado el 28/04/2025

#include <iostream>
#include <fstream>
#include "Registro.h"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Declaracion de variables
    fstream f("bitacora.txt");
    Registro r(Fecha(0, 0, 0, 0, 0));
    vector<Registro> bitacora;
    vector<Registro> resultados;

    // Lectura del archivo a un vector bitacora
    while (!f.eof()) {
        f >> r;
        bitacora.push_back(r);
    }

    // Ordenamiento del archivo por IP usando el operador < sobrecargado por IP
    sort(bitacora.begin(), bitacora.end());

    // Entrada de rango de IPs
    string ipInicio, ipFin;
    cout << "-- Ingrese la IP de inicio para buscar --\n";
    cin >> ipInicio;
    cout << "-- Ingrese la IP de fin para buscar --\n";
    cin >> ipFin;

    // Buscando las IPs dentro del rango
    for (const auto &reg : bitacora) {
        if (!(reg.getIp() < ipInicio) && !(ipFin < reg.getIp())) {
            resultados.push_back(reg);
        }
    }

    // Imprimiendo los resultados
    cout << "\nSe encontraron los siguientes registros:\n";
    for (int i = 0; i < resultados.size(); i++) {
        cout << resultados[i] << endl;
    }

    // Guardando la bitacora ordenada en un archivo
    ofstream fOrdenado("bitacoraOrdenadaPorIP.txt");
    if (!fOrdenado.is_open()) {
        cerr << "Error abriendo el archivo\n";
    } else {
        for (const auto &reg : bitacora) {
            fOrdenado << reg << '\n';
        }
        cout << "Se guardo correctamente el archivo\n";
    }
    fOrdenado.close();

    return 0;
}
