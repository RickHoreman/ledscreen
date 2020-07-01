Content folders:
ledscreen - the ledscreen library files. Library for using the WS2812B as window/screen, or just as addressable ledstrip.
tetris & effects - example project using the ledscreen library. 						Name may or may not be inspired by the latest installment.
hwlib - hardware library, used for the very low level usage of the arduino gpio pins among other things. Also used as basis for the window classes in ledscreen.
bmptk - required for building c++ for the arduino due, among other things.

IMPORTANT: ONLY THE LEDSCREEN AND TETRIS&EFFECTS FOLDERS CONTAIN CODE MADE BY ME, Rick Horeman, I DO NOT CLAIM TO OWN ANY OF THE CONTENTS IN THE OTHER FOLDERS, THEY ARE MERELY REQUIRED FOR THE OTHER TWO.

Ledscreen library demos can be found under ledscreen/library/demos. See README in that location.

ledscreen/library/html contains doxygen documentation for the library's main files. Make sure to check out hwlib's documentation as well for information on the usage of the window class among other things.

The ledscreen library is provided with a boost 1.0 license.

To experience the tetris & effects example project exactly 300 WS2812B leds are required. A lot of information on how to wire these up can be found online, adafruit is a particularly good source.
Some simple tips:
	- Make sure your circuit can deliver enough power. Taking account for about a third of the total max power draw will be fine most of the time, you will rarely, if ever, have to light the entire thing up with full brightness white.
	- Use a logic level converter to convert the microcontroller's 3,3V data output to the required 5V.
	- A roughly 500ohm resistor as close to the data in on the ledstrip can help get rid of noise.
	- Although I've heared mixed opinions, a significantly sized capacitor in parallel with the ledstrip's power circuitry is supposed to protect them from sudden surges, especially when first plugged in.

I've tried my best to squish all bugs, but if you find any, let me know at github.com/RickHoreman/ledscreen.