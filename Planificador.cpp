#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <map>

#include "schedule.h"

using namespace std;

vector<string> days;
vector<schedule> arr;

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
    days.push_back("mon");
    days.push_back("tue");
    days.push_back("wed");
    days.push_back("thu");
    days.push_back("fri");
    days.push_back("sat");

    if(argc<3)
    {
        cout<<"sin argumentos que tomar"<<endl;
        return 0;
    }

    string ar=argv[1];
    int times=convert(ar);
    cout<<"Minutos de diferencia: "<<times<<endl<<endl;

    for (int i = 2; i < argc; ++i)
    {
        string tmp=argv[i];
        tmp+=".txt";
        cout<<"Archivo "<<tmp<<":"<<endl;
        char *cstr = new char[tmp.length()+1];
        strcpy (cstr, tmp.c_str());
        schedule(cstr).print_schedule();
        ingresar(cstr);
        cout<<endl;
    }
    
    cout<<"Resultado: "<<endl;
    calcular(times);
    
	return 0;
}// probar con /a.out 00:45 a b c