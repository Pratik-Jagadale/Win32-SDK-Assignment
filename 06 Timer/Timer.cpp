//header
#include<windows.h>
//#include"MyWindow.h"
#define MYTIMER 102
int iPaintFlag = 0;

//global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Winmain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR
	lpszCmdLine, int iCmdShow)
{
	//variable declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	TCHAR str[] = TEXT("Hello World!!!");
	static HBRUSH brush[5];
	//code
	switch (iMsg)
	{
	case WM_CREATE:
		brush[0] = CreateSolidBrush(RGB(255, 0, 0));
		brush[1] = CreateSolidBrush(RGB(0, 255, 0));
		brush[2] = CreateSolidBrush(RGB(0, 0, 255));
		brush[3] = CreateSolidBrush(RGB(255, 255, 0));
		brush[4] = CreateSolidBrush(RGB(0, 255, 255));
		SetTimer(hwnd, MYTIMER, 1000, NULL);
		break;

	case WM_TIMER:
		KillTimer(hwnd, MYTIMER);
		if (iPaintFlag < 4)
		{
			iPaintFlag = iPaintFlag + 1;
		}
		else
		{
			iPaintFlag = 0;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		SetTimer(hwnd, MYTIMER, 1000, NULL);
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		//SelectObject(hdc, brush[iPaintFlag]);
		if (iPaintFlag == 0)
		{
			SelectObject(hdc, brush[0]);
			SetBkColor(hdc, RGB(255, 0, 0));
		}
		else if (iPaintFlag == 1)
		{
			SelectObject(hdc, brush[1]);
			SetBkColor(hdc, RGB(0, 255, 0));
		}
		else if (iPaintFlag == 2)
		{
			SelectObject(hdc, brush[2]);
			SetBkColor(hdc, RGB(0, 0, 255));
		}
		else if (iPaintFlag == 3)
		{
			SelectObject(hdc, brush[3]);
			SetBkColor(hdc, RGB(255, 255, 0));
		}
		else if (iPaintFlag == 4)
		{
			SelectObject(hdc, brush[4]);
			SetBkColor(hdc, RGB(0, 255, 255));
		}
		FillRect(hdc, &rc, brush[iPaintFlag]);
		//SetBkColor(hdc, RGB(255, 255, 255));
		SetTextColor(hdc, RGB(0, 0, 0));
		/*if (iPaintFlag == 1)
		{
			SetTextColor(hdc, RGB(255, 0, 0));
		}
		if (iPaintFlag == 2)
		{
			SetTextColor(hdc, RGB(0, 0, 255));
		}
		if (iPaintFlag == 3)
		{
			SetTextColor(hdc, RGB(0, 128, 0));
		}
		if (iPaintFlag == 4)
		{
			SetTextColor(hdc, RGB(225, 255, 0));
		}
		if (iPaintFlag == 5)
		{
			SetTextColor(hdc, RGB(225, 0, 255));
		}*/
		DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
