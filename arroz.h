#ifndef ARRROZ_H
#define ARROZ_H

#include "producto.h"

class Arroz : public Producto {
public:
    Arroz(string nombre, float area, int edad, float produccionAnual, string tipoGrano);

    string GetTipoGrano() const;

private:
    string tipoGrano;
};

#endif // ARROZ_H
