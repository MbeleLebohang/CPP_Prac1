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
    cout << "database test Load" << endl;
    database empty_students;
    
    if(empty_students.records.size() > 0){
        std::cout << "%TEST_FAILED% time=0 testname=testLoad (databasetest) message=Loaded students even though no file was given." << std::endl;
    }
    
    database non_empty_students("student_records.csv");
    if(non_empty_students.records.size() <= 0){
        std::cout << "%TEST_FAILED% time=0 testname=testLoad (databasetest) message=Could not load the previous database" << std::endl;
    }

}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% databasetest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    
    std::cout << "%TEST_STARTED% testSum (databasetest)\n" << std::endl;
    testLoad();
    std::cout << "%TEST_FINISHED% time=0 testSum (databasetest)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

