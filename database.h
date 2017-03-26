/* CSC3002H Assignment 1
 * 
 * File:   database.h
 * Author: Mbele Lebohang
 *
 * Created on 25 March 2017, 9:15 PM
 */

// Standard includes
#include <vector>
#include <cstdlib>
#include <string>

// Join the std namespace
using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

struct StudentRecord{
    string name;
    string surname;
    string student_number;
    string class_record;
};

namespace MBLLEB006 {
    class database {
    public:
       /**

        */
        /**
         * Create a database with empty student records
         */
        database();
        /**
         * Pre-conditions: Given and already existing database file (.csv) load it
         *                  into the object vector as the object is created
         * Post-conditions: The new object instance should have a database with 
         *                  all records in filename
         * @param filename
         */
        database(const char* filename);
        virtual ~database();
        /**
         * add two number a and b and return the sum
         * @param a
         * @param b
         * @return 
         */
        int sum(int a, int b);
        
        /* The means to store the student records. */
        vector<StudentRecord> records;
    private:

    };
}
#endif /* DATABASE_H */

