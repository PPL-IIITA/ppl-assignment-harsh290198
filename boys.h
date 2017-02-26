#ifndef boys_h
#define boys_h
#include "girls.h"
using namespace std ;
class Boys {
    public :
        // Personal details
        string name ;
        string gf_name ;
        int attractiveness ;
        int intelligence ;
        int budget ;
        int min_attraction ;
        bool committed ;
        string committed_type ;
        int happiness ;
        // Gift details
        int total_gift_price , total_gift_value ;
        // Utility Functions
        Boys () {
            committed = false ;
        }
        void add_boy ( string nme , int att , int intel , int bud , int min_at , string ct ) {
            name = nme ;
            attractiveness = att ;
            intelligence = intel ;
            budget = bud ;
            min_attraction = min_at ;
            committed_type = ct ;
        }
        void set_committed () {
            committed = true ;
        }
        void set_girlfriend ( string gname ) {
            if ( committed == false ) return ;
            gf_name = gname ;
        }
        void set_happiness ( vector < Girls > g , int ng ) {
            if ( committed == false ) return ;
            if ( committed_type == "Miser" ) {
                happiness = budget-total_gift_price ;
            }
            else if ( committed_type == "Generous" ) {
                for ( int i = 0 ; i < ng ; i++ ) {
                    if ( gf_name == g[i].name )
                        happiness = g[i].happiness ;
                }
            }
            else if ( committed_type == "Geek" ) {
                for ( int i = 0 ; i < ng ; i++ ) {
                    if ( gf_name == g[i].name )
                        happiness = g[i].intelligence ;
                }
            }
    }
} ;
#endif // boys_h
