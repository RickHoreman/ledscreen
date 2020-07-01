#include "ledscreen.hpp"
#include "tetris.hpp"
#include "effects.hpp"

int main(){
    auto pin = hwlib::target::pin_out(hwlib::target::pins::d13);
    auto leds = ledscreen::ledwindow_vertical_bottom_right(hwlib::xy(12,25), pin);
    auto changeModeButton = hwlib::target::pin_in(hwlib::target::pins::d12);
    auto hotkey1 = hwlib::target::pin_in(hwlib::target::pins::d11);
    auto hotkey2 = hwlib::target::pin_in(hwlib::target::pins::d10);
    auto hotkey3 = hwlib::target::pin_in(hwlib::target::pins::d9);
    auto hotkey4 = hwlib::target::pin_in(hwlib::target::pins::d8);
    auto rightButton = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto downButton = hwlib::target::pin_in(hwlib::target::pins::d5);
    auto leftButton = hwlib::target::pin_in(hwlib::target::pins::d4);
    auto tetris = tetris::game(leds, leftButton, hotkey3, rightButton, hotkey4, downButton, hotkey1, changeModeButton);
    int tetrisResult=2;
    int seed=0;
    leds.clear();
    leds.flush();
    for(;;){
        if(tetrisResult==2){
            seed = effects_main(leds, leftButton, rightButton, downButton, hotkey1, hotkey2, hotkey3, hotkey4, changeModeButton);//A timer value in effects_main is used to determine a mostly random seed for the tetris game. It is also desired to enter effects rather than tetris on boot.
            tetrisResult = 0;
        }else if(tetrisResult==0){
            tetrisResult = tetris.main(seed);
        }else{
            tetrisResult = tetris.restart_menu();
        }
    }
}