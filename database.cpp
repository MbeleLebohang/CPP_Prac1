/*
 * CSC3002H Assignment 1 - Database
 * Database class implementation
 */

/* 
 * File:   database.cpp
 * Author: Mbele Lebohang
 * 
 * Created on 25 March 2017, 9:15 PM
 */

// Standard includes
#include <string>
#include <fstream>
#include <iostream>

// Join the std namespace
using namespace std;

#include "database.h"
using namespace MBLLEB006;

/*************************************************************************/
/* Implementation of database methods                                        */
/*************************************************************************/

database::database() {
}

database::database(const char* filename) {
    load(filename);
}

database::~database() {
}

int database::load ( const char* filename ){
  string line;
  ifstream file (filename);
  if (file.is_open())
  {
    while ( getline (file,line) ){
        StudentRecord student;
        
        int pos = line.find(", ");
        student.name = line.substr(0, pos);
        
        line = line.substr(pos + 2);
         pos = line.find(", ");
        student.surname = line.substr(0, pos);  
      
        line = line.substr(pos + 2);
        pos = line.find(", ");
        student.student_number = line.substr(0, pos);      

        line = line.substr(pos + 2);
        pos = line.find(", ");
        student.class_record = line.substr(0, pos);
        
        records.push_back(student);
        }
        file.close();
    }
    else{
        cout << "Unable to open file"<< endl;
        return 0;
    }
}

int database::save(const char* filename){
    // save student records to .csv file filename

    ofstream records_file (filename);
    if (records_file.is_open())
    {
        for (StudentRecord student : records){
            records_file << student.name << ", "<< student.surname << ", " ;
            records_file << student.student_number << ", "<< student.class_record;
            records_file << '\n';
        }
        records_file.close();
        return 1;
    }
    else{
        cout << "Unable to open file";
        return 0; // return 0 to indicate no error
    }
}

void database::add(string name, string surname, string student_no, string class_record){
    // Creating a record and adding it to the vector
    int index = find(student_no);
    if(index == -1){
        // add new record
        StudentRecord student;
        records.push_back(student);
        index = records.size()-1;
    }
    
    // Update old record
    records[index].name = name;
    records[index].surname = surname;
    records[index].student_number = student_no;
    records[index].class_record = class_record;
}

void database::read(const char* filename){
    string line;
    ifstream file (filename);
    // Display the heading
    cout << "\nName\t\t"
        "Surname\t\t"
        "Student Number\t\t"
        "Class Record\n";
    if (file.is_open())
    {
        while ( getline (file,line) ){
            int pos = line.find(", ");
            string name = line.substr(0, pos);

            line = line.substr(pos + 2);
            pos = line.find(", ");
            string surname = line.substr(0, pos);  

            line = line.substr(pos + 2);
            pos = line.find(", ");
            string student_no = line.substr(0, pos);      

            line = line.substr(pos + 2);
            pos = line.find(", ");
            string class_record = line.substr(0, pos);
            
            cout << name << "\t\t" << surname << "\t\t" << student_no << "\t\t" << class_record << endl;
            
        }
        file.close();
    }
    else{
        cout << "Unable to open file"<< endl;
    }
}
void database::search(const char* filename, const char* student_no){
    string line;
    ifstream file (filename);
    // Display the heading
    cout << "\nName\t\t"
        "Surname\t\t"
        "Student Number\t\t"
        "Class Record\n";
    if (file.is_open())
    {
        int not_found = 1;
        
        while ( getline (file,line) ){
            int pos = line.find(", ");
            string name = line.substr(0, pos);

            line = line.substr(pos + 2);
            pos = line.find(", ");
            string surname = line.substr(0, pos);  

            line = line.substr(pos + 2);
            pos = line.find(", ");
            string student_number = line.substr(0, pos);      

            line = line.substr(pos + 2);
            pos = line.find(", ");
            string class_record = line.substr(0, pos);     
            
            if(student_number == student_no){
                cout << name << "\t\t" << surname << "\t\t" << student_no << "\t\t" << class_record << endl;
                not_found = 0;
            }
            
        }
        if(not_found){
            cout << "NO RESULTS FOUND!!!" << endl;
        }
        file.close();
    }
    else{
        cout << "Unable to open file"<< endl;
    }
}

void database::average(string student_no){
    
    int index = find(student_no);
    string results;
    if(index >= 0){
        results = records[index].class_record;
    }
    else{
        cout << "The record of " << student_no << " does not exist in the database."<<endl;
        cout << "Try again." << endl;
        return;
    }
    // Display the menu
    cout << "\nStudent Number\t\t"
            "Average\n";
    istringstream iss(results);
    string string_record;
    double sum = 0;
    int n = 0;
    while (!iss.eof()) { 
        iss >> string_record;
        int foo;
        n++;
        stringstream(string_record) >> foo;
        sum += foo;
    }
    if(n !=  0){
        cout << student_no << "\t\t" << (double)sum/n << endl;
    }
    else{
        cout << student_no << "\t\t"<< sum << endl;
    }
}

int database::find(string student_no){
    
    for(int i = 0; i < records.size(); i++){
        if(records[i].student_number == student_no){
            return i;
        }
    }
    return -1;
}