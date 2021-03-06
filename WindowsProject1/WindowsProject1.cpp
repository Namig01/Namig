// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100



// Глобальные переменные:



Property m_Property;

HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Menu(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
			case ID_32771:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Menu);
				InvalidateRect(hWnd, 0, true); //перерисовка 
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
			{
				HPEN hNewPen = CreatePen(PS_SOLID, m_Property.width, RGB(m_Property.m_Color.r, m_Property.m_Color.g, m_Property.m_Color.b));
				HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);

				m_Property.m_Point.x = 500.f;
				m_Property.m_Point.y = 300.f;
				m_Property.rept = 5;
				Star m_Star(m_Property.rept, 100, 255, m_Property.m_Point, m_Property.corner);
				m_Star.Draw(hdc);

				//DragonCurve m_DragonCurve;
				//Point<float> OneCoordinate((Point<float>)m_Property.m_Point);
				//Point<float> TwoCoordinate(0.f, 0.f);
				//Point<float> ThreeCoordinate(0.f, 0.f);
				//m_DragonCurve.Draw(hdc, m_Property.rept, OneCoordinate, TwoCoordinate, ThreeCoordinate);
				DeleteObject(hNewPen);

				

				//HPEN nPen = CreatePen(PS_SOLID, m_Property.width, RGB(m_Property.m_Color.r, m_Property.m_Color.g, m_Property.m_Color.b));
				//HPEN PenS = (HPEN)SelectObject(hdc, nPen);
				//Meander m_Meandr;
				//m_Meandr.Draw(hdc, m_Property.rept, m_Property.m_Point.x, m_Property.m_Point.y, m_Property.time);
				//DeleteObject(nPen);
			}

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


INT_PTR CALLBACK Menu(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	int wmId;

	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId = LOWORD(wParam);

		//Меню
		switch (wmId)
		{	
		case IDOK:
		{
			m_Property.width = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, NULL);
			m_Property.rept = GetDlgItemInt(hDlg, IDC_EDIT2, NULL, NULL);
			m_Property.m_Color.r = GetDlgItemInt(hDlg, IDC_EDIT3, NULL, NULL);
			m_Property.m_Color.g = GetDlgItemInt(hDlg, IDC_EDIT4, NULL, NULL);
			m_Property.m_Color.b = GetDlgItemInt(hDlg, IDC_EDIT5, NULL, NULL);
			m_Property.m_Point.x = GetDlgItemInt(hDlg, IDC_EDIT6, NULL, NULL);
			m_Property.m_Point.y = GetDlgItemInt(hDlg, IDC_EDIT7, NULL, NULL);
			m_Property.time = GetDlgItemInt(hDlg, IDC_EDIT8, NULL, NULL);

	
		}
		case IDCANCEL:
			EndDialog(hDlg, wmId);
			return (INT_PTR)FALSE;
			break;
		}

		break;
	}
	return (INT_PTR)FALSE;
}
