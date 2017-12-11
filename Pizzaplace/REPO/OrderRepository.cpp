#include "OrderRepository.h"
#include <fstream>
#include <iostream>



OrderRepository::OrderRepository()
{
    //ctor
}



void OrderRepository::storeOrder(const Order& order){       ///store orders to text file
    ofstream fout;
    fout.open("Orders.txt", ios::app);
    fout << order;
    fout.close();


}
/*
vector<Order> OrderRepository::retrieveOrder(){

   vector<Order> orders;

    ifstream fin;
    fin.open("Orders.txt");
    Order order;







        orders.push_back(order);


    fin.close();

}
*/
