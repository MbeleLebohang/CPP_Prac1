/* 
 * File:   newsimpletest.cpp
 * Author: Mbele Lebohang
 *
 * Created on 26 March 2017, 5:44 AM
 */

#include <stdlib.h>
#include <iostream>
#include "database.h"

// Join the namespaces
using namespace std;
using namespace MBLLEB006;

/*
 * Implementation of TDD
 */

void testSum() {
    cout << "database test Sum" << endl;
    database students;
    int sum = students.sum(2,4);

    if(sum != 6){
        std::cout << "%TEST_FAILED% time=0 testname=testSum (databasetest) message=error sum incorrect" << std::endl;
    }
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% databasetest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testSum (databasetest)\n" << std::endl;
    testSum();
    std::cout << "%TEST_FINISHED% time=0 testSum (databasetest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}
