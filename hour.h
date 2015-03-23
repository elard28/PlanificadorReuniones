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

		hour cross(hour &hour2) //mayor y luego menor
		{
			hour result;

			if( hour_end <= hour2.hour_ini || 
				hour2.hour_end <= hour_ini)
			return result;

			int hini=0;
			int mini=0;
			int hend=0;
			int mend=0;

			/*if(hour_end == hour2.hour_ini)
			{
				if(minute_end < hour2.minute_ini)
			}*/

			if( hour_ini <= hour2.hour_ini && 
				hour_end >= hour2.hour_end)
			{
				//result.set_values(hour2.hour_ini, hour2.minute_ini, hour2.hour_end, hour2.minute_end);
				hini=hour2.hour_ini;
				mini=hour2.minute_ini;
				hend=hour2.hour_end;
				mend=hour2.minute_end;
			}
				
			else if(hour_ini >= hour2.hour_ini && 
					hour_end <= hour2.hour_end)
			{
				//result.set_values(hour_ini, minute_ini, hour_end, minute_end);
				hini=hour_ini;
				mini=minute_ini;
				hend=hour_end;
				mend=minute_end;
			}
				
			else if(hour_ini <= hour2.hour_ini && 
					hour_end <= hour2.hour_end && 
					hour2.hour_ini < hour_end)
			{
				//result.set_values(hour2.hour_ini, hour2.minute_ini, hour_end, hour_end);
				hini=hour2.hour_ini;
				mini=hour2.minute_ini;
				hend=hour_end;
				mend=minute_end;
			}
				
			else if(hour_ini >= hour2.hour_ini && 
					hour_end >= hour2.hour_end && 
					hour2.hour_end > hour_ini)
			{
				//result.set_values(hour_ini, minute_ini, hour2.hour_end, hour2.minute_end);
				hini=hour_ini;
				mini=minute_ini;
				hend=hour2.hour_end;
				mend=hour2.minute_end;
			}

			if(hour_ini == hour2.hour_ini)
			{
				if(minute_ini >= hour2.minute_ini)
					mini=minute_ini;
				else mini=hour2.minute_ini;
			}

			if(hour_end == hour2.hour_end)
			{
				if(minute_end <= hour2.minute_end)
					mend=minute_end;
				else mend=hour2.minute_end;
			}

			result.set_values(hini,mini,hend,mend);
		}

		void print()
		{
			cout<<hour_ini<<":"<<minute_ini<<"-"<<hour_end<<":"<<minute_end<<"  ";
		}
	};