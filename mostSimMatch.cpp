#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <list>
#include <regex>  


using namespace std;

string MATCHDATA = "../matchData.txt";

bool readMatchData(list<string> * p_matchData);
bool mostSimMatch(string iStr, string oStr);


int main()
{
	mostSimMatch("a", "b");
	system("pause");

	return 0;
}

bool readMatchData(list<string> * p_matchData)
{
	ifstream ifstrm = ifstream(MATCHDATA);
	if (!ifstrm.is_open())
	{
		cerr << "open " + MATCHDATA + " failed!" << endl;
		return false;
	}
	while (true)
	{
		string temp;
		ifstrm >> temp;
		if (temp.empty())
			break;
		p_matchData->push_back(temp);
	}
	ifstrm.close();
	return true;
}

bool mostSimMatch(string &iStr, string &oStr)
{
	list<string> matchData;
	bool isOk = readMatchData(&matchData);
	if (!isOk)
	{
		exit(-1);
	}

	for (auto dataIterator = matchData.begin(); dataIterator != matchData.end(); ++dataIterator)
	{
		string temp = *dataIterator;
		/*匹配输入字符串iStr和数据库中的字符串temp*/
		if (iStr.find(temp) != string::npos)
		{
			oStr = temp;
			return true;
		}
	}

	int index0 = string::npos, index1 = string::npos, index2 = string::npos, index3 = string::npos;
	for (auto dataIterator = matchData.begin(); dataIterator != matchData.end(); ++dataIterator)
	{
		string temp = *dataIterator;
		if ()
		{

		}
	}
			

	return true;
}