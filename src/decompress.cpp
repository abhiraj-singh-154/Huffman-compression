#include "decompress.h"
#include <fstream>
#include <map>
#include <string>

void HuffmanDecompressor::decompress(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream fin(inputFile, std::ios::binary);
    std::ofstream fout(outputFile, std::ios::binary);

   
    int originalSize;
    fin.read((char*)&originalSize, sizeof(int));

    int mapSize;
    fin.read((char*)&mapSize, sizeof(int));
    std::map<unsigned char, int> freq;
    for (int i = 0; i < mapSize; i++) {
        unsigned char ch;
        int f;
        fin.read((char*)&ch, sizeof(unsigned char));
        fin.read((char*)&f, sizeof(int));
        freq[ch] = f;
    }

    tree.buildTree(freq);
    HuffmanNode* root = tree.getRootNode();
    HuffmanNode* current = root;

    
    std::vector<unsigned char> bytes(
        (std::istreambuf_iterator<char>(fin)),
        std::istreambuf_iterator<char>()
    );

    if (bytes.empty()) return;

    unsigned char lastBits = bytes.back(); 
    bytes.pop_back();

    int count = 0;
    for (size_t i = 0; i < bytes.size(); i++) {
        unsigned char byte = bytes[i];
        int bitsToRead = (i == bytes.size() - 1) ? lastBits : 8;

        for (int j = 7; j >= 8 - bitsToRead && count < originalSize; j--) {
            int bit = (byte >> j) & 1;
            current = (bit == 0) ? current->left : current->right;

            if (!current->left && !current->right) {
                fout.put(current->getValue());
                current = root;
                count++;
            }
        }
    }

    fin.close();
    fout.close();
}
