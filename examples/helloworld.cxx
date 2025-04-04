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

        // Display "Hello, World!" centered on the screen
        const std::string message = "Hello, World!";
        int textWidth = message.size() * 8; // Each character is 8 pixels wide
        int x = (oled.width() - textWidth) / 2; // Center horizontally
        int y = (oled.height() - 16) / 2; // Center vertically (16 pixels high font)

        drawString8x8(SSD1306::OledPoint{x, y}, message, SSD1306::PixelStyle::Set, oled);

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
