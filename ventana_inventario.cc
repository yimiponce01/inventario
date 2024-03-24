#include <tchar.h> //Usamos esta libreria para castear cadenas
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "cacao.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iostream>

// Macros o identificadores
#define OPERADOR 100
#define CALCULAR 101
#define SALIR 102
#define DESARROLLADORES 103
#define DIGITA 110
#define RESUL 120
#define PORCENTAJE_ARCILLA 200
#define AREA 201
#define PORCENTAJE_LIMO 202
#define PH 203

#define MATERIA_ORGANICA 204

std::string getData(string nombreArchivo)
{
    std::string Tabla; // Utiliza std::string en lugar de un array de char
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir el archivo." << std::endl;
        throw std::runtime_error("No se pudo abrir el archivo."); // Lanza una excepción en caso de error
    }

    while (std::getline(archivo, linea))
    {
        Tabla += linea + "\r\n"; // Concatena directamente a std::string
    }

    archivo.close();
    return Tabla; // Retorna el std::string
}

LRESULT CALLBACK WindowsInventario(HWND Ventana_Inventario,
                                   UINT MensajeComunica,
                                   WPARAM wParam,
                                   LPARAM lParam)
{

    HWND controles;
    static HINSTANCE Instancia;
    BOOL exito = FALSE;
    float porcentajeArcilla = 0;
    float porcentajeArena = 0;
    float porcentajeLimo = 0;
    float ph = 0;
    float materiaOrganica = 0;
    int item = SendDlgItemMessage(Ventana_Inventario, OPERADOR, CB_GETCURSEL, 0, 0); // CB_GETCURSELpara recuperar el índice del elemento seleccionado
    int opcion = 1;
    char Tabla[500] = {0};
    char Resultado[500] = {0};

    // vector<Cacao> cacaoss = getCacaos();

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

        controles = CreateWindow(_T("STATIC"), _T("Reporte "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 10, 75, 22, Ventana_Inventario,
                                 (HMENU)-1, Instancia,
                                 NULL);

        controles = CreateWindowEx(WS_EX_CLIENTEDGE, _T("EDIT"), _T(""),
                                   WS_CHILD | WS_VISIBLE | WS_VSCROLL |
                                       ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL |
                                       ES_READONLY,
                                   10, 125, 365, 195, Ventana_Inventario,
                                   (HMENU)RESUL, Instancia, NULL);

        // BOTÓN PARA SALIR DEL PROGRAMA
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Salir"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 100, 100, 22, Ventana_Inventario,
                                   (HMENU)SALIR, Instancia,
                                   NULL);
        try
        {
            sprintf(Resultado, "DATOS CACAO\r\n%s\r\n", getData("datos_cacao.txt").c_str());

            strcat(Tabla, Resultado);

            sprintf(Resultado, "\r\nDATOS ARROZ\r\n%s\r\n", getData("datos_arroz.txt").c_str());
            strcat(Tabla, Resultado);

            SetDlgItemText(Ventana_Inventario, RESUL, Tabla);

            // GUARDA LA SELECCION DEL ITEM ESCOGIDO DEL COMBOBOX
            SendDlgItemMessage(Ventana_Inventario, OPERADOR, CB_SETCURSEL,
                               (WPARAM)0, (LPARAM)0);
        }
        catch (exception &e)
        {

            string message = e.what();
            string msg = "Memoria completa " + message;
            wstring wmsg(msg.begin(), msg.end());
            MessageBoxW(Ventana_Inventario, wmsg.c_str(), wmsg.c_str(), MB_ICONERROR);
        }

        break;

    // DAR FUNCIONALIDAD A TODOS LOS CONTROLES
    case WM_COMMAND:

        // ESCOGE EL CONTROL QUE SELECCIONAMOS AL QUE SE LE DARÁ UNA FUNCIÓN
        switch (LOWORD(wParam))
        {

        case SALIR:
            if (MessageBox(Ventana_Inventario, _T("Seguro que quieres salir?"), _T("SALIR "), MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(Ventana_Inventario);

                return 0;
            }
            break;

        case DESARROLLADORES:
            if (MessageBox(Ventana_Inventario, _T("- -"), _T("DESARROLLADORES: "), MB_OK))
            {
                SetFocus(GetDlgItem(Ventana_Inventario, DIGITA));
            }
            break;
        }

        break;

    default:
        return DefWindowProc(Ventana_Inventario, MensajeComunica, // garantiza que se procesen todos los mensajes
                             wParam, lParam);
    }

    return 0;
}

// Creacion de la ventana
int WINAPI WinInventario(HINSTANCE hThisInstance,
                         HINSTANCE hPrevInstance,
                         LPSTR lpszArgument,
                         int nCmdShow)
{
    WNDCLASSEX estilo1;
    HWND Ventana_Muestra;
    HWND ventana2;
    MSG MensajeComunica;
    estilo1.hInstance = hThisInstance;
    estilo1.lpszClassName = _T("Ventana");
    estilo1.lpfnWndProc = WindowsInventario;
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

    Ventana_Muestra = CreateWindowEx(0, _T("Ventana"),
                                     _T("VENTANA DE MUESTRA"),
                                     WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                     550,
                                     150,
                                     400,
                                     400,
                                     HWND_DESKTOP,
                                     NULL,
                                     hThisInstance,
                                     NULL);

    ShowWindow(Ventana_Muestra, nCmdShow);
    ShowWindow(GetConsoleWindow(), SW_HIDE); // ESCONDE LA CONSOLA

    while (GetMessage(&MensajeComunica, NULL, 0, 0) > 0) // CICLO DE MENSAJES
    {
        TranslateMessage(&MensajeComunica);

        DispatchMessage(&MensajeComunica);
    }
    return MensajeComunica.wParam;
}