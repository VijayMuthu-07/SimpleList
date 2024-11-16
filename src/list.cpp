#include "include/list.h"

void List::print_menu() {
    int choice;

    cout << "********************\n";
    cout << "1 - print items\n";
    cout << "2 - add item\n";
    cout << "3 - delete item item\n";
    cout << "4 - Save list\n";
    cout << "5 - quit\n";

    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            print_list();
            break;
        case 2:
            add_item();
            break;
        case 3:
            delete_item();
            break;
        case 4:
            save_list();
            break;
        case 5:
            return;
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }

    cin.clear();
}

void List::print_list() {
    char choice;

    cout << "*****List*****\n";
    for(unsigned int list_index = 0;list_index < list.size();list_index++) {
        if(list_index == 0) {
            continue;
        }
        cout << " * " << list[list_index] << '\n';
    }

    cout << "M - return to menu\n";
    cin >> choice;

    if(choice == 'M' || choice == 'm') {
        print_menu();
    }
    else {
        cout << "Invalid Input, quitting ...\n";
        exit(0);
    }
}

void List::add_item() {
    string item;

    cout << "*****ADD ITEM*****\n";

    cout << "Enter an item to add: ";
    cin >> item;

    list.push_back(item);
    cout << "Item successfully added in list\n";

    cin.clear();
    print_menu();
}

void List::delete_item() {
    int index;

    cout << "*****DELETING ITEM*****\n";

    for(unsigned int list_index = 0;list_index < list.size();list_index++) {
        if(list_index == 0) {
            continue;
        }
        cout << list_index << " - " << list[list_index] << '\n';
    }

    cout << "Enter item index to delete: ";
    cin >> index;

    list.erase(list.begin() + index);
    
    cin.clear();
    print_menu();
}

bool List::find_userList() {
    bool userFound = false;

    cout << "Welcome " << name << '\n';

    for(unsigned int user_index = 0;user_index < mainList.size();user_index++) {
        if(mainList[user_index][0] == name) {
            list = mainList[user_index];
            currentUserIndex = user_index;
            userFound = true;
            break;
        }
    }

    if(userFound == false) {
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = mainList.size()-1;
    }

    return userFound;
}

void List::save_list() {
    cout << "Saving list...\n";
    mainList[currentUserIndex] = list;
    data.write(mainList);
    print_menu();
}