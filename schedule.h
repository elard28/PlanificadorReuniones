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
#include "hour.h"

using namespace std;

class schedule
{
private:
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
		//vector<hour> sun;
		hr["mon"]=mon;
		hr["tue"]=tue;
		hr["wed"]=wed;
		hr["thu"]=thu;
		hr["fri"]=fri;
		hr["sat"]=sat;
		//hr["sun"]=sun;
	}

	void add_text(char *txt)
	{
		string day;
		char chain[128];
    	ifstream fe(txt);
    	while(!fe.eof())
    	{
    		fe >> chain;
    		string chain_str=chain;
    		if(chain_str=="mon" || chain_str=="tue" || chain_str=="wed" || chain_str=="thu" || chain_str=="fri" || chain_str=="sat" /*||chain_str=="sun"*/)
  				day=chain_str;
  			else
  			{
  				char *cstr = new char [chain_str.length()+1];
  				strcpy (cstr, chain_str.c_str());

  				hour time;
  				time.set_text(cstr);
  				hr[day].push_back(time);
  				cout<<endl;
  				cout<<endl;
  			}
    	}
    	fe.close();
	}

	void add_time(string day, hour time)
	{
		hr[day].push_back(time);
	}

	vector<hour> get_day(string day)
	{
		return hr[day];
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