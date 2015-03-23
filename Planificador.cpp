#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <map>

using namespace std;

typedef std::vector<string> type_time;
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
			calendar.insert( std::pair<string,type_time>(day,times) );
			times.clear();
			day = buff;
		}else{
			r_time = buff;
			times.push_back(r_time);
		}
    }
    calendar.insert( std::pair<string,type_time>(day, times) );
    users.insert( std::pair<string,type_calendar>(username, calendar) );
}

void print(vector<string> tmp_time){
	std::vector<string>::iterator it = tmp_time.begin();
 	for (; it!=tmp_time.end(); ++it)
    	std::cout << "   " << *it << " ";	
}

void print(map<string, type_time > tmp_day){
	std::map<string,type_time>::iterator it = tmp_day.begin();
	std::cout << "time contains:\n";
 	for (; it!=tmp_day.end(); ++it){
    	std::cout << "   " << it->first << " => ";
    	print(it->second);
    	cout << endl;	
    }
}

void print(){
	std::map<string,type_calendar>::iterator it = users.begin();
	std::cout << "mymap contains:\n";
 	for (it = users.begin(); it!=users.end(); ++it){
    	std::cout << it->first << " => " << '\n';
    	print(it->second);
 	}
} 

int main()
{
	load("a.txt", "a");
	load("b.txt", "b");
	print();

	return 0;
}