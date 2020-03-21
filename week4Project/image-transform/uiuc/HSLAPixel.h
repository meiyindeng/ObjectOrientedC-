/**
 * @file HSLAPixel.h
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#pragma once

#include <iostream>
#include <sstream>

using namespace std;

namespace uiuc {
  // Put your HSLAPixel class definition here.
  // (Remember to end it with a semicolon!)
  
  class HSLAPixel{
    public:
    //Hue color 0 - 360
      double h;
    
    //Saturation 0.0 - 1.0
      double s;
    
    //Luminance 0.0 - 1.0
      double l;
    
    //Alpha channel 0.0 - 1.0
      double a;
    
      HSLAPixel(double Hue, double Saturation, double Luminance);
      HSLAPixel(double Hue, double Saturation, double Luminance, double Alpha);
      HSLAPixel();
      HSLAPixel(const HSLAPixel& other);
      HSLAPixel& operator= (const HSLAPixel &other);
    
  };
  
}
