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
    string half, other_half;
    while (getline(my_file, line))
    {
        half = line.substr(0, line.length()/2);
        other_half = line.substr(line.length()/2);
        char matching = matching_characters(half, other_half)[0];
        sum += priority(matching);
    }
	my_file.close();
    cout << sum << endl;
	return 0;
}
