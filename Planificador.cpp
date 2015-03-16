#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> archives;

void load(char* filename){
    ifstream ar(filename);
    char* buff[200];
    string cad;
    while (ar>>buff){
	cad = cad + buff;
    }
    cout << cad << endl; 
}

int main()
{

	return 0;
}
