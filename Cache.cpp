#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct cacheTable{
	bool valid = false;
	int tag;};
int block_add[32], miss = 0, hit = 0;
int main(int argc, char *argv[])
	{
	string filename(argv[1]);
	int number=0;
	ifstream input_file(filename);
	if (*argv[2] == '1')
		{
		cacheTable directMap [1024];
		if(!input_file.is_open())
			{
				cout<<"file is not open "<<filename<<endl;
			}
		else
			{
			while(input_file >> number)
				{
				//to get line by line code
				//To convert integer into binary
				int i=0;
				while(number!=0)
					{
					block_add[i]=number%2; //remainder
					i++; //index increments
					number=number/2; //For next
					}
				for(int j=i;j<32;j++){
					block_add[j]=0;}
				//To convert index from binary to integer.
				int baseForIndex=1 , baseForTag = 1, index=0, tag = 0;
				for(int k =0; k < 9; k++){
					index += block_add[k] * baseForIndex;
					baseForIndex = baseForIndex * 2;}
				cout<< index << "\t";
				//To convert tag from binary to integer.
				for(int k =10; k < 32; k++){
					tag += block_add[k] * baseForTag;
					baseForTag = baseForTag * 2;}
				cout<< tag << "\n";
				//to Delete all record from block_add
				for(int j=0;j<32;j++){
					block_add[j]=0;}
				if (directMap[index].valid == false)
					{
					directMap[index] = {true, tag};
					++miss;
					}
				else if (directMap[index].valid == true && directMap[index].tag == tag)
					{
					++hit;
					}
				else
					{
					directMap[index] = {true, tag};
					++miss;}
					}
			input_file.close();
			cout<< "Total No. of Misses are " <<miss<<" Total No. of Hits are "<<hit;
				}
			}
	if (*argv[2] == '4')
		{
		cacheTable fourWay [256][4];
		if(!input_file.is_open())
			{
				cout<<"file is not open "<<filename<<endl;
			}
		else
			{
			while(input_file >> number)
				{
				//to get line by line code
				//To convert integer into binary
				int i=0;
				while(number!=0)
					{
					block_add[i]=number%2; //remainder
					i++; //index increments
					number=number/2; //For next
					}
				for(int j=i;j<32;j++){
					block_add[j]=0;}
				//To convert index from binary to integer.
				int baseForIndex=1 , baseForTag = 1, index=0, tag = 0;
				for(int k =0; k < 9; k++){
					index += block_add[k] * baseForIndex;
					baseForIndex = baseForIndex * 2;}
				cout<< index << "\t";
				//To convert tag from binary to integer.
				for(int k =10; k < 32; k++){
					tag += block_add[k] * baseForTag;
					baseForTag = baseForTag * 2;}
				cout<< tag << "\n";
				//to Delete all record from block_add
				for(int j=0;j<32;j++){
					block_add[j]=0;}
				if (fourWay[index/4][0].valid == false && fourWay[index/4][1].valid == false && fourWay[index/4][2].valid == false && fourWay[index/4][3].valid == false)
					{
						fourWay[index/4][0] = {true, tag};
						++miss;
					}
					else if (fourWay[index/4][0].valid == true || fourWay[index/4][1].valid == true || fourWay[index/4][2].valid == true || fourWay[index/4][3].valid == true)
					{
						for (int j = 0; j < 4; ++j)
						{
							if (fourWay[index/4][j].valid == true && fourWay[index/4][j].tag == tag)
							{
								++hit;
								break;
							}
							else if (fourWay[index/4][j].valid == false)
							{
								fourWay[index/4][j] = {true, tag};
								++miss;
								break;
								
							}
							else
							{
								fourWay[index/4][j] = {true, tag};
								++miss;
								break;
								
							}
						}
					}
				}
			input_file.close();
			}
		cout<< "Total No. of Misses are " <<miss<<" Total No. of Hits are "<<hit;
		}
	if (*argv[2] == '8')
		{
		cacheTable eightWay [128][8];
		if(!input_file.is_open())
			{
				cout<<"file is not open "<<filename<<endl;
			}
		else
			{
			while(input_file >> number)
				{
				//to get line by line code
				//To convert integer into binary
				int i=0;
				while(number!=0)
					{
					block_add[i]=number%2; //remainder
					i++; //index increments
					number=number/2; //For next
					}
				for(int j=i;j<32;j++){
					block_add[j]=0;}
				//To convert index from binary to integer.
				int baseForIndex=1 , baseForTag = 1, index=0, tag = 0;
				for(int k =0; k < 9; k++){
					index += block_add[k] * baseForIndex;
					baseForIndex = baseForIndex * 2;}
				cout<< index << "\t";
				//To convert tag from binary to integer.
				for(int k =10; k < 32; k++){
					tag += block_add[k] * baseForTag;
					baseForTag = baseForTag * 2;}
				cout<< tag << "\n";
				//to Delete all record from block_add
				for(int j=0;j<32;j++){
					block_add[j]=0;}
				if (eightWay[index/8][0].valid == false && eightWay[index/8][1].valid == false && eightWay[index/8][2].valid == false && eightWay[index/8][3].valid == false && eightWay[index/8][4].valid == false && eightWay[index/8][5].valid == false && eightWay[index/8][6].valid == false && eightWay[index/8][7].valid == false)
					{
						eightWay[index/8][0] = {true, tag};
						++miss;
					}
					else if (eightWay[index/8][0].valid == true || eightWay[index/8][1].valid == true || eightWay[index/8][2].valid == true || eightWay[index/8][3].valid == true || eightWay[index/8][4].valid == true || eightWay[index/8][5].valid == true || eightWay[index/8][6].valid == true || eightWay[index/8][7].valid == true)
					{
						for (int j = 0; j < 8; ++j)
						{
							if (eightWay[index/8][j].valid == true && eightWay[index/8][j].tag == tag)
							{
								++hit;
								break;
							}
							else if (eightWay[index/8][j].valid == false)
							{
								eightWay[index/8][j] = {true, tag};
								++miss;
								break;
								
							}
							else
							{
								eightWay[index/8][j] = {true, tag};
								++miss;
								break;
								
							}
						}
					}
				}
			input_file.close();
			}
		cout<< "Total No. of Misses are " <<miss<<" Total No. of Hits are "<<hit;
		}
	if (*argv[2] == '2')
		{
		cacheTable twoWay [512][2];
		if(!input_file.is_open())
			{
				cout<<"file is not open "<<filename<<endl;
			}
		else
			{
			while(input_file >> number)
				{
				//to get line by line code
				//To convert integer into binary
				int i=0;
				while(number!=0)
					{
					block_add[i]=number%2; //remainder
					i++; //index increments
					number=number/2; //For next
					}
				for(int j=i;j<32;j++){
					block_add[j]=0;}
				//To convert index from binary to integer.
				int baseForIndex=1 , baseForTag = 1, index=0, tag = 0;
				for(int k =0; k < 9; k++){
					index += block_add[k] * baseForIndex;
					baseForIndex = baseForIndex * 2;}
				cout<< index << "\t";
				//To convert tag from binary to integer.
				for(int k =10; k < 32; k++){
					tag += block_add[k] * baseForTag;
					baseForTag = baseForTag * 2;}
				cout<< tag << "\n";
				//to Delete all record from block_add
				for(int j=0;j<32;j++){
					block_add[j]=0;}
				if ((twoWay[index/2][0].valid == false) && (twoWay[index/2][1].valid == false))
						{
						twoWay[index/2][0] = {true, tag};
						++miss;
						}
				else
						{
						for (int j = 0; j < 2; ++j)
							{
							if (twoWay[index/2][j].valid == true && twoWay[index/2][j].tag == tag)
							{
								++hit;
								break;
							}
							else if (twoWay[index/2][j].valid == false)
							{
								twoWay[index/2][j] = {true, tag};
								++miss;
								break;
								
							}
							else
							{
								twoWay[index/2][j] = {true, tag};
								++miss;
								break;
								
							}
							}
						}
				}
			input_file.close();
			}
		cout<< "Total No. of Misses are " <<miss<<" Total No. of Hits are "<<hit;
		}
	}
