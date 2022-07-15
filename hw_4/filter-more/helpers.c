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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    Sobel edge detection algorithm
    A convolutional filter:
    Gx: left to right
    -1|0|1
    -2|0|2
    -1|0|1

    Gy: top to bottom
    -1|-2|-1
     0| 0| 0
     1| 2| 1
    
    treat pixel beyond border as 0
    calculate Gx and Gy for all channels
    and square root (Gx**2 +Gy**2)
    */

    int Gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            float Gx_sum_red = 0;
            float Gx_sum_green = 0;
            float Gx_sum_blue = 0;
            float Gy_sum_red = 0;
            float Gy_sum_green = 0;
            float Gy_sum_blue = 0;
            int position = 0;

            for (int k = -1; k < 2; k++){
                for (int l = -1; l < 2; l++){
                    if (i + k < 0 || i + k >= height){
                        position++;
                        continue;
                    }
                    if (j + l < 0 || j + l >= width){
                        position++;
                        continue;
                    }
                    Gx_sum_red += Gx[position] * temp[i+k][j+l].rgbtRed;
                    Gy_sum_red += Gy[position] * temp[i+k][j+l].rgbtRed;
                    Gx_sum_green += Gx[position] * temp[i+k][j+l].rgbtGreen;
                    Gy_sum_green += Gy[position] * temp[i+k][j+l].rgbtGreen;
                    Gx_sum_blue += Gx[position] * temp[i+k][j+l].rgbtBlue;
                    Gy_sum_blue += Gy[position] * temp[i+k][j+l].rgbtBlue;
                    position++;
                }
            }
            int red = round(sqrt(pow((double)Gx_sum_red, 2) + pow((double)Gy_sum_red, 2)));
            int green = round(sqrt(pow((double)Gx_sum_green, 2) + pow((double)Gy_sum_green, 2)));
            int blue = round(sqrt(pow((double)Gx_sum_blue, 2) + pow((double)Gy_sum_blue, 2)));
            if (red > 255){
                red = 255;
            }
            if (green > 255){
                green = 255;
            }
            if (blue > 255){
                blue = 255;
            }
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
