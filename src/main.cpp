#include "include/list.h"

int main(int arg_count, char *args[]) {
    List SimpleList;

    if(arg_count > 1) {
        SimpleList.name = string(args[1]);
        SimpleList.mainList = SimpleList.data.read();
        SimpleList.find_userList();
        SimpleList.print_menu();
    } 
    else {
        cout << "Error: No Username was provided.\n";
    }

    return 0;
}