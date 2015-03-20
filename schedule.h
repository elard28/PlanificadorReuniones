#ifndef SCHEDULE_H
#deende SCHEDULE_H

#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility>

using namespace std;

class schedule
{
private:
	class hour
	{
		int hour_ini;
		int minute_ini;
		int hour_end;
		int minute_end;
		hour(int hini,int mini,int hend,int mend)
		{
			hour_ini=hini;
			minute_ini=mini;
			hour_end=hend;
			minute_end=mend;
		}
		
		hour();
		
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

		void set_ini_text(char *tok)
		{
			char *token;
			token=strtok(tok,":");
			hour_ini=atoi(token);
			token = strtok(NULL, ":");
			minute_ini=atoi(token);
		}

		void set_end_text(char *tok)
		{
			char *token;
			token=strtok(tok,":");
			hour_end=atoi(token);
			token = strtok(NULL, ":");
			minute_end=atoi(token);
		}

		void set_text(char *tok)
		{
			char *token;
			token=strtok(tok,"-");
			set_ini_text(token);
			token = strtok(NULL, "-");
			set_end_text(token);
		}
	};

	map<string,vector<hour> > hr;

public:
	schedule()
	{
		vector<hour> mon;
		vector<hour> tue;
		vector<hour> wed;
		vector<hour> thu;
		vector<hour> fri;
		vector<hour> sat;

		hr["mon"]=mon;
		hr["tue"]=tue;
		hr["wed"]=wed;
		hr["thu"]=thu;
		hr["fri"]=fri;
		hr["sat"]=sat;
	}

	void add(string texto)
	{
		string day;
		char *cstr = new char [texto.length()+1];
  		strcpy (cstr, texto.c_str());
  		char *token;
  		token=strtok(cstr," ");
  		while(token!=NULL)
  		{
  			if(token=="mon" || token=="tue" || token=="wed" || token=="thu" || token=="fri" || token=="sat")
  				day=token;
  			else
  			{
  				hour time;
  				time.set_text(token);
  				hr[day].push_back(time);
  			}
  			token = strtok(NULL, " ");
  		}
	}

	~schedule();

};




#endif