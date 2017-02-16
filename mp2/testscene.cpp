/**********************************************************
 * testscene.cpp -- part of CS225 MP2
 *
 * This file performs some basic tests of the Scene class.
 * It is not intended to catch every possible error.You may
 * modifty this or write your own testscene.cpp to perform
 * additional tests.
 *
 *   Author: Jonathan Ray
 *   Date: 02 Feb 2007
 */

#include "image.h"
#include "scene.h"

int main()
{
  //  std::cout << "step 1..." << endl;
    Scene* set = new Scene(5);
    set->addpicture("in_01.png", 0, 0, 0);
    set->addpicture("in_02.png", 1, 60, 60);
    set->addpicture("in_03.png", 2, 150, 0);
    Image result = set->drawscene();
    result.writeToFile("scene.png");

    //set->changemaxlayers(10);

   std::cout << "step 2...change layer" << endl;
    set->changelayer(1, 3);
    result = set->drawscene();
    result.writeToFile("scene2.png");

  //  std::cout << "step 3...translate" << endl;
    set->translate(0, 50, 50);
    result = set->drawscene();
    result.writeToFile("scene3.png");

    //std::cout << "step 4..." << endl;
    set->getpicture(0)->adjustbrightness(-70, -70, -70);
    result = set->drawscene();
    result.writeToFile("scene4.png");

    //std::cout << "step 5..." << endl;
    set->deletepicture(3);
    result = set->drawscene();
    result.writeToFile("scene5.png");

    //std::cout << "step 6..." << endl;
    Scene* sc = new Scene(*set);
    //std::cout << "step 7...get picture" << endl;
    sc->getpicture(0)->flipleft();
    //std::cout << "step 7 complete" << endl;
    result = set->drawscene();
    result.writeToFile("scene6.png"); // scene 5 and scene 6 should be the same
    result = sc->drawscene();
    result.writeToFile("scene7.png");


    delete set;
    set = new Scene(5);
    //std::cout << "test 2" << endl;
    *set = *sc;
    result = set->drawscene();
    result.writeToFile("scene8.png");
   // scene7 and scene8 should be the same.
    delete set;
    delete sc;
    //std::cout << "test 3" << endl;



    return 0;
}
