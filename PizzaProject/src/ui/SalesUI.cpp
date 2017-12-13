#include "../../include/ui/SalesUI.h"
#include <iostream>
#include "InvalidAnswerException.h"

using namespace std;

SalesUI::SalesUI()
{
    //ctor
}

SalesUI::~SalesUI()
{
    //dtor
}
void SalesUI::startUI(){
    char selection = '\0';
    cout << "Sales" << endl;
    string comment = "";
    Workplaces workplace;

    workplace = workplacesui.selectWorkplace();
    cout << endl;

    while(selection != 'Q'){

        cout << "1. Add pizza from menu" << endl;
        cout << "2. Add your own pizza" << endl;
        cout << "3. Add something extra" << endl;
        cout << "-----------------------" << endl;
        cout << "4. Show current order" << endl;
        cout << "5. Add comment" << endl;
        cout << "6. Save order" << endl << endl;
        cout << "q. to go back and cancel order" << endl;

        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        if(selection == '1') {
            addPizzaFromMenu();
        }
        else if(selection == '2') {
            addPizza();
        }
        else if(selection == '3') {
            addExtras();
        }
        else if(selection == '4') {
            order = orderservice.makeOrder(pizzasInOrder, extrasInOrder, false, workplace, comment);
            cout << "- Your order -" << endl;
            cout << order << endl;
        }

        else if(selection == '5'){
            comment = getComment();
        }
        else if(selection == '6'){
            saveOrder(workplace, comment);
        }
    }
    cout << endl;
}
void SalesUI::addPizzaFromMenu(){
    int select = 0;
    cout << "Pick a pizza to add to the order" << endl;
    pizzaui.listAvailablePizzas();
    cin >> select;
    cout << endl;

    Pizza pizza;

    pizza = pizzaservice.getPizzaAt(select - 1);

    cout << pizza << " was added to the order" << endl << endl;

    pizzasInOrder.push_back(pizza);
}
void SalesUI::addExtras(){
    int select = 0;
    cout << "Pick an item to add to your order:" << endl << endl;

    extrasui.listExtras();

    cin >> select;
    cout << endl;

    Extras extras;
    extras = extrasservice.getExtrasAt(select - 1);

    cout << extras << " was added to the order" << endl << endl;
    extrasInOrder.push_back(extras);
}
void SalesUI::addPizza(){
    char answer = 'Y';
    do{
        Pizza pizza;
        cout << "Making a new pizza for order" << endl << endl;
        pizza = pizzaui.makeAPizza();
        pizzasInOrder.push_back(pizza);
        cout << endl;
        cout << pizza << " was added to the order" << endl;

        bool flag = true;
        do{
            try{
                cout << "Do you want to add another pizza? (y/n)" << endl;
                cin >> answer;
                checkAnswer(answer);
            }
            catch(InvalidAnswerException){
                cout << "Invalid answer!" << endl;
            }
            answer = toupper(answer);
            if(answer == 'Y' || answer == 'N'){
                flag = true;
            }
            else{
                flag = false;
            }
        }while(!flag);

    }while(answer == 'Y');
}

void SalesUI::saveOrder(Workplaces workplace, string comment){
    bool paidfor = true;
    char answer = '0';
    do{
        try{
            cout << "Has the order been paid for? (y/n)" << endl;
            cin >> answer;
            paidfor = checkAnswer(answer);
        }
        catch(InvalidAnswerException){
            answer = false;
            cout << "Invalid answer!" << endl;
        }
    }while(!answer);

    order = orderservice.makeOrder(pizzasInOrder, extrasInOrder, paidfor, workplace, comment);
    cout << "Your order" << endl;
    cout << order;
    cout << "Has been made" << endl << endl;
    orderservice.addOrder(order);
}

string SalesUI::getComment(){
  bool valid = true;
  string comment = "";
    do{
        cout << "Add your comment (max 50 characters): ";
        cin.ignore();
        getline(cin, comment);

        if (comment.length() > 50){
            valid = false;
            cout << "Comments can only have a maximum of 50 characters" << endl;
        }
        else{
            valid = true;
        }
    }while(!valid);
    return comment;
}

bool SalesUI::checkAnswer(char answer){
    answer = toupper(answer);
    if(answer == 'Y'){
        return true;
    }
    else if(answer == 'N'){
        return false;
    }
    else{
        throw InvalidAnswerException();
    }
}

