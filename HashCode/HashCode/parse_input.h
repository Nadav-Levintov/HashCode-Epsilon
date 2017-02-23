#ifndef PARSE_INPUT
#define PARSE_INPUT 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>

class Requests {
public:
	int size;
	int endpoint;
	Requests(){}

};

class Video {
public:
	int size;
	std::list<Requests*> req;
	std::list<Requests*>::iterator req_it;
};

class Endpoint_Data
{
public:
	int data_center_latency;
	int num_of_caches;
	int *caches_latency;
	Endpoint_Data()
	{
		caches_latency = NULL;
	}
	~Endpoint_Data()
	{
		delete[] caches_latency;
	}
};


class Data
{
public:
	int v, e, r, c, x;
	Video *video_arr;
	Endpoint_Data *endpoint_data_arr;
	
	Data()
	{
		video_arr = NULL;
		endpoint_data_arr = NULL;
	}


	~Data()
	{
		delete[] video_arr;
	}
};



#endif // !PARSE_INPUT