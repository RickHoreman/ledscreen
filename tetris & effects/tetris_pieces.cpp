#include "tetris_pieces.hpp"

void tetris::piece::draw(ledscreen::ledwindow_base & window){
    window.write(hitbox.pos0, colour);
    window.write(hitbox.pos1, colour);
    window.write(hitbox.pos2, colour);
    window.write(hitbox.pos3, colour);
}

void tetris::piece::clear(ledscreen::ledwindow_base & window){
    window.write(hitbox.pos0, hwlib::color(0,0,0));
    window.write(hitbox.pos1, hwlib::color(0,0,0));
    window.write(hitbox.pos2, hwlib::color(0,0,0));
    window.write(hitbox.pos3, hwlib::color(0,0,0));
}

int tetris::piece::update(ledscreen::ledwindow_base & window, const int & x, const int & y, const int & r){
    int result=0; //Will remain 0 if nothing special needs to happen upon return.
    if(x!=0 || y!=0){
        if((window.get(hwlib::xy(hitbox.pos0.x+x, hitbox.pos0.y+y))==0 || hwlib::xy(hitbox.pos0.x+x, hitbox.pos0.y+y)==hitbox.pos1 || hwlib::xy(hitbox.pos0.x+x, hitbox.pos0.y+y)==hitbox.pos2 || hwlib::xy(hitbox.pos0.x+x, hitbox.pos0.y+y)==hitbox.pos3 || hitbox.pos0.y+y<5)
        && (window.get(hwlib::xy(hitbox.pos1.x+x, hitbox.pos1.y+y))==0 || hwlib::xy(hitbox.pos1.x+x, hitbox.pos1.y+y)==hitbox.pos0 || hwlib::xy(hitbox.pos1.x+x, hitbox.pos1.y+y)==hitbox.pos2 || hwlib::xy(hitbox.pos1.x+x, hitbox.pos1.y+y)==hitbox.pos3 || hitbox.pos1.y+y<5)
        && (window.get(hwlib::xy(hitbox.pos2.x+x, hitbox.pos2.y+y))==0 || hwlib::xy(hitbox.pos2.x+x, hitbox.pos2.y+y)==hitbox.pos0 || hwlib::xy(hitbox.pos2.x+x, hitbox.pos2.y+y)==hitbox.pos1 || hwlib::xy(hitbox.pos2.x+x, hitbox.pos2.y+y)==hitbox.pos3 || hitbox.pos2.y+y<5)
        && (window.get(hwlib::xy(hitbox.pos3.x+x, hitbox.pos3.y+y))==0 || hwlib::xy(hitbox.pos3.x+x, hitbox.pos3.y+y)==hitbox.pos0 || hwlib::xy(hitbox.pos3.x+x, hitbox.pos3.y+y)==hitbox.pos1 || hwlib::xy(hitbox.pos3.x+x, hitbox.pos3.y+y)==hitbox.pos2 || hitbox.pos3.y+y<5)
        && (!(hitbox.pos0.y+y>=window.size.y) && !(hitbox.pos1.y+y>=window.size.y) && !(hitbox.pos2.y+y>=window.size.y) && !(hitbox.pos3.y+y>=window.size.y))
        && (hitbox.pos0.x+x!=11 && hitbox.pos0.x+x!=0 && hitbox.pos1.x+x!=11 && hitbox.pos1.x+x!=0 && hitbox.pos2.x+x!=11 && hitbox.pos2.x+x!=0 && hitbox.pos3.x+x!=11 && hitbox.pos3.x+x!=0)){
            //Only move if every new hitbox position is free or occupied by own hitbox. Or if piece is still above the playing field (ignore the top of the game's frame). Also dont move if at the bottom of the screen.
            move(window, x,y);
        }else if(x==0 && y!=0){
            draw(window); //Draw piece in final position.
            if(hitbox.pos0.y < 5 || hitbox.pos1.y < 5 || hitbox.pos2.y < 5 || hitbox.pos3.y < 5){
                result = 2; //Piece landed on something and is (partly) outside the top of the playing field. This means game over. Tell main loop to set fallingPiece to an empty piece and set pieceFalling to false and initialize game over animations.
            }else{
                result = 1; //Piece landed on something, tell main loop to set fallingPiece to an empty piece and set pieceFalling to false.
            }
        }
    }else if(r!=0){
        positions newHitbox = rotate(r);
        if((window.get(newHitbox.pos0)==0 || newHitbox.pos0==hitbox.pos0 || newHitbox.pos0==hitbox.pos1 || newHitbox.pos0==hitbox.pos2 || newHitbox.pos0==hitbox.pos3 || newHitbox.pos0.y<5)
        && (window.get(newHitbox.pos1)==0 || newHitbox.pos1==hitbox.pos1 || newHitbox.pos1==hitbox.pos0 || newHitbox.pos1==hitbox.pos2 || newHitbox.pos1==hitbox.pos3 || newHitbox.pos1.y<5)
        && (window.get(newHitbox.pos2)==0 || newHitbox.pos2==hitbox.pos2 || newHitbox.pos2==hitbox.pos0 || newHitbox.pos2==hitbox.pos1 || newHitbox.pos2==hitbox.pos3 || newHitbox.pos2.y<5)
        && (window.get(newHitbox.pos3)==0 || newHitbox.pos3==hitbox.pos3 || newHitbox.pos3==hitbox.pos0 || newHitbox.pos3==hitbox.pos1 || newHitbox.pos3==hitbox.pos2 || newHitbox.pos3.y<5)
        && (!(newHitbox.pos0.y>=window.size.y) && !(newHitbox.pos1.y>=window.size.y) && !(newHitbox.pos2.y>=window.size.y) && !(newHitbox.pos3.y>=window.size.y))){
            //Only rotate if newHitbox positions are free, occupied by own hitbox or above the playing field (ignore top part of the game's frame). Dont rotate if newHitbox goes under the playing field.
            clear(window);//Get rid of old version before rotating
            hitbox = newHitbox;
        }
    }
    return result;
}

