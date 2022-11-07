#include "Wifibot.h"
#include <unistd.h>

using namespace std;

Wifibot::Wifibot() : 
    m_order(0, 0, true),
    m_stop(false)
    {
        m_p_thread = new std::thread([this]() { run(); });
    }

Wifibot::~Wifibot() {
    m_stop = true;
    usleep(200000);
    delete m_p_thread;
}

void Wifibot::stop() {
    m_order.set_order(0, 0);
}

void Wifibot::speed_up() {
    m_order.set_order(m_order.get_order_L()+5, m_order.get_order_R()+5);
}

void Wifibot::speed_down() {
    m_order.set_order(m_order.get_order_L()-5, m_order.get_order_R()-5);
}

void Wifibot::turn(int direction) {
    if(direction == -1){
        m_order.set_order(m_order.get_order_L()*1.2, m_order.get_order_R()*0.8);
    }else if(direction == 1){       
        m_order.set_order(m_order.get_order_L()*0.8, m_order.get_order_R()*1.2);
    }
}
    
void Wifibot::rotate(int direction) {
    
    stop();
    usleep(1000000);

    if(direction == -1){
        m_order.set_order(10, -10); 
    }else if(direction == 1){
        m_order.set_order(-10, 10);
    }
}

void Wifibot::print(){
    cout << m_order.get_order_L() << endl;
    cout << m_order.get_order_R() << endl;
}

void Wifibot::run() {
    static int cpt;
    while(m_stop == false) {
        cout << "Thread [send] : " << ++cpt << endl;
       
        this_thread::sleep_for(chrono::milliseconds(LOOP_TIME));
    } 
    cout << "Thread [send] : stop!" << endl << endl;
}

