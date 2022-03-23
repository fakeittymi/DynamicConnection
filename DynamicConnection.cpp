#include <iostream>
#include <Windows.h>

int main()
{
    typedef long double(*MyFunction)(double, long int);
    MyFunction FuncPtr;
    setlocale(2, "Russian");
    HINSTANCE dllInstance = LoadLibrary(L"MyDLL.dll");
    if (dllInstance == NULL) {
        std::cout << "Couldn't get DLL instance";
        return 1;
    }
    FuncPtr = (MyFunction)GetProcAddress(dllInstance,"SomeF");
    if (FuncPtr == NULL) {
        std::cout << "Couldn't get function";
        return 2;
    }
    double x = 0;
    long int y = 0;
    std::cout << "Введите Х:\n";
    std::cin >> x;
    std::cout << "Введите Y:\n";
    std::cin >> y;
    std::cout << "Answer = " << FuncPtr(x, y) << "\n";
    FreeLibrary(dllInstance);
    system("PAUSE");
}
