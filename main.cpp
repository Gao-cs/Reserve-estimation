#include <iostream>
#include "IDW.h"
using namespace std;

int main() {
    // Sample data
    vector<BlockData> blocks = {
        {1, 10.0, 20.0, 5.0, 2.0, 3.0, 1.0, 0.0},
        {2, 15.0, 25.0, 6.0, 2.0, 3.0, 1.0, 0.0},
        {3, 12.0, 18.0, 4.0, 2.0, 3.0, 1.0, 0.0}
    };

    vector<BlastHoleData> blastHoles = {
        {1, 8.0, 19.0, 7.0, 1.5},
        {2, 16.0, 24.0, 5.0, 2.0}
    };

    // Parameters
    //power 幂指数
    //scale 判断是否对输出的矿石结构进行细分。
    double power = 2.0;
    double scale = 1.0;

    // Predict cu values
    vector<BlockData> predictedBlocks = predictCu(blocks, blastHoles, power, scale);

    // Print predicted block data
    printBlockData(predictedBlocks);

    return 0;
}