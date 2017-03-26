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

database::database() {
}

database::database(const char* filename) {
  string line;
  ifstream old_file (filename);
  if (old_file.is_open())
  {
    while ( getline (old_file,line) )
    {
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
    old_file.close();
  }

  else {
      cout << "Unable to open file" << filename << endl; 
  }
}

database::~database() {
}


int database::sum(int a, int b){
	return a + b;
}