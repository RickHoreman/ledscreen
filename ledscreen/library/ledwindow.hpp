
//          Copyright Rick Horeman 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#ifndef LEDWINDOW_HPP
#define LEDWINDOW_HPP

#include "ledstrip.hpp"

/// @file

namespace ledscreen {
    /// \brief
    /// Base hwlib::window based window for the WS2812B.
    /// \details
    /// Adds base functionality of hwlib::window to the WS2812B so it can easily be used as a screen. This version only supports length x 1 as dimensions. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_base : public hwlib::window, public ledscreen::WS2812B {
    private:
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(pos.x, colour.rgb());
        }
        virtual int xy_conversion(hwlib::xy pos)=0;
    public:
        /// \brief
        /// Constructor for base ledwindow class.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_base(const hwlib::xy & size, hwlib::pin_out & pin):
        window(size),
        WS2812B(pin, size.x*size.y)
        {}
	/// \brief
	/// Flushes internal draw buffer to ledstrip.
	/// \details
	/// Simply calls WS2812B::flush() to actually show what you drew on the ledstrip.
        void flush()override{
            WS2812B::flush();
        }
	/// \brief
	/// Getter function to get colour values from internal draw buffer using hwlib::xy coords.
	/// \details
	/// Allows you to get the colour value of a specific pixel. Useful for applications that want to use the colour data, so that they dont need to keep a copy themselves. Returns zero if coords out of bounds.
        int get(const hwlib::xy & pos){
            if(pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y){
                return 0x0;
            }
            return WS2812B::get(xy_conversion(pos));
        }
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a horizontally-layed-out WS2812B matrix with the 0th pixel in the top left. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_horizontal_top_left : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.y % 2){ //if pos.y is uneven
                newPos = (pos.y * size.x) + (size.x - pos.x -1);
            }else{
                newPos = (pos.y * size.x) + pos.x;
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for horizontal ledwindow class with the 0th/first pixel in the top left.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_horizontal_top_left(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a horizontally-layed-out WS2812B matrix with the 0th pixel in the top right. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_horizontal_top_right : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.y % 2){ //if pos.y is uneven
                newPos = (pos.y * size.x + pos.x);
            }else{
                newPos = (pos.y * size.x) + (size.x - pos.x - 1);
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for horizontal ledwindow class with the 0th/first pixel in the top right.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_horizontal_top_right(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a horizontally-layed-out WS2812B matrix with the 0th pixel in the bottom left. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_horizontal_bottom_left : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.y % 2){ //if pos.y is uneven
                newPos = ((size.y - pos.y -1) * size.x) + pos.x;
            }else{
                newPos = ((size.y - pos.y -1) * size.x) + (size.x - pos.x -1);
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for horizontal ledwindow class with the 0th/first pixel in the bottom left.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_horizontal_bottom_left(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a horizontally-layed-out WS2812B matrix with the 0th pixel in the bottom right. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_horizontal_bottom_right : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.y % 2){ //if pos.y is uneven
                newPos = ((size.y-pos.y-1) * size.x + (size.x - pos.x - 1));
            }else{
                newPos = ((size.y-pos.y-1) * size.x) + pos.x;
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for horizontal ledwindow class with the 0th/first pixel in the bottom right.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_horizontal_bottom_right(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a vertically-layed-out WS2812B matrix with the 0th pixel in the top left. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_vertical_top_left : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.x % 2){ //if pos.x is uneven
                newPos = (pos.x * size.y + (size.y - pos.y - 1));
            }else{
                newPos = (pos.x * size.y) + pos.y;
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for vertical ledwindow class with the 0th/first pixel in the top left.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_vertical_top_left(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a vertically-layed-out WS2812B matrix with the 0th pixel in the top right. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_vertical_top_right : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.x % 2){ //if pos.x is uneven
                newPos = ((size.x - pos.x -1) * size.y + pos.y);
            }else{
                newPos = ((size.x - pos.x -1) * size.y) + (size.y - pos.y - 1);
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for vertical ledwindow class with the 0th/first pixel in the top right.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_vertical_top_right(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a vertically-layed-out WS2812B matrix with the 0th pixel in the bottom left. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_vertical_bottom_left : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.x % 2){ //if pos.x is uneven
                newPos = (pos.x * size.y + pos.y);
            }else{
                newPos = (pos.x * size.y) + (size.y - pos.y - 1);
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for vertical ledwindow class with the 0th/first pixel in the bottom left.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_vertical_bottom_left(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    /// \brief
    /// Layout expansion on ledscreen::window_base.
    /// \details
    /// Adds support for a vertically-layed-out WS2812B matrix with the 0th pixel in the bottom right. Supports any dimensions with no more than 2048 total leds. See hwlib::window documentation for information on how to use various write functions.
    class ledwindow_vertical_bottom_right : public ledscreen::ledwindow_base {
    private:
        int xy_conversion(hwlib::xy pos)override{
            int newPos;
            if(pos.x % 2){ //if pos.x is uneven
                newPos = ((size.x-pos.x-1) * size.y + (size.y - pos.y - 1));
            }else{
                newPos = ((size.x-pos.x-1) * size.y) + pos.y;
            }
            return newPos;
        }
        void write_implementation(hwlib::xy pos, hwlib::color colour)override{
            
            WS2812B::draw(xy_conversion(pos), colour.rgb());
        }
    public:
        /// \brief
        /// Constructor for vertical ledwindow class with the 0th/first pixel in the bottom right.
        /// \details
        /// Requires size as xy coordinates (for a 12x25 window x=12 and y=25) and correct hwlib-style gpio pin that the ledstrip is connected.
        ledwindow_vertical_bottom_right(const hwlib::xy & size, hwlib::pin_out & pin):
        ledwindow_base(size, pin)
        {}
    };

    
};
#endif