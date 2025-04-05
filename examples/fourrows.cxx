#include <iostream>
#include <exception>
#include <chrono>
#include <thread>
#include <string>
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

        // Initialize counters for each row
        int row1Value = 0;
        int row2Value = 0;
        int row3Value = 0;
        int row4Value = 0;

        while (true)
        {
            // Clear the display for the new values
            oled.clear();

            // Update the values
            row1Value += 1;
            row2Value += 2;
            row3Value += 3;
            row4Value += 4;

            // Convert values to strings
            std::string row1Text = "row1: " + std::to_string(row1Value);
            std::string row2Text = "row2: " + std::to_string(row2Value);
            std::string row3Text = "row3: " + std::to_string(row3Value);
            std::string row4Text = "row4: " + std::to_string(row4Value);

            // Display the updated values on the OLED
            drawString8x8(SSD1306::OledPoint{0, 0}, row1Text, SSD1306::PixelStyle::Set, oled); // Row 1
            drawString8x8(SSD1306::OledPoint{0, 8}, row2Text, SSD1306::PixelStyle::Set, oled); // Row 2
            drawString8x8(SSD1306::OledPoint{0, 16}, row3Text, SSD1306::PixelStyle::Set, oled); // Row 3
            drawString8x8(SSD1306::OledPoint{0, 24}, row4Text, SSD1306::PixelStyle::Set, oled); // Row 4

            // Update the display
            oled.displayUpdate();

            // Wait for 0.5 second before updating again
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}