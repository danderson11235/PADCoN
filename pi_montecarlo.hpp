#pragma onece
#include <vector>

class PiMontecarlo {
public:
    PiMontecarlo();
    ~PiMontecarlo();

    int exec(int threadCount);
private:
    void calculatePi(int count);
};