void tetris::piece::move(ledscreen::ledwindow_base & window, const int & x, const int & y){
    clear(window);
    start.x += x;
    start.y += y;
    hitbox.pos0.x += x;
    hitbox.pos0.y += y;
    hitbox.pos1.x += x;
    hitbox.pos1.y += y;
    hitbox.pos2.x += x;
    hitbox.pos2.y += y;
    hitbox.pos3.x += x;
    hitbox.pos3.y += y;
}

positions tetris::piece::rotate(const int & r){
    positions newHitbox;
    if(type=='i'){
        if(rotation==0){
            newHitbox.pos0 = hwlib::xy(start.x-1,start.y);
            newHitbox.pos1 = start;
            newHitbox.pos2 = hwlib::xy(start.x+1,start.y);
            newHitbox.pos3 = hwlib::xy(start.x+2,start.y);
            rotation = 1;
        }else if(rotation==1){
            newHitbox.pos0 = hwlib::xy(start.x, start.y-2);
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = start;
            newHitbox.pos3 = hwlib::xy(start.x, start.y+1);
            rotation = 0;
        }
    }else if(type=='o'){
        newHitbox = hitbox;
    }else if(type=='t'){
        if((rotation==1 && r==-1) || (rotation==-1 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x-1, start.y);
            newHitbox.pos3 = hwlib::xy(start.x+1, start.y);
            rotation = 0;
        }else if((rotation==2 && r==-1) || (rotation==0 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x, start.y+1);
            newHitbox.pos3 = hwlib::xy(start.x+1, start.y);
            rotation = 1;
        }else if((rotation==-1 && r==-1) || (rotation==1 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x-1, start.y);
            newHitbox.pos2 = hwlib::xy(start.x, start.y+1);
            newHitbox.pos3 = hwlib::xy(start.x+1, start.y);
            rotation = 2;
        }else if((rotation==0 && r==-1) || (rotation==2 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x-1, start.y);
            newHitbox.pos2 = hwlib::xy(start.x, start.y+1);
            newHitbox.pos3 = hwlib::xy(start.x, start.y-1);
            rotation = -1;
        }
    }else if(type=='s'){
        if(rotation==1){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x+1, start.y-1);
            newHitbox.pos3 = hwlib::xy(start.x-1, start.y);
            rotation = 0;
        }else if(rotation==0){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x+1, start.y);
            newHitbox.pos3 = hwlib::xy(start.x+1, start.y+1);
            rotation = 1;
        }
    }
    else if(type=='z'){
        if(rotation==1){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x-1, start.y-1);
            newHitbox.pos3 = hwlib::xy(start.x+1, start.y);
            rotation = 0;
        }else if(rotation==0){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x+1, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x+1, start.y);
            newHitbox.pos3 = hwlib::xy(start.x, start.y+1);
            rotation = 1;
        }
    }else if(type=='j'){
        if((rotation==1 && r==-1) || (rotation==-1 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x, start.y+1);
            newHitbox.pos3 = hwlib::xy(start.x-1, start.y+1);
            rotation = 0;
        }else if((rotation==2 && r==-1) || (rotation==0 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x+1, start.y);
            newHitbox.pos2 = hwlib::xy(start.x-1, start.y);
            newHitbox.pos3 = hwlib::xy(start.x-1, start.y-1);
            rotation = 1;
        }else if((rotation==-1 && r==-1) || (rotation==1 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x+1, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos3 = hwlib::xy(start.x, start.y+1);
            rotation = 2;
        }else if((rotation==0 && r==-1) || (rotation==2 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x+1, start.y+1);
            newHitbox.pos2 = hwlib::xy(start.x+1, start.y);
            newHitbox.pos3 = hwlib::xy(start.x-1, start.y);
            rotation = -1;
        }
    }else if(type=='l'){
        if((rotation==1 && r==-1) || (rotation==-1 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x, start.y+1);
            newHitbox.pos3 = hwlib::xy(start.x+1, start.y+1);
            rotation = 0;
        }else if((rotation==2 && r==-1) || (rotation==0 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x+1, start.y);
            newHitbox.pos2 = hwlib::xy(start.x-1, start.y);
            newHitbox.pos3 = hwlib::xy(start.x-1, start.y+1);
            rotation = 1;
        }else if((rotation==-1 && r==-1) || (rotation==1 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x, start.y-1);
            newHitbox.pos2 = hwlib::xy(start.x, start.y+1);
            newHitbox.pos3 = hwlib::xy(start.x-1, start.y-1);
            rotation = 2;
        }else if((rotation==0 && r==-1) || (rotation==2 && r==1)){
            newHitbox.pos0 = start;
            newHitbox.pos1 = hwlib::xy(start.x+1, start.y);
            newHitbox.pos2 = hwlib::xy(start.x-1, start.y);
            newHitbox.pos3 = hwlib::xy(start.x+1, start.y-1);
            rotation = -1;
        }
    }
    return newHitbox;
}