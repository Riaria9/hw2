#include"movie.h"
#include<iostream>
#include"product.h"
#include"util.h"
using namespace std;

//constructor
Movie::Movie(const std::string category, const string name, double price, int qty,string genre, string rating)
    :Product(category, name,price,qty),genre_(genre), rating_(rating) {}

//create key word from author, name, and isbn.
set<string> Movie::keywords()const
{
    set<string> s1 = parseStringToWords(name_);
    set<string> s2 = parseStringToWords(genre_);
    set<string> s3 = setUnion(s1,s2);
    return s3;
}
//print book's info
string Movie::displayString()const
{
    return name_ +"\n"+"Genre: "+genre_+" Rating: "+rating_+"\n"+to_string(price_)+" "+to_string(qty_)+" left\n";
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