#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // take average value of RGB and make it into integer
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // calculate average value and assign to the image
            int average = round((red + green + blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    sepia algorithm:
    sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    */

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
            // sanity check, make sure the bits value between 0 to 255
            if (sepiaRed > 255){
                sepiaRed = 255;
            }
            if (sepiaGreen > 255){
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255){
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i){
        for (int j = 0; j < (width/2); j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-(j+1)];
            image[i][width-(j+1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            float sum_red = 0;
            float sum_green = 0;
            float sum_blue = 0;
            int valid_count = 0;

            for (int k = -1; k < 2; k++){
                for (int l = -1; l < 2; l++){
                    if (i + k < 0 || i + k >= height){
                        continue;
                    }
                    if (j + l < 0 || j + l >= width){
                        continue;
                    }
                    sum_red += temp[i+k][j+l].rgbtRed;
                    sum_green += temp[i+k][j+l].rgbtGreen;
                    sum_blue += temp[i+k][j+l].rgbtBlue;
                    valid_count++;
                }
            }

            image[i][j].rgbtRed = round(sum_red / valid_count);
            image[i][j].rgbtGreen = round(sum_green / valid_count);
            image[i][j].rgbtBlue = round(sum_blue / valid_count);
        }
    }
    return;
}
