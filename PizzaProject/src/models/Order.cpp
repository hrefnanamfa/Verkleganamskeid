#include "../../include/models/Order.h"

Order::Order()
{
    this->paid = false;
    this->currentStatus = 1;
    this->price = 0;
    this->comment = "";
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

void Order::setComment(string comment){
    this->comment = comment;
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

string Order::getComment(){
    return this->comment;
}

bool Order::checkPaid(){
    return paid;
}

void Order::checkCurrentStatus(){
    if(this->currentStatus == 1){
        cout << "On hold";
    }
    else if(this->currentStatus == 2){
        cout << "In making";
    }
    else if (this->currentStatus == 3){
        cout << "Ready";
    }
    else{
        cout << "Delivered";
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

    int commentLength = comment.length() + 1;
    fout.write((char*)(&commentLength), sizeof(int));
    fout.write(comment.c_str(), commentLength);
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

    int commentLength;
    fin.read((char*)(&commentLength), sizeof(int));
    char *str = new char[commentLength];
    fin.read(str, commentLength);
    comment = str;
}

istream& operator >>(istream& in, Order& order){

    return in;
}

ostream& operator <<(ostream& out, Order& order){
    if(!order.pizzas.empty()){
        out << "Pizzas: " << endl;

        for(unsigned int i = 0; i < order.pizzas.size(); i++){
            out << "    " << (i + 1) << ". " << order.pizzas.at(i) << endl;
        }
    }
    if(!order.extras.empty()){
        out << "Extras: " << endl;
        for(unsigned int i = 0; i < order.extras.size(); i++){
            out << "    " << (i + 1) << ". " << order.extras.at(i) << endl;
        }
    }
    out << "Status: ";
    order.checkCurrentStatus();
    out << " // ";
        out << "Paid for: ";
    if(order.checkPaid())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    if(order.getComment() != ""){
    out << "Comment: " << order.getComment() << endl;
    }
    out << "Total cost: " << order.getPrice() << " kr." << endl;

    return out;
}


