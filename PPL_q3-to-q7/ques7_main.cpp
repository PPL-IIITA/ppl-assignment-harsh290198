#include<bits/stdc++.h>
#include "check.h"
#include "couple.h"
#include "boy.h"
#include "girl.h"
#include "gift.h"
vector < Gift > vogift ;
vector < Couples > voc ;
vector < Boy > vob ;
vector < Girl > vog ;
vector < string > vb ;
using namespace std ;
bool cmp ( Gift a , Gift b ) {
    if ( a.price < b.price ) return true ;
    return false ;
}
int main () {
    // Add all boys in the list
    //Add Boys
    freopen( "boys_list.txt" , "r" , stdin ) ;
    while ( 1 ) {
        std::string nme ; int att ; int intel ; int bud ; int min_at ; std::string ct ;
        std::cin >> nme >> att >> intel >> bud >> min_at >> ct ;
        if ( nme == "%$#" ) break ;
        Boy b ;
        b.add_boy( nme , att , intel , bud , min_at , ct ) ;
        vob.push_back ( b ) ;
    }
    // Add Girls
    freopen( "girls_list.txt" , "r" , stdin ) ;
    while ( 1 ) {
        std::string nme ; int att ; int mb ; int intel ; std::string cb , ct ;
        std::cin >> nme >> att >> mb >> intel >> cb >> ct ;
        if ( nme == "%$#" ) break ;
        Girl g ;
        g.add_girl ( nme , att , mb , intel , cb , ct ) ;
        vog.push_back ( g ) ;
    }
    // Add Gifts
    freopen( "gift_list.txt" , "r" , stdin ) ;
    while ( 1 ) {
        int pr , val ; string tt ; int lr , df , uv , uc ;
        cin >> pr >> val >> tt >> lr >> df >> uv >> uc ;
        if ( tt == "***" ) break ;
        Gift g ;
        g.add_gift( pr , val , tt , lr , df , uv , uc ) ;
        vogift.push_back ( g ) ;
    }
    sort ( vogift.begin() , vogift.end() , cmp ) ;
    // Make Couple
    vector < Boy > temp ;
    int nb = vob.size() ; int ng = vog.size() ;
    for ( int i = 0 ; i < ng ; i++ ) {
        temp.clear() ;
        for ( int j = 0 ; j < nb ; j++ ) {
            if ( vob[j].budget >= vog[i].maintenance_budget && vob[j].committed == false && vob[j].min_attraction <= vog[i].attractiveness )
                temp.push_back ( vob[j] ) ;
        }
        int nt = temp.size() , ind = -1 , mx = -1 ;
        if ( vog[i].criteria_boys == "Most_Attractive" )
            for ( int j = 0 ; j < nt ; j++ ) {
                if ( temp[j].attractiveness >= mx ) mx = temp[j].attractiveness , ind = j ;
            }
        if ( vog[i].criteria_boys == "Most_Rich" )
            for ( int j = 0 ; j < nt ; j++ ) {
                if ( temp[j].budget >= mx ) mx = temp[j].budget , ind = j ;
            }
        if ( vog[i].criteria_boys == "Most_Intelligent" )
            for ( int j = 0 ; j < nt ; j++ ) {
                if ( temp[j].intelligence >= mx ) mx = temp[j].intelligence , ind = j ;
            }
        if ( ind != -1 ) {
            Couples c ; int ind2 = -1 ;
            for ( int j = 0 ; j < nb ; j++ ) {
                if ( vob[j].name == temp[ind].name ) { ind2 = j; }
            }
            c.add_couple ( &vob[ind2] , &vog[i] ) ;
            voc.push_back( c ) ;
        }
    }
    for ( int i = 0 ; i < voc.size() ; i++ ) {
        voc[i].set_gifts ( &vob , nb , &vog , ng , vogift ) ;
    }
    // Boys who are to be checked
    for ( int i = 0 ; i < vob.size() ; i++ )
        vb.push_back( vob[i].name ) ;
    int i = 0 ;
    freopen( "ques7_ouput.txt" , "w" , stdout ) ;
    if ( i%2 == 0 ) {
        //Implementing Couple List check
        Couple_list_check cl ;
        cl.vob = vob ;
        cl.voc = voc ;
        cl.check( vb ) ;
    }
    else {
        //Implementing hash check
        Hash_check hc ;
        hc.vob = vob ;
        hc.voc = voc ;
        hc.check( vb ) ;
    }
    return 0 ;
}
