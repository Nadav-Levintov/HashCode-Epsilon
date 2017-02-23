#ifndef PARSE_INPUT
#define PARSE_INPUT 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class Data
{
public:
	int v, e, r, c, x;
	int *video_sizes;
	Endpoint_Data* endpoint_data_arr;

	~Data()
	{
		delete[] video_sizes;
	}
};

class Endpoint_Data
{
public:
	int data_center_latency;
	int num_of_caches;
	int *caches_latency;
};

#endif // !PARSE_INPUT