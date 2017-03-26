/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: sponono
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
 * 
 */

void test1() {
    cout << "database test test 1" << endl;
}

void test2() {
    cout << "database test test 2" << endl;
}

int main(int argc, char** argv) {
    cout << "%SUITE_STARTING% database test" << endl;
    cout << "%SUITE_STARTED%" << endl;

    cout << "%TEST_STARTED% test1 (database test)" << endl;
    test1();
    cout << "%TEST_FINISHED% time=0 test1 (database test)" << endl;

    cout << "%TEST_STARTED% test2 (database test)\n" << endl;
    test2();
    cout << "%TEST_FINISHED% time=0 test2 (database test)" << endl;

    cout << "%SUITE_FINISHED% time=0" << endl;

    return (EXIT_SUCCESS);
}

