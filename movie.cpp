#include"movie.h"
#include<iostream>
#include"product.h"
#include"util.h"
#include<sstream>
#include <iomanip>
using namespace std;

//constructor
Movie::Movie(const std::string category, const string name, double price, int qty,string genre, string rating)
    :Product(category, name,price,qty),genre_(genre), rating_(rating) {}

//create key word from author, name, and isbn.
set<string> Movie::keywords()const
{
    set<string> s1 = parseStringToWords(name_);
    s1.insert(convToLower(genre_));
    return s1;
}
//print book's info
string Movie::displayString()const
{
    stringstream s;
    string price;
    s<<fixed<<setprecision(2)<<price_;
    price = s.str();
    return name_ +"\n"+"Genre: "+genre_+" Rating: "+rating_+"\n"+ price+" "+to_string(qty_)+" left.\n";
}
//print database format info
void Movie::dump(std::ostream& os) const
{

    os<<category_<<endl;
    os<<name_<<endl;
    os<<price_<<endl;
    os<<qty_<<endl;
    os<<genre_<<endl;
    os<<rating_<<endl;


}