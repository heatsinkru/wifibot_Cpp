#include "Wifibot.h"

int main() {

    Wifibot robot;

    for(int i; i<3; i++) {
        std::cout << "Thread [main]" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    robot.~Wifibot();

    return 0;
}