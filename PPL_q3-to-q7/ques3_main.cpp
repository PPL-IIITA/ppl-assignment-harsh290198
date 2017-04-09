#include<bits/stdc++.h>
#include "boy.h"
#include "girl.h"
#include "gift.h"
#include "couple.h"
vector < Boy > vob , temp ;
vector < Girl > vog ;
vector < Couples > voc ;
vector < Gift > vogift ;
bool cmp ( Gift a , Gift b ) {
    if ( a.price < b.price ) return true ;
    return false ;
}
bool cmp1 ( Couples a , Couples b ) {
    if ( a.happiness > b.happiness ) return true ;
    return false ;
}
bool cmp2 ( Couples a , Couples b ) {
    if ( a.compatibility < b.compatibility ) return true ;
    return false ;
}
int main () {
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
    freopen( "couples_list.txt" , "w" , stdout ) ;
    for ( int i = 0 ; i < voc.size() ; i++ ) {
        cout << voc[i].name_boy << " " << voc[i].name_girl << " " << voc[i].happiness << " " << voc[i].compatibility << endl ;
    }
    cout << "***" ;
    cout << endl ;
    int k = 20 ;
    sort ( voc.begin() , voc.end() , cmp1 ) ;
    freopen ( "k_happiest.txt" , "w" , stdout ) ;
    for ( int i = 0 ; i < k && i < voc.size() ; i++ ) {
        cout << voc[i].name_boy << " " << voc[i].name_girl << endl ;
    }
    sort ( voc.begin() , voc.end() , cmp2 ) ;
    freopen ( "k_compatible.txt" , "w" , stdout ) ;
    for ( int i = 0 ; i < k && i < voc.size() ; i++ ) {
        cout << voc[i].name_boy << " " << voc[i].name_girl << endl ;
    }
    return 0 ;
}

