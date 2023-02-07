#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include"datastore.h"
#include<vector>
#include<map>

class MyDataStore : public DataStore
{
public:
    MyDataStore();//constructor to setup the keywordMap structure

    void addProduct(Product* p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);

private:
    std::vector<Product*> product_;//the set containing products
    std::vector<User*> user_;//the set containing users
    std::map<string, vector<Product*>> keywordMap;
    
};

#endif