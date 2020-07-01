#include "ledscreen.hpp"

int main (){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto ledstrip = ledscreen::WS2812B(pin, 300);
    for(;;){
        for(unsigned int l=0; l<300; l++){
            ledstrip.draw(l, 75,15,0); //Insert RGB values here, length can be adjusted above.
            ledstrip.flush();
        }
        hwlib::wait_ms(10);
    }
}