#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height; i++){
        for ( int j = 0; j < width; j++){
            int red;int green; int blue; int average;
            char *redc; char *greenc; char *bluec;

            red = strtol(image[i][j].rgbtRed, &redc ,16);
            green = strtol(image[i][j].rgbtGreen, &greenc ,16);
            blue = strtol(image[i][j].rgbtBlue, &bluec ,16);

            average = (red + blue + green)/3;
            

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
