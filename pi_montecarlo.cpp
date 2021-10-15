#include "pi_montecarlo.hpp"
#include <thread>
#include <cmath>
#include <stdlib.h>
#include <time.h>


PiMontecarlo::PiMontecarlo() {
    srand(time(NULL));
}

int PiMontecarlo::exec(int threadCount) {
    float pi = M_PI;
    float* res = new float[threadCount];
    std::vector<std::thread> th;
    for (int i = 0; i < threadCount; i++) {
        th.emplace_back(calculatePi, 10, res[i]);
    }
    for (auto& t:th) {
        t.join();
    }
    return 0;
}

void PiMontecarlo::calculatePi(int count, float* res) {
    int numInCircle = 0;
    for (int i = 0; i < count; i ++) {
        float a = ((float)rand()) / (float) RAND_MAX;
        float b = ((float)rand()) / (float) RAND_MAX;
        if (sqrt((a*a) + (b*b)) < 1) numInCircle++;
    }
    *res = (float)(4 * count / numInCircle);
}