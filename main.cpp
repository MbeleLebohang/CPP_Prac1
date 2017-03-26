/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Mbele Lebohang
 *
 * Created on 25 March 2017, 8:48 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "database.h"
using namespace MBLLEB006;

// Program entry point
int main ( int argc, char* argv [] )
{
    int cont = 1; // continue running the program until cont=0
 
    string record_name = "testlog.csv";
    cout << "Welcome to Student Records\n";

    // check if a parameter was given for the name of the log file to use
    if (argc>1) {
        record_name = argv[1];
    }

    // try to load the log file
    ifstream record_file(record_name);
    if (is_empty(record_file)) {
        // if it doesn't load then assume starting with an empty log
        cout << "Starting with empty Database\n";
        record_file.close();
        database database_records;
    }
    else{
        cout << "Loading an old Database." << endl;
        record_file.close();
        database database_records(record_name);
    }

    // continuously display the menu and ask user to choose an option
    while (cont) {

        // display the name of the active log file
        cout << "\nStudent Records : " << record_name;

        // Display the menu
        cout << "\nMENU:\n"
            "1:   Add entry\n"
            "2:   List all entries\n"
            "3:   List priority\n"
            "4:   Search\n"
            "5:   Delete\n"
            "6:   Save\n"
            "Esc: Exit\n";
        cout << "Select an option: ";
        // User needs to select one of the options

        int ch = getch();
        switch (ch) {
            case 1: // here is code to ask for a priority and keywords to enter into the log
                    {
                       cout << "Priority: ";
                       int priority;
                       cin  >> priority;
                       cout << "Notes: ";
                       string notes;
                       cin  >> notes;
                       elog.add(priority,notes);
                       break;
                    }

            case 2: // List all entries
                    {
                        elog.listEnties();
                        break;
                    }

            case 3: // List all entries
                    {
                        cout << "Enter a priority number: ";
                        int priority;
                        cin >> priority;
                        elog.listPriorities(priority);
                        break;
                    }
            case 4: // search an enry with a given word
                    {
                        cout << "Search string: ";
                        string word;
                        cin >> word;
                        elog.Search(word.c_str());
                        break;
                    }
            case 5: // delete the nth entry
                    {
                        cout << "Enter the entry number: ";
                        int n;
                        cin >> n;
                        elog.Delete(n);
                        break;
                    }
            case 6: // Save the file to a given filame
                    {
                        cout << "Enter a filename:";
                        string filename;
                        cin >> filename;

                        elog.save(filename.c_str());
                        break;
                    }

            case 27 :
                    {
                        cont=0;
                        break; // Esc key is code 27, exists program
                    }
            default :
                    {
                        cout << "Unknown command\n";
                        break;
                    }
        };
    }

    //system("PAUSE"); // wait for keypress
    return 0;
}

