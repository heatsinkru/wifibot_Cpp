#include "Order.h"
#include <iostream>

using namespace std;

Order::Order(short left, short right, bool ctr){ 
    m_order_R = right;
    m_order_L = left;
    m_speed_ctr = ctr;
}

Order::~Order(){}

short const Order::get_order_R(){ return m_order_R; }

short const Order::get_order_L(){ return m_order_L; }

bool const Order::get_speed_ctr(){ return m_speed_ctr; }

void Order::set_order(short left, short right){ 
    m_order_R = right;
    m_order_L = left;
}

void Order::set_speed_ctr(bool ctr){ m_speed_ctr = ctr; }

void Order::limit(){
    
    switch(m_speed_ctr) {
        case true:
            
            if(m_order_R > SPEED_MAX_WITH_CTL)
                m_order_R = SPEED_MAX_WITH_CTL;

            else if(m_order_R < -SPEED_MAX_WITH_CTL)
                m_order_R =  -SPEED_MAX_WITH_CTL;
            

            if(m_order_L > SPEED_MAX_WITH_CTL)
                m_order_L = SPEED_MAX_WITH_CTL;
            else if(m_order_L < -SPEED_MAX_WITH_CTL)
                m_order_L = -SPEED_MAX_WITH_CTL;

            break;

        case false:

            if(m_order_R > SPEED_MAX_WITHOUT_CTL)
                m_order_R = SPEED_MAX_WITHOUT_CTL;
            else if(m_order_R < -SPEED_MAX_WITHOUT_CTL)
                m_order_R =  -SPEED_MAX_WITHOUT_CTL;
            

            if(m_order_L > SPEED_MAX_WITHOUT_CTL)
                m_order_L = SPEED_MAX_WITHOUT_CTL;
            else if(m_order_L < -SPEED_MAX_WITHOUT_CTL)
                m_order_L = -SPEED_MAX_WITHOUT_CTL;

            break;
    }

};
