#ifndef IDW_H
#define IDW_H

#include <vector>

struct BlockData {
    int blockId;
    double east;
    double north;
    double elev;
    double dx;
    double dy;
    double dz;
    double cu;
};

struct BlastHoleData {
    int Id;
    double east;
    double north;
    double elev;
    double cu;
};

// Calculate the inverse distance weighting
double calculateIDW(const std::vector<BlastHoleData>& blastHoles, const BlockData& block, double power);

// Predict the cu value for each block
std::vector<BlockData> predictCu(const std::vector<BlockData>& blocks, const std::vector<BlastHoleData>& blastHoles, double power, double scale);

// Print the block data
void printBlockData(const std::vector<BlockData>& blocks);

#endif  // IDW_H