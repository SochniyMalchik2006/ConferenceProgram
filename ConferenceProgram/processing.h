#pragma once
#ifndef PROCESSING_H
#define PROCESSING_H

#include "conf_prog.h"

void heapSortByTime(conf_prog* arr[], int m, int n, int(*filterParam)(conf_prog* element, conf_prog* element_2));
void merge(conf_prog* array[], int left, int right, int(*filterParam)(conf_prog* element, conf_prog* element_2));
int getDurationInStr(conf_prog* arr, conf_prog* arr_2);
int getDurationInMin(conf_prog* arr, conf_prog* arr_2);

#endif
