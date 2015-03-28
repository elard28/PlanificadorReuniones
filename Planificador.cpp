#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <map>

#include "schedule.h"

using namespace std;

/*typedef vector<string> type_time;
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

	cout << "day contains:\n";

 	for (; it!=tmp_day.end(); ++it){
    	cout << "   " << it->first << " => ";
    	print(it->second);
    	cout << endl;	
    }
}

void print(){
	map<string,type_calendar>::iterator it = users.begin();

	cout << "archives contains:\n";

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
}*/









vector<schedule> schedules;
vector<string> days;


schedule compare(int min, schedule a,schedule b)
{
    schedule result;
    for (int i = 0; i < days.size(); ++i)
    {
        vector<hour> hour_a=a.get_day(days[i]);
        vector<hour> hour_b=b.get_day(days[i]);

        for (int j = 0; j < hour_a.size(); ++j)
        {
            for (int k = 0; k < hour_b.size(); ++k)
            {
                hour hour_cross=hour_a[j].cross(hour_b[k]);
                if(hour_cross.is_valid && hour_cross.get_time_minutes()>=min)
                    result.add_time(days[i],hour_cross);
            }
        }

    }
    return result;
}

int convert(string times)
{
    int hour;
    int minute;

    char *cstr = new char [times.length()+1];
    strcpy (cstr, times.c_str());

    char *token;
    token=strtok(cstr,":");
    hour=atoi(token);
    token=strtok(NULL,":");
    minute=atoi(token);
    return (hour * 60) + minute;
}

vector<schedule> arr;

void ingresar(char* filename){
	arr.push_back(schedule(filename));
}

void calcular(int time){
	schedule cal;
	cal = arr[0];
	for (int i=1; i < arr.size();i++){
        cal = compare(time,cal,arr[i]);
	}
	cal.print_schedule();
}

int main(int argc, char const *argv[])
{
    /*load("a.txt", "a");
	load("b.txt", "b");

	count_day();
	//print();*/


    days.push_back("mon");
    days.push_back("tue");
    days.push_back("wed");
    days.push_back("thu");
    days.push_back("fri");
    days.push_back("sat");
    //days.push_back("sun");

    if(argc<3)
    {
        cout<<"sin argumentos que tomar"<<endl;
        return 0;
    }

    string ar=argv[1];
    int times=convert(ar);

    for (int i = 2; i < argc; ++i)
    {
        cout<<"----------------------------------------------------------------"<<endl;
        string tmp=argv[i];
        tmp+=".txt";
        cout<<tmp<<endl;
        char *cstr = new char[tmp.length()+1];
        strcpy (cstr, tmp.c_str());
        schedule(cstr).print_schedule();
        ingresar(cstr);
    }
    cout<<"_____________________________________________________________"<<endl<<endl;
    cout<<"Result"<<endl;
    calcular(times);
    

	return 0;
}// probar con /a.out 00:45 a b c