#include "../../include/ui/SalesUI.h"

void SalesUI::startUI(){
    char selection = '\0';
    cout << "Sales" << endl;
    string comment = "";

    while(selection != 'Q'){

        cout << "1. Add pizza from menu" << endl;
        cout << "2. Add your own pizza" << endl;
        cout << "3. Add something extra" << endl;
        cout << "-----------------------" << endl;
        cout << "4. Show current order" << endl;
        cout << "5. Add comment" << endl;
        cout << "6. Save order" << endl;

        cout << "q. to go back and cancel order" << endl;

        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        if(selection == '1') {
            addPizzaFromMenu();
        }
        else if(selection == '2') {
            pizzaui.setVerbose(false);
            addPizza();
        }
        else if(selection == '3') {
            addExtras();
        }
        else if(selection == '4') {
            order = orderservice.makeOrder(pizzasInOrder, extrasInOrder, false, workplaces, comment, pickup, address, addressNumber);
            cout << "- Your order -" << endl;
            cout << order << endl;
        }

        else if(selection == '5'){
            comment = getComment();
        }
        else if(selection == '6'){
            bool flag;
            if(!orderempty()){
                if(!workplacesui.isWorkplacesVectorEmpty()){

                    setPickupOrDelivery();

                    saveOrder(workplaces, comment);

                    flag = createNewOrder(&order);
                    }
                if (flag == false){
                    break;
                }
            }
            else
                continue;
        }
    }
    cout << endl;
}

bool SalesUI::orderempty(){
    if(pizzasInOrder.empty() && extrasInOrder.empty()){
        cout << "There are no items in the order" << endl;
        return true;
    }
    return false;
}

bool SalesUI::createNewOrder(Order *order){
    char select = '\0';
    Order newOrder;
    cout << "Would you like to create a new order? (y/n)" << endl;
    cin >> select;
    select = toupper(select);

    if(select == 'Y'){
        pizzasInOrder.clear();
        extrasInOrder.clear();
        return true;
    }
    else if(select == 'N'){
        return false;
    }
    else{
        cout << "Invalid input!" << endl;
        createNewOrder(&newOrder);
    }
    return true;
}

void SalesUI::setPickupOrDelivery(){
    string input;
    int select;
    do{
        cout << "Choose whether the order should be picked up or delivered" << endl;
        cout << "1. Picked up" << endl;
        cout << "2. Delivered" << endl;
        cin >> input;
        select = orderui.inputSanitize(input, 3);
    }while(select < 0);
    if(select == 1){
        pickup = true;
        cout << "Where to pick up?" << endl;

        workplaces = workplacesui.selectWorkplace();
        order.setWorkplace(workplaces);
        cout << endl;
    }
    else if(select == 2){
        pickup = false;
        cout << "Please enter street name and then the house number (0 if no house number)" << endl;
        cin >> address;
        cin >> addressNumber;

        cout << "Which store should make the delivery?" << endl;
        workplaces = workplacesui.selectWorkplace();
        order.setWorkplace(workplaces);
    }
}

void SalesUI::addPizzaFromMenu(){
    string input;
    int select = 0;
    bool pizzaempty;

    do{
        pizzaui.listAvailablePizzas();
        pizzaempty = pizzaui.isPizzaVectorEmpty();
        if(!pizzaempty){
            cout << "Pick a pizza to add to the order" << endl;
            cin >> input;
            cout << endl;
            select = orderui.inputSanitize(input, (int)pizzaui.getPizzaMenuSize() + 1);
        }
    }while(select < 0);

    if (!pizzaempty) {
        Pizza pizza;
        pizza = pizzaservice.getPizzaAt(select - 1);

        cout << pizza << " was added to the order" << endl << endl;

        pizzasInOrder.push_back(pizza);
    }
    cout << endl;
}

void SalesUI::addExtras(){
    string input;
    int select = 0;
    bool extrasempty;

    do{
        extrasui.listExtras();
        extrasempty = extrasui.isExtrasVectorEmpty();
        if(!extrasempty){
            cout << "Pick an item to add to your order:" << endl;

            cin >> input;
            cout << endl;
            select = orderui.inputSanitize(input, (int)extrasui.getExtrasVectorSize() + 1);
        }
    }while(select < 0);

    if (!extrasempty) {
        Extras extras;
        extras = extrasservice.getExtrasAt(select - 1);

        cout << extras << " was added to the order" << endl << endl;
        extrasInOrder.push_back(extras);

    }
}

void SalesUI::addPizza(){
    char answer = 'Y';
    do{
        try{
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
        }
        catch(InvalidPizzaException){
            cout << "Not possible to make pizza!" << endl;
            cout << endl;
            return;
        }
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

    order = orderservice.makeOrder(pizzasInOrder, extrasInOrder, paidfor, workplace, comment, pickup, address, addressNumber);
    cout << " ~ Your order ~ " << endl;
    cout << order;
    cout << " ~ Has been made ~ " << endl << endl;
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
            cout << "Comments can only have a maximum of 50 characters!" << endl;
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
