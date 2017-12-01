#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H


class PizzaRepository
{
    private:

    public:
        PizzaRepository();
        virtual ~PizzaRepository();

        void storePizza(Pizza pizza);
        Pizza retrievePizza();
};

#endif // PIZZAREPOSITORY_H
