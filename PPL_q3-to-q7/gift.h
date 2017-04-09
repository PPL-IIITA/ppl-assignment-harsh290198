#ifndef gift_h
#define gift_h
class Gift {
    public :
        string type ;
        int price , value ; // Details of each gift
        void add_gift ( int pr , int val, string tt , int lr , int df , int uv , int uc ) {
            price = pr ;
            value = val ;
            type = tt ;
        }
} ;
class Essential : public Gift {
    public :
        void add_gift ( int pr , int val, string tt , int lr , int df , int uv , int uc ) {
            price = pr ;
            value = val ;
            type = "Essential" ;
        }
} ;
class Luxury : public Gift {
    public :
        int luxury_rating ;
        int difficulty ;
        void add_gift ( int pr , int val , string tt , int lr , int df , int uv , int uc ) {
            price = pr ;
            value = val ;
            luxury_rating = lr ;
            difficulty = df ;
            type = "Luxury" ;
        }
} ;
class Utility : public Gift {
    public :
        int utility_value ;
        int utility_class ;
        void add_gift ( int pr , int val , string tt , int lr , int df , int uv , int uc ) {
            price = pr ;
            value = val ;
            utility_class = uc ;
            utility_value = uv ;
            type = "Utility" ;
        }
} ;
#endif // gift_h
