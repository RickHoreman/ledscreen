#ifndef EFFECTS_HPP
#define EFFECTS_HPP
#include "ledscreen.hpp"
#include "effects.hpp"
#include <cmath>
#include <random>

int effects_main(ledscreen::ledwindow_base & window, hwlib::pin_in & left, hwlib::pin_in & right, hwlib::pin_in & down, hwlib::pin_in & hotkey1, 
                hwlib::pin_in & hotkey2, hwlib::pin_in & hotkey3, hwlib::pin_in & hotkey4, hwlib::pin_in & close);

namespace effects{
    class effect {
    protected:
        ledscreen::ledwindow_base & window;
        int frame;
    public:
        effect(ledscreen::ledwindow_base & window):
        window(window),
        frame(0)
        {}
        virtual void tick()=0;
    };

    class effect_seeded  {
        protected:
        ledscreen::ledwindow_base & window;
        int frame;
    public:
        effect_seeded(ledscreen::ledwindow_base & window):
        window(window),
        frame(0)
        {}
        virtual void tick(const int & seed)=0;
    };

    class cold_shift : public effect {
    public:
        cold_shift(ledscreen::ledwindow_base & window):
        effect(window)
        {}
        void tick()override;
    };

    class game_of_life : public effect_seeded {
    private:
    public:
        game_of_life(ledscreen::ledwindow_base & window):
        effect_seeded(window)
        {}
        void tick(const int & seed)override;
    };

    class colour_lines : public effect_seeded {
    private:
        hwlib::color col0, col1, col2, col3;
        bool slow;
    public:
        colour_lines(ledscreen::ledwindow_base & window, const hwlib::color & col0, const hwlib::color & col1, const hwlib::color & col2, const hwlib::color & col3, const bool & slow=false):
        effect_seeded(window),
        col0(col0),
        col1(col1),
        col2(col2),
        col3(col3),
        slow(slow)
        {}
        void tick(const int & seed)override;
    };
};

#endif