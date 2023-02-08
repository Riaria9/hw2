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
    //everytime adding a product, update the keyword map for searching purpose
    product_.push_back(p);

    set<string>keywordInProduct = p->keywords();
    set<string>::iterator it;
    //when the size is 0, every keyword in products would create a new pairs
    if(product_.size()==0){
        //iterate each of the keyword and create pairs and insert into the keyword map
        for(it = keywordInProduct.begin(); it != keywordInProduct.end(); ++it){
            set<Product*> tempSet; tempSet.insert(p);//vector that contains the product
            pair<string,set<Product*>>p1(*it,tempSet);
            keywordMap.insert(p1);
        }
    }
    else{
        //if some products already exist, when go go through the keywordInProduct, need to check if that keyword already existed in keywordMap
        for(it = keywordInProduct.begin(); it != keywordInProduct.end(); ++it){
            if(keywordMap.find(*it) != keywordMap.end()){//if not find,
                ((*(keywordMap.find(*it))).second).insert(p);
            }
            else{//if find it! push it to the 
                set<Product*> tempSet; tempSet.insert(p);//create new set that contains the product and insert to the map
                pair<string,set<Product*>> p1(*it,tempSet);
                keywordMap.insert(p1);
            }
        }
    }
}

/**
     * Adds a user to the data store
     */
void MyDataStore::addUser(User* u) 
{   //std::map<std::string,std::pair<User*,std::queue<Product*>>>userWithNameNCart;
    queue<Product*> q_withpd;
    pair<User*,queue<Product*>> p(u,q_withpd);
    string username = convToLower(u->getName());
    pair<string,pair<User*,queue<Product*>>>temp(username,p);
    userWithNameNCart.insert(temp);
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
    //AND Search
    if(type == 0){
        //iterate over each of the terms.
    int size = terms.size();
    vector<Product*> p;
    //if only 1 term
    if(size == 1){
        if (keywordMap.find(terms[0]) != keywordMap.end()){
            vector<Product*> vectorOfProducts((*(keywordMap.find(terms[0]))).second.begin(),(*(keywordMap.find(terms[0]))).second.end());
            return vectorOfProducts;
        }
    }
    //if 2 items, then simply find intersection between the 2 vector
    else if(size ==2){
        set<Product*> setOfProducts= setIntersection((*(keywordMap.find(terms[0]))).second,(*(keywordMap.find(terms[1]))).second);
        vector<Product*> vectorOfProducts(setOfProducts.begin(),setOfProducts.end());
        return vectorOfProducts;
    }
    
        //first find the union of first 2 sets
        set<Product*> tempSet = setIntersection((*(keywordMap.find(terms[0]))).second,(*(keywordMap.find(terms[1]))).second);
        for(int i = 2; i<size; i++){
        tempSet = setIntersection(tempSet,(*(keywordMap.find(terms[i]))).second);//update the tempSet to the newest intersection between itself and next set of products
        }
        vector<Product*> vectorOfProducts(tempSet.begin(),tempSet.end());
        return vectorOfProducts;
    }

//OR search
    else{
        int size = terms.size();
        if(size == 1){
            vector<Product*>vectorOfProducts(((*(keywordMap.find(terms[0]))).second).begin(),((*(keywordMap.find(terms[0]))).second).end());
            return vectorOfProducts;
        }
        else if(size==2){
            set<Product*>setOfProducts = setUnion(((*(keywordMap.find(terms[0]))).second),((*(keywordMap.find(terms[1]))).second));
            vector<Product*>vectorOfProducts(setOfProducts.begin(),setOfProducts.end());
            return vectorOfProducts;
        }
        else{
            set<Product*> tempSet = setUnion((*(keywordMap.find(terms[0]))).second,(*(keywordMap.find(terms[1]))).second);
            for(int i = 2; i<size; i++){
            tempSet = setUnion(tempSet,(*(keywordMap.find(terms[i]))).second);//update the tempSet to the newest intersection between itself and next set of products
            }
            vector<Product*> vectorOfProducts(tempSet.begin(),tempSet.end());
            return vectorOfProducts;
        }
         
    }
    
}

void MyDataStore::dump(ostream& ofile)
{
    ofile<<"<products>"<<endl;
    int size = product_.size();
    for(int i=0 ;i<size;i++){
        product_[i]->dump(ofile);
    }
    ofile<<"</products>"<<endl;


    ofile<<"<users>"<<endl;
    map<string,pair<User*,queue<Product*>>>::iterator it;
    for(it = userWithNameNCart.begin() ;it!=userWithNameNCart.end();it++){
        ((((*it).second)).first)->dump(ofile);
    }
    ofile<<"</users>"<<endl;
}