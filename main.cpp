/* 
 * CSC2022H Assignment 1 - database
 * 
 * File:   main.cpp
 * Author: Mbele Lebohang
 *
 * Created on 25 March 2017, 8:48 PM
 */

// standard includes
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

//join the std namespace
using namespace std;

#include "database.h"
using namespace MBLLEB006;

// Program entry point
int main ( int argc, char* argv [] )
{
    int cont = 1; // continue running the program until cont=0
    database student_records;
    string record_name = "student_records.csv";
    cout << "Welcome to Student Records\n";

    // check if a parameter was given for the name of the log file to use
    if (argc>1) {
        record_name = argv[1];
    }

    // try to load the log file
    if (!student_records.load(record_name.c_str())) {
        // if it doesn't load then assume starting with an empty log
        cerr << "Starting with empty eLog\n";
    }

    // continuously display the menu and ask user to choose an option
    while (cont) {

        // display the name of the active log file
        cout << "\nStudent Records : " << record_name;

        // Display the menu
        cout << "\nMENU:\n"
            "1:   Add student\n"
            "2:   Read database\n"
            "3:   Save database\n"
            "4:   Display given student\n"
            "5:   Grade student\n"
            "99:  Exit\n";
        cout << "Select an option: ";
        // User needs to select one of the options

        int ch;
        cin >> ch;
        switch (ch) {
            case 1: // Add a student record
                    {
                      cout << "Enter the student record." << endl;
                       cout << "Name: " << endl;
                       string name;
                       getline(cin, name);
                       getline(cin, name);
                       cout << "Surname: " << endl;
                       string surname;
                       getline(cin, surname);
                       cout << "Student Number: " << endl;
                       string student_no;
                       getline(cin, student_no);
                       cout << "Class record: " << endl;
                       string class_record;
                       getline(cin, class_record);
                       cout << name << surname << student_no << class_record << endl;
                       student_records.add(name, surname, student_no, class_record);
                       break;
                    }

            case 2: // List all records saved in the database (csv file)
                    {
                        student_records.read(record_name.c_str());
                        break;
                    }
            
            case 3: // Save the file to a given filename
                    {
                        cout << "Enter a filename to save to (.csv):";
                        string filename;
                        cin >> filename;

                        student_records.save(filename.c_str());
                        break;
                    }
            case 4: // search a record of a given student number
                    {
                        cout << 4 << endl;
                        cout << "Search student number: ";
                        string student_no;
                        getline(cin, student_no);
                        student_records.search(record_name.c_str(), student_no.c_str());
                        break;
                    }
            case 5: // delete the nth entry
                    {
                        cout << 5 << endl;
                        /*cout << "Enter the entry number: ";
                        int n;
                        cin >> n;
                        elog.Delete(n);*/
                        break;
                    }

            case 99:
                    {
                        cont=0;
                        break; 
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

