#include "effects.hpp"

int effects_main(ledscreen::ledwindow_base & window, hwlib::pin_in & left, hwlib::pin_in & right, hwlib::pin_in & down, hwlib::pin_in & hotkey1, 
                hwlib::pin_in & hotkey2, hwlib::pin_in & hotkey3, hwlib::pin_in & hotkey4, hwlib::pin_in & close){
    window.clear();
    window.flush();
    int timer=0;
    hwlib::wait_ms(500);
    int menuOption=0;
    int numberOfOptions=3;
    auto coldShift = effects::cold_shift(window);
    auto gameOfLife = effects::game_of_life(window);
    auto colourLinesSlow = effects::colour_lines(window, hwlib::color(0,0,100), hwlib::color(0,100,0), hwlib::color(100,0,0), hwlib::color(75,75,75), true);
    auto colourLines = effects::colour_lines(window, hwlib::color(0,0,100), hwlib::color(0,100,0), hwlib::color(100,0,0), hwlib::color(75,75,75));
    for(;;){
        
        if(!left.read()){
            if(menuOption==0){
                menuOption = numberOfOptions;
            }else{
                menuOption--;
            }
            window.clear();
            hwlib::wait_ms(300);

        }else if(!right.read()){
            if(menuOption==numberOfOptions){
                menuOption = 0;
            }else{
                menuOption++;
            }
            window.clear();
            hwlib::wait_ms(300);

        }else if(!down.read()){
            menuOption = 0;
            window.clear();
            hwlib::wait_ms(300);
        }

        if(menuOption==0){
            coldShift.tick();
        }else if(menuOption==1){
            gameOfLife.tick(timer);
        }else if(menuOption==2){
            colourLinesSlow.tick(timer);
        }else if(menuOption==3){
            colourLines.tick(timer);
        }
        

        if(!close.read()){
            return timer;
        }
        if(timer > 1000000){
            timer = 0;
        }
        timer++;
    }
}

void effects::cold_shift::tick(){
    window.clear();
    for(int i=0; i<window.size.y; i++){
        for(int j=0; j<window.size.x; j++){
            int y = i + frame;
            if(y > 24){
                y -= 25;
            }
            window.write(hwlib::xy(j,y), hwlib::color(-0.520833333*pow(i-12, 2)+75, 15, 100));
        }
    }
    window.flush();
    frame++;
    if(frame>24){
        frame=0;
    }
}

void effects::game_of_life::tick(const int & seed){
    if(!frame){
        std::knuth_b generator(seed*1000);
        std::uniform_int_distribution<int> distribution(0, 299);

        for(unsigned int i=0; i<150; i++){
            int pos = distribution(generator);
            window.WS2812B::draw(pos, 75,75,75);
        }
    }
    bool life[12][25];
    for(unsigned int x=0; x<12; x++){
        for(unsigned int y=0; y<25; y++){
            int liveCount=0;
            if(window.get(hwlib::xy(x-1,y-1))){
                liveCount++;
            }
            if(window.get(hwlib::xy(x,y-1))){
                liveCount++;
            }
            if(window.get(hwlib::xy(x+1,y-1))){
                liveCount++;
            }
            if(window.get(hwlib::xy(x-1,y))){
                liveCount++;
            }
            if(window.get(hwlib::xy(x+1,y))){
                liveCount++;
            }
            if(window.get(hwlib::xy(x-1,y+1))){
                liveCount++;
            }
            if(window.get(hwlib::xy(x,y+1))){
                liveCount++;
            }
            if(window.get(hwlib::xy(x+1,y+1))){
                liveCount++;
            }
            if(liveCount==2 && window.get(hwlib::xy(x,y))){
                life[x][y] = true;
            }else if(liveCount==3){
                life[x][y] = true;
            }else{
                life[x][y] = false;
            }
        }
    }
    int totalLiveCount=0;
    for(unsigned int x=0; x<12; x++){
        for(unsigned int y=0; y<25; y++){
            if(life[x][y]==true){
                totalLiveCount++;
                window.write(hwlib::xy(x,y), hwlib::color(75,75,75));
            }else{
                window.write(hwlib::xy(x,y), hwlib::color(0,0,0));
            }
        }
    }
    frame++;
    if(frame>150 || totalLiveCount==0){
        frame=0;
    }
    window.flush();
    hwlib::wait_ms(100);
}

void effects::colour_lines::tick(const int & seed){
    if(slow){
        frame++;
        if(frame<300000){
            return;
        }else{
            frame=0;
        }
    }
    std::knuth_b generator(seed*1000);
    std::uniform_int_distribution<int> distribution_x(0, 11);
    std::uniform_int_distribution<int> distribution_y(0, 24);
    std::uniform_int_distribution<int> distribution_col(0, 3);
    int x0 = distribution_x(generator);
    int y0 = distribution_y(generator);
    int x1 = distribution_x(generator);
    int y1 = distribution_y(generator);
    int colN = distribution_col(generator);
    hwlib::color colour;
    if(colN==0){
        colour = col0;
    }else if(colN==1){
        colour = col1;
    }else if(colN==2){
        colour = col2;
    }else if(colN==3){
        colour = col3;
    }
    auto line = hwlib::line(hwlib::xy(x0,y0), hwlib::xy(x1,y1), colour);
    line.draw(window);
    window.flush();
}