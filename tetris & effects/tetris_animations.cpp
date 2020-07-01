#include "tetris_animations.hpp"

void tetris_logo(hwlib::window & window){
    window.clear();
    window.flush();
    auto t_base = hwlib::line(hwlib::xy(3,2), hwlib::xy(3,6), hwlib::color(100,0,0));
    t_base.draw(window);

    auto e_base = hwlib::line(hwlib::xy(6,3), hwlib::xy(6,8), hwlib::color(100,15,0));
    auto e_top = hwlib::line(hwlib::xy(6,3), hwlib::xy(10,3), hwlib::color(100,15,0));
    auto e_mid = hwlib::line(hwlib::xy(6,5), hwlib::xy(9,5), hwlib::color(100,15,0));
    for(unsigned int i=0; i<9; i++){
        auto t_top = hwlib::line(hwlib::xy(2-i,1), hwlib::xy(4+i,1), hwlib::color(100,0,0));
        t_top.draw(window);
        window.flush();
        if(i==6){ 
            e_base.draw(window);
        }else if(i==7){
            e_top.draw(window);
        }else if(i==8){
            e_mid.draw(window);
        }
    }
    auto e_bot = hwlib::line(hwlib::xy(6,7), hwlib::xy(10,7), hwlib::color(100,15,0));
    e_bot.draw(window);
    window.flush();
    auto t2_top = hwlib::line(hwlib::xy(0,7), hwlib::xy(5,7), hwlib::color(100,40,0));
    t2_top.draw(window);
    window.flush();
    for(unsigned int i=0; i<4; i++){ //t2_base
        window.write(hwlib::xy(2,8+i), hwlib::color(100,40,0));
        window.flush();
    }
    auto r_top = hwlib::line(hwlib::xy(5, 9), hwlib::xy(8,9), hwlib::color(0,100,0));
    r_top.draw(window);
    window.flush();
    auto r_right = hwlib::line(hwlib::xy(8, 10), hwlib::xy(8,12), hwlib::color(0,100,0));
    r_right.draw(window);
    auto r_left = hwlib::line(hwlib::xy(5, 10), hwlib::xy(5,16), hwlib::color(0,100,0));
    r_left.draw(window);
    window.flush();
    auto r_mid = hwlib::line(hwlib::xy(6, 12), hwlib::xy(8,12), hwlib::color(0,100,0));
    r_mid.draw(window);
    window.flush();
    auto r_bot = hwlib::line(hwlib::xy(6, 13), hwlib::xy(9,16), hwlib::color(0,100,0));
    r_bot.draw(window);
    window.flush();
    window.write(hwlib::xy(3,13), hwlib::color(0,0,100)); //i dot
    window.flush();
    for(unsigned int i=0; i<5; i++){ //i base
        window.write(hwlib::xy(3,15+i), hwlib::color(0,0,100));
        window.flush();
    }
    auto s_top = hwlib::line(hwlib::xy(7,17), hwlib::xy(10,17), hwlib::color(100,0,100));
    s_top.draw(window);
    window.flush();
    auto s_left = hwlib::line(hwlib::xy(6,18), hwlib::xy(6,20), hwlib::color(100,0,100));
    s_left.draw(window);
    window.flush();
    auto s_mid = hwlib::line(hwlib::xy(7,20), hwlib::xy(9,20), hwlib::color(100,0,100));
    s_mid.draw(window);
    window.flush();
    auto s_right = hwlib::line(hwlib::xy(9,21), hwlib::xy(9,23), hwlib::color(100,0,100));
    s_right.draw(window);
    window.flush();
    auto s_bot = hwlib::line(hwlib::xy(6,23), hwlib::xy(9,23), hwlib::color(100,0,100));
    s_bot.draw(window);
    window.flush();
    hwlib::wait_ms(1000);
    window.clear();
    window.flush();
}

