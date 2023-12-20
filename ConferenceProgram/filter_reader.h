#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "conf_prog.h"
conf_prog** filter(conf_prog* array[], int size, bool (*check)(conf_prog* element), void(*sorting)(conf_prog* element[], int m, int size, int(*filterParam)(conf_prog* element, conf_prog* element_2)), int(*filterParam)(conf_prog* element, conf_prog* element_2), int& result_size);
bool check_book_subscription_by_name(conf_prog* element);
bool check_book_subscription_by_speed(conf_prog* element);

#endif