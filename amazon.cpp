//TODO incomplete
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include "product.h"
#include "db_parser.h"
#include "product_parser.h"
#include "util.h"
#include "mydatastore.h"

using namespace std;
struct ProdNameSorter {
    bool operator()(Product* p1, Product* p2) {
        return (p1->getName() < p2->getName());
    }
};
void displayProducts(vector<Product*>& hits);

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cerr << "Please specify a database file" << endl;
        return 1;
    }

    /****************
     * Declare your derived DataStore object here replacing
     *  DataStore type to your derived type
     ****************/
    MyDataStore ds;



    // Instantiate the individual section and product parsers we want
    ProductSectionParser* productSectionParser = new ProductSectionParser;
    productSectionParser->addProductParser(new ProductBookParser);
    productSectionParser->addProductParser(new ProductClothingParser);
    productSectionParser->addProductParser(new ProductMovieParser);
    UserSectionParser* userSectionParser = new UserSectionParser;

    // Instantiate the parser
    DBParser parser;
    parser.addSectionParser("products", productSectionParser);
    parser.addSectionParser("users", userSectionParser);

    // Now parse the database to populate the DataStore
    if( parser.parse(argv[1], ds) ) {
        cerr << "Error parsing!" << endl;
        return 1;
    }

    cout << "=====================================" << endl;
    cout << "Menu: " << endl;
    cout << "  AND term term ...                  " << endl;
    cout << "  OR term term ...                   " << endl;
    cout << "  ADD username search_hit_number     " << endl;
    cout << "  VIEWCART username                  " << endl;
    cout << "  BUYCART username                   " << endl;
    cout << "  QUIT new_db_filename               " << endl;
    cout << "====================================" << endl;

    vector<Product*> hits;
    bool done = false;
    while(!done) {
        cout << "\nEnter command: " << endl;
        string line;
        getline(cin,line);
        stringstream ss(line);
        string cmd;
        if((ss >> cmd)) {
            if( cmd == "AND") {
                string term;
                vector<string> terms;
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 0);
                displayProducts(hits);
            }
            else if ( cmd == "OR" ) {
                string term;
                vector<string> terms;
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 1);
                displayProducts(hits);
            }

            /* Add support for other commands here */
            else if (cmd == "ADD"){
                string username;
                int numOfArgs = 0;
                if(ss>>username){
                    if((ds.userWithNameNCart).find(convToLower(username)) == (ds.userWithNameNCart).end()){
                    cout<<"Invalid request"<<endl;
                    continue;
                    }
                    numOfArgs++;
                }
                else{
                    cout<<"Invalid request"<<endl;
                    continue;
                }
                size_t idx;
                if(ss>>idx){
                    //if the idx is greater than the size of hit
                    if(idx>=hits.size()){
                        cout<<"Invalid request"<<endl;
                        continue;
                    }
                    Product* tempProduct = hits[idx];
                    //now find the user and add it to user's cart
                    (((*((ds.userWithNameNCart).find(username))).second).second).push(tempProduct);
                }
                else{
                    cout<<"Invalid request"<<endl;
                }    
            }
            else if( cmd == "VIEWCART"){
                string username;
                if(ss>>username){
                    map<std::string,std::pair<User*,std::queue<Product*>>>::iterator it = ds.userWithNameNCart.find(username);
                    if(it == ds.userWithNameNCart.end()){//if username not found
                        cout<<"Invalid username"<<endl;
                    }
                    else{//if found, display the cart by creating a new vector containing all the element in cart queue and execute displayProducts
                        // size_t size = ((*it).second.second).size();
                        // vector<Product*> tempProduct;
                        // queue<Product*> tempQueue = (*it).second.second;
                        // for(size_t i = 0; i<size; i++){
                        //     tempProduct.push_back(tempQueue.front());
                        //     tempQueue.pop();
                        // }
                        // displayProducts(tempProduct);
                        queue<Product*>tempQueue = (*it).second.second;
                        size_t size = ((*it).second.second).size();
                        for(size_t i = 0; i<size; i++){
                            string temp ((tempQueue.front())->displayString());
                            cout<<++i<<endl;
                            cout<<temp<<endl;
                        }
                    }
                }
                else{
                    cout<<"Invalid username"<<endl;
                }
            }
            //TODO
            else if (cmd == "BUYCART"){
                //go to the cart. make a copy of the cart. use front(), pop().
                //for each fo the
            }

            else if ( cmd == "QUIT") {
                string filename;
                if(ss >> filename) {
                    ofstream ofile(filename.c_str());
                    ds.dump(ofile);
                    ofile.close();
                }
                done = true;
            }
	    




            else {
                cout << "Unknown command" << endl;
            }
        }

    }
    return 0;
}

void displayProducts(vector<Product*>& hits)
{
    int resultNo = 1;
    if (hits.begin() == hits.end()) {
    	cout << "No results found!" << endl;
    	return;
    }
    std::sort(hits.begin(), hits.end(), ProdNameSorter());
    for(vector<Product*>::iterator it = hits.begin(); it != hits.end(); ++it) {
        cout << "Hit " << setw(3) << resultNo << endl;
        cout << (*it)->displayString() << endl;
        cout << endl;
        resultNo++;
    }
}
