#pragma once

#include <map>
#include <queue>
#include <string>
#include "HuffmannNode.h"

class HuffmanTree {
    private:
    HuffmanNode* rootNode;
    std::map<unsigned char, std::string> encodingTable;
    void generateCodes(HuffmanNode* node, const std::string& prefix){
        if(!node) return;
        if(!node->left && !node->right){
            encodingTable[node->getValue()] = prefix;
        }
        generateCodes(node->left, prefix + "0");
        generateCodes(node->right, prefix + "1");
    }

     void destroyTree(HuffmanNode* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    HuffmanTree() : rootNode(nullptr) {}
    ~HuffmanTree() { destroyTree(rootNode); }
    void buildTree(const std::map<unsigned char, int>& frequencies){
auto cmp = [](HuffmanNode* a, HuffmanNode* b) { return a->getWeight() > b->getWeight(); };
std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, decltype(cmp)> minHeap(cmp);

for (auto& pair : frequencies) {
    minHeap.push(new HuffmanNode(pair.first, pair.second));
}

while (minHeap.size() > 1) {
    HuffmanNode* left = minHeap.top(); minHeap.pop();
    HuffmanNode* right = minHeap.top(); minHeap.pop();
    HuffmanNode* parent = new HuffmanNode(left->getWeight() + right->getWeight());
    parent->left = left;
    parent->right = right;
    minHeap.push(parent);
}
 rootNode = minHeap.empty() ? nullptr : minHeap.top();
  encodingTable.clear();
   generateCodes(rootNode, "");
    }


std::map<unsigned char, std::string> getEncodingTable() const { return encodingTable; }
 HuffmanNode* getRootNode() const { return rootNode; }
 void clearTree() { destroyTree(rootNode); rootNode = nullptr; encodingTable.clear(); }
};
    

