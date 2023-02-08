#include"clothing.h"
#include<iostream>
#include"product.h"
#include"util.h"
#include<sstream>
#include<iomanip>
using namespace std;

//constructor
Clothing::Clothing(const std::string category, const string name, double price, int qty,string size, string brand)
    :Product(category, name,price,qty),size_(size), brand_(brand) {}

//create key word from author, name, and isbn.
set<std::string> Clothing::keywords() const
{
    set<string> s1 = parseStringToWords(name_);
    set<string> s2 = parseStringToWords(brand_);
    set<string> s3 = setUnion(s1,s2);
    return s3;
}
//print book's info
string Clothing::displayString() const
{
    stringstream s;
    string price;
    s<<fixed<<setprecision(2)<<price_;
    price = s.str();
    return name_ +"\n"+"Size: "+size_+" Brand: "+brand_+"\n"+ price +" "+to_string(qty_)+" left.\n";
}
//print database format info
void Clothing::dump(std::ostream& os) const
{

    os<<category_<<endl;
    os<<name_<<endl;
    os<<price_<<endl;
    os<<qty_<<endl;
    os<<size_<<endl;
    os<<brand_<<endl;


}