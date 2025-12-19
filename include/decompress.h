#pragma once
#include <string>
#include "HuffmannTree.h"

class HuffmanDecompressor {
private:
    HuffmanTree tree;

public:
    HuffmanDecompressor() = default;
    ~HuffmanDecompressor() = default;

    void decompress(const std::string& inputFile, const std::string& outputFile);
};
