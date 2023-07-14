#include "IDW.h"
#include <cmath>
#include <iostream>


double calculateIDW(const std::vector<BlastHoleData>& blastHoles, const BlockData& block, double power) {
    double weightedSum = 0.0;
    double weightSum = 0.0;

    for (const BlastHoleData& blastHole : blastHoles) {
        double distance = std::sqrt(std::pow(blastHole.east - block.east, 2) + std::pow(blastHole.north - block.north, 2) + std::pow(blastHole.elev - block.elev, 2));
        double weight = std::pow(1.0 / distance, power);
        weightedSum += weight * blastHole.cu;
        weightSum += weight;
    }

    return weightedSum / weightSum;
}

std::vector<BlockData> predictCu(const std::vector<BlockData>& blocks, const std::vector<BlastHoleData>& blastHoles, double power, double scale) {
    std::vector<BlockData> predictedBlocks;

    for (const BlockData& block : blocks) {
        BlockData predictedBlock = block;
        if (scale != 1.0) {
            predictedBlock.dx *= scale;
            predictedBlock.dy *= scale;
            predictedBlock.dz *= scale;
        }
        predictedBlock.cu = calculateIDW(blastHoles, predictedBlock, power);
        predictedBlocks.push_back(predictedBlock);
    }

    return predictedBlocks;
}

void printBlockData(const std::vector<BlockData>& blocks) {
    for (const BlockData& block : blocks) {
        std::cout << "Block ID: " << block.blockId << std::endl;
        std::cout << "East: " << block.east << std::endl;
        std::cout << "North: " << block.north << std::endl;
        std::cout << "Elevation: " << block.elev << std::endl;
        std::cout << "Cu: " << block.cu << std::endl;
        std::cout << std::endl;
    }
}