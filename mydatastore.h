#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include"datastore.h"
#include<vector>

class MyDataStore : public DataStore
{
public:
    void addProduct(Product* p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);

private:
    std::vector<Product*> product_;//the set containing products
    std::vector<User*> user_;//the set containing users
    
};

#endif