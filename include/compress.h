#pragma once
#include <string>
#include "HuffmannTree.h"
#include <map>
class HuffmanCompressor {
private:
    HuffmanTree tree;

    std::map<unsigned char, int> calculateFrequencies(const std::string& inputFile);

public:
    HuffmanCompressor() = default;
    ~HuffmanCompressor() = default;

    void compress(const std::string& inputFile, const std::string& outputFile);
};
