#include "../../include/models/Order.h"

Order::Order()
{
    this->paid = false;
    this->currentStatus = INPROGRESS;
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

string Order::getPickup(){
    return workplaces.getName();
}

int Order::getPrice() {
    setPrice();
    return this->price;
}
void Order::checkPaid(){
    if(this->paid == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
void Order::checkCurrentStatus(){
    if(this->currentStatus == 1){
        cout << "In progress" << endl;
    }
    else if(this->currentStatus == 2){
        cout << "Ready" << endl;
    }
    else{
        cout << "Delivered" << endl;
    }
}
void Order::addPizza(Pizza& pizza){
    pizzas.push_back(pizza);
}


void Order::write(ofstream& fout) const{

    int countPizza = pizzas.size();
    fout.write((char*)(&countPizza), sizeof(int));

    for (int i = 0; i < countPizza; i++)
    {
        pizzas.at(i).write(fout);
    }
    fout.write((char*)(&paid), sizeof(bool));
    fout.write((char*)(&currentStatus), sizeof(int));
    fout.write((char*)(&price), sizeof(int));
}

void Order::read(ifstream& fin){

    int countPizza = 0;
    fin.read((char*)(&countPizza), sizeof(int));

    for (int i = 0; i < countPizza; i++)
    {
        Pizza pizza;
        pizza.read(fin);
        addPizza(pizza);
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
    out << "Status: ";
    order.checkCurrentStatus();

    out << "Paid for? ";
    order.checkPaid();

    out << "Cost: " << order.getPrice() << "kr." << endl;
    out << endl;

    return out;
}


