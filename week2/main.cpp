/**
 * C++ program invoking Cube's assignment operator.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>

class Pair{
public:
    int* pa, *pb;

    Pair(int a, int b){
        pa = new int;
        *pa = a;
        pb = new int;
        *pb = b;
    }

    Pair(const Pair& other){
        pa = new int;
        *pa = *other.pa;
        pb = new int;
        *pb = *other.pb;
    }
    ~Pair(){
        delete pa;
        delete pb;
        pa = NULL;
        pb = NULL;
    }
};

int main() {



    return 0;
}
