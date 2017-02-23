#include "parse_input.h"
using namespace std;

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

void parser(Data* ourData)
{
	string videosS, endpointS, requestS, cacheS, sizeS;

	cin >> videosS >> endpointS >> requestS >> cacheS >> sizeS;

	ourData->v = stoi(videosS);
	ourData->e = stoi(endpointS);
	ourData->r = stoi(requestS);
	ourData->c = stoi(cacheS);
	ourData->x = stoi(sizeS);

	ourData->endpoint_data_arr = new Endpoint_Data[ourData->e];

	string video_stize_temp;
	ourData->video_sizes = new int[ourData->v];

	int i = 0, j = 0;
	for (i = 0; i < ourData->v; i++);
	{
		cin >> video_stize_temp;
		ourData->video_sizes[i] = stoi(video_stize_temp);
	}

	string latancy_temp, num_of_caches_temp,cache_id_temp,cache_latancy_temp;
	for (i = 0; i < ourData->e; i++);
	{
		cin >> latancy_temp;
		ourData->endpoint_data_arr[i].data_center_latency = stoi(latancy_temp);
		cin >> num_of_caches_temp;
		ourData->endpoint_data_arr[i].num_of_caches = stoi(num_of_caches_temp);
		ourData->endpoint_data_arr[i].caches_latency = new int[ourData->endpoint_data_arr[i].num_of_caches];
		for (j = 0; j < ourData->endpoint_data_arr[i].num_of_caches; j++)
		{
			cin >> cache_id_temp >> cache_latancy_temp;
			ourData->endpoint_data_arr[i].caches_latency[stoi(cache_id_temp)] = stoi(cache_latancy_temp);
		}

	}


}