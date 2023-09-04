#include "main.h"

void log::init()
{
    AllocConsole(); // 显示控制台
    FILE *stream;
    // system("chcp 65001");
    SetConsoleOutputCP(65001);
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONIN$", "r", stdin);
}

void log::Message(const char *text)
{
    printf("Message: %s\r\n", text);
}
