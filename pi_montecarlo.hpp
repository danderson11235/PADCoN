#pragma onece
#include <vector>

class PiMontecarlo {
public:
    PiMontecarlo();
    // ~PiMontecarlo();

    float exec(int threadCount);
    // void operator()(int count, float *res);
private:

    void calculatePi(int count, float& res);
};