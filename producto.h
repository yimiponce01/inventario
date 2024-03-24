#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Producto {
public:
    Producto(string nombre, float area, int edad, float produccionAnual);
    string GetNombre() const;
    float GetArea() const;
    int GetEdad() const;
    float GetProduccionAnual() const;
    void SetNombre(string nombre) const;
    void SetArea(float area) const;
    void SetEdad(int edad) const;
    void SetProduccionAnual(float produccionAnual) const;

    string MostrarDatos();

private:
    string nombre;
    float area;
    int edad;
    float produccionAnual;
};

#endif
