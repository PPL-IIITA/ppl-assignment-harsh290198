#ifndef girls_h
#define girls_h
using namespace std ;
class Girls {
    public :
        // Personal Details
        string name ;
        string bf_name ;
        int attractiveness ;
        int maintenance_budget ;
        int intelligence ;
        string criteria_boys ;
        bool committed ;
        string committed_type ;
        int happiness ;
        // Gift details
        int total_gift_price , total_gift_value ;
        // Utility Functions
        Girls() {
            committed = false ;
        }
        void set_committed ( ) {
            committed = true ;
        }
        void set_boyfriend ( string bname ) {
            if ( committed == false ) return ;
            bf_name = bname ;
        }
        void add_girl ( string nme , int att , int mb , int intel , string cb , string ct ) {
            name = nme ;
            attractiveness = att ;
            maintenance_budget = mb ;
            intelligence = intel ;
            criteria_boys = cb ;
            committed_type = ct ;
        }
        void set_happiness () {
            if ( committed == false ) return ;
            if ( committed_type == "Choosy" ) {
                int t = 0 , x = total_gift_price + total_gift_value ;
                while ( x ) { t++ ; x /= 10 ; }
                happiness = t;
            }
            else if ( committed_type == "Normal" ) {
                happiness = (total_gift_price)+(total_gift_value) ;
            }
            else if ( committed_type == "Desperate" ) {
                happiness = (total_gift_price)*(total_gift_price)*(total_gift_price) ;
            }
        }
} ;
#endif // girls_h
