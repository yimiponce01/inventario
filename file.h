#ifndef FILE_H
#define FILE_H

#include <string>
using namespace std;

class File {
public:
    File(string nombre, string tipo);

    void ResgitrarDato();

private:
    string nombre;
    string tipo;
};

#endif
