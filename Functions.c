#include <Windows.h>

void gotoxy(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorCoord;
    cursorCoord.X = y;
    cursorCoord.Y = x;
    SetConsoleCursorPosition(consoleHandle, cursorCoord);
}

void setTextColor(int textColor, int backColor = 0)
{

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

void changeScreenSize(COORD NewSize)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;

    GetConsoleScreenBufferInfo(hOut, &SBInfo);

    DisplayArea.Bottom = NewSize.Y;
    DisplayArea.Right = NewSize.X;

    SetConsoleWindowInfo(hOut, true, &DisplayArea);
}

void hideCursor()
{
    HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO CURSOR;
    CURSOR.dwSize = 1;
    CURSOR.bVisible = FALSE;
    SetConsoleCursorInfo(myconsole, &CURSOR);
}