#ifndef check_h
#define chech_h
#include "boy.h"
#include "couple.h"
using namespace std ;
class Check {
    public :
        vector < Boy > vob ;
        vector < Couples > voc ;
        virtual void check ( vector < string > vb ) {
            cout << "Checking if the boys are committed or not\n" ;
        }
} ;
class Hash_check : public Check {
    public :
        void check ( vector < string > vb ) {
            for ( int i = 0 ; i < vb.size() ; i++ ) {
                cout << i <<  " " ;
                for ( int j = 0 ; j < vob.size() ; j++ ) {
                    if ( vb[i] == vob[j].name && vob[j].committed == true ) {
                        cout << vb[i] << " is committed\n" ;
                        break ;
                    }
                }
            }
        }
} ;
class Couple_list_check : public Check {
    public :
        void check ( vector < string > vb ) {
            for ( int i = 0 ; i < vb.size() ; i++ ) {
                for ( int j = 0 ; j < voc.size() ; j++ ) {
                    if ( vb[i] == voc[j].name_boy ) {
                        cout << vb[i] << " is committed\n" ;
                        break ;
                    }
                }
            }
        }
} ;
#endif // check_h

