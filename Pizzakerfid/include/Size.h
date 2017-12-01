#ifndef SIZE_H
#define SIZE_H


class Size
{
    private:
        int inches;

    public:
        Size(int inches);
        void setSize(int inches);
        virtual ~Size();

};

#endif // SIZE_H
