#include "../../include/repositories/OrderRepository.h"

void OrderRepository::addOrderToRepo(Order& order){
    ofstream fout;
    string filename = order.getLocation() + ".dat";

    try {

        fout.open(filename.c_str(), ios::binary|ios::app);

        if (fout.is_open()){
            order.write(fout);
            fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE " << filename << "]" << endl;
    }
}

void OrderRepository::replaceOrdersInRepo(vector<Order> orders, string workplace){
    ofstream fout;
    string filename = workplace + ".dat";

    try {
        fout.open(filename.c_str(), ios::binary);
        if (fout.is_open()){

            for(unsigned int i = 0; i < orders.size(); i++){
                orders.at(i).write(fout);
            }
        fout.close();
        }
        else {
            throw InvalidWriteException();
        }
    }
    catch (InvalidWriteException){
        cout << "[UNABLE TO WRITE INTO FILE " << filename << "]" << endl;
    }
}

vector<Order> OrderRepository::getOrders(string work){
    ifstream fin;
    vector<Order> orders;
    string filename = work + ".dat";

    try {

        fin.open(filename.c_str(), ios::binary);

        if (fin.is_open()){

            while(!fin.eof()){
                Order order;
                order.read(fin);

                if(fin.eof()){
                    break;
                }

                orders.push_back(order);
            }

        fin.close();
        }
        else {
            throw InvalidReadException();
        }
    }
    catch (InvalidReadException){
        cout << "[UNABLE TO READ FILE " << filename << "]" << endl;
    }

    return orders;
}

