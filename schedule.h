//#ifndef SCHEDULE_H
//#define SCHEDULE_H

#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <fstream>

using namespace std;

class schedule
{
private:
	struct hour
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
		
		hour(){};
		
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
			cout<<"tokenhour1:"<<token<<endl;
			hour_ini=atoi(token);
			cout<<"hour_ini:"<<hour_ini<<endl;
			token = strtok(NULL, ":");
			cout<<"tokenmin1:"<<token<<endl;
			minute_ini=atoi(token);
			cout<<"minute_ini:"<<minute_ini<<endl;
		}

		void set_end_text(char *tok)
		{
			char *token;
			token=strtok(tok,":");
			cout<<"tokenhour2:"<<token<<endl;
			hour_end=atoi(token);
			cout<<"hour_end:"<<hour_end<<endl;
			token = strtok(NULL, ":");
			cout<<"tokenmin2:"<<token<<endl;
			minute_end=atoi(token);
			cout<<"minute_end:"<<minute_end<<endl;
		}

		/*void set_text(char *tok)
		{
			char *token;
			token=strtok(tok,"-");
			cout<<"token_text_ini:"<<token<<endl;
			set_ini_text(token);
			token = strtok(NULL, "-");
			cout<<"token_text_fin:"<<token<<endl;
			set_end_text(token);
		}*/

		void set_text(char *tok)
		{
			char *token;
			token=strtok(tok,":-");
			cout<<"tokenhour1: "<<token<<endl;
			hour_ini=atoi(token);
			token=strtok(NULL, ":-");
			cout<<"tokenminute1: "<<token<<endl;
			minute_ini=atoi(token);
			token=strtok(NULL, ":-");
			cout<<"tokenhour2: "<<token<<endl;
			hour_end=atoi(token);
			token=strtok(NULL, ":-");
			cout<<"tokenminute2: "<<token<<endl;
			minute_end=atoi(token);
		}

		void print()
		{
			cout<<hour_ini<<":"<<minute_ini<<"-"<<hour_end<<":"<<minute_end<<"   ";
		}

	};

	map<string,vector<hour> > hr;

public:
	schedule()
	{
		cout<<"inicio1"<<endl;
		vector<hour> mon;
		vector<hour> tue;
		vector<hour> wed;
		vector<hour> thu;
		vector<hour> fri;
		vector<hour> sat;
		cout<<"inicio2"<<endl;
		hr["mon"]=mon;
		hr["tue"]=tue;
		hr["wed"]=wed;
		hr["thu"]=thu;
		hr["fri"]=fri;
		hr["sat"]=sat;
		cout<<"inicio3"<<endl;
	}

	/*void add(string texto)
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
	}*/

	void add_text(char *txt)
	{
		string day;
		char chain[128];
    	ifstream fe(txt);
    	while(!fe.eof())
    	{
    		fe >> chain;
    		string chain_str=chain;
    		if(chain_str=="mon" || chain_str=="tue" || chain_str=="wed" || chain_str=="thu" || chain_str=="fri" || chain_str=="sat")
  			{
  				day=chain_str;
  				cout<<day<<endl;
  			}	
  			else
  			{
  				char *cstr = new char [chain_str.length()+1];
  				strcpy (cstr, chain_str.c_str());

  				hour time;
  				time.set_text(cstr);
  				time.print();
  				cout<<endl;
  				hr[day].push_back(time);
  				cout<<endl;
  				print_schedule();
  				cout<<endl;
  				cout<<"tiempo"<<endl<<endl;
  			}
    	}
    	fe.close();
	}

	void print_schedule()
	{
		for(map<string,vector<hour> >::iterator it=hr.begin(); it!=hr.end(); ++it)
    	{
    		cout << it->first << " => ";
    		for (int i = 0; i < it->second.size(); ++i)
    			it->second[i].print();
    		cout<<endl;
    	}	
	}

	//~schedule();

};




//#endif