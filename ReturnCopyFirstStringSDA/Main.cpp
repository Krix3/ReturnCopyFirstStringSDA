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
        result.append(str, 0, pos);  // �������� ����� ������ �� ���������
        result.append("(" + subStr + ")");  // �������� ��������� � �������
        pos += subStrLen;
        str = str.substr(pos);  // �������� �������� ������, ������ ������������ �����
    }

    result.append(str);  // �������� ������� ������
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str = "abaracadabra";
    string subStr = "ab";

    string result = highlightOccurrences(str, subStr);
    cout << result << endl;  // ������ ������� "(ab)aracad(ab)ra"

    return 0;
}