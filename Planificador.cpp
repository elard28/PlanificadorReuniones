#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <map>

#include "schedule.h"

using namespace std;

typedef vector<string> type_time;
typedef map<string, type_time > type_calendar;

map<string,type_calendar > users;

void load(char* filename, char* username){
    ifstream ar(filename);
    type_calendar calendar;
    string day, r_time;
    type_time times;
    char buff[200];

    ar >> buff;
    day = buff;
    
    while (ar >> buff){
		if (isalpha(buff[0])){
			calendar.insert( pair<string,type_time>(day,times) );
			times.clear();
			day = buff;
		}else{
			r_time = buff;
			times.push_back(r_time);
		}
    }
    calendar.insert( pair<string,type_time>(day, times) );
    users.insert( pair<string,type_calendar>(username, calendar) );
}

void print(vector<string> tmp_time){
	vector<string>::iterator it = tmp_time.begin();
 	for (; it!=tmp_time.end(); ++it)
    	cout << "   " << *it << " ";	
}

void print(map<string, type_time > tmp_day){
	map<string,type_time>::iterator it = tmp_day.begin();
	cout << "time contains:\n";
 	for (; it!=tmp_day.end(); ++it){
    	cout << "   " << it->first << " => ";
    	print(it->second);
    	cout << endl;	
    }
}

void print(){
	map<string,type_calendar>::iterator it = users.begin();
	cout << "mymap contains:\n";
 	for (it = users.begin(); it!=users.end(); ++it){
    	cout << it->first << " => " << '\n';
    	print(it->second);
 	}
}


int main()
{
    load("a.txt", "a");
	load("b.txt", "b");
	print();

    schedule sch;

	return 0;
}