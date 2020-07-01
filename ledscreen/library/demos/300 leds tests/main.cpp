#include "ledscreen.hpp"

void white_test(ledscreen::ledwindow_base & leds);
void rgb_test(ledscreen::ledwindow_base & leds);

int main(){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto leds = ledscreen::ledwindow_vertical_bottom_right(hwlib::xy(12,25), pin); // <-- change dimension and layout to fit your matrix. The max tested is 25x12 for a total of 300 pixels.
    
    //Very useful for testing if the leds are all getting enough power. I calculated a third of the max power draw per pixel, so it turns yellow if I try to make them all white. 
    white_test(leds);

    //Miscellaneous test to see if all colours are being displayer correcty if the entire lot is covered.
    //rgb_test(leds);
}

void white_test(ledscreen::ledwindow_base & leds){
    for(;;){
        leds.clear();
        for(int i=0; i<leds.size.y; i++){
            for(int j=0; j<leds.size.x; j++){
                leds.write(hwlib::xy(j, i));
                leds.flush();
            }
        }
    }
}

void rgb_test(ledscreen::ledwindow_base & leds){
    leds.clear();
    for(;;){
        for(int i=0; i<leds.size.y; i++){
            for(int j=0; j<leds.size.x; j++){
                leds.write(hwlib::xy(j, i), hwlib::color(255,0,0));
                leds.flush();
            }
        }
        for(int i=0; i<leds.size.y; i++){
            for(int j=0; j<leds.size.x; j++){
                leds.write(hwlib::xy(j, i), hwlib::color(0,255,0));
                leds.flush();
            }
        }
        for(int i=0; i<leds.size.y; i++){
            for(int j=0; j<leds.size.x; j++){
                leds.write(hwlib::xy(j, i), hwlib::color(0,0,255));
                leds.flush();
            }
        }
    }
}