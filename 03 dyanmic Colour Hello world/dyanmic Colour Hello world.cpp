//My First Window
#include<Windows.h>

//Global function decleration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int iPaintFlag = 0;

//Winmain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declartion
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("My App");

	//code
	// initailization of WNDCLASSEX
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

	//create  window
	hwnd = CreateWindow(szAppName, TEXT("My First GUI Programing Window"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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
	PAINTSTRUCT Ps;
	RECT Rc;
	TCHAR str[] = TEXT("HELLO WORLD");
	//code
	switch (iMsg)
	{
	case WM_CHAR:

		switch (wParam)
		{
		case 'r':
			iPaintFlag = 1;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'R':
			iPaintFlag = 1;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'G':
			iPaintFlag = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'g':
			iPaintFlag = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;


		case 'Y':
			iPaintFlag = 3;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'y':
			iPaintFlag = 3;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'M':
			iPaintFlag = 4;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'm':
			iPaintFlag = 4;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case WM_LBUTTONDOWN:
			iPaintFlag = 5;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case WM_RBUTTONDOWN:
			iPaintFlag = 6;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		}
	case WM_PAINT:

		GetClientRect(hwnd, &Rc);
		hdc = BeginPaint(hwnd, &Ps);
		SetBkColor(hdc, RGB(0, 0, 0));
		if (iPaintFlag == 0)
		{
			SetTextColor(hdc, RGB(0, 255, 0));
		}
		else if (iPaintFlag == 1)
		{
			SetTextColor(hdc, RGB(255, 0, 0));
		}
		else if (iPaintFlag == 2)
		{
			SetTextColor(hdc, RGB(0, 128, 0));
		}
		else if (iPaintFlag == 3)
		{
			SetTextColor(hdc, RGB(255, 255, 0));
		}
		else if (iPaintFlag == 4)
		{
			SetTextColor(hdc, RGB(255, 0, 255));
		}
		else if (iPaintFlag == 5)
		{
			SetTextColor(hdc, RGB(255, 255, 255));
		}
		else if (iPaintFlag == 6)
		{
			SetTextColor(hdc, RGB(255, 69, 0));
		}


		DrawText(hdc, str, -1, &Rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &Ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}