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
}









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

int convertir(char *times)
{
    int hour;
    int minute;
    char *token;
    token=strtok(times,":");
    hour=atoi(token);
    token=strtok(NULL,":");
    minute=atoi(token);
    return (hour * 60) + minute;
}

int main(int argc, char const *argv[])
{
    load("a.txt", "a");
	load("b.txt", "b");
	count_day();
	//print();

    cout<<"_____________________________________________________________"<<endl<<endl;

    days.push_back("mon");
    days.push_back("tue");
    days.push_back("wed");
    days.push_back("thu");
    days.push_back("fri");
    days.push_back("sat");
    //days.push_back("sun");

    schedule a;
    a.add_text("a.txt");
    a.print_schedule();

    cout<<"------------------------------------"<<endl;

    schedule b;
    b.add_text("b.txt");
    b.print_schedule();
    cout<<endl;
    cout<<"================Res================"<<endl;

    schedule res=compare(45,a,b);
    res.print_schedule();

    /*for (int i = 1; i < argc; ++i)
    {
        string tex=argv[i];
        tex+=".txt";
        char *cstr = new char [tex.length()+1];
        strcpy (cstr, tex.c_str());
        schedule sch;
        sch.add_text(cstr);
        schedules.push_back(sch);
    }*/

    /*char hora[6];
    char file_a[100];
    char file_b[100];

    cout<<"Tiempo: ";
    cin>>hora;
    cout<<"Primer archivo: ";
    cin>>file_a;
    cout<<"Segundo archivo: ";
    cin>>file_b;

    int times = convertir(hora);

    string tex1=argv[2];
    tex1+=".txt";
    char *cstr1 = new char [tex1.length()+1];
    strcpy (cstr1, tex1.c_str());
    schedule a;
    a.add_text(cstr1);

    string tex2=argv[3];
    tex2+=".txt";
    char *cstr2 = new char [tex2.length()+1];
    strcpy (cstr2, tex2.c_str());
    schedule b;
    b.add_text(cstr2);

    schedule res=compare(times,a,b);
    res.print_schedule();*/

	return 0;
}