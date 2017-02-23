#include "parse_input.h"
using namespace std;



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
	ourData->video_arr = new Video[ourData->v];

	int i = 0, j = 0;
	for (i = 0; i < ourData->v; i++)
	{
		cin >> video_stize_temp;
		ourData->video_arr[i].size = stoi(video_stize_temp);
	}

	string latancy_temp, num_of_caches_temp, cache_id_temp, cache_latancy_temp;
	for (i = 0; i < ourData->e; i++)
	{
		cin >> latancy_temp;
		ourData->endpoint_data_arr[i].data_center_latency = stoi(latancy_temp);
		cin >> num_of_caches_temp;
		ourData->endpoint_data_arr[i].num_of_caches = stoi(num_of_caches_temp);
		ourData->endpoint_data_arr[i].caches_latency = new int[ourData->c];

		for (j = 0; j < ourData->c; j++)
		{
			
			ourData->endpoint_data_arr[i].caches_latency[j] = 0;
		}

		for (j = 0; j < ourData->endpoint_data_arr[i].num_of_caches; j++)
		{
			cin >> cache_id_temp >> cache_latancy_temp;
			ourData->endpoint_data_arr[i].caches_latency[stoi(cache_id_temp)] = stoi(cache_latancy_temp);
		}

	}
	string req_video_temp, req_endpoint_temp, req_size_temp;

	for (i = 0; i < ourData->r; i++)
	{
		cin >> req_video_temp >> req_endpoint_temp >> req_size_temp;
		Requests* req_temp = new Requests();
		req_temp->endpoint = stoi(req_endpoint_temp);
		req_temp->size = stoi(req_size_temp);
		ourData->video_arr[stoi(req_video_temp)].req.insert(ourData->video_arr[stoi(req_video_temp)].req.begin(), req_temp);
	}
}

int main()
{
	Data* ourData = new Data();
	parser(ourData);
	return 0;
}