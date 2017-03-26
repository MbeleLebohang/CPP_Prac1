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

// Join the std namespace
using namespace std;

#include "database.h"
using namespace MBLLEB006;

database::database() {
}

database::database(const database& orig) {
}

database::~database() {
}


int database::sum(int a, int b){
	return a + b;
}