#include "pi_montecarlo.hpp"
#include <thread>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>


PiMontecarlo::PiMontecarlo() {
    srand(time(NULL));
}

float PiMontecarlo::exec(int threadCount=3) {
    float pi = M_PI;
    // float* res = new float[threadCount]{0};
    float res[3] = {0};
    std::vector<std::thread> th;
    // for (int i = 0; i < threadCount; i++) {
    //     float temp = 0;
    //     std::thread t(&PiMontecarlo::calculatePi, this, 1000, &temp);
    //     res[i] = temp;
    //     th.push_back(t);
    // }
    // for (auto& t:th) {
    //     t.join();
    // }
    std::thread t1(&PiMontecarlo::calculatePi, this, 100, std::ref(res[0]));
    float resAvg = 0;
    for (int i = 0; i < threadCount; i++) {
        resAvg += res[i];
    }
    resAvg = resAvg / threadCount;
    return resAvg;
}

void PiMontecarlo::calculatePi(int count, float& res){
    int numInCircle = 0;
    for (int i = 0; i < count; i ++) {
        float a = ((float)rand()) / (float) RAND_MAX;
        float b = ((float)rand()) / (float) RAND_MAX;
        if (sqrt((a*a) + (b*b)) < 1) numInCircle++;
    }
    res = (float)(4 * count / numInCircle);
}

// void PiMontecarlo::operator()(int count, float *res) {
//     int numInCircle = 0;
//     for (int i = 0; i < count; i ++) {
//         float a = ((float)rand()) / (float) RAND_MAX;
//         float b = ((float)rand()) / (float) RAND_MAX;
//         if (sqrt((a*a) + (b*b)) < 1) numInCircle++;
//     }
//     *res = (float)(4 * count / numInCircle);
// }