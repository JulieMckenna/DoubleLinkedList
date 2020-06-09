//Julie Mckenna lab 7

#include <iostream>
#include <string>
#include <fstream>

#include "linkedlistclass.h"

using namespace std;

int main(){

    string fName, lName;
    int year;
    int user = 0;
    int user2;


    ifstream superbowls("Lab6_List.txt");
    ifstream eckert("Lab7_list.txt");

    cout << "Creating a list based of winning quarterbacks based on Superbowl wins. \n";
    linkedlist_c eckertwinners(eckert);
    cout << "Creating a list of Eckert-Mauchly Award winners. \n";
    linkedlist_c quarterbacks(superbowls);

    while(user !=7){
        cout << "Press 1: \tto add an entry to the list" << endl;
        cout << "Press 2: \tto delete an entry from the list" << endl;
        cout << "Press 3: \tto delete all of the entries" << endl;
        cout << "Press 4: \tto print all the entries or" << endl;
        cout << "Press 5: \tto search the list for a member" << endl;
        cout << "Press 6: \tto reset the list of players" << endl;
        cout << "Press 7: \tto exit the program" << endl;
        cin >> user;
        cout << endl;


        switch(user){
            case 1:
                cout << "What list would you like to add to? \n" << endl;
                cout << "1: Quarterbacks \t 2: Eckert-Mauchly Award winners \n" << endl;
                cin >> user2;

                switch(user2){
                case 1:
                cout << "What is the Quarterback's first name?" << endl;
                cin >> fName;
                cout << "What is the Quarterback's last name?" << endl;
                cin >> lName;
                cout << "What year did they win?" << endl;
                cin >> year;
                quarterbacks.addName(fName, lName, year);
                break;

                case 2:
                cout << "What is the winner's first name?" << endl;
                cin >> fName;
                cout << "What is the winner's last name?" << endl;
                cin >> lName;
                cout << "What year did they win?" << endl;
                cin >> year;
                eckertwinners.addName(fName, lName, year);
                break;

                }
                break;
            case 2:
                cout << "What list would you like to delete from? \n" << endl;
                cout << "1: Quarterbacks \t 2: Eckert-Mauchly Award winners \n" << endl;
                cin >> user2;
                switch(user2){
                case 1 :
                    cout << "What is the Quarterback's first name?" << endl;
                    cin >> fName;
                    cout << "What is the Quarterback's last name?" << endl;
                    cin >> lName;
                    quarterbacks.deleteName(fName, lName);
                    break;

                case 2:
                    cout << "What is the winner's first name?" << endl;
                    cin >> fName;
                    cout << "What is the winners's last name?" << endl;
                    cin >> lName;
                    eckertwinners.deleteName(fName, lName);
                    break;

                }

                break;

            case 3:
                cout << "What list would you like to delete all entries from? \n" << endl;
                cout << "1: Quarterbacks \t 2: Eckert-Mauchly Award winners \n" << endl;
                cin >> user2;
                switch(user2){
                case 1 :
                    quarterbacks.deleteAll();break;
                case 2:
                    eckertwinners.deleteAll(); break;
                }
                break;
            case 4:
                cout << "What list would you like to print? \n" << endl;
                cout << "1: Quarterbacks \t 2: Eckert-Mauchly Award winners \n" << endl;
                cin >> user2;
                switch(user2){
                case 1 :
                    quarterbacks.printAll();break;
                case 2:
                    eckertwinners.printAll(); break;
                }
                break;
            case 5:
                cout << "What list would you like to search? \n" << endl;
                cout << "1: Quarterbacks \t2: Eckert-Mauchly Award winners \t3: Both(for year won)\n" << endl;
                cin >> user2;
                switch(user2){
                case 1 :
                    quarterbacks.search();break;
                case 2:
                    eckertwinners.search(); break;
                case 3:
                    quarterbacks.search(eckertwinners);break;
                }
                break;
            case 6:
                cout << "What list would you like to reset? \n" << endl;
                cout << "1: Quarterbacks \t 2: Eckert-Mauchly Award winners \n" << endl;
                cin >> user2;
                switch(user2){
                case 1 :
                    quarterbacks.deleteAll();
                    quarterbacks.addAll(superbowls);
                case 2:
                    eckertwinners.deleteAll();
                    eckertwinners.addAll(eckert); break;
                }
                break;

            case 7: cout << "Exiting program" << endl;break;


            default: cout << "That input is not valid, please enter 1-6";
        }
    //doesn't end the loop until the user wants to exit
    }
    //deleted everything before exiting
    quarterbacks.deleteAll();
    eckertwinners.deleteAll();

}
