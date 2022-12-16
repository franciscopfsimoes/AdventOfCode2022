#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void print_set(set<char> myset){
     for (set<char>::iterator it=myset.begin(); it!=myset.end(); ++it)
        cout << ' ' << *it;
        cout << '\n';
}

int main() {
	ifstream my_file;
	my_file.open("input.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
        return -1;
	}
    string line;

    int pos = 0;
    string assignments, interval;
    set<char> substr;
    while (getline(my_file, line))
    {
        for(int i=0; i<line.length(); i++){
            if(!(substr.empty())){
                if(substr.count(line[i]) != 0){
                    cout << "conflicting " << line[i] << endl;
                    i = i - substr.size() + 1;
                    substr.clear();
                }
            }
            substr.insert(line[i]);
            print_set(substr);
            if(substr.size() == 14){pos = i + 1; break;}
        }
    }
	my_file.close();
    cout << pos  << endl;
	return 0;
}
