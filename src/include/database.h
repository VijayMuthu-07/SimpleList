#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Database{
    public:
        vector<vector<string>> mainList;
        string name;

        Database() {
            //constructor
        }
        ~Database() {
            //deconstructor
        }

        vector<vector<string>> read();
        void write(vector<vector<string>> mainList);

};