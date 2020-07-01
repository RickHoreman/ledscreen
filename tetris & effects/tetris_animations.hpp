#ifndef TETRIS_ANIMATIONS_HPP
#define TETRIS_ANIMATIONS_HPP
#include "hwlib.hpp"
#include <cmath>

void tetris_logo(hwlib::window & window);
void game_over_anim(hwlib::window & window);
void draw_pointer(hwlib::window & window, const hwlib::color & pointerColour, const int & pointerPos);
void draw_level(hwlib::window & window, const int & level);
void draw_score(hwlib::window & window, const int & score);
void draw_number(hwlib::window & window, const hwlib::xy & start, const unsigned int & n, const hwlib::color & colour=hwlib::color(0,0,50));
void fill_screen(hwlib::window & w, const int & r, const int & g, const int & b);
void write_m(hwlib::window & w, const hwlib::color & colour, const hwlib::xy & pos0, const hwlib::xy & pos1=hwlib::xy(-5,-5), const hwlib::xy & pos2=hwlib::xy(-5,-5),
    const hwlib::xy & pos3=hwlib::xy(-5,-5), const hwlib::xy & pos4=hwlib::xy(-5,-5), const hwlib::xy & pos5=hwlib::xy(-5,-5), const hwlib::xy & pos6=hwlib::xy(-5,-5),
    const hwlib::xy & pos7=hwlib::xy(-5,-5), const hwlib::xy & pos8=hwlib::xy(-5,-5), const hwlib::xy & pos9=hwlib::xy(-5,-5), const hwlib::xy & pos10=hwlib::xy(-5,-5),
    const hwlib::xy & pos11=hwlib::xy(-5,-5), const hwlib::xy & pos12=hwlib::xy(-5,-5), const hwlib::xy & pos13=hwlib::xy(-5,-5), const hwlib::xy & pos14=hwlib::xy(-5,-5),
    const hwlib::xy & pos15=hwlib::xy(-5,-5), const hwlib::xy & pos16=hwlib::xy(-5,-5), const hwlib::xy & pos17=hwlib::xy(-5,-5), const hwlib::xy & pos18=hwlib::xy(-5,-5),
    const hwlib::xy & pos19=hwlib::xy(-5,-5), const hwlib::xy & pos20=hwlib::xy(-5,-5), const hwlib::xy & pos21=hwlib::xy(-5,-5), const hwlib::xy & pos22=hwlib::xy(-5,-5),
    const hwlib::xy & pos23=hwlib::xy(-5,-5), const hwlib::xy & pos24=hwlib::xy(-5,-5));

#endif