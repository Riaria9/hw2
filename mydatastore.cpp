#include"mydatastore.h"
#include<set>
#include<iostream>
#include"util.h"
using namespace std;

/*** 
 ** Adds a product to the data store
*/

//Constructor that setup the datasture keywordMap
MyDataStore::MyDataStore(){
    
}


void MyDataStore::addProduct(Product* p)
{
    product_.push_back(p);
}

/**
     * Adds a user to the data store
     */
void MyDataStore::addUser(User* u) 
{
    user_.push_back(u);
}

 /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */

//std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
//std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
    // //perform AND search
    // vector<Product*> p;
    // int size = product_.size();
    // set<string> t(terms.begin(),terms.end());
    // //AND search
    // if(type == 0){
    //     for(int i = 0; i<size; i++){
    //         //setIntersection() requires same type argument. need Conversion
    //         set<string >product_kw = product_[i]->keywords();
    //         set<string> shared_str = setIntersection(t, product_kw);
    //         //if the length of the shared_str matches the len of the terms, then must interse
    //         if(shared_str.size()==terms.size()){ p.push_back(product_[i]);}
    //         //addidas airforce ,shared_str, addidas airforce,
    //     }
    // }
    // //OR search
    // else{
    //     for(int i = 0; i<size; i++){
    //         //setIntersection() requires same type argument. need Conversion
    //         set<string >product_kw = product_[i]->keywords();
    //         set<string> shared_str (setIntersection(t, product_kw)) ;
    //         //if the length of the shared_str matches the len of the terms, then must interse
    //         if(shared_str.size() > 0){ p.push_back(product_[i]);}

    //     }
    // }
    // return p;
}

void MyDataStore::dump(ostream& ofile)
{

}