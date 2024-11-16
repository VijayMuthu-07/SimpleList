#include "include/database.h"

void Database::write(vector<vector<string>> mainList) {
    ofstream db;
    db.open("db/lists.sl");

    if(db.is_open()) {
        for(unsigned int user_index = 0;user_index < mainList.size();user_index++) {
            for(unsigned int list_index = 0;list_index < mainList[user_index].size();list_index++) {
                if(list_index == 0) {
                    db << '#' << mainList[user_index][list_index] << '\n';
                }
                else {
                    db << mainList[user_index][list_index] << '\n';
                }
            }
            db << '%' << '\n'; 
        }  
    }
    else {
        cout << "Error: Unable to access database\n";
    }

    db.close();
}

vector<vector<string>> Database::read() {
    string line;
    ifstream db;
    db.open("db/lists.sl");

    vector<string> userList;

    if(db.is_open()) {
        while(getline(db, line, '\n')) {
            if(line.front() == '#') {
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if(line.front() == '%') {
                mainList.push_back(userList);
                userList.clear();
            }
            else {
                userList.push_back(line);
            }
        }
    }
    else {
        cout << "Error: Unable to access database\n";
    }

    db.close();
    return mainList;
}