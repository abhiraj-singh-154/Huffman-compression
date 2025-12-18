#include "compress.h"
#include <fstream>
#include <map>
#include <string>

std::map<unsigned char, int> HuffmanCompressor::calculateFrequencies(const std::string& inputFile) {
    std::ifstream fin(inputFile, std::ios::binary);
    std::map<unsigned char, int> freq;
    unsigned char c;
    while (fin.read(reinterpret_cast<char*>(&c), 1)) {
        freq[c]++;
    }
    fin.close();
    return freq;
}

void HuffmanCompressor::compress(const std::string& inputFile, const std::string& outputFile) {
    auto freq = calculateFrequencies(inputFile);
    tree.buildTree(freq);
    auto codes = tree.getEncodingTable();

    std::ifstream fin(inputFile, std::ios::binary);
    std::ofstream fout(outputFile, std::ios::binary);

   
    int originalSize = 0;
    for (auto& p : freq) originalSize += p.second;
    fout.write((char*)&originalSize, sizeof(int));

    
    int mapSize = freq.size();
    fout.write((char*)&mapSize, sizeof(int));
    for (auto& p : freq) {
        fout.write((char*)&p.first, sizeof(unsigned char));
        fout.write((char*)&p.second, sizeof(int));
    }

    
    std::string bitString;
    unsigned char c;
    while (fin.read(reinterpret_cast<char*>(&c), 1)) {
        bitString += codes[c];
        while (bitString.size() >= 8) {
            unsigned char byte = 0;
            for (int i = 0; i < 8; i++)
                if (bitString[i] == '1') byte |= (1 << (7 - i));
            fout.put(byte);
            bitString.erase(0, 8);
        }
    }

    
    unsigned char lastBits = bitString.size();
    if (!bitString.empty()) {
        unsigned char byte = 0;
        for (size_t i = 0; i < bitString.size(); i++)
            if (bitString[i] == '1') byte |= (1 << (7 - i));
        fout.put(byte);
    }
    fout.put(lastBits);

    fin.close();
    fout.close();
}
