#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;
int main() {
	ifstream my_file;
	my_file.open("input1.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
        return -1;
	}
    string line;
    int  acc = 0;
    vector<int> calories(3, 0);
    while (getline(my_file, line))
    {
        istringstream iss(line);
        int a;
        if (!(iss >> a)) {
            auto min_cal = min_element(calories.begin(), calories.end());
            if(acc > *min_cal){
                int position = distance(begin(calories), min_cal);
                calories[position] = acc;
            }
            acc=0; 
            continue;
        } // finds a blank space
        acc = acc + a;
    }
    auto result = accumulate(calories.begin(), calories.end(), 0);
    cout << result << endl;
	my_file.close();
	return 0;
}
