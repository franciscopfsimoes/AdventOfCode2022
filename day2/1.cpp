#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	ifstream my_file;
	my_file.open("input.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
        return -1;
	}
    string line;

    int score = 0;
    while (getline(my_file, line))
    {
        istringstream iss(line);
        char  oponent, me, c;
        if (!(iss >> oponent >> me >> c)) {
            if(me == 'X'){score = score + 1; if(oponent == 'C'){score = score + 6;} if(oponent == 'A'){score = score + 3;}} //rock
            if(me == 'Y'){score = score + 2; if(oponent == 'A'){score = score + 6;} if(oponent == 'B'){score = score + 3;}} //paper
            if(me == 'Z'){score = score + 3; if(oponent == 'B'){score = score + 6;} if(oponent == 'C'){score = score + 3;}} //scisors
        }
    }
    cout << score << endl;
	my_file.close();
	return 0;
}
