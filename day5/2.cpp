#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ifstream my_file;
	my_file.open("input.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
        return -1;
	}
    string line;
    getline(my_file, line) ;
    int num_containers = (line.length() + 1)/4;
    cout << "there are " << num_containers << " containers" << endl;
    stack<char> ship[num_containers];
    string assignments, cargo;
    string container;
    my_file.clear();
    my_file.seekg(0,my_file.beg);
    while(getline(my_file, line) && line.length()!=0)
    {
        int i = 0 ;
        for(int j = 0; j < num_containers; j++){
            cargo = line.substr(j*3+i, 3);
            cargo = cargo[1];
            if(cargo!= " "){
                ship[j].push(cargo[0]);
            }
            i++;
        }
        

    }

    for(int j = 0; j < num_containers; j++){
        //erases the numbers of the containers
        ship[j].pop();
        stack<char> tmpship [num_containers];
        //reverses stack
        while (ship[j].empty() == false)
       {
          char item = ship[j].top();
          ship[j].pop();
          tmpship[j].push(item);
       }
        ship[j] = tmpship[j];
    }
    for(int j = 0; j < num_containers; j++){
        cout << ship[j].top();
    }
    cout << endl;

    int num, from , to;

    while(getline(my_file, line) && line.length()!=0){
        stringstream ss(line);
        for(int i = 0; i < 6; i++){
            getline(ss, container, ' ');
            if(i == 1){num = stoi(container);}
            if(i == 3){from = stoi(container) - 1;}
            if(i == 5){to = stoi(container) - 1;}
        }
        stack<char> car;
        for(int i = 0; i < num; i ++){
            car.push(ship[from].top());
            ship[from].pop();
        }
        while(!(car.empty())){
            ship[to].push(car.top());
            car.pop();
        }
        
    }

    for(int j = 0; j < num_containers; j++){
        cout << ship[j].top();
    }
    cout << endl;


	my_file.close();
	return 0;
}
