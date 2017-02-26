#ifndef gifts_h
#define gifts_h
using namespace std;
class Gift {
    public :
        int price ;
        int value ;
        string type ;
        int luxury_rating ;
        int difficulty ;
        int utility_values ;
        int utility_class ;
        Gift () {
            luxury_rating = 0 ;
            difficulty = 0 ;
            utility_class = 0 ;
            utility_values = 0 ;
        }
        void add_gift ( int pr , int val, string tt , int lr , int df , int uv , int uc ) {
            price = pr ;
            value = val ;
            type = tt ;
            if ( tt == "Luxury" ) {
                luxury_rating = lr ;
                difficulty = df ;
            }
            else if ( tt == "Utility" ) {
                utility_values = uv ;
                utility_class = uc ;
            }
        }
} ;
#endif // gifts_h
