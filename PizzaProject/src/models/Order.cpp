#include "../../include/models/Order.h"

Order::Order()
{
    this->paid = false;
    this->currentStatus = 1;
    this->price = 0;
}

Order::~Order()
{
    //dtor
}

void Order::setPizzas(vector<Pizza> pizzas){
    this->pizzas = pizzas;
}

void Order::setExtras(vector<Extras> extras){
    this->extras = extras;
}

void Order::setPaid(bool paid){
    this->paid = paid;
}
void Order::setCurrentStatus(int status){
    this->currentStatus = status;
}

void Order::setPrice(){
    int currentPrice = 0;

    for(unsigned int i = 0; i < pizzas.size(); i++){
        currentPrice += pizzas.at(i).getPriceOfPizza();
    }

    for(unsigned int i = 0; i < extras.size(); i++){
        currentPrice += extras.at(i).getPriceOfExtras();
    }

    this->price = currentPrice;
}

void Order::setPickup(Workplaces workplaces){
    this->workplaces = workplaces;
}

string Order::getLocation(){
    return workplaces.getName();
}

int Order::getPrice() {
    setPrice();
    return this->price;
}
int Order::getStatus(){
    return this->currentStatus;
}

bool Order::checkPaid(){
    return paid;
}

void Order::checkCurrentStatus(){
    if(this->currentStatus == 1){
        cout << "On hold" << endl;
    }
    else if(this->currentStatus == 2){
        cout << "In making" << endl;
    }
    else if (this->currentStatus == 3){
        cout << "Ready" << endl;
    }
    else{
        cout << "Delivered" << endl;
    }
}

void Order::addPizza(Pizza& pizza){
    pizzas.push_back(pizza);
}

void Order::addExtras(Extras& extra){
    extras.push_back(extra);
}

void Order::write(ofstream& fout) const{

    int countPizza = pizzas.size();
    fout.write((char*)(&countPizza), sizeof(int));

    for (int i = 0; i < countPizza; i++){
        pizzas.at(i).write(fout);
    }

    int countExtras = extras.size();
    fout.write((char*)(&countExtras), sizeof(int));

    for (int i = 0; i < countExtras; i++){
        extras.at(i).write(fout);
    }
    fout.write((char*)(&paid), sizeof(bool));
    fout.write((char*)(&currentStatus), sizeof(int));
    fout.write((char*)(&price), sizeof(int));
}

void Order::read(ifstream& fin){

    int countPizza = 0;
    fin.read((char*)(&countPizza), sizeof(int));

    for (int i = 0; i < countPizza; i++){
        Pizza pizza;
        pizza.read(fin);
        addPizza(pizza);
    }

    int countExtras = 0;
    fin.read((char*)(&countExtras), sizeof(int));

    for (int i = 0; i < countExtras; i++){
        Extras extra;
        extra.read(fin);
        addExtras(extra);
    }

    fin.read((char*)(&paid), sizeof(bool));
    fin.read((char*)(&currentStatus), sizeof(int));
    fin.read((char*)(&price), sizeof(int));

}

istream& operator >>(istream& in, Order& order){

    return in;
}

ostream& operator <<(ostream& out, Order& order){
    out << "Pizzas: " << endl;

    for(unsigned int i = 0; i < order.pizzas.size(); i++){
        out << (i + 1) << ". " << order.pizzas.at(i) << endl;
    }

    out << "Extras: " << endl;
    for(unsigned int i = 0; i < order.extras.size(); i++){
        out << (i + 1) << ". " << order.extras.at(i) << endl;
    }
    out << "Status: ";
    order.checkCurrentStatus();

    out << "Paid for? ";
    if(order.checkPaid())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    out << "Cost: " << order.getPrice() << "kr." << endl;
    out << endl;

    return out;
}