void game_over_anim(hwlib::window & w){
    for(unsigned int k=0; k<5; k++){
        w.clear();
        w.flush();
        hwlib::wait_ms(50);
        fill_screen(w,20,0,0);
        w.flush();
        hwlib::wait_ms(50);
    }
    for(unsigned int i=0; i<3; i++){
        w.clear();
        write_m(w, hwlib::color(50,0,0), hwlib::xy(4,1), hwlib::xy(5,1), hwlib::xy(6,1), hwlib::xy(7,1), hwlib::xy(8,2), hwlib::xy(3,2), hwlib::xy(3,3), hwlib::xy(3,4), hwlib::xy(3,5), hwlib::xy(4,6), hwlib::xy(5,6), hwlib::xy(6,6), hwlib::xy(7,6), hwlib::xy(8,5), hwlib::xy(8,4), hwlib::xy(6,4), hwlib::xy(5,4));
        // ^G
        write_m(w, hwlib::color(50,0,0), hwlib::xy(5,8), hwlib::xy(6,8), hwlib::xy(4,9), hwlib::xy(4,10), hwlib::xy(3,11), hwlib::xy(3,12), hwlib::xy(7,9), hwlib::xy(7,10), hwlib::xy(8,11), hwlib::xy(8,12), hwlib::xy(4,10), hwlib::xy(5,10), hwlib::xy(6,10));
        // ^A
        write_m(w, hwlib::color(50,0,0), hwlib::xy(5,16), hwlib::xy(6,16), hwlib::xy(4,15), hwlib::xy(3,14), hwlib::xy(3,15), hwlib::xy(3,16), hwlib::xy(3,17), hwlib::xy(7,15), hwlib::xy(8,14), hwlib::xy(8,15), hwlib::xy(8,16), hwlib::xy(8,17));
        // ^M
        write_m(w, hwlib::color(50,0,0), hwlib::xy(8,19), hwlib::xy(7,19), hwlib::xy(6,19), hwlib::xy(5,19), hwlib::xy(4,19), hwlib::xy(3,19), hwlib::xy(3,20), hwlib::xy(3,21), hwlib::xy(4,21), hwlib::xy(5,21), hwlib::xy(6,21), hwlib::xy(3,22), hwlib::xy(3,23), hwlib::xy(4,23), hwlib::xy(5,23), hwlib::xy(6,23), hwlib::xy(7,23), hwlib::xy(8,23));
        // ^E
        w.flush();
        hwlib::wait_ms(750);
        w.clear();
        write_m(w, hwlib::color(0,0,50), hwlib::xy(4,0), hwlib::xy(5,0), hwlib::xy(6,0), hwlib::xy(7,0), hwlib::xy(3,1), hwlib::xy(3,2), hwlib::xy(3,3), hwlib::xy(3,4), hwlib::xy(4,5), hwlib::xy(5,5), hwlib::xy(6,5), hwlib::xy(7,5), hwlib::xy(8,4), hwlib::xy(8,3), hwlib::xy(8,2), hwlib::xy(8,1));
        // ^O
        write_m(w, hwlib::color(0,0,50), hwlib::xy(5,11), hwlib::xy(4,10), hwlib::xy(4,9), hwlib::xy(3,8), hwlib::xy(3,7), hwlib::xy(6,11), hwlib::xy(7,10), hwlib::xy(7,9), hwlib::xy(8,8), hwlib::xy(8,7));
        // ^V
        write_m(w, hwlib::color(0,0,50), hwlib::xy(8,13), hwlib::xy(7,13), hwlib::xy(6,13), hwlib::xy(5,13), hwlib::xy(4,13), hwlib::xy(3,13), hwlib::xy(3,14), hwlib::xy(3,15), hwlib::xy(4,15), hwlib::xy(5,15), hwlib::xy(6,15), hwlib::xy(3,16), hwlib::xy(3,17), hwlib::xy(4,17), hwlib::xy(5,17), hwlib::xy(6,17), hwlib::xy(7,17), hwlib::xy(8,17));
        // ^E
        write_m(w, hwlib::color(0,0,50), hwlib::xy(3,19), hwlib::xy(4,19), hwlib::xy(5,19), hwlib::xy(6,19), hwlib::xy(7,19), hwlib::xy(8,20), hwlib::xy(8,21), hwlib::xy(7,22), hwlib::xy(6,22), hwlib::xy(5,22), hwlib::xy(4,22), hwlib::xy(3,22), hwlib::xy(3,21), hwlib::xy(3,20), hwlib::xy(3,23), hwlib::xy(3,24), hwlib::xy(5,23), hwlib::xy(6,23), hwlib::xy(7,24), hwlib::xy(8,24));
        // ^R
        w.flush();
        hwlib::wait_ms(750);
    }
}

