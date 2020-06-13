#include <windows.h>

#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    int x = MessageBox(NULL, TEXT("Hello World\nThis is Windows Programming"), TEXT("Process Scanner"), 1);
    printf("%d", x);
    return 0;
}
