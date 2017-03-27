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
         * Create a database with empty student records
         */
        database();

        database(const char* filename);
        
        virtual ~database();
        
        /**
         * Save the current data to the database
         * Returns true if successfully saved, otherwise false.
         * @param filename
         * @return 
         */
        int save(const char* filename);
                  
        /**
         * Load a given database/file to the new instance of database
         * Returns true if file was loaded.
         * Returns false if file was not found.
         * @param filename
         * @return 
         */
        int load(const char* filename);
        
        /**
         * Function to add student records
         * @param name
         * @param surname
         * @param student_no
         * @param class_record
         */
        void add(string name, string surname, string student_no, string class_record);
        
        /* The means to store the student records. */
        vector<StudentRecord> records;
    private:
        /**
         * Find a student of a given student number
         *      return index of student if found, else return -1
         * @param student_no
         * @return 
         */
        int find(string student_no);
    };
}
#endif /* DATABASE_H */

