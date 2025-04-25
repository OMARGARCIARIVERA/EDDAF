#include "Fecha.h"
#include <sstream>
#include <iostream>

using namespace std;

// Constructores
Fecha::Fecha(int mes, int dia, int hh, int mm, int ss) : mes(mes), dia(dia), hh(hh), mm(mm), ss(ss) {
}

// Overload de operadores
fstream& operator>>(fstream& file,Fecha& f) {
    string str;
    file >> str;
    f.mes = f.mtoi(str);
    file >> f.dia >> str;
    stringstream ss(str);
    getline(ss,str,':');
    f.hh = stoi(str); // string to int
    getline(ss,str,':');
    f.mm = stoi(str);
    getline(ss,str);
    f.ss = stoi(str);
    return file;
}

std::ostream& operator<<(std::ostream& os, const Fecha& f) {
    os << f.getMes() << " " << f.getDia()
       << (f.getHh() < 10 ? " 0" : " ") << f.getHh()
       << (f.getMm() < 10 ? ":0" : ":") << f.getMm()
       << (f.getSs() < 10 ? ":0" : ":") << f.getSs();
    return os;
}

// Funcion que toma como parametro una referencia a otro objeto de fecha y regresa si es mas grande la fecha
bool Fecha::operator<(const Fecha &otraFecha) const {
    if (mes != otraFecha.mes)
        return mes < otraFecha.mes;

    if (dia != otraFecha.dia)
        return dia < otraFecha.dia;

    if (hh != otraFecha.hh)
        return hh < otraFecha.hh;

    if (mm != otraFecha.mm)
        return mm < otraFecha.mm;

    if (ss != otraFecha.ss)
        return ss < otraFecha.ss;

    return false;
}

// Funcion que toma como parametro una referencia a otro objeto de fecha e iguala los valores entre ellos
bool Fecha::operator==(const Fecha &otraFecha) const {
    return (dia == otraFecha.dia && mes == otraFecha.mes && hh == otraFecha.hh && mm == otraFecha.mm && ss == otraFecha.ss );
}

// Funciones
// Funcion que toma como parametro una string, para despues pedir los elementos de una fecha y regresar un objeto Fecha con estos
Fecha Fecha::fechaEntradatofechaObjeto(const string &entrada) {
    int e_mes, e_dia, e_hh, e_mm, e_ss;
    cout << entrada << "Formato: ";
    cout << "Mes Dia - Hora:Minuto:Segundos = ";
    cin >> e_mes >> e_dia >> e_hh >> e_mm >> e_ss;
    return Fecha(e_mes, e_dia, e_hh, e_mm, e_ss);
}

int Fecha::mtoi(const std::string& mes) {
    string M[] = {"Oct","Aug","Jun","Sep","Jul"};
    int nM[] = {10,8,6,9,7};
    for (int i = 0; i < 5; i++) {
        if (mes == M[i]) {
            return nM[i];
        }
    }
    return 12;
}

// Sets y gets
int Fecha::getMes() const {
    return mes;
}

void Fecha::setMes(int mes) {
    Fecha::mes = mes;
}

int Fecha::getDia() const {
    return dia;
}

void Fecha::setDia(int dia) {
    Fecha::dia = dia;
}

int Fecha::getHh() const {
    return hh;
}

void Fecha::setHh(int hh) {
    Fecha::hh = hh;
}

int Fecha::getMm() const {
    return mm;
}

void Fecha::setMm(int mm) {
    Fecha::mm = mm;
}

int Fecha::getSs() const {
    return ss;
}

void Fecha::setSs(int ss) {
    Fecha::ss = ss;
}
