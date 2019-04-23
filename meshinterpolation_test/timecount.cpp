#include "stdafx.h"
#include "timecount.h"
#include <io.h>//access
struct log
{
	float duration;
};

log logdata;

clock_t start_time;
clock_t end_time;

void timeStart()
{
	cout << "time : begin" << endl;
	start_time = clock();
};

void timeEnd()
{
	end_time = clock();
	float duration = (end_time - start_time) / (float)1000;
	logdata.duration = duration;
	cout<< "	duration " << duration << " sec" << endl;
	cout << "time : end" << endl;
};



void writelog_console()
{
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, "log.txt", "a");

	if(err == 0)//fopen_s error
	{
		time_t timer;
		struct tm t;
		timer = time(NULL);
		localtime_s(&t, &timer);

		fprintf(fp, "logtime %d/%d/%d %d:%d:%d", t.tm_year,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);
		fprintf(fp, ", duration %f sec\n", logdata.duration);
		
		fclose(fp);
	}
	else
	{
		printf("file error during : writelog_console\n");
	}
};

void resetlog()
{
	char* path = "log.txt";
	if(access(path, 0) == 0)
	{
		remove(path);
	}
};

void endstop()
{
	printf("\n>> End of Procedure, Press Any Key to Close\n");
	_getch();
};