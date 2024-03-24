#include <tchar.h> //Usamos esta libreria para castear cadenas
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

// Macros o identificadores
#define CACAO 101
#define SALIR 102
#define SALIR1 103

#define DESARROLLADORES 103
#define MENU 205
#define MUESTRA 301
#define MUESTRA_ARROZ 302
#define INVENTARIO 303

#define DIGITA 110
#define RESUL 120

LRESULT CALLBACK WindowsMuestra(HWND ventana_muestra,
                                UINT MensajeComunica,
                                WPARAM wParam,
                                LPARAM lParam);

LRESULT CALLBACK WindowsMuestraArroz(HWND ventana_muestra_arroz,
                                     UINT MensajeComunica,
                                     WPARAM wParam,
                                     LPARAM lParam);

LRESULT CALLBACK WindowsInventario(HWND ventana_inventario,
                                   UINT MensajeComunica,
                                   WPARAM wParam,
                                   LPARAM lParam);

LRESULT CALLBACK WindowProcedures(HWND ventana2,
                                  UINT MensajeComunica,
                                  WPARAM wParam,
                                  LPARAM lParam)
{

    HWND controles;
    static HINSTANCE Instancia;
    BOOL exito = FALSE;
    int numero = 0; // SendDlgItemMessage Envía un mensaje

    switch (MensajeComunica)
    {

    case WM_DESTROY:
        PostQuitMessage(0); // solicita al sistema terminar(salir)
        break;

    case WM_CREATE:

        Instancia = ((LPCREATESTRUCT)lParam)->hInstance;

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Manejo de cacao"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   110, 110, 150, 22, ventana2,
                                   (HMENU)MUESTRA, Instancia,
                                   NULL);

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Manejo de arroz"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   110, 140, 150, 22, ventana2,
                                   (HMENU)MUESTRA_ARROZ, Instancia,
                                   NULL);

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Salir"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   110, 170, 150, 22, ventana2,
                                   (HMENU)SALIR1, Instancia,
                                   NULL);
        break;

    // DAR FUNCIONALIDAD A TODOS LOS CONTROLES
    case WM_COMMAND:

        // ESCOGE EL CONTROL QUE SELECCIONAMOS AL QUE SE LE DARÁ UNA FUNCIÓN
        switch (LOWORD(wParam))
        {

        case MUESTRA:
        {
            WNDCLASSEX estiloMuestra;
            HWND VentanaMuestra;
            MSG MensajeComunicaMuestra;

            estiloMuestra.hInstance = Instancia;
            estiloMuestra.lpszClassName = _T("VentanaMuestra");
            estiloMuestra.lpfnWndProc = WindowsMuestra;
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
                estiloMuestra.lpszClassName = _T("VentanaMuestra");
                estiloMuestra.lpfnWndProc = WindowsMuestra;
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

            VentanaMuestra = CreateWindowEx(0, _T("VentanaMuestra"),
                                            _T("VENTANA DE MUESTRA"),
                                            WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                            550,
                                            150,
                                            400,
                                            400,
                                            HWND_DESKTOP,
                                            NULL,
                                            Instancia,
                                            NULL);

            ShowWindow(VentanaMuestra, SW_SHOW);

            while (GetMessage(&MensajeComunicaMuestra, NULL, 0, 0) > 0)
            {
                TranslateMessage(&MensajeComunicaMuestra);
                DispatchMessage(&MensajeComunicaMuestra);
            }

            // Código para limpiar y liberar recursos cuando se cierra la ventana de MUESTRA
            // ...
        }
        break;

        case MUESTRA_ARROZ:
        {
            WNDCLASSEX estiloMuestraArroz;
            HWND VentanaMuestraArroz;
            MSG MensajeComunicaMuestraArroz;

            estiloMuestraArroz.hInstance = Instancia;
            estiloMuestraArroz.lpszClassName = _T("VentanaMuestraArroz");
            estiloMuestraArroz.lpfnWndProc = WindowsMuestraArroz;
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
                estiloMuestraArroz.lpszClassName = _T("VentanaMuestraArroz");
                estiloMuestraArroz.lpfnWndProc = WindowsMuestraArroz;
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

            VentanaMuestraArroz = CreateWindowEx(0, _T("VentanaMuestraArroz"),
                                                 _T("VENTANA DE MUESTRA ARROZ"),
                                                 WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                                 550,
                                                 150,
                                                 400,
                                                 400,
                                                 HWND_DESKTOP,
                                                 NULL,
                                                 Instancia,
                                                 NULL);

            ShowWindow(VentanaMuestraArroz, SW_SHOW);

            while (GetMessage(&MensajeComunicaMuestraArroz, NULL, 0, 0) > 0)
            {
                TranslateMessage(&MensajeComunicaMuestraArroz);
                DispatchMessage(&MensajeComunicaMuestraArroz);
            }

            // Código para limpiar y liberar recursos cuando se cierra la ventana de muestra
            // ...
        }
        break;

        case SALIR1:
            if (MessageBox(ventana2, _T("Seguro que quieres salir ventana menu?"), _T("SALIR "), MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
            {
                std::cout << "entro en salir";
                DestroyWindow(ventana2);
            }
            break;
        }

        break;

    default:
        return DefWindowProc(ventana2, MensajeComunica, // garantiza que se procesen todos los mensajes
                             wParam, lParam);
    }

    return 0;
}

