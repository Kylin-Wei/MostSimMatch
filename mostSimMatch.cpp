#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <list>
#include <regex>  


using namespace std;

string MATCHDATA = "../matchData.txt";

bool readMatchData(list<string> * p_matchData);
bool mostSimMatch(string &iStr, string &oStr);


int main()
{
	string iStr("45G1");
	string oStr;
	mostSimMatch(iStr, oStr);
	cout << oStr;
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

	//int index0 = string::npos, index1 = string::npos, index2 = string::npos, index3 = string::npos;
	for (auto dataIterator = matchData.begin(); dataIterator != matchData.end(); ++dataIterator)
	{
		string temp = *dataIterator;
		std::regex reg(temp.replace(2, 1, "[a-zA-Z]"));
cout << temp << endl;
		std::smatch matchResult;
		if (std::regex_search((string::const_iterator)iStr.begin(), (string::const_iterator)iStr.end(), matchResult, reg))
		{
			if (matchResult[2].str() == "6")
			{
				oStr = matchResult.str().replace(2, 1, "G");
			}
			else
			{
				oStr = matchResult.str().replace(2, 1, "U");
			}
			return true;
		}
	}
			
	return true;
}