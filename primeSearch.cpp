#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>
using namespace std;


int main() {
    const int range = 1000000;

    bool nums[range];
    fill_n(nums,range, 1);
    //vector<bool> nums;
    //nums.assign(range, 1);

    int primes = -2;

    int runs = 0;

    // consts
    int halfRange = (int)range/2;

    uint64_t start = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    while (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() - start < 5000000) {
        for(int a=2; a<=halfRange; a++) {
            for(int b=2; b<=a; b++) {
                if (a*b>=range) {
                    break;
                }
                nums[a*b] = 0;
            }
        }
        runs++;
    }
    for (int i=0; i<range; i++) {
        primes += nums[i];
    }
    

    cout << primes << "   " << runs << '\n';
}