void draw_pointer(hwlib::window & window, const hwlib::color & pointerColour, const int & pointerPos){
    write_m(window, pointerColour, hwlib::xy(0+pointerPos,9), hwlib::xy(1+pointerPos,9), hwlib::xy(1+pointerPos,10), hwlib::xy(2+pointerPos,11), hwlib::xy(2+pointerPos,10), hwlib::xy(2+pointerPos,9), hwlib::xy(3+pointerPos,10), hwlib::xy(3+pointerPos,9), hwlib::xy(4+pointerPos,9), hwlib::xy(2+pointerPos,8), hwlib::xy(2+pointerPos,7), hwlib::xy(2+pointerPos,6), hwlib::xy(2+pointerPos,5), hwlib::xy(2+pointerPos,4), hwlib::xy(2+pointerPos,3));
}

void draw_level(hwlib::window & window, const int & level){
    write_m(window, hwlib::color(0,50,0), hwlib::xy(4,0), hwlib::xy(4,1), hwlib::xy(4,2), hwlib::xy(4,3), hwlib::xy(5,3));
    // ^left L
    write_m(window, hwlib::color(50,0,0), hwlib::xy(5,2), hwlib::xy(6,3), hwlib::xy(7,2));
    // ^v
    write_m(window, hwlib::color(0,50,0), hwlib::xy(7,0), hwlib::xy(7,1), hwlib::xy(7,3), hwlib::xy(8,3));
    // ^right L
    draw_number(window, hwlib::xy(9,0), level);
}

void draw_score(hwlib::window & window, const int & score){
    window.clear();
    hwlib::xy pos[12] = {hwlib::xy(9,19), hwlib::xy(5,19), hwlib::xy(1,19), hwlib::xy(9,13), hwlib::xy(5,13), hwlib::xy(1,13), hwlib::xy(9,7), hwlib::xy(5,7), hwlib::xy(1,7), hwlib::xy(9,1), hwlib::xy(5,1), hwlib::xy(1,1)};
    hwlib::color colours[10] = {hwlib::color(50,50,50), hwlib::color(0,75,0), hwlib::color(0,0,75), hwlib::color(75,0,0), hwlib::color(75,75,0), hwlib::color(0,75,25), hwlib::color(75,25,25), hwlib::color(75,15,0), hwlib::color(50,0,75), hwlib::color(20,0,0)};
    for(unsigned int i=0; i<12; i++){
        int digit = fmod(score/pow(10,i), 10);
        draw_number(window, pos[i], digit, colours[digit]);
    }
    window.flush();
    hwlib::wait_ms(15000);
}

