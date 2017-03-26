/* 
 * File:   database.h
 * Author: Mbele Lebohang
 *
 * Created on 25 March 2017, 9:15 PM
 */

#ifndef DATABASE_H
#define DATABASE_H

namespace MBLLEB006 {
    class database {
    public:
        database();
        database(const database& orig);
        virtual ~database();
        
        int sum(int a, int b);
    private:

    };
}
#endif /* DATABASE_H */

