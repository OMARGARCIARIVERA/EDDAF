#ifndef ENTREGA1_ESTDATOS_FECHA_H
#define ENTREGA1_ESTDATOS_FECHA_H

#include <fstream>

class Fecha {
    private:
        int mes,dia,hh,mm,ss;
    public:
    // Constructor
    Fecha(int mes, int dia, int hh, int mm, int ss);

    // Overload de operadores
    bool operator<(const Fecha&) const;
    bool operator==(const Fecha &) const;
    friend std::fstream& operator>>(std::fstream&,Fecha&);
    friend std::ostream& operator<<(std::ostream&, const Fecha&);

    // Funciones
    Fecha fechaEntradatofechaObjeto(const std::string &prompt);
    int mtoi(const std::string&);

    // Sets y gets
    int getMes() const;
    void setMes(int mes);
    int getDia() const;
    void setDia(int dia);
    int getHh() const;
    void setHh(int hh);
    int getMm() const;
    void setMm(int mm);
    int getSs() const;
    void setSs(int ss);
};

#endif
