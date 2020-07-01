#include "ledscreen.hpp"

int main (){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto ledstrip = ledscreen::WS2812B(pin, 25);
    for(;;){
        for(unsigned int i=0; i<105; i++){
            for(unsigned int l=0; l<25; l++){
                ledstrip.draw(l, i-l, i/2-l, i*2-l);
            }
            ledstrip.flush();
            hwlib::wait_ms(10);
        }
    }
}