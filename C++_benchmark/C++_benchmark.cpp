// C++_benchmark.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <random>
#include <time.h>
#include <windows.h>
using namespace std;

int times = 100000000;
string Chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string _RandomChars(int length){
	srand((unsigned)time(NULL));
	string sb = "";
	for (int i = 0; i < length; i++)
	{
		int pos = rand() % Chars.size() + 1;
		sb += Chars[pos];
	}
	return sb;
}

SYSTEMTIME showNowTime()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	char szTime[25] = { 0 };
	return st;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << times << "回ループします" << endl;
	
	SYSTEMTIME starttime = showNowTime();
	cout << "start : " << starttime.wMinute << ":" << starttime.wSecond << "." << starttime.wMilliseconds << endl;

	for (int i = 0; i < times; i++)
	{
		_RandomChars(10);
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


	return 0;
}

