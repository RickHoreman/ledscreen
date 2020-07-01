#include "tetris.hpp"

int tetris::game::main(const int & seed){
    tetris_logo(window); //Clears screen, then plays animation and then clears again.
    pieceFalling = false;
    unsigned int timer=0;
    std::knuth_b generator(seed);
    std::uniform_int_distribution<int> distribution(0, 6);
    int pieceN = distribution(generator);
    score = 0;
    level = 0;
    nextPiece = newPiece(pieceN);
    for(;;){
        pieceN = distribution(generator);
        if(!pieceFalling){
            fallingPiece = spawn(nextPiece);
            nextPiece = newPiece(pieceN);
            pieceFalling = true;
        }

        player_input();
        if((timer % (12-level))==0){
            int updateResult = fallingPiece.update(window, 0, 1, 0);
            if(updateResult==1){
                score += check_score();
                score += check_score(); //Needs to happen twice in case two (sets of) line(s) are cleared with a gap in between.
                fallingPiece = tetris::piece('e', hwlib::xy(-5,-5), hwlib::color(0,0,0));
                pieceFalling = false;
            }else if(updateResult==2){
                fallingPiece = tetris::piece('e', hwlib::xy(-5,-5), hwlib::color(0,0,0));
                pieceFalling = false;
                game_over_anim(window);
                draw_score(window, score);
                return 1;
            }
        }
        
        fallingPiece.draw(window);
        draw_frame();
        nextPiece.draw(window);
        update_level();
        draw_level(window, level);
        window.flush();
        
        if(!close.read()){
            return 2;
        }
        if(timer > 1000){
            timer = 0;
        }
        timer++;   
    }
}

void tetris::game::player_input(){
    if(!pause.read()){
        hwlib::wait_ms(1000);
        while(pause.read()){
        }
        hwlib::wait_ms(1000);
    }
    if(!down.read()){
        if(fallingPiece.update(window, 0, 1, 0)==1){
            score += check_score();
            fallingPiece = tetris::piece('e', hwlib::xy(-5,-5), hwlib::color(0,0,0));
            pieceFalling = false;
        }
        hwlib::wait_ms(100);
    }else if(!left.read()){
        fallingPiece.update(window, -1, 0, 0);
        hwlib::wait_ms(100);
    }else if(!right.read()){
        fallingPiece.update(window, 1, 0, 0);
        hwlib::wait_ms(100);
    }
    if(!rLeft.read()){
        fallingPiece.update(window, 0, 0, -1);
        hwlib::wait_ms(100);
    }else if(!rRight.read()){
        fallingPiece.update(window, 0, 0, 1);
        hwlib::wait_ms(100);
    }
}

void tetris::game::draw_frame(){
    auto frameLeft = hwlib::line(hwlib::xy(0,4), hwlib::xy(0,25),hwlib::color(0,15,5));
    auto frameRight = hwlib::line(hwlib::xy(11,4), hwlib::xy(11,25),hwlib::color(0,15,5));
    auto frameTop = hwlib::line(hwlib::xy(0,4), hwlib::xy(11,4),hwlib::color(0,15,5));
    auto clearSpace0 = hwlib::line(hwlib::xy(0,0), hwlib::xy(12,0),hwlib::color(0,0,0));
    auto clearSpace1 = hwlib::line(hwlib::xy(0,1), hwlib::xy(12,1),hwlib::color(0,0,0));
    auto clearSpace2 = hwlib::line(hwlib::xy(0,2), hwlib::xy(12,2),hwlib::color(0,0,0));
    auto clearSpace3 = hwlib::line(hwlib::xy(0,3), hwlib::xy(12,3),hwlib::color(0,0,0));
    frameLeft.draw(window);
    frameRight.draw(window);
    frameTop.draw(window);
    clearSpace0.draw(window);
    clearSpace1.draw(window);
    clearSpace2.draw(window);
    clearSpace3.draw(window);
}

tetris::piece tetris::game::spawn(tetris::piece & piece){
    if(piece.type == 'i'){
        return tetris::piece('i', hwlib::xy(5,3), hwlib::color(50,0,0));
    }else if(piece.type == 'o'){
        return tetris::piece('o', hwlib::xy(5,4), hwlib::color(50,50,0));
    }else if(piece.type == 't'){
        return tetris::piece('t', hwlib::xy(5,4), hwlib::color(0,50,0));
    }else if(piece.type == 's'){
        return tetris::piece('s', hwlib::xy(5,4), hwlib::color(50,15,0));
    }else if(piece.type == 'z'){
        return tetris::piece('z', hwlib::xy(5,4), hwlib::color(0,0,50));
    }else if(piece.type == 'j'){
        return tetris::piece('j', hwlib::xy(6,3), hwlib::color(50,0,50));
    }else{
        return tetris::piece('l', hwlib::xy(5,3), hwlib::color(20,20,20));
    }
}

tetris::piece tetris::game::newPiece(const int & pieceN){
    if(pieceN==0){
        return tetris::piece('i', hwlib::xy(1,2), hwlib::color(50,0,0));
    }else if(pieceN==1){
        return tetris::piece('o', hwlib::xy(1,1), hwlib::color(50,50,0));
    }else if(pieceN==2){
        return tetris::piece('t', hwlib::xy(1,2), hwlib::color(0,50,0));
    }else if(pieceN==3){
        return tetris::piece('s', hwlib::xy(1,2), hwlib::color(50,15,0));
    }else if(pieceN==4){
        return tetris::piece('z', hwlib::xy(1,2), hwlib::color(0,0,50));
    }else if(pieceN==5){
        return tetris::piece('j', hwlib::xy(1,1), hwlib::color(50,0,50));
    }else{
        return tetris::piece('l', hwlib::xy(1,1), hwlib::color(20,20,20));
    }
}

