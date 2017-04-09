#ifndef boy_h
#define boy_h
#include "girl.h"
using namespace std;
class Boy {
    public :
        string name ;
        string gf_name ;
        bool committed ;
        int attractiveness ; // attractiveness level
        int intelligence ; // intlelligence level of boy
        int budget ; // budget for gf
        int min_attraction ; // minimum attraction needed for gf
        int happiness ; // happiness of boy
        int total_gift_price ; // price of his gifts
        int total_gift_value ; // value of his gifts
        string committed_type ;
        Boy () {
            committed = false ;
            gf_name = "" ;
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
        void unset_committed () {
            committed = false ;
        }
        void set_girlfriend ( string gname ) {
            set_committed() ;
            gf_name = gname ;
        }
        void set_happiness ( vector < Girl > g , int ng ) {
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
class Commited_boy : public Boy {
    public :
        string name ; // name of boy
        string type ; // can be miser , generous or geek
} ;
#endif //boy_h
