#ifndef QUANTITY_H_
#define QUANTITY_H_

class Quantity
{

public:
    Quantity(){};
    virtual ~Quantity(){};
    virtual double getWeight()
    {
        return 0;
    };
};

#endif /* QUANTITY_H_ */
