#include <iostream>

using namespace std;

#include"conf_prog.h"
#include"constants.h"
#include"file_reader.h"
#include"filter_reader.h"
#include"processing.h"

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
    cout << "Group: 21PINZH1D\n";

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
            output(roses[i]);
        }

        bool (*check_function)(conf_prog*) = NULL;
        void (*sorting)(conf_prog * [], int, int, int  (*filterParam)(conf_prog*, conf_prog*)) = NULL;
        int  (*filterParam)(conf_prog*, conf_prog*) = NULL;

        bool flag = true;
        while (flag) {
            cout << "�������� ����������  : \n1. ������� ��� ������� ������� ����� ���������.\n2.������� ��� ������� ������������� ������ 15 �����.\n\n0.�����\n\n->";
            int item;
            cin >> item;
            switch (item)
            {
            case 1:
                check_function = check_book_subscription_by_name;
                break;
            case 2:
                check_function = check_book_subscription_by_speed;
                break;
            case 0:
                flag = 0;
                break;
            default:
                throw " ��� ����� ���������� ";
            }

            cout << "�������� ����������  : \n1.������������� ���������� (Heap sort)\n2.���������� �������� (Merge sort)\n\n0.�����\n\n->";
            cin >> item;
            switch (item)
            {
            case 1:
                sorting = heapSortByTime;
                break;
            case 2:
                sorting = merge;
                break;
            case 0:
                flag = 0;
                break;
            default:
                throw " ��� ����� ���������� ";
            }

            cout << "�������� �������� ����������  : \n1.�� �������� ������������ ������� (������� ����� �������� ��������� � ������ �������)\n2.�� ����������� ������� ������ �������, � � ������ ������ ������ �� ����������� ���� �������\n\n0.�����\n\n->";
            cin >> item;
            switch (item)
            {
            case 1:
                filterParam = getDurationInMin;
                break;
            case 2:
                filterParam = getDurationInStr;
                break;
            case 0:
                flag = 0;
                break;
            default:
                throw " ��� ����� ���������� ";
            }


            if (check_function)
            {
                int new_size;


                conf_prog** filtered = filter(roses, size, check_function, sorting, filterParam, new_size);
                for (int i = 0; i < new_size; i++)
                {
                    output(filtered[i]);
                }
                delete[] filtered;
            }

            for (int i = 0; i < size; i++)
            {
                delete roses[i];
            }
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

>>>>>>> dev
    return 0;
}
