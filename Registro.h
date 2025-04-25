#ifndef ENTREGA2_ESTDATOS_REGISTRO_H
#define ENTREGA2_ESTDATOS_REGISTRO_H

#include <string>
#include <fstream>
#include "Fecha.h"

class Registro {
    private:
        Fecha f;
        std::string ip;
        std::string mensaje;
    public:
        // Constructores
        Registro(Fecha f);
        Registro(Fecha,std::string,std::string);

        // Overload de operadores
        friend std::fstream& operator>>(std::fstream&,Registro&);
        friend std::ostream& operator<<(std::ostream&, const Registro&);
        bool operator<(const Registro &) const; // Comparación por IP
        bool menorPorFecha(const Registro &) const; // Comparación por fecha

        // Sets y gets
        const Fecha &getF() const;
        void setF(const Fecha &f);
        const std::string &getIp() const;
        void setIp(const std::string &ip);
        const std::string &getMensaje() const;
        void setMensaje(const std::string &mensaje);
};

#endif //ENTREGA2_ESTDATOS_REGISTRO_H
