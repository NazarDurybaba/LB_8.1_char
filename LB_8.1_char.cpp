#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

int Count(char* s) // s = �������� �� ������� �����
{
    int k = 0,
        pos = 0; // pos = ������� ������� ������
    char* t;
    while (t = strstr(s + pos, "abc")) // t = �������� �� "abc"
    {
        pos = t - s + 1; // pos = ��������� ������ ���� "abc"
        k++;
    }
    return k;
}

char* Change(char* s) // s = �������� �� ������� �����
{
    char* t = new char[strlen(s) * 2]; 
    char* p;
    int pos1 = 0, // pos1 = ������� ������� ������
        pos2 = 0;
    *t = 0;
    while (p = strstr(s + pos1, "abc")) // p = �������� �� "abc"
    {
        pos2 = p - s + 3; // pos2 = ������� ���������� ������� ���� "abc"
        strncat_s(t, strlen(s) * 2, s + pos1, pos2 - pos1 - 3);

        strcat_s(t, strlen(s) * 2, "**");

        pos1 = pos2;
    }
    if (pos1 < strlen(s)) {
        strcat_s(t, strlen(s) * 2, s + pos1);
    }

    strcpy_s(s, strlen(t) + 1, t);

    return t;
}

int main()
{
    SetConsoleOutputCP(1251);
    char str[101];
    cout << "������ �����:" << endl;
    cin.getline(str, 100);
    cout << "����� ������ " << Count(str) << " ���� ���� 'abc'" << endl;
    char* dest = new char[201];
    dest = Change(str);
    cout << "������� ����� (��������) : " << str << endl;
    cout << "������� ����� (���������): " << dest << endl;
    return 0;
}
