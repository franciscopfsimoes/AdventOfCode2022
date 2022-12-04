#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int is_overlap(int assign[2][2]){
    int res = 0;
    if(assign[0][0] <= assign[1][1]){
        if(assign[0][1] >= assign[1][0]){ res = 1; }
    }
    if( assign[0][1] >= assign[1][0]){
        if(assign[0][0] <= assign[1][1]) { res = 1; }
    }
    return res;
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
    string assignments, interval;
    int assign[2][2]; 
    while (getline(my_file, line))
    {
        stringstream ss(line);
        for(int j = 0; j < 2; j++){
            getline(ss, assignments, ',');
            stringstream sss(assignments);
            for(int i = 0; i < 2; i++){
                getline(sss, interval, '-');
                assign[j][i] = stoi(interval);
            }
        }
        sum += is_overlap(assign);
        //cout << assign[0][0] << " " << assign[0][1] << "\t" << assign[1][0] << " " << assign[1][1] << endl;
        //cout << is_overlap(assign) << endl;
    }
	my_file.close();
    cout << sum << endl;
	return 0;
}
