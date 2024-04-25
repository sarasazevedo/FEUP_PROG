/*
Consider the definition of class Product given in header file Product.h:
class Product {
public:
  Product(int id, float price) : id_(id), price_(price) { };
  int get_id() const { return id_; }
  virtual float get_sell_price() const { return price_; }
protected:
  int id_;
  float price_;
};
This class is used to represent the products made and sold by a company. The company also resells some products that it buys to other companies. To represent these resale products it is useful to define a class ResaleProduct, derived from Product, defined in header ResaleProduct.h.
ResaleProduct has an additional attribute: the profit margin of the company (an integer value, that represents the percentage of profit). For example if the price of a product acquired for resale is 200 and the profit margin is 10%, the final price of the resale product is 200x(100+10)/100=220.
Note: in C/C++, be careful with the division of 2 integer values!
Write the definition of class ResaleProduct, that should be a subclass of Product, having:
A constructor that takes all the parameters necessary to define a resale product: id, price and profit margin;
Functions int get_profit_margin() const and void set_profit_margin(int margin) to set the profit margin.
and a redefinition of get_sell_price() according to the requirements above.
*/

#include <iostream>
#include <iomanip>
#include "Product.h"
#include "ResaleProduct.h"
#include <vector>
using namespace std;

int main(){
    { const ResaleProduct p1(10001, 2.5f, 10);
    cout << fixed << setprecision(2)
       << p1.get_id() << ' ' 
       << p1.get_profit_margin() << ' ' 
       << p1.get_sell_price() << endl; }

    { ResaleProduct p1(10002, 10, 0);
    p1.set_profit_margin(30);
    cout << fixed << setprecision(2)
        << p1.get_id() << ' ' 
        << p1.get_profit_margin() << ' ' 
        << p1.get_sell_price() << endl; }

    { const Product& p1 = ResaleProduct(10003, 2.75f, 100);
    cout << fixed << setprecision(2)
        << p1.get_id() << ' ' 
        << p1.get_sell_price() << endl; }

    { const Product& p1 = ResaleProduct(10004, 100.90f, 50);
    cout << fixed << setprecision(2)
        << p1.get_id() << ' ' 
        << p1.get_sell_price() << endl; }

    return 0;
}