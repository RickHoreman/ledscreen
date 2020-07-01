#include "ledscreen.hpp"

int main(){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto leds = ledscreen::ledwindow_horizontal_bottom_right(hwlib::xy(25,3), pin);
    for(;;){
        for(unsigned int i=0; i<25; i++){
            for(unsigned int j=0; j<3; j++){
                leds.clear();
                leds.write(hwlib::xy(i, j));
                leds.flush();
                hwlib::wait_ms(100);
            }
        }
    }
}