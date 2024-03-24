#include <string>
using namespace std;

#ifndef MUESTRA_H
#define MUESTRA_H

class Muestra
{
public:
    Muestra(float porcentajeArcilla, float porcentajeArena, float porcentajeLimo, float ph, float materiaOrganica);

    float GetPorcentajeArcilla() const;
    float GetPorcentajeArena() const;

    float GetPorcentajeLimo() const;

    float GetPorcentajePh() const;
    float GetMateriaOrganica() const;

private:
    float porcentajeArcilla;
    float porcentajeArena;
    float porcentajeLimo;
    float ph;
    float materiaOrganica;
};

#endif // MUESTRA_H
