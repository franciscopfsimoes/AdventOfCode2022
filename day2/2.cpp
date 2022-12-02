#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int win(char opp){
    if(opp == 'C'){return 1;}
    if(opp == 'A'){return 2;} 
    else{return 3;}
}
int draw(char opp){
    if(opp == 'A'){return 1;}
    if(opp == 'B'){return 2;} 
    else{return 3;}
}
int lose(char opp){
    if(opp == 'B'){return 1;}
    if(opp == 'C'){return 2;} 
    else{return 3;}
}
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
        char  opponent, result, c;
        if (!(iss >> opponent >> result >> c)) {
            if(result == 'X'){score = score + 0 + lose(opponent);} //lose
            if(result == 'Y'){score = score + 3 + draw(opponent);}
            if(result == 'Z'){score = score + 6 + win(opponent);}
        }
    }
    cout << score << endl;
	my_file.close();
	return 0;
}
