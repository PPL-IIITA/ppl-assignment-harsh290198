#ifndef couples_h
#define couples_h
#include "boys.h"
#include "girls.h"
#include "gifts.h"
using namespace std ;
class Couples {
    public :
        string name_girl ;
        string name_boy ;
        int happiness ;
        int compatibility ;
        Couples () {
            }
        void set_happiness ( vector<Boys> b , int nb , vector < Girls > g , int ng ) {
            int boy , girl ;
            for ( int i = 0 ; i < ng ; i++ ) {
                if ( name_girl == g[i].name ) girl = i ;
            }
            for ( int i = 0 ; i < nb ; i++ ) {
                if ( name_boy == b[i].name ) boy = i ;
            }
            happiness = b[boy].happiness + g[girl].happiness ;
        }
        void set_compatibility ( Boys b , Girls g ) {
            compatibility = b.budget - g.maintenance_budget ;
            compatibility += abs ( b.attractiveness - g.attractiveness ) ;
            compatibility += abs ( b.intelligence - g.intelligence ) ;
        }
        void add_couple ( Boys *b , Girls *g ) {
            name_girl = (*g).name ;
            name_boy = (*b).name ;
            (*b).set_committed() ;
            (*b).set_girlfriend( (*g).name ) ;
            (*g).set_committed() ;
            (*g).set_boyfriend( (*b).name ) ;
            set_compatibility( (*b) , (*g) ) ;
        }
        bool cmp ( Gift a , Gift b ) {
            if ( a.price > b.price ) return true ;
            return false ;
        }
        void set_gifts ( vector<Boys> *b , int nb , vector < Girls > *g , int ng , vector < Gift > vg ) {
            int boy , girl ;
            for ( int i = 0 ; i < nb ; i++ )
                if ( name_boy == (*b)[i].name ) boy = i ;
            for ( int i = 0 ; i < ng ; i++ )
                if ( name_girl == (*g)[i].name ) girl = i ;
            int basket_price = 0 , basket_value = 0  ;
            if ( (*b)[boy].committed_type == "Generous" )
                for ( int i = vg.size()-1 ; i >= 0 ; i-- ) {
                    if ( basket_price + vg[i].price <= (*b)[boy].budget ) {
                        basket_price += vg[i].price ;
                        if ( (*g)[girl].committed_type == "Choosy" && vg[i].type == "Luxury" ) basket_value += 2*vg[i].value ;
                        else basket_value += vg[i].value ;
                    }
                }
            else
                for ( int i = 0 ; i < vg.size() ; i++ ) {
                    if ( basket_price + vg[i].price <= (*b)[boy].budget ) {
                        basket_price += vg[i].price ;
                        if ( (*g)[girl].committed_type == "Choosy" && vg[i].type == "Luxury" ) basket_value += 2*vg[i].value ;
                        else basket_value += vg[i].value ;
                    }
                }
            (*b)[boy].total_gift_price = basket_price ;
            (*b)[boy].total_gift_value = basket_value ;
            (*g)[girl].total_gift_price = basket_price ;
            (*g)[girl].total_gift_value = basket_value ;
            (*g)[girl].set_happiness ( ) ;
            (*b)[boy].set_happiness ( *g , ng ) ;
            set_happiness( *b , nb , *g , ng ) ;
        }
};
#endif // couples_h
