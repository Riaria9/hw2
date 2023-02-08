#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include"datastore.h"
#include<vector>
#include<map>
#include<queue>

class MyDataStore : public DataStore
{
public:
    ~MyDataStore();
    MyDataStore();//constructor to setup the keywordMap structure

    void addProduct(Product* p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);


    //std::map<User*,std::queue<Product*>>userWithCart;
    std::map<std::string,std::pair<User*,std::queue<Product*>>>userWithNameNCart;
    std::vector<Product*> product_;//the set containing products
    std::map<std::string, std::set<Product*>> keywordMap;
    std::vector<Product*>hits_;
    
};

#endif