#include "producto.h"
#include <string>
using namespace std;

Producto::Producto(string nombre, float area, int edad, float produccionAnual) : nombre(nombre), area(area), edad(edad), produccionAnual(produccionAnual) {}

string Producto::GetNombre() const {
    return nombre;
}

float Producto::GetArea() const {
    return area;
}

int Producto::GetEdad() const {
    return area;
}

float Producto::GetProduccionAnual() const {
    return produccionAnual;
}

string Producto::MostrarDatos() {
     char buffer_area[50]; // Tamaño suficiente para almacenar el float convertido a string
    sprintf(buffer_area, "%.2f", area);
    char buffer_produccion_anual[50]; // Tamaño suficiente para almacenar el float convertido a string
    sprintf(buffer_produccion_anual, "%.2f", produccionAnual); 
    return "Nombre: " + nombre + " Area: " + string(buffer_area) + " Edad: " + to_string(edad) + " Produccion anual: " + string(buffer_produccion_anual) ;
}


