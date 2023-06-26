#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    RGBTRIPLE pixel;
    for ( int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if(pixel.rgbtBlue == 0x00 && pixel.rgbtGreen == 0 && pixel.rgbtRed == 0){
                pixel.rgbtBlue = 0xff;
            }
        }
    }
}