int tetris::game::check_score(const int unsigned & line, const unsigned int & linesCleared){
    if(line > 20 || linesCleared==4){
        line_clear(window.size.y-line+linesCleared, linesCleared);
        return count_score(linesCleared);
    }
    int emptySpaces=0;
    for(unsigned int i=1; i<11; i++){
        if(!window.get(hwlib::xy(i, window.size.y-line))){
            emptySpaces++;
            if(linesCleared > 0){
                line_clear(window.size.y-line+linesCleared, linesCleared);
                return count_score(linesCleared);
            }
        }
    }
    if(emptySpaces==10){
        return count_score(linesCleared);
    }else if(emptySpaces>0){
        return check_score(line+1);
    }else{
        return check_score(line+1, linesCleared+1);
    }
}

int tetris::game::count_score(const unsigned int & linesCleared){
    if(linesCleared==0){
        return 0;
    }else if(linesCleared==1){
        return 40 * (level + 1);
    }else if(linesCleared==2){
        return 100 * (level + 1);
    }else if(linesCleared==3){
        return 300 * (level + 1);
    }else{
        return 1200 * (level + 1);
    }
}

void tetris::game::line_clear(const unsigned int & y, const unsigned int & lines){
    if(lines>0 && lines<4){
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(0,0,0));
            }
        }
        window.flush();
    }else if(lines==4){
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(0,0,0));
            }
        }
        window.flush();
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(50,0,0));
            }
        }
        window.flush();
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(0,0,0));
            }
        }
        window.flush();
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(0,50,0));
            }
        }
        window.flush();
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(0,0,0));
            }
        }
        window.flush();
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(0,0,50));
            }
        }
        window.flush();
        for(unsigned int i=y; i>y-lines; i--){
            for(unsigned int x=1; x<11; x++){
                window.write(hwlib::xy(x,i), hwlib::color(0,0,0));
            }
        }
        window.flush();
    }
    if(lines>0){
        for(unsigned int i=0; i<lines; i++){
            for(unsigned int j=y; j>4; j--){
                int emptySpaces=0;
                for(unsigned int x=1; x<11; x++){
                    if(window.get(hwlib::xy(x,j))==0){
                        emptySpaces++;
                    }
                }
                if(emptySpaces>10){
                    return;
                }else{
                    for(unsigned int x=1; x<11; x++){
                        if(j > 5){
                            window.write(hwlib::xy(x,j), hwlib::color(window.get(hwlib::xy(x,j-1))));
                        }else{
                            window.write(hwlib::xy(x,j), hwlib::color(0,0,0));
                        }
                    }
                }
            }
            window.flush();
        }
    }
}

int tetris::game::restart_menu(){
    int pointerPos=0;
    auto pointerColour=hwlib::color(0,0,0);
    int timer=1;
    window.clear();
    write_m(window, hwlib::color(0,0,50), hwlib::xy(0,13), hwlib::xy(1,13), hwlib::xy(2,13), hwlib::xy(3,13), hwlib::xy(4,14), hwlib::xy(4,15), hwlib::xy(4,16), hwlib::xy(3,17), hwlib::xy(2,17), hwlib::xy(1,17), hwlib::xy(0,17), hwlib::xy(0,16), hwlib::xy(0,15), hwlib::xy(0,14), hwlib::xy(0,18), hwlib::xy(0,19), hwlib::xy(0,20), hwlib::xy(0,21), hwlib::xy(1,18), hwlib::xy(2,19), hwlib::xy(3,20), hwlib::xy(4,21));
    // ^R
    write_m(window, hwlib::color(50,0,0), hwlib::xy(9,13), hwlib::xy(8,13), hwlib::xy(7,13), hwlib::xy(6,14), hwlib::xy(6,15), hwlib::xy(6,16), hwlib::xy(6,17), hwlib::xy(6,18), hwlib::xy(6,19), hwlib::xy(7,20), hwlib::xy(8,20), hwlib::xy(9,20), hwlib::xy(10,19), hwlib::xy(10,18), hwlib::xy(10,17), hwlib::xy(10,16), hwlib::xy(10,15), hwlib::xy(10,14), hwlib::xy(9,19), hwlib::xy(10,20), hwlib::xy(11,21));
    // ^Q
    for(;;){
        if(!left.read()){
            draw_pointer(window, hwlib::color(0,0,0), pointerPos);
            pointerPos = 0;
        }else if(!right.read()){
            draw_pointer(window, hwlib::color(0,0,0), pointerPos);
            pointerPos = 6;
        }
        if(timer==10){
            pointerColour = hwlib::color(20,20,20);
            // ^Pointer on
        }else if(timer>=20){
            pointerColour = hwlib::color(0,0,0);
            // ^Pointer off
            timer = 1;
        }
        draw_pointer(window, pointerColour, pointerPos);
        window.flush();
        timer++;

        if(!down.read()){
            draw_pointer(window, hwlib::color(0,50,0), pointerPos);
            window.flush();
            score=0;
            level=0;
            hwlib::wait_ms(1000);
            if(pointerPos==0){
                return 0;
            }else{
                return 2;
            }
        }
    }
}

void tetris::game::update_level(){
    if(level<9){
        int requiredScore=0;
        for(int i=0; i<=level+1; i++){ //Calculate total score required for next level. 1000 * level(to get to)^2 + previous. So getting to level 2 takes 2*1000 + 1*1000 + 0*1000 = 3000 total score.
            requiredScore += 1000 * i*i;
        }
        if(score > requiredScore){
            level++;
        }
    }else{
        level = 9;
    }
}