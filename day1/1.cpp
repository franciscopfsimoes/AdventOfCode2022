#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	ifstream my_file;
	my_file.open("input1.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
        return -1;
	}
    string line;
    int max_sum, acc = 0;

    while (getline(my_file, line))
    {
        istringstream iss(line);
        int a;
        if (!(iss >> a)) {if(acc > max_sum) {max_sum = acc;} acc=0; continue;} // finds a blank space
        acc = acc + a;
    }
    cout << max_sum << "\n";
	my_file.close();
	return 0;
}
