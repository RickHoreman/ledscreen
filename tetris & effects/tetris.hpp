#ifndef TETRIS_HPP
#define TETRIS_HPP
#include "ledscreen.hpp"
#include "tetris_pieces.hpp"
#include "tetris_animations.hpp"
#include "hwlib.hpp"
#include <random> 

namespace tetris{
    class game {
    private:
        ledscreen::ledwindow_base & window;
        hwlib::pin_in &left, &rLeft, &right, &rRight, &down, &pause, &close;
        bool pieceFalling;
        int level;
        int score;
        tetris::piece fallingPiece;
        tetris::piece nextPiece;
    public:
        game(ledscreen::ledwindow_base & window, hwlib::pin_in & left, hwlib::pin_in & rLeft, hwlib::pin_in & right, hwlib::pin_in & rRight, hwlib::pin_in & down, hwlib::pin_in & pause, hwlib::pin_in & close):
        window(window),
        left(left),
        rLeft(rLeft),
        right(right),
        rRight(rRight),
        down(down),
        pause(pause),
        close(close),
        pieceFalling(false),
        level(0),
        score(0),
        fallingPiece(tetris::piece('e', hwlib::xy(-5,-5), hwlib::color(0,0,0))),
        nextPiece(tetris::piece('e', hwlib::xy(-5,-5), hwlib::color(0,0,0)))
        {}
        int main(const int & seed);
        void player_input();
        void draw_frame();
        int check_score(const int unsigned & line=1, const unsigned int & linesCleared=0);
        int count_score(const unsigned int & linesCleared);
        void line_clear(const unsigned int & y, const unsigned int & lines);
        tetris::piece spawn(tetris::piece & piece);
        tetris::piece newPiece(const int & seedAddition);
        int restart_menu();
        void update_level();
    };
};


#endif