#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for ( int i = 0; i < height; i++){
        for ( int j = 0; j < width; j++){
            int red;int green; int blue;
            char *red; char *green; char *blue;

             red = strtol(image[i][j].rgbtRed,&red,16);
             green = strtol(image[i][j].rgbtGreen,&green,16);
             blue = strtol(image[i][j].rgbtBlue,,16);



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
