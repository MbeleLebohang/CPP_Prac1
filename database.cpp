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
    // Display the menu
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

int database::find(string student_no){
    
    for(int i = 0; i < records.size(); i++){
        if(records[i].student_number == student_no){
            return i;
        }
    }
    return -1;
}