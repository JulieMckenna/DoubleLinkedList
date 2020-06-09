#ifndef LINKEDLIST_L
#define LINKEDLIST_L

//Linked list class
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class linkedlist_c{

private:
    struct person_t{
    string firstName, lastName;
    int numWins = 0;
    int years[5] = {NULL};
    person_t *next;
    person_t *previous;
    };
    person_t *head = NULL;
    person_t *tail = NULL;

public:
    linkedlist_c(){
        cout << "You have made an empty list... Please populate it." << endl;
    };
    void addAll(ifstream &inputFile){
        int user;
        string fName, lName;
        int year;

        while(!inputFile.eof()){
            inputFile >> fName >> lName >> year;
            //uses the add function to add each player based off input from the file
            addName(fName, lName, year);
        }
    };
    linkedlist_c(ifstream &inputFile){
        addAll(inputFile);
        cout<< "Created a list based on the input File" << endl;
    }
    ~linkedlist_c(){
        cout << "A list is being deleted." << endl;
    };

    int nameRepeat(string fName, string lName, int year){
     person_t *temp = head;
    //must do the loop once to check the head then increments the pointer to the next element
    do{
        //if the first and last name of the new entry equal the first and last name of whatever entry the pointer is looking for
       if((temp->firstName == fName) && (temp->lastName == lName)){
                //adds the year that the player won to the years array
                temp->years[temp->numWins] = year;
                //increments the number of wins
                temp->numWins += 1;
                return 1;
        }
       temp = temp->next;
       //while the pointer hasn't reached head, the tails next points to the head so once it reaches head it will have gone through the whole list
    }while(temp!=head);
    return 0;
    };
    void addName(string fName, string lName, int year){
     //makes a new player datat type
    person_t *newPlayer = new person_t;
    person_t *temp = head;

    //if adding at the head
    if(temp == NULL){
        //both head and tail will be the same if one entry
        head = newPlayer;
        tail = head;
        head->firstName = fName;
        head->lastName = lName;
        head->years[head->numWins] = year;
        //increment number of wins because it starts at 0
        head->numWins += 1;
        head->next = head;
        head->previous = tail;
    //adding to the tail
    }else{
        //checks if the name is already entered
        if(nameRepeat(fName, lName, year)){}else{
            //iterates through the loop
            for(temp = head; temp->next!=head; temp = temp->next){}
            temp->next = newPlayer;
            tail = temp->next;
            head->previous = tail;
            temp->next->firstName = fName;
            temp->next->lastName = lName;
            temp->next->years[temp->next->numWins] = year;
            temp->next->numWins += 1;
            temp->next->next = head;
            temp->next->previous = temp;
        }
    }

};
    void deleteName(string fName, string lName){
    person_t *temp = head;
    //need to do a do while to loop through the whole list, do so it does the head then set the while to run until temp = head again
    do{
        //if the name matches the name the user wants to remove
       if((temp->firstName == fName) && (temp->lastName == lName)){
                    //if it is the head
                    if(temp == head){
                        head = temp->next;
                        tail->next = head;
                        head->previous = tail;
                        delete temp;
                        return;
                    //if it is the tail
                    }else if(temp == tail){
                        tail = temp->previous;
                        head->previous = tail;
                        tail->next = head;
                        delete temp;
                        return;
                    //if it is neither head or tail(something in the middle of the list)
                    }else{
                        person_t *before = temp->previous;
                        person_t *after = temp->next;
                        delete temp;
                        before->next = after;
                        after->previous = before;
                        return;
                    }
        }
        //increments the temp to loop through the list
       temp = temp->next;
       //when temp = head will have restarted the list want to stop after tail
    }while(temp!=head);
    //if the name wasn't found
    cout << "That name isn't in the list" << endl;
    };
    void deleteAll(){
     //makes a player type to delete
    person_t *tempDelete = head;
    if(tempDelete == NULL){
         return;
    }
    //loops through the array and deletes each one by one
    person_t *tempHolder = head->next;
    while(tempDelete != tail){
        delete tempDelete;
        tempDelete = tempHolder;
        if(tempHolder != head){
            tempHolder = tempHolder->next;
        }
    }
    head = NULL;
    tail = NULL;

    };
    void search(){
    cout << "Press 1: \tto search by name" << endl;
    cout << "Press 2: \tto search by year" << endl;
    cout << "Press 3: \tto search by number of wins" << endl;
    person_t *temp = head;
    int choice;
    int found = 0;
    cin >> choice;

    switch(choice){
    case 1:{
        string firstName, lastName;
        cout << "What is the person's first name?" << endl;
        cin >> firstName;
        cout << "What is the persons's last name?" << endl;
        cin >> lastName;
        //searches through the list by the players name
        do{
           if((temp->firstName == firstName) && (temp->lastName == lastName)){
                    found = 1;
                    cout << endl << temp->firstName << " " << temp->lastName << "\t\t" << temp->numWins << endl;
                    for(int i = 0; (*(temp->years+i)!=NULL); i++){
                        if(i>4){break;}
                        cout << *(temp->years+i) << endl;
                    }
           }
           temp = temp->next;
        }while(temp!=head);
    }
        break;
    case 2:{
        int year;
        cout << "What year did the person win?" << endl;
        cin >> year;
        //searches for the player by what year they won
        do{
            for(int i = 0; i < 5; i++){
                if(temp->years[i] == year){
                    found = 1;
                    cout << endl << temp->firstName << " " << temp->lastName << "\t\t" << temp->numWins << endl;
            }
            }
           temp = temp->next;
        }while(temp!=head);
    }
        break;
    case 3:{
        int wins;
        cout << "How many wins does the person have?" << endl;
        cin >> wins;
        //searches for the player based off how many wins they have
        do{
                if(temp->numWins == wins){
                    found = 1;
                    cout << endl << temp->firstName << " " << temp->lastName << "\t\t" << temp->numWins << endl;
                    for(int j = 0; (*(temp->years+j)!=NULL); j++){
                        if(j>4){break;}
                        cout << *(temp->years+j) << endl;
                    }
            }
           temp = temp->next;
        }while(temp!=head);
    }

        break;
    default: cout << "That is an invalid input" << endl;
    }
    //if the player wasn't found in the list
    if(!found){
    cout << "Couldn't find any person" << endl;
    }
};
    void search(linkedlist_c &otherlist){
        int found;
        int found2 = 0;
        int year;
        cout << "What year are you looking for the winners? \n";
        cin >> year;

        person_t *temp = head;

        do{
            for(int i = 0; i < 5; i++){
                if(temp->years[i] == year){
                    found = 1;
                    cout << endl << "The winning quarterback from that year was: " << temp->firstName << " " << temp->lastName << endl;
            }
            }
            temp = temp->next;
        }while(temp!=head);

        if( 2005 < year ){
        temp = otherlist.head;
         do{
            if(temp->years[0] == year){
                found2 = 1;
                cout << endl << "The Eckert-Mauchly Award winner that year was: " <<temp->firstName << " " << temp->lastName << endl;
            }
           temp = temp->next;
        }while(temp!=otherlist.head);
        }
        else
            cout << "There are no Eckert-Mauchly Award winners in the list from that year \n";


    };
    void printAll(){
    if(head == NULL){
        cout << "There are currently no entries in the list" << endl << endl;
        return;
    }

    person_t *temp = head;
    //loops through the list and prints the players
    do{
       cout << endl << temp->firstName << " " << temp->lastName << "\t\t" << temp->numWins << endl;
       for(int i = 0; (*(temp->years+i)!=NULL); i++){
           if(i>4){break;}
            cout << *(temp->years+i) << endl;
       }
       temp = temp->next;
    }while(temp!=head);
    };
};
#endif
