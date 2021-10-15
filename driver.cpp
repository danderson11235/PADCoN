#include "pi_montecarlo.hpp"
#include <iostream>
#include <math.h>

int main(void) {
    PiMontecarlo pi;
    int PI = M_PI;
    float piRes = pi.exec(3);
    float err = abs(PI - piRes) / PI;
    std::cout << "The calculated value of pi was: " << piRes << 
        "\nwith a error of :" << err << std::endl;
    return 0;
}