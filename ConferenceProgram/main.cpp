#include <iostream>

using namespace std;

#include"conf_prog.h"
#include"constants.h"
#include"file_reader.h"
#include"filter_reader.h"
#include"processing.h"

void output(conf_prog* rose)
{
    cout << "Àâòîð äîêëàäà....   ";
    cout << rose->reader.first_name << ' ';
    cout << rose->reader.maddle_name << ' ';
    cout << rose->reader.last_name << '\n';
    cout << "Íà÷àëî äîêëàäà....  ";
    cout << rose->start.hour << ':';
    cout << rose->start.min << '\n';
    cout << "Êîíåö äîêëàäà...    ";
    cout << rose->finish.hour << ':';
    cout << rose->finish.min << '\n';
    cout << "Òåìà äîêëàäà....    ";
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
    cout << "Ëàáîðàòîðíàÿ ðàáîòà #8.GIT\n";
    cout << "Âàðèàíò #2. Ïðîãðàììà êîíôåðåíöèè\n";
    cout << "Àâòîð: Ðîìàí Òèõîíîâ\n";
    conf_prog* roses[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", roses, size);
        cout << "***** Ïðîãðàììà êîíôåðåíöèè *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(roses[i]);
        }

        bool (*check_function)(conf_prog*) = NULL;
        void (*sorting)(conf_prog * [], int, int, int  (*filterParam)(conf_prog*, conf_prog*)) = NULL;
        int  (*filterParam)(conf_prog*, conf_prog*) = NULL;

        bool flag = true;
        while (flag) {
            cout << "Âûáåðèòå ôèëüòðàöèþ  : \n1. Âûâåñòè âñå äîêëàäû Èâàíîâà Èâàíà Èâàíîâè÷à.\n2.Âûâåñòè âñå äîêëàäû äëèòåëüíîñòüþ áîëüøå 15 ìèíóò.\n\n0.Âûõîä\n\n->";
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
                throw " Íåò òàêîé ôèëüòðàöèè ";
            }

            cout << "Âûáåðèòå ñîðòèðîâêó  : \n1.Ïèðàìèäàëüíàÿ ñîðòèðîâêà (Heap sort)\n2.Ñîðòèðîâêà ñëèÿíèåì (Merge sort)\n\n0.Âûõîä\n\n->";
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
                throw " Íåò òàêîé ôèëüòðàöèè ";
            }

            cout << "Âûáåðèòå ïàðàìåòð ñîðòèðîâêè  : \n1.Ïî óáûâàíèþ äëèòåëüíîñòè äîêëàäà (ðàçíèöû ìåæäó âðåìåíåì îêîí÷àíèÿ è íà÷àëà äîêëàäà)\n2.Ïî âîçðàñòàíèþ ôàìèëèè àâòîðà äîêëàäà, à â ðàìêàõ îäíîãî àâòîðà ïî âîçðàñòàíèþ òåìû äîêëàäà\n\n0.Âûõîä\n\n->";
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
                throw " Íåò òàêîé ôèëüòðàöèè ";
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

    return 0;
}
