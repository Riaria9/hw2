#include"book.h"
#include<iostream>
#include"product.h"
#include"util.h"
#include<sstream>
#include<iomanip>
using namespace std;

//constructor
Book::Book(const std::string category, const string name, double price, int qty,string isbn, string author)
    :Product(category, name,price,qty),isbn_(isbn),author_(author) {}

//create key word from author, name, and isbn.
set<std::string> Book::keywords () const
{
    set<string> s1 = parseStringToWords(name_);
    set<string> s2 = parseStringToWords(author_);
    set<string> s3 = setUnion(s1,s2);
    s3.insert(isbn_);
    return s3;
}
//print book's info
string Book::displayString() const
{
    stringstream s;
    string price;
    s<<fixed<<setprecision(2)<<price_;
    price = s.str();
    return name_+"\nAuthor: "+author_+" ISBN: "+isbn_+ "\n" +price+" "+to_string(qty_)+" left.\n";
}
//print database format info
void Book::dump(std::ostream& os) const
{

    os<<category_<<endl;
    os<<name_<<endl;
    os<<price_<<endl;
    os<<qty_<<endl;
    os<<isbn_<<endl;
    os<<author_<<endl;
}