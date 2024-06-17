#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string highlightOccurrences(const string& str, const string& subStr)
{
    string result;
    size_t pos = 0;
    size_t subStrLen = subStr.length();

    while ((pos = str.find(subStr, pos)) != string::npos)
    {
        result.append(str, 0, pos);  // Добавить часть строки до подстроки
        result.append("(" + subStr + ")");  // Добавить подстроку в скобках
        pos += subStrLen;
        str = str.substr(pos);  // Обновить исходную строку, удаляя обработанную часть
    }

    result.append(str);  // Добавить остаток строки
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str = "abaracadabra";
    string subStr = "ab";

    string result = highlightOccurrences(str, subStr);
    cout << result << endl;  // Должен вывести "(ab)aracad(ab)ra"

    return 0;
}