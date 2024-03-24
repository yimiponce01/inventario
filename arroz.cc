#include "arroz.h"

Arroz::Arroz(string nombre, float area, int edad, float produccionAnual, string tipoGrano)
    : Producto(nombre, area, edad, produccionAnual), tipoGrano(tipoGrano) {}
  
string Arroz::GetTipoGrano() const {
    return "Tipo Grano: " + tipoGrano;
}
