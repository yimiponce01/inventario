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

vector<Muestra> muestras;

// prototipo de procedimiento de ventana
LRESULT CALLBACK WindowsCacao(HWND ventana_muestra,
                              UINT MensajeComunica,
                              WPARAM wParam,
                              LPARAM lParam);

LRESULT CALLBACK WindowsMuestra(HWND Ventana_Muestra,
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
    int item = SendDlgItemMessage(Ventana_Muestra, OPERADOR, CB_GETCURSEL, 0, 0); // CB_GETCURSELpara recuperar el índice del elemento seleccionado
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
                                 6, 10, 75, 22, Ventana_Muestra,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   85, 10, 100, 22, Ventana_Muestra,
                                   (HMENU)PORCENTAJE_ARCILLA, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Por. Arena "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 38, 75, 22, Ventana_Muestra,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 38, 100, 22, Ventana_Muestra,
                                   (HMENU)PORCENTAJE_ARENA, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Por. Limo "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 66, 75, 22, Ventana_Muestra,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 66, 100, 22, Ventana_Muestra,
                                   (HMENU)PORCENTAJE_LIMO, Instancia,
                                   NULL);
        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Por. Ph "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 94, 75, 22, Ventana_Muestra,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 94, 100, 22, Ventana_Muestra,
                                   (HMENU)PH, Instancia,
                                   NULL);

        // PARA MOSTRAR UN MENSAJE
        controles = CreateWindow(_T("STATIC"), _T("Materia organica "),
                                 BS_CENTER | SS_CENTER | WS_VISIBLE | WS_CHILD, // BS_CENTER CENTRA EL TEXTO HORIZONTALMENTE, CHLID QUE ES UNA VENTANA HIJO
                                 6, 122, 75, 22, Ventana_Muestra,
                                 (HMENU)-1, Instancia,
                                 NULL);
        // ESPACIO PARA DIGITAR EL NUMERO
        controles = CreateWindowEx(0, _T("EDIT"), _T(""),
                                   ES_LEFT | ES_NUMBER | WS_BORDER | WS_CHILD | WS_VISIBLE, // LEFT IZQUIERDA
                                   85, 122, 100, 22, Ventana_Muestra,
                                   (HMENU)MATERIA_ORGANICA, Instancia,
                                   NULL);

        // BOTÓN PARA HACER EL CÁLCULO
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Evaluar"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 75, 100, 22, Ventana_Muestra,
                                   (HMENU)CALCULAR, Instancia,
                                   NULL);
        // BOTÓN PARA SALIR DEL PROGRAMA
        controles = CreateWindowEx(0, _T("BUTTON"), _T("Salir"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   275, 100, 100, 22, Ventana_Muestra,
                                   (HMENU)SALIR, Instancia,
                                   NULL);

        for (int i = 0; i < opcion; i++)
        {
            SendDlgItemMessage(Ventana_Muestra, OPERADOR,
                               CB_ADDSTRING, 0,
                               (LPARAM)Operaciones[i]);
        }

        // GUARDA LA SELECCION DEL ITEM ESCOGIDO DEL COMBOBOX
        SendDlgItemMessage(Ventana_Muestra, OPERADOR, CB_SETCURSEL,
                           (WPARAM)0, (LPARAM)0);
        break;

    // DAR FUNCIONALIDAD A TODOS LOS CONTROLES
    case WM_COMMAND:

        // ESCOGE EL CONTROL QUE SELECCIONAMOS AL QUE SE LE DARÁ UNA FUNCIÓN
        switch (LOWORD(wParam))
        {
        case CALCULAR:
        {
            try
            {
                char Resultado[500] = {0}; // INICIALIZA EN 0
                char Tabla[500] = {0};

                TCHAR text_porcentaje_arcilla[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Muestra, PORCENTAJE_ARCILLA, text_porcentaje_arcilla, sizeof(text_porcentaje_arcilla) / sizeof(text_porcentaje_arcilla[0]));

                TCHAR text_porcentaje_arena[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Muestra, PORCENTAJE_ARENA, text_porcentaje_arena, sizeof(text_porcentaje_arena) / sizeof(text_porcentaje_arena[0]));

                TCHAR text_porcentaje_limo[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Muestra, PORCENTAJE_LIMO, text_porcentaje_limo, sizeof(text_porcentaje_limo) / sizeof(text_porcentaje_limo[0]));

                TCHAR text_ph[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Muestra, PH, text_ph, sizeof(text_ph) / sizeof(text_ph[0]));

                TCHAR text_materia_organica[100]; // Buffer para almacenar el texto
                GetDlgItemText(Ventana_Muestra, MATERIA_ORGANICA, text_materia_organica, sizeof(text_materia_organica) / sizeof(text_materia_organica[0]));

                if ((stof(text_porcentaje_arcilla) >= 20 || stof(text_porcentaje_arcilla) < 40) && (stof(text_porcentaje_arena) >= 30 || stof(text_porcentaje_arena) < 50) && (stof(text_porcentaje_limo) >= 20 || stof(text_porcentaje_limo) < 40) && stof(text_ph) < 6.5 && stof(text_materia_organica) < 3.0)
                {
                    WNDCLASSEX estiloMuestra;
                    HWND VentanaCacao;
                    MSG MensajeComunicaMuestra;

                    estiloMuestra.hInstance = Instancia;
                    estiloMuestra.lpszClassName = _T("VentanaCacao");
                    estiloMuestra.lpfnWndProc = WindowsCacao;
                    estiloMuestra.style = CS_DBLCLKS;
                    estiloMuestra.cbSize = sizeof(WNDCLASSEX);
                    estiloMuestra.hIcon = LoadIcon(NULL, IDI_QUESTION);
                    estiloMuestra.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
                    estiloMuestra.hCursor = LoadCursor(NULL, IDC_HAND);
                    estiloMuestra.lpszMenuName = NULL;
                    estiloMuestra.cbClsExtra = 0;
                    estiloMuestra.cbWndExtra = 0;
                    estiloMuestra.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;

                    if (!RegisterClassEx(&estiloMuestra))
                    {
                        WNDCLASSEX estiloMuestra;

                        estiloMuestra.hInstance = Instancia;
                        estiloMuestra.lpszClassName = _T("VentanaCacao");
                        estiloMuestra.lpfnWndProc = WindowsCacao;
                        estiloMuestra.style = CS_DBLCLKS;
                        estiloMuestra.cbSize = sizeof(WNDCLASSEX);
                        estiloMuestra.hIcon = LoadIcon(NULL, IDI_QUESTION);
                        estiloMuestra.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
                        estiloMuestra.hCursor = LoadCursor(NULL, IDC_HAND);
                        estiloMuestra.lpszMenuName = NULL;
                        estiloMuestra.cbClsExtra = 0;
                        estiloMuestra.cbWndExtra = 0;
                        estiloMuestra.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;
                    }

                    VentanaCacao = CreateWindowEx(0, _T("VentanaCacao"),
                                                  _T("VENTANA DE CACAO"),
                                                  WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                                  550,
                                                  150,
                                                  400,
                                                  400,
                                                  HWND_DESKTOP,
                                                  NULL,
                                                  Instancia,
                                                  NULL);

                    ShowWindow(VentanaCacao, SW_SHOW);

                    while (GetMessage(&MensajeComunicaMuestra, NULL, 0, 0) > 0)
                    {
                        TranslateMessage(&MensajeComunicaMuestra);
                        DispatchMessage(&MensajeComunicaMuestra);
                    }
                }
                else
                {
                    MessageBox(Ventana_Muestra, _T("No cumple con muestra requerida!"), _T("Mensaje"), MB_OK);
                }
            }
            catch (exception &e)
            {
                string message = e.what();
                string msg = "Error en los campos " + message;
                wstring wmsg(msg.begin(), msg.end());
                MessageBoxW(Ventana_Muestra, wmsg.c_str(), wmsg.c_str(), MB_ICONERROR);
            }
        }
        break;

        case SALIR:
            if (MessageBox(Ventana_Muestra, _T("Seguro que quieres salir?"), _T("SALIR "), MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(Ventana_Muestra);
            }
            break;

        case DESARROLLADORES:
            if (MessageBox(Ventana_Muestra, _T("- -"), _T("DESARROLLADORES: "), MB_OK))
            {
                SetFocus(GetDlgItem(Ventana_Muestra, DIGITA));
            }
            break;
        }

        break;

    default:
        return DefWindowProc(Ventana_Muestra, MensajeComunica, // garantiza que se procesen todos los mensajes
                             wParam, lParam);
    }

    return 0;
}

// Creacion de la ventana
int WINAPI WinMuestra(HINSTANCE hThisInstance,
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
    estilo1.lpfnWndProc = WindowsMuestra;
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