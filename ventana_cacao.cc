#include <tchar.h> //Usamos esta libreria para castear cadenas
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "cacao.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

// Macros o identificadores
#define OPERADOR 100
#define CALCULAR 101
#define SALIR 102
#define DESARROLLADORES 103
#define DIGITA 110
#define RESUL 120
#define NOMBRE 200
#define AREA 201
#define EDAD 202
#define PRODUCCION_ANUAL 203

#define TIPO_FRUTO 204

vector<Cacao> cacaos;


void GuardarEnArchvio(Cacao cacao) {
    std::ofstream archivo("datos_cacao.txt", std::ios::app);
    if (archivo.is_open()) {
        // Escribe los datos al archivo, seguido de un salto de línea
        archivo << cacao.MostrarDatos() << " " << cacao.GetTipoFruto() << "\n";
        
        archivo.close(); // No olvides cerrar el archivo
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}

// prototipo de procedimiento de ventana
LRESULT CALLBACK WindowsCacao(HWND Ventana_Cacao,
                              UINT MensajeComunica,
                              WPARAM wParam,
                              LPARAM lParam)
{

    HWND controles;
    static HINSTANCE Instancia;
    BOOL exito = FALSE;
    string nombre = "";
    float area = 0;
    int edad = 0;
    float produccionAnual = 0;
    string tipoFruto = "";
    int item = SendDlgItemMessage(Ventana_Cacao, OPERADOR, CB_GETCURSEL, 0, 0); // CB_GETCURSELpara recuperar el índice del elemento seleccionado
    int opcion = 1;
    const char *Operaciones[] = {
        "simples", "agregados"};

    switch (MensajeComunica)
    {

    case WM_DESTROY:
        PostQuitMessage(0); // solicita al sistema terminar(salir)
        break;

    case WM_CREATE:

        Instancia = ((LPCREATESTRUCT)lParam)->hInstance;

        // VENTANA PRINCIPAL

        // VENTANA 1

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Nombre "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 10, 75, 22, Ventana_Cacao,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   85, 10, 100, 22, Ventana_Cacao,
                                   (HMENU)NOMBRE, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Edad "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 38, 75, 22, Ventana_Cacao,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 38, 100, 22, Ventana_Cacao,
                                   (HMENU)EDAD, Instancia,
                                   NULL);
        // texto desplegable
        controles = CreateWindow(_T("STATIC"), _T("Tipo. fruto "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 66, 75, 22, Ventana_Cacao,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // DESPLEGABLE ARROZ, Cacao, ADMIN
        controles = CreateWindow(_T("COMBOBOX"), _T(""),
                                 CBS_DROPDOWNLIST | WS_CHILD | WS_VISIBLE,
                                 85, 66, 100, 500,
                                 Ventana_Cacao, (HMENU)TIPO_FRUTO, Instancia,
                                 NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Area "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 190, 10, 75, 22, Ventana_Cacao,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   270, 10, 100, 22, Ventana_Cacao,
                                   (HMENU)AREA, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE PRODUCCION ANUAL
        controles = CreateWindow(_T("STATIC"), _T("Prod. Anual "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 190, 38, 75, 22, Ventana_Cacao,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   270, 38, 100, 22, Ventana_Cacao,
                                   (HMENU)PRODUCCION_ANUAL, Instancia,
                                   NULL);

        // LISTADO
        controles = CreateWindow(_T("STATIC"), _T(""),
                                 ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                 10, 125, 365, 195, Ventana_Cacao,
                                 (HMENU)RESUL, Instancia, // SE LE VA MANDAR INFORMACION DESDE EL COMANDO
                                 NULL);

        // BOTÓN PARA HACER EL CÁLCULO
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Guardar"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 75, 100, 22, Ventana_Cacao,
                                   (HMENU)CALCULAR, Instancia,
                                   NULL);
        // BOTÓN PARA SALIR DEL PROGRAMA
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Salir"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 100, 100, 22, Ventana_Cacao,
                                   (HMENU)SALIR, Instancia,
                                   NULL);

        for (int i = 0; i < opcion; i++)
        {
            SendDlgItemMessage(Ventana_Cacao, TIPO_FRUTO,
                               CB_ADDSTRING, 0,
                               (LPARAM)Operaciones[i]);
        }

        // GUARDA LA SELECCION DEL ITEM ESCOGIDO DEL COMBOBOX
        SendDlgItemMessage(Ventana_Cacao, TIPO_FRUTO, CB_SETCURSEL,
                           (WPARAM)0, (LPARAM)0);
        break;

    // DAR FUNCIONALIDAD A TODOS LOS CONTROLES
    case WM_COMMAND:

        // ESCOGE EL CONTROL QUE SELECCIONAMOS AL QUE SE LE DARÁ UNA FUNCIÓN
        switch (LOWORD(wParam))
        {

        case CALCULAR:
        {
            std::cout << "cero";

            try
            {
                std::cout << "primero";

                string valor_nombre = "";
                string valor_tipo_fruto = "";

                char Resultado[500] = {0}; // INICIALIZA EN 0
                char Tabla[500] = {0};
                std::cout << "segundo";

                TCHAR text_nombre[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Cacao, NOMBRE, text_nombre, sizeof(text_nombre) / sizeof(text_nombre[0]));
                std::cout << "tercero";

                edad = GetDlgItemInt(Ventana_Cacao, EDAD, &exito, TRUE); // TRADUCE EL TEXTO DE UN CONTROL EN ENTERO
                if (exito != TRUE)
                {
                    MessageBox(Ventana_Cacao, _T("Ingrese el EDAD"), _T("ERROR"), MB_ICONERROR); // CAJA DE MENSAJE
                    SetFocus(GetDlgItem(Ventana_Cacao, EDAD));                                   // SE DESIGNA EL ENFOQUE QUE TENDRA EL TECLADO
                    break;
                }

                std::cout << "cuarto";

                TCHAR text_area[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Cacao, AREA, text_area, sizeof(text_area) / sizeof(text_area[0]));

                std::cout << "quinto";

                TCHAR text_produccion_anual[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Cacao, PRODUCCION_ANUAL, text_produccion_anual, sizeof(text_produccion_anual) / sizeof(text_produccion_anual[0]));

                std::cout << "sexto";

                TCHAR text_tipo_fruto[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Cacao, TIPO_FRUTO, text_tipo_fruto, sizeof(text_tipo_fruto) / sizeof(text_tipo_fruto[0]));

                valor_nombre = text_nombre;
                valor_tipo_fruto = text_tipo_fruto;

                float valor_area = stof(text_area);
                float valor_produccion_anual = stof(text_produccion_anual);
                Cacao cacao(valor_nombre, valor_area, edad, valor_produccion_anual, valor_tipo_fruto);
                GuardarEnArchvio(cacao);
                cacaos.push_back(cacao);

                valor_area = std::stof(std::to_string(valor_area).substr(0, std::to_string(valor_area).find(".") + 3));
                valor_produccion_anual = std::stof(std::to_string(valor_produccion_anual).substr(0, std::to_string(valor_produccion_anual).find(".") + 3));
                for (int i = 0; i < cacaos.size(); i++)
                {

                    sprintf(Resultado, "%s %s\n", cacaos[i].MostrarDatos().c_str(), cacaos[i].GetTipoFruto().c_str());
                    strcat(Tabla, Resultado);
                }

                SetDlgItemText(Ventana_Cacao, RESUL, Tabla);
            }
            catch (exception &e)
            {

                string message = e.what();
                string msg = "Error en los campos " + message;
                wstring wmsg(msg.begin(), msg.end());
                MessageBoxW(Ventana_Cacao, wmsg.c_str(), wmsg.c_str(), MB_ICONERROR);
            }
        }
        break;

        case SALIR:
            if (MessageBox(Ventana_Cacao, _T("Seguro que quieres salir?"), _T("SALIR "), MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(Ventana_Cacao);
            }
            break;

        case DESARROLLADORES:
            if (MessageBox(Ventana_Cacao, _T("- -"), _T("DESARROLLADORES: "), MB_OK))
            {
                SetFocus(GetDlgItem(Ventana_Cacao, DIGITA));
            }
            break;
        }

        break;

    default:
        return DefWindowProc(Ventana_Cacao, MensajeComunica, // garantiza que se procesen todos los mensajes
                             wParam, lParam);
    }

    return 0;
}


// Creacion de la ventana
int WINAPI WinCacao(HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    WNDCLASSEX estilo1;
    HWND Ventana_Cacao;
    HWND ventana2;
    MSG MensajeComunica;
    estilo1.hInstance = hThisInstance;
    estilo1.lpszClassName = _T("Ventana");
    estilo1.lpfnWndProc = WindowsCacao;
    estilo1.style = CS_DBLCLKS;
    estilo1.cbSize = sizeof(WNDCLASSEX);
    estilo1.hIcon = LoadIcon(NULL, IDI_QUESTION);
    estilo1.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
    estilo1.hCursor = LoadCursor(NULL, IDC_HAND);
    estilo1.lpszMenuName = NULL;
    estilo1.cbClsExtra = 0;
    estilo1.cbWndExtra = 0;
    estilo1.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;

    if (!RegisterClassEx(&estilo1)) // RETORNA 0 SI AUN NO SE CREA UNA VENTANA
    {
        return 0;
    }

    Ventana_Cacao = CreateWindowEx(0, _T("Ventana"),
                                    _T("VENTANA DE CACAO"),
                                    WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                    550,
                                    150,
                                    400,
                                    400,
                                    HWND_DESKTOP,
                                    NULL,
                                    hThisInstance,
                                    NULL);

    ShowWindow(Ventana_Cacao, nCmdShow);
    ShowWindow(GetConsoleWindow(), SW_HIDE); // ESCONDE LA CONSOLA

    while (GetMessage(&MensajeComunica, NULL, 0, 0) > 0) // CICLO DE MENSAJES
    {
        TranslateMessage(&MensajeComunica);

        DispatchMessage(&MensajeComunica);
    }
    return MensajeComunica.wParam;
}

