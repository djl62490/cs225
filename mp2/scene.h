#ifndef SCENE_H
#define SCENE_H


#include "png.h"
#include "image.h"
#include <cstdint>
#include <iostream>

class Scene
{
public:
  int maxPics;
  int maxInt;
  Image ** pics;
  int * xcoords;
  int * ycoords;
  Scene(int max);
  //destructor
  ~Scene();
  Scene(const Scene & source);

  //helper functions
  Scene copy(const Scene & source);
  void clear();


  //member functions
  //assignment operator
  const Scene & operator=(const Scene & source);

  bool validIndex(int index) const;

  void changemaxlayers(int newmax);

  void addpicture(const char * FileName, int index, int x, int y);

  void changelayer(int index, int newindex);

  void translate(int index, int xcoord, int ycoord);

  void deletepicture (int index);

  Image * getpicture (int index) const;

  Image drawscene() const;

}
;
#endif
