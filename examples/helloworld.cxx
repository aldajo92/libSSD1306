#include <iostream>
#include <exception>
#include <chrono>
#include <thread>
#include "OledFont8x8.h"
#include "OledI2C.h"

int main()
{
    try
    {
        // Initialize the OLED display
        SSD1306::OledI2C oled{"/dev/i2c-1", 0x3C};

        // Clear the display
        oled.clear();

        // Display four rows of text
        drawString8x8(SSD1306::OledPoint{0, 0}, "row1", SSD1306::PixelStyle::Set, oled); // Row 1
        drawString8x8(SSD1306::OledPoint{0, 8}, "row2", SSD1306::PixelStyle::Set, oled); // Row 2
        drawString8x8(SSD1306::OledPoint{0, 16}, "row3", SSD1306::PixelStyle::Set, oled); // Row 3
        drawString8x8(SSD1306::OledPoint{0, 24}, "row4", SSD1306::PixelStyle::Set, oled); // Row 4

        // Update the display
        oled.displayUpdate();

        // Keep the message displayed for 5 seconds
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // Clear the display before exiting
        oled.clear();
        oled.displayUpdate();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}