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
    cout << "Let's make an order!" << endl;

    Order order;
    vector<Pizza> pizzasInOrder;
    vector<Extras> extrasInOrder;

    while(selection != 'Q'){

        cout << "1: Add a pizza from menu" << endl;
        cout << "2: Add your own pizza" << endl;
        cout << "3: Add something extra" << endl;
        cout << "4. Show current price" << endl;
        cout << "5: Delivery/pickup options" << endl;
        cout << "6: Add comment to order" << endl;
        cout << "7: Save order" << endl;
        cout << "q: To go back" << endl;

        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        if(selection == '1') {
            int select = 0;

            pizzaui.listAvailablePizzas();
            cout << "Pick a pizza to add to the order" << endl;
            cin >> select;
            cout << endl;

            Pizza pizza;

            pizza = pizzaservice.getPizzaAt(select - 1);

            cout << pizza << " was added to the order" << endl;
            cout << endl;
            pizzasInOrder.push_back(pizza);

        }
        else if(selection == '2') {
            char answer = 'Y';
            do{
                Pizza pizza;

                cout << "Making a new pizza for order" << endl;
                cout << endl;

                pizza = pizzaui.makeAPizza();

                pizzasInOrder.push_back(pizza);

                cout << endl;
                cout << pizza << " was added to the order" << endl;

                cout << "Do you want to add another pizza? (press Y for yes)" << endl;
                cin >> answer;
                answer = toupper(answer);


            }while(answer == 'Y');

        }
        else if(selection == '3') {
            do{
                int selection = 0;
                cout << "Pick an item to add to your order:" << endl << endl;
                extrasui.listExtras();

                cin >> selection;
                cout << endl;

                Extras extras;
                extras = extrasservice.getExtrasAt(selection - 1);

            cout << extras << " was added to the order" << endl;
            cout << endl;
            extrasInOrder.push_back(extras);
            }while(selection == 'Y' || selection == 'y');
        }
        else if(selection == '4') {
            cout << "The current price of order is: ";
            order = orderservice.makeOrder(pizzasInOrder, extrasInOrder, false);
            cout << orderservice.getPriceOfOrder(order) << "kr." << endl;
            cout << endl;

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

            order = orderservice.makeOrder(pizzasInOrder, extrasInOrder, paidfor);
            cout << "-Your order-" << endl;
            cout << order;

            orderservice.addOrder(order);

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

