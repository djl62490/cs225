#include "png.h"
#include "image.h"
#include "scene.h"
#include <cstdint>
#include <iostream>

using namespace std;


Scene::Scene(int max)
{
  //dynamically allocate array of Image pointers of size max
  pics = new Image*[max];
  //Store max as a member variable
  maxPics = max;
  //Create storage for the coordinates
  xcoords = new int[maxPics];
  ycoords = new int[maxPics];
  //initialize all of them to NULL
  for (int i = 0; i < max; i++){
    pics[i] = NULL;
    xcoords[i] = 0;
    ycoords[i] = 0;
  }



}

Scene::~Scene()
{
  clear();
}

//uses copy helper function to create an independent copy of the source
Scene::Scene(const Scene & source)
{
  copy(source);
}

//Copy helper function
Scene Scene::copy(const Scene & source)
{
  //copies member variables
  maxPics = source.maxPics;

  //creates a new image array and copies each individual image from the source
  Scene out(maxPics);
  pics = new Image*[maxPics];
  xcoords = new int[maxPics];
  ycoords = new int[maxPics];
  for (int i = 0; i < maxPics; i++)
  {
    pics[i] = NULL;
    xcoords[i] = 0;
    ycoords[i] = 0;
    if (source.pics[i] != NULL)
    {
      pics[i] = new Image();
      *pics[i] = *source.pics[i];
      xcoords[i] = source.xcoords[i];
      ycoords[i] = source.ycoords[i];
    }

  }
  return out;
}

//Clear helper function
void Scene::clear()
{
  for (int i = 0; i < maxPics; i++)
  {
    delete pics[i];
  }
  delete []  pics;
  delete [] xcoords;
  delete [] ycoords;
  pics = NULL;
}

//ASSIGNMENT OPERATOR
const Scene & Scene::operator=(const Scene & source)
{
  //check for self assignment
  if (&source == this)
  {
    return * this;
  }
  else
  {
    //deletes everything this Scene has allocated
    this->clear();
    //makes this Scene an independent copy of the source
    this->copy(source);
    //returns a reference to the current instance
    return *this;
  }
}

//valid index helper function
bool Scene::validIndex(int index) const
{
  if (index < 0 || index > maxPics)
  {
    return false;
  }
  else if (pics[index] == NULL)
  {
    return false;
  }
  else return true;
}

void Scene::changemaxlayers(int newmax)
{
  //first check if any images will be lost during the copy. If so, do not copy.
  int temp = 0;
  for (int i = 0; i < maxPics; i++)
  {
    if(pics[i] != NULL)
    {
      temp = i;
    }
  }
  if (temp > newmax - 1)
  {
    cout << "invalid newmax" << endl;
    return;
  }

  Image ** tempArray = new Image*[newmax];
  int * newx = new int[newmax];
  int * newy = new int[newmax];
  for (int i = 0 ; i < newmax; i++)
  {
    tempArray[i] = NULL;
    newx[i] = 0;
    newy[i] = 0;
  }

  for (int i = 0 ; i < temp; i++)
  {
    if (pics[i] != NULL)
    {
      tempArray[i] = new Image();
      *tempArray[i] = *pics[i];
      newx[i] = xcoords[i];
      newy[i] = ycoords[i];
    }
  }

  clear();
  maxPics = newmax;
  pics = tempArray;
  xcoords = newx;
  ycoords = newy;

}

void Scene::addpicture(const char * FileName, int index, int x, int y)
{
  if (index > maxPics - 1)
  {
    cout << "index out of bounds" << endl;
    return;
  }

  if (pics[index] != NULL)
  {
    delete pics[index];
    pics[index] = NULL;
  }
  //cout << pics[index] << endl;
  pics[index] = new Image();
  pics[index] -> readFromFile(FileName);
  xcoords[index] = x;
  ycoords[index] = y;

}

void Scene::changelayer(int index, int newindex)
{
  //If the new index is the same as the old index, do nothing and return.
  if (index == newindex) return;
  /* If either index is invalid, do nothing and use the following
  code to print an error message:*/
  if ((index < 0 || index > maxPics) || (newindex < 0 || newindex > maxPics))
  {
    cout << "invalid index" <<endl;
    return;
  }
  //If the destination is already occupied, delete the image there.
  if (pics[newindex] != NULL)
  {
    delete pics[newindex];
  }
  //change image location within the array
  pics[newindex] = pics[index];
  pics[index] = NULL;
  xcoords[newindex] = xcoords[index];
  ycoords[newindex] = ycoords[index];
  return;
}

void Scene::translate(int index, int xcoord, int ycoord)
{
  if (validIndex(index) != true)
  {
    cout << "invalid index" << endl;
    return;
  }

  xcoords[index] = xcoord;
  ycoords[index] = ycoord;
  return;
}

void Scene::deletepicture (int index)
{
  if (validIndex(index) != true)
  {
    cout << "invalid index" << endl;
    return;
  }
  else
  {
    delete pics[index];
    pics[index] = NULL;
    xcoords[index] = 0;
    ycoords[index] = 0;
    return;
  }
}

Image * Scene::getpicture ( int index ) const
{
  if (validIndex(index) != true)
  {
    cout << "invalid index" << endl;
    return NULL;
  }
  return pics[index];
}

Image Scene::drawscene() const
{
  size_t height = 0;
  size_t width = 0;

  //find dimensions necessary for final output png
  for (int i = 0; i < maxPics; i++)
  {
    if (pics[i] != NULL){
      size_t currentWidth = pics[i]->width() + xcoords[i];
      size_t currentHeight = pics[i]->height() + ycoords[i];
    //  cout << "width pic" << pics[i]->width() << endl;
    //  cout << "width coord" << xcoords[i] << endl;
      if (currentWidth > width) { width = currentWidth;}
      if (currentHeight > height) {height = currentHeight;}
    }
  }
  //create final image
  Image output(width, height);
  //std::cout << "t1" << endl;

  //iterate through each pixel and copy
  for (int i = 0 ; i <  maxPics ; i ++)
  {
    //cout << "x: " << xcoords[i] << endl;
    //cout << "y: " << xcoords[i] << endl;
    if(pics[i] != NULL)
    {
      //cout << pics[i] -> width() << endl;
      for (size_t x = 0 ; x < pics[i]->width() ; x++)
      {
        //cout << pics[i] -> height() << endl;
        for (size_t y = 0 ; y < pics[i]->height() ; y++)
        {
          //use access operator from PNG class to access each pixel
          //the operator returns a pointer to a pixel, so you need to dereference
          //cout << "printing pixel" << endl;
          *output(xcoords[i] + x, ycoords[i] + y) = *(*pics[i])(x, y);

        }
      }
    }
  }
  //std::cout << "t1" << endl;
  return output;
}
