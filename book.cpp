#include"book.h"
#include<iostream>
#include"product.h"
#include"util.h"
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
    string nl="\n";
    return name_+"\nAuthor: "+author_+" ISBN: "+isbn_+ "\n" +to_string(price_)+" "+to_string(qty_)+" left.\n";
}
//print database format info
void Book::dump(std::ostream& os) const
{

    cout<<category_<<endl;
    cout<<name_<<endl;
    cout<<price_<<endl;
    cout<<qty_<<endl;
    cout<<isbn_<<endl;
    cout<<author_<<endl;
}