// Cplus2_benchmark.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <random>
using namespace std;

int times = 100000000;
string Chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string rndword;

inline SYSTEMTIME showNowTime()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	char szTime[25] = { 0 };
	return st;
}

void _tmain(int argc, _TCHAR* argv[])
{
	cout << times << "回ループします" << endl;

	SYSTEMTIME starttime = showNowTime();
	cout << "start : " << starttime.wMinute << ":" << starttime.wSecond << "." << starttime.wMilliseconds << endl;
	
	for (int i = 0; i < times; i++)
	{
		for (int i = 0; i < 10; i++){
			rndword += Chars[rand() % 62];
		}
		rndword = "";
	}

	SYSTEMTIME endtime = showNowTime();
	cout << "end : " << endtime.wMinute << ":" << endtime.wSecond << "." << endtime.wMilliseconds << endl;

	SYSTEMTIME margin;
	UINT64 time1, time2;
	SystemTimeToFileTime(&starttime, (FILETIME *)&time1);
	SystemTimeToFileTime(&endtime, (FILETIME *)&time2);
	time2 = time2 - time1;
	FileTimeToSystemTime((FILETIME *)&time2, &margin);
	cout << "margin : " << margin.wMinute << ":" << margin.wSecond << "." << margin.wMilliseconds << endl;

	cout << "何かのキーを押してください" << endl;
	getchar();
}