// prototipo de procedimiento de ventana
LRESULT CALLBACK WindowProcedure(HWND ventana1,
                                 UINT MensajeComunica,
                                 WPARAM wParam,
                                 LPARAM lParam)
{

    HWND controles;
    static HINSTANCE Instancia;
    BOOL exito = FALSE;
    int numero = 0; // SendDlgItemMessage Envía un mensaje

    switch (MensajeComunica)
    {

    case WM_DESTROY:
        PostQuitMessage(0); // solicita al sistema terminar(salir)
        break;

    case WM_CREATE:

        Instancia = ((LPCREATESTRUCT)lParam)->hInstance;

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Manejo de cultivos"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   110, 110, 150, 22, ventana1,
                                   (HMENU)MENU, Instancia,
                                   NULL);

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Inventarios de cultivos"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   110, 140, 150, 22, ventana1,
                                   (HMENU)INVENTARIO, Instancia,
                                   NULL);

        controles = CreateWindowEx(0, _T("BUTTON"), _T("Salir"),
                                   BS_CENTER | BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE,
                                   110, 170, 150, 22, ventana1,
                                   (HMENU)SALIR, Instancia,
                                   NULL);
        break;

    // DAR FUNCIONALIDAD A TODOS LOS CONTROLES
    case WM_COMMAND:

        // ESCOGE EL CONTROL QUE SELECCIONAMOS AL QUE SE LE DARÁ UNA FUNCIÓN
        switch (LOWORD(wParam))
        {

        case MENU:
        {
            WNDCLASSEX estiloMenu;
            HWND ventanaMenu;
            MSG MensajeComunicaMenu;

            estiloMenu.hInstance = Instancia;
            estiloMenu.lpszClassName = _T("VentanaMenu");
            estiloMenu.lpfnWndProc = WindowProcedures;
            estiloMenu.style = CS_DBLCLKS;
            estiloMenu.cbSize = sizeof(WNDCLASSEX);
            estiloMenu.hIcon = LoadIcon(NULL, IDI_QUESTION);
            estiloMenu.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
            estiloMenu.hCursor = LoadCursor(NULL, IDC_HAND);
            estiloMenu.lpszMenuName = NULL;
            estiloMenu.cbClsExtra = 0;
            estiloMenu.cbWndExtra = 0;
            estiloMenu.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;

            if (!RegisterClassEx(&estiloMenu))
            {
                WNDCLASSEX estiloMenu;

                estiloMenu.hInstance = Instancia;
                estiloMenu.lpszClassName = _T("VentanaMenu");
                estiloMenu.lpfnWndProc = WindowProcedures;
                estiloMenu.style = CS_DBLCLKS;
                estiloMenu.cbSize = sizeof(WNDCLASSEX);
                estiloMenu.hIcon = LoadIcon(NULL, IDI_QUESTION);
                estiloMenu.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
                estiloMenu.hCursor = LoadCursor(NULL, IDC_HAND);
                estiloMenu.lpszMenuName = NULL;
                estiloMenu.cbClsExtra = 0;
                estiloMenu.cbWndExtra = 0;
                estiloMenu.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;
            }

            ventanaMenu = CreateWindowEx(0, _T("VentanaMenu"),
                                         _T("VENTANA DE MENU"),
                                         WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                         550,
                                         150,
                                         400,
                                         400,
                                         HWND_DESKTOP,
                                         NULL,
                                         Instancia,
                                         NULL);

            ShowWindow(ventanaMenu, SW_SHOW);

            while (GetMessage(&MensajeComunicaMenu, NULL, 0, 0) > 0)
            {
                TranslateMessage(&MensajeComunicaMenu);
                DispatchMessage(&MensajeComunicaMenu);
            }
        }
        break;

        case INVENTARIO:
        {
            WNDCLASSEX estiloMuestraArroz;
            HWND VentanaInventario;
            MSG MensajeComunicaMuestraArroz;

            estiloMuestraArroz.hInstance = Instancia;
            estiloMuestraArroz.lpszClassName = _T("VentanaInventario");
            estiloMuestraArroz.lpfnWndProc = WindowsInventario;
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
                estiloMuestraArroz.lpszClassName = _T("VentanaInventario");
                estiloMuestraArroz.lpfnWndProc = WindowsInventario;
                estiloMuestraArroz.style = CS_DBLCLKS;
                estiloMuestraArroz.cbSize = sizeof(WNDCLASSEX);
                estiloMuestraArroz.hIcon = LoadIcon(NULL, IDI_QUESTION);
                estiloMuestraArroz.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
                estiloMuestraArroz.hCursor = LoadCursor(NULL, IDC_HAND);
                estiloMuestraArroz.lpszMenuName = NULL;
                estiloMuestraArroz.cbClsExtra = 0;
                estiloMuestraArroz.cbWndExtra = 0;
                estiloMuestraArroz.hbrBackground = (HBRUSH)COLOR_GRADIENTACTIVECAPTION;

                // return 0;
            }

            VentanaInventario = CreateWindowEx(0, _T("VentanaInventario"),
                                               _T("VENTANA DE INVENTARIO"),
                                               WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                                               550,
                                               150,
                                               400,
                                               400,
                                               HWND_DESKTOP,
                                               NULL,
                                               Instancia,
                                               NULL);
            std::cout << "ENTRO";
            ShowWindow(VentanaInventario, SW_SHOW);

            while (GetMessage(&MensajeComunicaMuestraArroz, NULL, 0, 0) > 0)
            {
                TranslateMessage(&MensajeComunicaMuestraArroz);
                DispatchMessage(&MensajeComunicaMuestraArroz);
            }

            // Código para limpiar y liberar recursos cuando se cierra la ventana de muestra
            // ...
        }
        break;

        case SALIR:
            if (MessageBox(ventana1, _T("Seguro que quieres salir?"), _T("SALIR "), MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
            {
                PostQuitMessage(0);
            }
            break;

        case DESARROLLADORES:
            if (MessageBox(ventana1, _T("- Ponce Yimi"), _T("DESARROLLADORES: "), MB_OK))
            {
                SetFocus(GetDlgItem(ventana1, DIGITA));
            }
            break;
        }

        break;

    default:
        return DefWindowProc(ventana1, MensajeComunica, // garantiza que se procesen todos los mensajes
                             wParam, lParam);
    }

    return 0;
}

// Creacion de la ventana
int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nCmdShow)
{
    WNDCLASSEX estilo1;
    HWND ventana1;
    HWND ventana2;
    MSG MensajeComunica;
    estilo1.hInstance = hThisInstance;
    estilo1.lpszClassName = _T("Ventana");
    estilo1.lpfnWndProc = WindowProcedure;
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

    ventana1 = CreateWindowEx(0, _T("Ventana"),
                              _T("VENTANA PRINCIPAL"),
                              WS_MINIMIZEBOX | WS_CAPTION | WS_POPUPWINDOW,
                              550,
                              150,
                              400,
                              400,
                              HWND_DESKTOP,
                              NULL,
                              hThisInstance,
                              NULL);

    ShowWindow(ventana1, nCmdShow);
    ShowWindow(GetConsoleWindow(), SW_HIDE); // ESCONDE LA CONSOLA

    while (GetMessage(&MensajeComunica, NULL, 0, 0) > 0) // CICLO DE MENSAJES
    {
        TranslateMessage(&MensajeComunica);

        DispatchMessage(&MensajeComunica);
    }
    return MensajeComunica.wParam;
}