#include "parse_input.h"
using namespace std;

class Data
{
public:
	int v, e, r, c, x;
	int *video_sizes;
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

	string *video_sizesS = new string[ourData->v];
	ourData->video_sizes = new string[ourData->v];
	int i = 0;
	for (i = 0; i < ourData->v; i++);
	{
		cin>> video_sizesS[i];
	}


}