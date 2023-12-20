#include <iostream>

using namespace std;

#include"conf_prog.h"
#include"constants.h"
#include"file_reader.h"
void output(conf_prog* rose)
{
    cout << "Автор доклада....   ";
    cout << rose->reader.first_name << ' ';
    cout << rose->reader.maddle_name << ' ';
    cout << rose->reader.last_name << '\n';
    cout << "Начало доклада....  ";
    cout << rose->start.hour << ':';
    cout << rose->start.min << '\n';
    cout << "Конец доклада...    ";
    cout << rose->finish.hour << ':';
    cout << rose->finish.min << '\n';
    cout << "Тема доклада....    ";
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
    cout << "Лабораторная работа #8.GIT\n";
    cout << "Вариант #2. Программа конференции\n";
    cout << "Автор: Роман Тихонов\n";
    conf_prog* roses[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", roses, size);
        cout << "***** Программа конференции *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Автор доклада....   ";
            cout << roses[i]->reader.first_name << ' ';
            cout << roses[i]->reader.maddle_name << ' ';
            cout << roses[i]->reader.last_name << '\n';
            cout << "Начало доклада....  ";
            cout << roses[i]->start.hour << ':';
            cout << roses[i]->start.min << '\n';
            cout << "Конец доклада...    ";
            cout << roses[i]->finish.hour << ':';
            cout << roses[i]->finish.min << '\n';
            cout << "Тема доклада....    ";
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
