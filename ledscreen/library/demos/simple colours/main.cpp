#include "ledscreen.hpp"

int main (){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto ledstrip = ledscreen::WS2812B(pin, 75);
    for(;;){
        for(unsigned int l=0; l<75; l++){
            ledstrip.draw(l, 0, 100, 0);
        }
        ledstrip.flush();
        hwlib::wait_ms(10);
    }
}