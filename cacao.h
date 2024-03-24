#ifndef CACAO_H
#define CACAO_H

#include "producto.h"

class Cacao : public Producto {
public:
    Cacao(string nombre, float area, int edad, float produccionAnual, string tipoFruto);
    string GetTipoFruto() const;

private:
    string tipoFruto;
};

#endif
