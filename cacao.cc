#include "cacao.h"

Cacao::Cacao(string nombre, float area, int edad, float produccionAnual, string tipoFruto)
    : Producto(nombre, area, edad, produccionAnual), tipoFruto(tipoFruto) {}

string Cacao::GetTipoFruto() const {
    return "Tipo fruto: " + tipoFruto;
}


