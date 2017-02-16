#include <iostream>
#include "png.h"
#include "rgbapixel.h"

using namespace std;

/*This is the main function that uses the flip function to take an input PNG file, and save it as an output file that is rotated 180 degrees*/

int main()
{
   PNG image("in.png");
   int width = image.width();
   int height = image.height();
   PNG temp(width, height);
   
   for(int x = 0; x < width; x++){
      for(int y = 0; y < height; y++){
         int tempRed = image(width - 1 - x, height - 1 - y)->red;
	 int tempGreen = image(width - 1 - x, height - 1 - y)->green;
         int tempBlue = image(width - 1 - x, height - 1 - y)->blue;
         
         (temp)(x,y)->red = tempRed;
         (temp)(x,y)->green = tempGreen;
	 (temp)(x,y)->blue = tempBlue;
      }
   } 

   temp.writeToFile("out.png");
   return 0;

};
