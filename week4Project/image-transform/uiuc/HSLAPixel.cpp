/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#include <cmath>
#include <iostream>
#include "HSLAPixel.h"
using namespace std;


namespace uiuc {
    HSLAPixel::HSLAPixel(double Hue, double Saturation, double Luminance){
        h = Hue;
        s = Saturation;
        l = Luminance;
        a = 1.0;
    }
    
    HSLAPixel::HSLAPixel(){
        l = 1.0;
        a = 1.0;
    }
    
    HSLAPixel::HSLAPixel(double Hue, double Saturation, double Luminance, double Alpha){
        h = Hue;
        s = Saturation;
        l = Luminance;
        a = Alpha;
    }

    HSLAPixel::HSLAPixel(const HSLAPixel& other){
        h = other.h;
        s = other.s;
        l = other.l;
        a = other.a;
    }

    HSLAPixel& HSLAPixel:: operator= (const HSLAPixel &other){
        h = other.h;
        s = other.s;
        l = other.l;
        a = other.a;
        return *this;
    }
}

