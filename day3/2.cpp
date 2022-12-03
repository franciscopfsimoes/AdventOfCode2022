#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
string matching_characters(string s1, string s2) {
  sort(begin(s1), end(s1));
  sort(begin(s2), end(s2));
  string intersection;
  set_intersection(begin(s1), end(s1), begin(s2), end(s2),
                        back_inserter(intersection));
  return intersection;
}

int priority(char c){
    int value = c - 97 + 1; //asci code for letter "a" is 97
    if(value < 1){value = c - 65 + 1 + 26;} //asci code for letter "A" is 65
    return value;
}


int main() {
	ifstream my_file;
	my_file.open("input.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
        return -1;
	}
    string line;

    int sum = 0;
    int i = 0;
    string old_line, intersection;
    while (getline(my_file, line))
    {
        if(i == 0){old_line = line;}
        if(i == 1){intersection = matching_characters(line, old_line);};
        if(i == 2){char matching = matching_characters(line, intersection)[0];sum += priority(matching); i = -1;}
        i++;
        //cout << matching << priority(matching)  <<endl; 
    }
	my_file.close();
    cout << sum << endl;
	return 0;
}
