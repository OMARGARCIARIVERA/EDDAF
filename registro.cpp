#include "Registro.h"

using namespace std;

// Constructores
Registro::Registro(Fecha f) : f(f) {
}

Registro::Registro(Fecha _f, string ip, string mensaje)
        : f(_f), ip(ip), mensaje(mensaje) {
}

// Overload de operadores
fstream& operator>>(fstream& file, Registro& r) {
    file >> r.f >> r.ip;
    getline(file, r.mensaje);
    return file;
}

ostream& operator<<(ostream& os, const Registro& r) {
    os << r.getF() << " " << r.getIp() << " " << r.getMensaje();
    return os;
}

// Comparación por IP (para ordenamiento)
bool Registro::operator<(const Registro& otra) const {
    return ip < otra.ip;
}

// Comparación por fecha (para usar si se desea ordenar por fecha)
bool Registro::menorPorFecha(const Registro& otraFecha) const {
    return f < otraFecha.f;
}

// Sets y gets
const Fecha &Registro::getF() const {
    return f;
}

void Registro::setF(const Fecha &f) {
    Registro::f = f;
}

const string &Registro::getIp() const {
    return ip;
}

void Registro::setIp(const string &ip) {
    Registro::ip = ip;
}

const string &Registro::getMensaje() const {
    return mensaje;
}

void Registro::setMensaje(const string &mensaje) {
    Registro::mensaje = mensaje;
}
