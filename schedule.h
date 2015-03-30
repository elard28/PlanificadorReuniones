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
		hr["mon"]=vector<hour>();
		hr["tue"]=vector<hour>();
		hr["wed"]=vector<hour>();
		hr["thu"]=vector<hour>();
		hr["fri"]=vector<hour>();
		hr["sat"]=vector<hour>();
	}
	
	schedule(char *txt)
	{
		hr["mon"]=vector<hour>();
		hr["tue"]=vector<hour>();
		hr["wed"]=vector<hour>();
		hr["thu"]=vector<hour>();
		hr["fri"]=vector<hour>();
		hr["sat"]=vector<hour>();
		
		add_text(txt);
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

  				hour times(cstr);
  				add_time(day,times);
  			}
    	}
    	fe.close();
	}
	
	bool find(string day, hour times)
	{
	    vector<hour>::iterator it;
	    for(it = hr[day].begin() ; it != hr[day].end(); ++it)
	    {
	        if(*it == times)
	            return 1;
	    }
        return 0;
	}

	bool add_time(string day, hour time)
	{
		if(find(day,time))
		    return 0;
		hr[day].push_back(time);
		return 1;
	}

	vector<hour> get_day(string day)
	{
		return hr[day];
	}

	map<string,vector<hour> > get_schedule()
	{
		return hr;
	}

	void print_schedule()
	{
		for(map<string,vector<hour> >::iterator it=hr.begin(); it!=hr.end(); ++it)
    	{
    		if(it->second.size() > 0)
    		{
    			cout << it->first << " =>\t";
    			for (int i = 0; i < it->second.size(); ++i)
    				it->second[i].print();
    			cout<<endl;
    		}
    	}	
	}

	//~schedule();

};




//#endif