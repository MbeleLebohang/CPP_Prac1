/* Implementing TDD
 * 
 * File:   newsimpletest.cpp
 * Author: Mbele Lebohang
 *
 * Created on 26 March 2017, 5:44 AM
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "database.h"

// Join the namespaces
using namespace std;
using namespace MBLLEB006;

/**
 * Test a Load function
 *      Results: number is student record should be >0 given a .csv with 
 *      student records
 */
void testLoad() {
    cout << "database test load function" << endl;
    database empty_students;
    
    if(empty_students.records.size() > 0){
        std::cout << "%TEST_FAILED% time=0 testname=testLoad (databasetest) message=Loaded students even though no file was given." << std::endl;
    }
    
    database non_empty_students("student_records.csv");
    if(non_empty_students.records.size() <= 0){
        std::cout << "%TEST_FAILED% time=0 testname=testLoad (databasetest) message=Could not load the previous database" << std::endl;
    }
}

void testAdd(){
    cout << "database test add function" << endl;
    database students;
    
    students.add("Lebohang", "Mbele", "MBLLEB006", "100 100 100");
    
    if(students.records.back().name != "Lebohang"){
        std::cout << "%TEST_FAILED% time=0 testname=testAdd (databasetest) message=The record was not added correctly." << std::endl;
    }
    // test if duplicates are handled correctly
    students.add("Lebohang", "Mosia", "MBLLEB006", "100 100 100");
    if(students.records.size() > 1){
        std::cout << "%TEST_FAILED% time=0 testname=testAdd (databasetest) message=A duplicate record was added." << std::endl;
    }
    // test if the update went through
    if(students.records.back().surname != "Mosia"){
        std::cout << "%TEST_FAILED% time=0 testname=testAdd (databasetest) message=Duplicate record was not updated." << std::endl;
        cout << "Name found -->  " << students.records.back().name << endl;
    }
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% databasetest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    
    std::cout << "%TEST_STARTED% testLoad (databasetest)\n" << std::endl;
    testLoad();
    std::cout << "%TEST_FINISHED% time=0 testLoad (databasetest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testAdd (databasetest)\n" << std::endl;
    testAdd();
    std::cout << "%TEST_FINISHED% time=0 testAdd (databasetest)" << std::endl;
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

