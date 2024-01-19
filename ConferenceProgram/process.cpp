#include "processing.h"
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;


int getDurationInMin(conf_prog* arr, conf_prog* arr_2) {
    int min_1;
    int min_2;
    if (arr->finish.hour > arr->start.hour) {
        min_1 = arr->finish.min + (arr->finish.hour - arr->start.hour - 1) * 60 + 60 - arr->start.min;
    }
    else {
        min_1 = arr->finish.min - arr->start.min;
    }
    if (arr_2->finish.hour > arr_2->start.hour) {
        min_2 = arr_2->finish.min + (arr_2->finish.hour - arr_2->start.hour - 1) * 60 + 60 - arr_2->start.min;
    }
    else {
        min_2 = arr_2->finish.min - arr_2->start.min;
    }
    return min_1 - min_2;
}


int getDuration(conf_prog* arr) {
    int min_1;
    if (arr->finish.hour > arr->start.hour) {
        min_1 = arr->finish.min + (arr->finish.hour - arr->start.hour - 1) * 60 + 60 - arr->start.min;
    }
    else {
        min_1 = arr->finish.min - arr->start.min;
    }
    return min_1;

}



int getDurationInStr(conf_prog* arr, conf_prog* arr_2) {
    if (strcmp(arr->reader.first_name, arr_2->reader.first_name) == 0) {
        return strcmp(arr->title, arr_2->title);
    }
    return strcmp(arr->reader.first_name, arr_2->reader.first_name);
}

void heapify(conf_prog* arr[], int n, int i, int(*filterParam)(conf_prog* element, conf_prog* element_2))
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && filterParam(arr[l], arr[largest])>0)
        largest = l;
    if (r < n && filterParam(arr[r], arr[largest]) > 0)
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, filterParam);
    }
}

void heapSortByTime(conf_prog* arr[], int m, int n, int(*filterParam)(conf_prog* element, conf_prog* element_2))
{
    n += 1;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, filterParam);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, filterParam);
    }
}

void merge(conf_prog* array[], int left, int right, int(*filterParam)(conf_prog* element, conf_prog* element_2)) {
    if (right <= left) return;
    //  double k = getDurationInMin(array[(left + right) / 2]);
    int i = left - 1, j = right + 1;

    while (true) {
        while (filterParam(array[++i], array[(left + right) / 2]) < 0);
        while (filterParam(array[--j], array[(left + right) / 2]) > 0);
        if (i <= j) {
            swap(array[i], array[j]);
        }
        else { break; }
    }
    if (j > left) { merge(array, left, j, filterParam); }
    if (i < right) { merge(array, i, right, filterParam); }
}

void heapify2(conf_prog* arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && getDurationInMin(arr[l], arr[largest])>0)
        largest = l;
    if (r < n && getDurationInMin(arr[r], arr[largest]) > 0)
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify2(arr, n, largest);
    }
}
void heapSort(conf_prog* arr[], int m, int n)
{
    n += 1;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify2(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify2(arr, i, 0);
    }
}
int getLongestProject(conf_prog* arr[]) {
    heapSort(arr, 0, (sizeof(arr) / sizeof(*arr)));
    return getDuration(arr[(sizeof(arr) / sizeof(*arr))]);
}

