#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height; i++){
        for ( int j = 0; j < width; j++){
            // int red;int green; int blue; int average;
            // char *redc; char *greenc; char *bluec;
            // red = strtol(image[i][j].rgbtRed, &redc ,16);
            // green = strtol(image[i][j].rgbtGreen, &greenc ,16);
            // blue = strtol(image[i][j].rgbtBlue, &bluec ,16);
            // average = (red + blue + green)/3;
            int average;
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            average = round((red + green + blue)/3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newPixels[height][width];

    //this loop puts the reflected values into a new array newPixels of type RGBTRIPLE
    for( int i = 0; i < height; i++ ){
        for ( int j = 0; j < width; j++ ){

            newPixels[i][j].rgbtRed = image[i][width - j- 1].rgbtRed;
            newPixels[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            newPixels[i][j].rgbtBlue = image[i][width - j- 1].rgbtBlue;

        }
    }

    //this loop copies the new reflected values into the actual image;
    for( int i = 0; i < height; i++ ){
        for ( int j = 0; j < width; j++ ){

            image[i][j].rgbtRed = newPixels[i][j].rgbtRed;
            image[i][j].rgbtGreen = newPixels[i][j].rgbtGreen;
            image[i][j].rgbtBlue = newPixels[i][j].rgbtBlue;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //There is a maximum of 6 entries to average;
    //But there are times where not all the 6 entries exist(edge cases)
    //In these cases just make entry 0 but do not increment the total number
    //of entries, because it affects the average

    for ( int i = 0; i < height; i++){
        for ( int j = 0; j < width; j++){
            RGBTRIPLE neighbors[9]; //declared in this scope because
                                    //neighbor for each pixel is different
            // int count = 0;
            int red;
            int green;
            int blue;

            //for pixels that are not edge cases
            if (i > 0 && i < width - 1){
                red += image[i-1][j-1];
                
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
