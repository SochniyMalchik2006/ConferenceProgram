#include "file_reader.h"
#include "processing.h"
#include <cstring>
#include <iostream>
#include "filter_reader.h"

conf_prog** filter(conf_prog* array[], int size, bool (*check)(conf_prog* element), void(*sorting)(conf_prog* element[], int m, int size, int(*filterParam)(conf_prog* element, conf_prog* element_2)), int(*filterParam)(conf_prog* element, conf_prog* element_2), int& result_size)
{
	conf_prog** result = new conf_prog * [size];
	result_size = 0;
	sorting(array, 0, size - 1, filterParam);

	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}


bool check_book_subscription_by_name(conf_prog* element)
{

	return strcmp(element->reader.first_name, "Иванов") == 0 &&
		strcmp(element->reader.maddle_name, "Иван") == 0 &&
		strcmp(element->reader.last_name, "Иванович") == 0;


}

bool check_book_subscription_by_speed(conf_prog* element)
{
	return element->finish.min - element->start.min >= 15;
}