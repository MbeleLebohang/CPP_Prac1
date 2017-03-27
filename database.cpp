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
