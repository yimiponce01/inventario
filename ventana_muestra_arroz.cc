#include <tchar.h> //Usamos esta libreria para castear cadenas
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "muestra.h"
#include <vector>

#include <iostream>

// Macros o identificadores
#define OPERADOR 100
#define CALCULAR 101
#define SALIR 102
#define DESARROLLADORES 103
#define DIGITA 110
#define RESUL 120
#define PORCENTAJE_ARCILLA 200
#define PORCENTAJE_ARENA 201
#define PORCENTAJE_LIMO 202
#define PH 203

#define MATERIA_ORGANICA 204

vector<Muestra> muestrasArroz;

// prototipo de procedimiento de ventana
LRESULT CALLBACK WindowsArroz(HWND ventana_muestra_arroz,
                              UINT MensajeComunica,
                              WPARAM wParam,
                              LPARAM lParam);

LRESULT CALLBACK WindowsMuestraArroz(HWND Ventana_Muestra_Arroz,
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
    int item = SendDlgItemMessage(Ventana_Muestra_Arroz, OPERADOR, CB_GETCURSEL, 0, 0); // CB_GETCURSELpara recuperar el índice del elemento seleccionado
    int opcion = 1;
    const char *Operaciones[] = {
        "Cedro"};

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
        controles = CreateWindow(_T("STATIC"), _T("Por. Arcilla "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 10, 75, 22, Ventana_Muestra_Arroz,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   85, 10, 100, 22, Ventana_Muestra_Arroz,
                                   (HMENU)PORCENTAJE_ARCILLA, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Por. Arena "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 38, 75, 22, Ventana_Muestra_Arroz,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 38, 100, 22, Ventana_Muestra_Arroz,
                                   (HMENU)PORCENTAJE_ARENA, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Por. Limo "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 66, 75, 22, Ventana_Muestra_Arroz,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 66, 100, 22, Ventana_Muestra_Arroz,
                                   (HMENU)PORCENTAJE_LIMO, Instancia,
                                   NULL);
        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Por. Ph "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 94, 75, 22, Ventana_Muestra_Arroz,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 94, 100, 22, Ventana_Muestra_Arroz,
                                   (HMENU)PH, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Materia organica "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 122, 75, 22, Ventana_Muestra_Arroz,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 122, 100, 22, Ventana_Muestra_Arroz,
                                   (HMENU)MATERIA_ORGANICA, Instancia,
                                   NULL);

        // BOTÓN PARA HACER EL CÁLCULO
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Evaluar"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 75, 100, 22, Ventana_Muestra_Arroz,
                                   (HMENU)CALCULAR, Instancia,
                                   NULL);
        // BOTÓN PARA SALIR DEL PROGRAMA
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Salir"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 100, 100, 22, Ventana_Muestra_Arroz,
                                   (HMENU)SALIR, Instancia,
                                   NULL);

        for (int i = 0; i < opcion; i++)
        {
            SendDlgItemMessage(Ventana_Muestra_Arroz, OPERADOR,
                               CB_ADDSTRING, 0,
                               (LPARAM)Operaciones[i]);
        }

        // GUARDA LA SELECCION DEL ITEM ESCOGIDO DEL COMBOBOX
        SendDlgItemMessage(Ventana_Muestra_Arroz, OPERADOR, CB_SETCURSEL,
                           (WPARAM)0, (LPARAM)0);
        break;

    // DAR FUNCIONALIDAD A TODOS LOS CONTROLES
    case WM_COMMAND:

        // ESCOGE EL CONTROL QUE SELECCIONAMOS AL QUE SE LE DARÁ UNA FUNCIÓN
        switch (LOWORD(wParam))
        {
        case CALCULAR:
        {
            try {
            char Resultado[500] = {0}; // INICIALIZA EN 0
            char Tabla[500] = {0};

            TCHAR text_porcentaje_arcilla[100]; // Buffer para almacenar el texto
            GetDlgItemText(Ventana_Muestra_Arroz, PORCENTAJE_ARCILLA, text_porcentaje_arcilla, sizeof(text_porcentaje_arcilla) / sizeof(text_porcentaje_arcilla[0]));

            TCHAR text_porcentaje_arena[100]; // Buffer para almacenar el texto
            GetDlgItemText(Ventana_Muestra_Arroz, PORCENTAJE_ARENA, text_porcentaje_arena, sizeof(text_porcentaje_arena) / sizeof(text_porcentaje_arena[0]));

            TCHAR text_porcentaje_limo[100]; // Buffer para almacenar el texto
            GetDlgItemText(Ventana_Muestra_Arroz, PORCENTAJE_LIMO, text_porcentaje_limo, sizeof(text_porcentaje_limo) / sizeof(text_porcentaje_limo[0]));

            TCHAR text_ph[100]; // Buffer para almacenar el texto
            GetDlgItemText(Ventana_Muestra_Arroz, PH, text_ph, sizeof(text_ph) / sizeof(text_ph[0]));

            TCHAR text_materia_organica[100]; // Buffer para almacenar el texto
            GetDlgItemText(Ventana_Muestra_Arroz, MATERIA_ORGANICA, text_materia_organica, sizeof(text_materia_organica) / sizeof(text_materia_organica[0]));

            if ((stof(text_porcentaje_arcilla) >= 20 || stof(text_porcentaje_arcilla) < 40) && (stof(text_porcentaje_arena) >= 40 || stof(text_porcentaje_arena) < 60) && (stof(text_porcentaje_limo) >= 40 || stof(text_porcentaje_limo) < 40) && stof(text_ph) < 6.5 && stof(text_materia_organica) < 1.0)
            {
                
                WNDCLASSEX estiloMuestraArroz;
                HWND VentanaArroz;
                MSG MensajeComunicaMuestra;

                estiloMuestraArroz.hInstance = Instancia;
                estiloMuestraArroz.lpszClassName = _T("VentanaArroz");
                estiloMuestraArroz.lpfnWndProc = WindowsArroz;
                estiloMuestraArroz.style = CS_DBLCLKS;
                estiloMuestraArroz.cbSize = sizeof(WNDCLASSEX);
                estiloMuestraArroz.hIcon = LoadIcon(NULL, IDI_QUESTION);
                estiloMuestraArroz.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
                estiloMuestraArroz.hCursor = LoadCursor(NULL, IDC_HAND);
                estiloMuestraArroz.lpszMenuName = NULL;
                estiloMuestraArroz.cbClsExtra = 0;
                estiloMuestraArroz.cbWndExtra = 0;
                estiloMuestraArroz.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;

                if (!RegisterClassEx(&estiloMuestraArroz))
                {
                    
                WNDCLASSEX estiloMuestraArroz;

                estiloMuestraArroz.hInstance = Instancia;
                estiloMuestraArroz.lpszClassName = _T("VentanaArroz");
                estiloMuestraArroz.lpfnWndProc = WindowsArroz;
                estiloMuestraArroz.style = CS_DBLCLKS;
                estiloMuestraArroz.cbSize = sizeof(WNDCLASSEX);
                estiloMuestraArroz.hIcon = LoadIcon(NULL, IDI_QUESTION);
                estiloMuestraArroz.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
                estiloMuestraArroz.hCursor = LoadCursor(NULL, IDC_HAND);
                estiloMuestraArroz.lpszMenuName = NULL;
                estiloMuestraArroz.cbClsExtra = 0;
                estiloMuestraArroz.cbWndExtra = 0;
                estiloMuestraArroz.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;
                }

                VentanaArroz = CreateWindowEx(0, _T("VentanaArroz"),
                                              _T("VENTANA DE ARROZ"),
                                              WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                              550,
                                              150,
                                              400,
                                              400,
                                              HWND_DESKTOP,
                                              NULL,
                                              Instancia,
                                              NULL);

                ShowWindow(VentanaArroz, SW_SHOW);

                while (GetMessage(&MensajeComunicaMuestra, NULL, 0, 0) > 0)
                {
                    TranslateMessage(&MensajeComunicaMuestra);
                    DispatchMessage(&MensajeComunicaMuestra);
                }
            }
            else
            {
                std::cout << "ENTRO Y NO CUMPLE";
                MessageBox(Ventana_Muestra_Arroz, _T("No cumple con muestra requerida!"), _T("Mensaje"), MB_OK);
            }
            }
            catch (exception &e)
            {

                string message = e.what();
                string msg = "Error en los campos " + message;
                wstring wmsg(msg.begin(), msg.end());
                MessageBoxW(Ventana_Muestra_Arroz, wmsg.c_str(), wmsg.c_str(), MB_ICONERROR);
            }
        }
        break;

        case SALIR:
            if (MessageBox(Ventana_Muestra_Arroz, _T("Seguro que quieres salir?"), _T("SALIR "), MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(Ventana_Muestra_Arroz);
            }
            break;

        case DESARROLLADORES:
            if (MessageBox(Ventana_Muestra_Arroz, _T("- -"), _T("DESARROLLADORES: "), MB_OK))
            {
                SetFocus(GetDlgItem(Ventana_Muestra_Arroz, DIGITA));
            }
            break;
        }

        break;

    default:
        return DefWindowProc(Ventana_Muestra_Arroz, MensajeComunica, // garantiza que se procesen todos los mensajes
                             wParam, lParam);
    }

    return 0;
}

// Creacion de la ventana
int WINAPI WinMuestraArroz(HINSTANCE hThisInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR lpszArgument,
                      int nCmdShow)
{
    WNDCLASSEX estilo1;
    HWND Ventana_Muestra_Arroz;
    HWND ventana2;
    MSG MensajeComunica;
    estilo1.hInstance = hThisInstance;
    estilo1.lpszClassName = _T("Ventana");
    estilo1.lpfnWndProc = WindowsMuestraArroz;
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

    Ventana_Muestra_Arroz = CreateWindowEx(0, _T("Ventana"),
                                     _T("VENTANA DE MUESTRA ARROZ"),
                                     WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                     550,
                                     150,
                                     400,
                                     400,
                                     HWND_DESKTOP,
                                     NULL,
                                     hThisInstance,
                                     NULL);

    ShowWindow(Ventana_Muestra_Arroz, nCmdShow);
    ShowWindow(GetConsoleWindow(), SW_HIDE); // ESCONDE LA CONSOLA

    while (GetMessage(&MensajeComunica, NULL, 0, 0) > 0) // CICLO DE MENSAJES
    {
        TranslateMessage(&MensajeComunica);

        DispatchMessage(&MensajeComunica);
    }
    return MensajeComunica.wParam;
}