#ifndef ORDER_H
#define ORDER_H

#define SPEED_MAX_WITH_CTL 40
#define SPEED_MAX_WITHOUT_CTL 60

class Order{
 
    private:

        short m_order_R, m_order_L;
        bool m_speed_ctr;

        void limit();

    public:
    
        Order(short left = 0, short right = 0, bool str = true);
        ~Order();

        short const get_order_R();
        short const get_order_L();
        bool const get_speed_ctr();

        void set_order(short left, short right);
        void set_speed_ctr(bool ctr);
};

#endif // ORDER_H
