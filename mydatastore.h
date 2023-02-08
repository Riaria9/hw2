#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include"datastore.h"
#include<vector>
#include<map>
<<<<<<< HEAD
=======
#include<queue>
>>>>>>> 8d2e1645e6d9282a03e0cf0949f4428190cdb712

class MyDataStore : public DataStore
{
public:
    MyDataStore();//constructor to setup the keywordMap structure

    void addProduct(Product* p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);

<<<<<<< HEAD
private:
    std::vector<Product*> product_;//the set containing products
    std::vector<User*> user_;//the set containing users
=======

    //std::map<User*,std::queue<Product*>>userWithCart;
    std::map<std::string,std::pair<User*,std::queue<Product*>>>userWithNameNCart;
    std::vector<Product*> product_;//the set containing products
>>>>>>> 8d2e1645e6d9282a03e0cf0949f4428190cdb712
    std::map<std::string, std::set<Product*>> keywordMap;
    
};

#endif