#include "png.h"
#include "image.h"
#include <cstdint>
#include <iostream>
#include "rgbapixel.h"

Image::Image(size_t width, size_t height)
  : PNG(width, height) {}

//*flips the image about a vertical line through its center by swapping pixels*//
void Image::flipleft()
{
    int width = this->width();
    int height = this->height();
    RGBAPixel leftTemp;
    for (int x = 0; x < width / 2; x++)
    {
        for (int y = 0; y < height; y++)
        {
            RGBAPixel * left  = (*this)(x,y);
            RGBAPixel * right = (*this)(width - 1 - x, y);
            leftTemp          = *(*this)(x,y);
            *left             = *right;
            *right            = leftTemp;
        }
    }
}

void Image::adjustbrightness(int r, int g, int b)
{
    int width = this->width();
    int height = this->height();

    for (int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            //overflow/underflow cases for red
            int tempRed = (int)(*this)(x,y) -> red;
            int tempGreen = (int)(*this)(x,y) -> green;
            int tempBlue = (int)(*this)(x,y) -> blue;

            if (tempRed + r > 255)
                (*this)(x,y) -> red = 255;
            else if (tempRed + r < 0)
                (*this)(x,y) -> red = 0;
            else
                (*this)(x,y) -> red += r;

            //overflow/underflow cases for green
            if (tempGreen + g > 255)
                (*this)(x,y) -> green = 255;
            else if (tempGreen + g < 0)
                (*this)(x,y) -> green = 0;
            else
                (*this)(x,y) -> green += g;

            //overflow/underflow cases for blue
            if (tempBlue + b < 0)
                (*this)(x,y) -> blue = 0;
            else if (tempBlue + b < 0)
                (*this)(x,y) -> blue = 0;
            else
                (*this)(x,y) -> blue += b;

        }
    }
}

void Image::invertcolors()
{
    int width = this->width();
    int height = this->height();

    for (int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            (*this)(x,y) -> red = 255 - (*this)(x,y)   -> red;
            (*this)(x,y) -> green = 255 - (*this)(x,y) -> green;
            (*this)(x,y) -> blue = 255 - (*this)(x,y)  -> blue;
        }
    }
}
