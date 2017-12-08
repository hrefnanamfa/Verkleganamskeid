#include "SalesUI.h"
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
    cout << "Let's make an order!" << endl;

    Order order;
    vector<Pizza> pizzasInOrder;

    while(selection != 'Q'){

        cout << "1: Add a pizza from menu" << endl;
        cout << "2: Add your own pizza" << endl;
        cout << "3: Add something extra" << endl;
        cout << "4: Delivery/pickup options" << endl;
        cout << "5: Order payment status" << endl;
        cout << "6: Add comment to order" << endl;
        cout << "7: Save order" << endl;
        cout << "q: To go back" << endl;

        cin >> selection;
        selection = toupper(selection);

        if(selection == '1') {
            int select = 0;

            pizzaui.listAvailablePizzas();
            cout << "Pick a pizza to add to the order" << endl;
            cin >> select;

            Pizza pizza;

            pizza = pizzaservice.getPizzaAt(select - 1);

            cout << pizza << " was added to the order" << endl;

            pizzasInOrder.push_back(pizza);

        }
        else if(selection == '2') {
            char answer = 'Y';
            do{
                Pizza pizza;

                pizza = pizzaui.makeAPizza();

                pizzasInOrder.push_back(pizza);

                cout << pizza << " was added to the order" << endl;

                cout << "Do you want to add another pizza? (press Y for yes)" << endl;
                cin >> answer;
                answer = toupper(answer);


            }while(answer == 'Y');

        }
        else if(selection == '3') {

        }
        else if(selection == '4') {

        }
        else if(selection == '5'){

        }
        else if(selection == '6'){

        }
        else if(selection == '7'){
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

            cout << "Pizzas in vector:" << pizzasInOrder.size();
            order = orderservice.makeOrder(pizzasInOrder, paidfor);
            cout << order;
        }
    }
    cout << endl;
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