void draw_number(hwlib::window & window, const hwlib::xy & s, const unsigned int & n, const hwlib::color & colour){
    if(n==0){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x, s.y+1), hwlib::xy(s.x, + s.y+2), hwlib::xy(s.x, s.y+3), hwlib::xy(s.x, s.y+4), hwlib::xy(s.x+2, s.y+1), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+2, s.y+3), hwlib::xy(s.x+2, s.y+4), hwlib::xy(s.x+1, s.y+4));
    }else if(n==1){
        write_m(window, colour, hwlib::xy(s.x,s.y+1), hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+1,s.y+1), hwlib::xy(s.x+1,s.y+2), hwlib::xy(s.x+1,s.y+3), hwlib::xy(s.x+1,s.y+4), hwlib::xy(s.x,s.y+4), hwlib::xy(s.x+2,s.y+4));
    }else if(n==2){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+1, s.y+2), hwlib::xy(s.x, s.y+2), hwlib::xy(s.x, s.y+3), hwlib::xy(s.x, s.y+4), hwlib::xy(s.x+1, s.y+4), hwlib::xy(s.x+2, s.y+4), hwlib::xy(s.x+1, s.y+4), hwlib::xy(s.x+2,s.y+1));
    }else if(n==3){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x, + s.y+2), hwlib::xy(s.x+1, + s.y+2), hwlib::xy(s.x, s.y+4), hwlib::xy(s.x+2, s.y+1), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+2, s.y+3), hwlib::xy(s.x+2, s.y+4), hwlib::xy(s.x+1, s.y+4));
    }else if(n==4){
        write_m(window, colour, s, hwlib::xy(s.x+2, s.y), hwlib::xy(s.x, s.y+1), hwlib::xy(s.x, + s.y+2), hwlib::xy(s.x+1, + s.y+2), hwlib::xy(s.x+2, s.y+1), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+2, s.y+3), hwlib::xy(s.x+2, s.y+4));
    }else if(n==5){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x, s.y+1), hwlib::xy(s.x+1, + s.y+2), hwlib::xy(s.x, + s.y+2), hwlib::xy(s.x, s.y+4), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+2, s.y+3), hwlib::xy(s.x+2, s.y+4), hwlib::xy(s.x+1, s.y+4));
    }else if(n==6){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x, s.y+1), hwlib::xy(s.x+1, + s.y+2), hwlib::xy(s.x, + s.y+2), hwlib::xy(s.x, s.y+3), hwlib::xy(s.x, s.y+4), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+2, s.y+3), hwlib::xy(s.x+2, s.y+4), hwlib::xy(s.x+1, s.y+4));
    }else if(n==7){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x+1, + s.y+2), hwlib::xy(s.x+1, s.y+3), hwlib::xy(s.x+2, s.y+1), hwlib::xy(s.x+1, s.y+4));
    }else if(n==8){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x, s.y+1), hwlib::xy(s.x+1, + s.y+2), hwlib::xy(s.x, + s.y+2), hwlib::xy(s.x, s.y+3), hwlib::xy(s.x, s.y+4), hwlib::xy(s.x+2, s.y+1), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+2, s.y+3), hwlib::xy(s.x+2, s.y+4), hwlib::xy(s.x+1, s.y+4));
    }else if(n==9){
        write_m(window, colour, s, hwlib::xy(s.x+1,s.y), hwlib::xy(s.x+2, s.y), hwlib::xy(s.x, s.y+1), hwlib::xy(s.x+1, + s.y+2), hwlib::xy(s.x, + s.y+2), hwlib::xy(s.x, s.y+4), hwlib::xy(s.x+2, s.y+1), hwlib::xy(s.x+2, s.y+2), hwlib::xy(s.x+2, s.y+3), hwlib::xy(s.x+2, s.y+4), hwlib::xy(s.x+1, s.y+4));
    }
}

void fill_screen(hwlib::window & w, const int & r, const int & g, const int & b){
    for(int i=0; i<w.size.x; i++){
        for(int j=0; j<w.size.y; j++){
            w.write(hwlib::xy(i,j), hwlib::color(r,g,b));
        }
    }
}

void write_m(hwlib::window & w, const hwlib::color & colour, const hwlib::xy & pos0, const hwlib::xy & pos1, const hwlib::xy & pos2,
    const hwlib::xy & pos3, const hwlib::xy & pos4, const hwlib::xy & pos5, const hwlib::xy & pos6,
    const hwlib::xy & pos7, const hwlib::xy & pos8, const hwlib::xy & pos9, const hwlib::xy & pos10,
    const hwlib::xy & pos11, const hwlib::xy & pos12, const hwlib::xy & pos13, const hwlib::xy & pos14,
    const hwlib::xy & pos15, const hwlib::xy & pos16, const hwlib::xy & pos17, const hwlib::xy & pos18,
    const hwlib::xy & pos19, const hwlib::xy & pos20, const hwlib::xy & pos21, const hwlib::xy & pos22,
    const hwlib::xy & pos23, const hwlib::xy & pos24){
        w.write(pos0, colour);
        w.write(pos1, colour);
        w.write(pos2, colour);
        w.write(pos3, colour);
        w.write(pos4, colour);
        w.write(pos5, colour);
        w.write(pos6, colour);
        w.write(pos7, colour);
        w.write(pos8, colour);
        w.write(pos9, colour);
        w.write(pos10, colour);
        w.write(pos11, colour);
        w.write(pos12, colour);
        w.write(pos13, colour);
        w.write(pos14, colour);
        w.write(pos15, colour);
        w.write(pos16, colour);
        w.write(pos17, colour);
        w.write(pos18, colour);
        w.write(pos19, colour);
        w.write(pos20, colour);
        w.write(pos21, colour);
        w.write(pos22, colour);
        w.write(pos23, colour);
        w.write(pos24, colour);
    }