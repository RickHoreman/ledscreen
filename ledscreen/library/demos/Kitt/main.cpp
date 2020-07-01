#include "ledscreen.hpp"

int main (){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto ledstrip = ledscreen::WS2812B(pin, 25);
    for(;;){
        for(unsigned int i=0; i<21; i++){
            ledstrip.draw(i+4, 10, 0, 0);
            ledstrip.draw(i+3, 60, 0, 0);
            ledstrip.draw(i+2, 0xFF0000);
            ledstrip.draw(i+1, 0xFF0000);
            ledstrip.draw(i, 60, 0, 0);
            ledstrip.draw(i-1, 10, 0, 0);
            ledstrip.draw(i-2, 0x0);
            ledstrip.flush();
            hwlib::wait_ms(30);
        }
        for(unsigned int i=24; i>3; i--){
            ledstrip.draw(i-4, 10, 0, 0);
            ledstrip.draw(i-3, 60, 0, 0);
            ledstrip.draw(i-2, 0xFF0000);
            ledstrip.draw(i-1, 0xFF0000);
            ledstrip.draw(i, 60, 0, 0);
            ledstrip.draw(i, 10, 0, 0);
            ledstrip.draw(i+2, 0x0);
            ledstrip.flush();
            hwlib::wait_ms(30);
        }
    }
}