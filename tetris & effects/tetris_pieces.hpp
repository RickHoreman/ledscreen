#ifndef TETRIS_PIECES_HPP
#define TETRIS_PIECES_HPP
#include "hwlib.hpp"
#include "ledscreen.hpp"

struct positions {
    hwlib::xy pos0;
    hwlib::xy pos1;
    hwlib::xy pos2;
    hwlib::xy pos3;
};

namespace tetris{
    class piece{
    public:
        int type;
        hwlib::xy start;
        positions hitbox;
        hwlib::color colour;
        int rotation;
        piece(int type, hwlib::xy start, hwlib::color colour):
        type(type),
        start(start),
        colour(colour),
        rotation(0)
        {
            if(type=='i'){
                hitbox.pos0 = hwlib::xy(start.x, start.y-2);
                hitbox.pos1 = hwlib::xy(start.x, start.y-1);
                hitbox.pos2 = start;
                hitbox.pos3 = hwlib::xy(start.x, start.y+1);
            }else if(type=='o'){
                hitbox.pos0 = start;
                hitbox.pos1 = hwlib::xy(start.x, start.y+1);
                hitbox.pos2 = hwlib::xy(start.x+1, start.y);
                hitbox.pos3 = hwlib::xy(start.x+1, start.y+1);
            }else if(type=='t'){
                hitbox.pos0 = start;
                hitbox.pos1 = hwlib::xy(start.x, start.y-1);
                hitbox.pos2 = hwlib::xy(start.x-1, start.y);
                hitbox.pos3 = hwlib::xy(start.x+1, start.y);
            }else if(type=='s'){
                hitbox.pos0 = start;
                hitbox.pos1 = hwlib::xy(start.x, start.y-1);
                hitbox.pos2 = hwlib::xy(start.x+1, start.y-1);
                hitbox.pos3 = hwlib::xy(start.x-1, start.y);
            }else if(type=='z'){
                hitbox.pos0 = start;
                hitbox.pos1 = hwlib::xy(start.x, start.y-1);
                hitbox.pos2 = hwlib::xy(start.x-1, start.y-1);
                hitbox.pos3 = hwlib::xy(start.x+1, start.y);
            }else if(type=='j'){
                hitbox.pos0 = start;
                hitbox.pos1 = hwlib::xy(start.x, start.y-1);
                hitbox.pos2 = hwlib::xy(start.x, start.y+1);
                hitbox.pos3 = hwlib::xy(start.x-1, start.y+1);
            }else if(type=='l'){
                hitbox.pos0 = start;
                hitbox.pos1 = hwlib::xy(start.x, start.y-1);
                hitbox.pos2 = hwlib::xy(start.x, start.y+1);
                hitbox.pos3 = hwlib::xy(start.x+1, start.y+1);
            }else if(type=='e'){
                hitbox.pos0 = start;
                hitbox.pos1 = start;
                hitbox.pos2 = start;
                hitbox.pos3 = start;
            }
        }
        int update(ledscreen::ledwindow_base & window, const int & horizontal, const int & vertical, const int & rotate);
        void move(ledscreen::ledwindow_base & window, const int & x, const int & y);
        positions rotate(const int & r);
        void draw(ledscreen::ledwindow_base & window);
        void clear(ledscreen::ledwindow_base & window);
    };
};

#endif