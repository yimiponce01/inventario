#include "muestra.h"

Muestra::Muestra(float porcentajeArcilla, float porcentajeArena, float porcentajeLimo, float ph, float materiaOrganica)
    : porcentajeArcilla(porcentajeArcilla), porcentajeArena(porcentajeArena), porcentajeLimo(porcentajeLimo), ph(ph), materiaOrganica(materiaOrganica) {}

float Muestra::GetPorcentajeArcilla() const {
    return porcentajeArcilla;
}

float Muestra::GetPorcentajeArena() const {
    return porcentajeArena;
}

float Muestra::GetPorcentajeLimo() const {
    return porcentajeLimo;
}

float Muestra::GetPorcentajePh() const {
    return ph;
}

float Muestra::GetMateriaOrganica() const {
    return materiaOrganica;
}
