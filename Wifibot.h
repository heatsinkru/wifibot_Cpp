#ifndef WIFIBOT_H
#define WIFIBOT_H

#define LOOP_TIME 200

#include "Order.h"
#include "socket.h"
#include <thread>
#include <iostream>

class Wifibot{

    private:
    
        Order m_order;
        std::thread* m_p_thread;
        bool m_stop;
    
    public:
        
        Wifibot();
        ~Wifibot();

        void stop();
        void speed_up();
        void speed_down();
        void turn(int direction);
        void rotate(int direction);
        void print();
        void run();

};
#endif // WIFIBOT_H
