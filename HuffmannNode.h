#pragma once

class HuffmanNode {
    unsigned char value;
    int weight;

public:
    HuffmanNode* left;
    HuffmanNode* right;
    
    HuffmanNode(int f)
    : value('\0'), weight(f), left(nullptr), right(nullptr) {}
    HuffmanNode(unsigned char v, int w)
        : value(v), weight(w), left(nullptr), right(nullptr) {}

    unsigned char getValue() const { return value; }
    int getWeight() const { return weight; }
};
