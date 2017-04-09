#include<bits/stdc++.h>
#include "boy.h"
#include "girl.h"
#include "couple.h"
#include "gift.h"
vector < Boy > vob ; // Vector containing all boys
vector < Girl > vog ; // Vector containing all girls
vector < Couples > voc ; // Vecotor containg all couples
bool cmp1 ( Couples a , Couples b ) {
    if ( a.happiness > b.happiness ) return true ;
    return false ;
}
int main () {
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
    freopen( "couples_list.txt" , "r" , stdin ) ;
    while ( 1 ) {
        string bname , gname ; int happ , comp ;
        cin >> bname >> gname >> happ >> comp ;
        if ( bname == "***" ) break ;
        Couples c ;
        c.name_boy = bname ; c.name_girl = gname ; c.happiness = happ ; c.compatibility = comp ;
        voc.push_back ( c ) ;
    }
    // Now performing breakup
    sort ( voc.begin() , voc.end() , cmp1 ) ;
    int k = 1 ;
    for ( int i = 0 ; i < k && i < voc.size() ; i++ ) {
        int ind1 , ind2 ; Couples c = voc[i] ;
        for ( int j = 0 ; j < vob.size() ; j++ ) {
            if ( vob[j].name == voc[i].name_boy ) {
                ind1 = j;
            }
        }
        for ( int j = 0 ; j < vog.size() ; j++ ) {
            if ( vog[j].name == voc[i].name_boy ) {
                ind2 = j ;
            }
        }
        c.break_up( &vob[ind1] , &vog[ind2] ) ;
        voc[i].name_boy = "****" ;
    }
    freopen( "couples_list_after_breakup.txt" , "w" , stdout ) ;
    for ( int i = 0 ; i < voc.size() ; i++ ) {
        if ( voc[i].name_boy == "****" ) continue ;
        cout << voc[i].name_boy << " " << voc[i].name_girl << " " << voc[i].happiness << " " << voc[i].compatibility << endl ;
    }
    cout << "***" ;
    return 0 ;
}
