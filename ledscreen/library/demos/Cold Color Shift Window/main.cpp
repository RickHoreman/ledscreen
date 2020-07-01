#include "ledscreen.hpp"
#include <cmath>

int main(){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto leds = ledscreen::ledwindow_horizontal_bottom_right(hwlib::xy(25,3), pin);
    for(;;){
        for(unsigned int k=0; k<25; k++){
            for(unsigned int i=0; i<25; i++){
                for(unsigned int j=0; j<3; j++){
                    int c = i+k;
                    if(c>25){
                        c -= 25;
                    }
                    leds.write(hwlib::xy(c, j), hwlib::color(-0.96*pow(i-12.5, 2.0)+150,0,255));
                }
            }
            leds.flush();
            hwlib::wait_ms(20);
        }
    }
}