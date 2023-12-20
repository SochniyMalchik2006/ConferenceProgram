#include <iostream>

using namespace std;

#include"conf_prog.h"
#include"constants.h"
#include"file_reader.h"
void output(conf_prog* rose)
{
    cout << "����� �������....   ";
    cout << rose->reader.first_name << ' ';
    cout << rose->reader.maddle_name << ' ';
    cout << rose->reader.last_name << '\n';
    cout << "������ �������....  ";
    cout << rose->start.hour << ':';
    cout << rose->start.min << '\n';
    cout << "����� �������...    ";
    cout << rose->finish.hour << ':';
    cout << rose->finish.min << '\n';
    cout << "���� �������....    ";
    cout << rose->title << '\n';
    cout << '\n';
}



int main()
{

    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #2. Conference Program\n";
    cout << "Author: Roman Tikhonov\n";
    cout << "Group 14\n";

    setlocale(LC_ALL, "RUSSIAN");
    cout << "������������ ������ #8.GIT\n";
    cout << "������� #2. ��������� �����������\n";
    cout << "�����: ����� �������\n";
    conf_prog* roses[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", roses, size);
        cout << "***** ��������� ����������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "����� �������....   ";
            cout << roses[i]->reader.first_name << ' ';
            cout << roses[i]->reader.maddle_name << ' ';
            cout << roses[i]->reader.last_name << '\n';
            cout << "������ �������....  ";
            cout << roses[i]->start.hour << ':';
            cout << roses[i]->start.min << '\n';
            cout << "����� �������...    ";
            cout << roses[i]->finish.hour << ':';
            cout << roses[i]->finish.min << '\n';
            cout << "���� �������....    ";
            cout << roses[i]->title << '\n';
            cout << '\n';
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    return 0;
}
