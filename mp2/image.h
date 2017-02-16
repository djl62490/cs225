#ifndef MYIMAGE_H
#define MYIMAGE_H

#include "png.h"

//image class definition, a subclass of PNG
class Image : public PNG
{
    public:
        Image() = default;
        Image(size_t width, size_t height);
        void flipleft();
        void adjustbrightness(int r, int g, int b);
        void invertcolors();
        size_t _width;
        size_t _height;

};

#endif
