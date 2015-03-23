#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <fstream>

using namespace std;

struct hour
	{
		int hour_ini;
		int minute_ini;
		int hour_end;
		int minute_end;

		bool no_empty;

		hour(int hini,int mini,int hend,int mend)
		{
			hour_ini=hini;
			minute_ini=mini;
			hour_end=hend;
			minute_end=mend;
			no_empty=1;
		}
		
		hour()
		{
			no_empty=0;	
		};

		void set_values(int hini,int mini,int hend,int mend)
		{
			hour_ini=hini;
			minute_ini=mini;
			hour_end=hend;
			minute_end=mend;
			no_empty=1;
		}
		
		void set_ini(int hini,int mini)
		{
			hour_ini=hini;
			minute_ini=mini;
		}

		void set_end(int hend,int mend)
		{
			hour_end=hend;
			minute_end=mend;
		}

		void set_text(char *tok)
		{
			char *token;
			token=strtok(tok,":-");
			hour_ini=atoi(token);
			token=strtok(NULL, ":-");
			minute_ini=atoi(token);
			token=strtok(NULL, ":-");
			hour_end=atoi(token);
			token=strtok(NULL, ":-");
			minute_end=atoi(token);
			no_empty=1;
		}

		hour cross(hour &hour_cross) //mayor y luego menor
		{
			hour result;
			//int hini;
			//int mini;
			//int hend;
			//int mend;
			if(hour_ini <= hour_cross.hour_ini && hour_end >= hour_cross.hour_end)
				result.set_values(hour_cross.hour_ini, hour_cross.minute_ini, hour_cross.hour_end, hour_cross.minute_end);

			else if(hour_ini >= hour_cross.hour_ini && hour_end <= hour_cross.hour_end)
				result.set_values(hour_ini, minute_ini, hour_end, minute_end);

			else if(hour_ini <= hour_cross.hour_ini && hour_end <= hour_cross.hour_end && hour_cross.hour_ini <= hour_end)
				result.set_values(hour_cross.hour_ini, hour_cross.minute_ini, hour_end, hour_end);

			else if(hour_ini >= hour_cross.hour_ini && hour_end >= hour_cross.hour_end && hour_cross.hour_ini >= hour_end)
				result.set_values(hour_ini, minute_ini, hour_cross.hour_end, hour_cross.minute_end);

			return result;
		}

		void print()
		{
			cout<<hour_ini<<":"<<minute_ini<<"-"<<hour_end<<":"<<minute_end<<"  ";
		}
	};