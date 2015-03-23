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
<<<<<<< HEAD
    calendar.insert( std::pair<string,type_time>(day, times) );
=======
    calendar.insert( pair<string,type_time>(day, times) );
>>>>>>> 8afb8d87a57fd82da092a2a837e5bba10b66858e
    users.insert( pair<string,type_calendar>(username, calendar) );
}

void print(vector<string> tmp_time){
	vector<string>::iterator it = tmp_time.begin();
 	for (; it!=tmp_time.end(); ++it)
    	cout << "   " << *it << " ";	
}

void print(map<string, type_time > tmp_day){
	map<string,type_time>::iterator it = tmp_day.begin();
<<<<<<< HEAD
	cout << "day contains:\n";
=======
	cout << "time contains:\n";
>>>>>>> 8afb8d87a57fd82da092a2a837e5bba10b66858e
 	for (; it!=tmp_day.end(); ++it){
    	cout << "   " << it->first << " => ";
    	print(it->second);
    	cout << endl;	
    }
}

void print(){
	map<string,type_calendar>::iterator it = users.begin();
<<<<<<< HEAD
	cout << "archives contains:\n";
=======
	cout << "mymap contains:\n";
>>>>>>> 8afb8d87a57fd82da092a2a837e5bba10b66858e
 	for (it = users.begin(); it!=users.end(); ++it){
    	cout << it->first << " => " << '\n';
    	print(it->second);
 	}
}


void count_day(){
	string days[7] = {"mon","tue","wed","thu","fri","sat","sun"};
	int n_days[7] = {0,0,0,0,0,0,0};

	map<string,type_calendar>::iterator it = users.begin();

	for (it = users.begin(); it!=users.end(); ++it){
		map<string,type_time>::iterator it2 = it->second.begin();

		for (; it2!=it->second.end(); ++it2){
			for (int i=0; i<7;i++){
				if (it2->first == days[i]){
					n_days[i]++;
					break;
				}
			}
		}
	}

	for (int i=0;i<7;i++)
		cout << days[i] << " = " << n_days[i] << endl;
}

int main()
{
    load("a.txt", "a");
	load("b.txt", "b");
	count_day();
	//print();

    schedule sch;

	return 0;
}