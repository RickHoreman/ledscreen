#include "ledscreen.hpp"

int main(){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto ledwindow = ledscreen::ledwindow_base(hwlib::xy(30,1), pin);
    for(;;){
        for(unsigned int i=0; i<21; i++){
            ledwindow.clear();
            auto line = hwlib::line(hwlib::xy(i,0), hwlib::xy(i+5,0), hwlib::color(0,0,255));
            line.draw(ledwindow);
            ledwindow.flush();
            hwlib::wait_ms(100);
        }
    }
}