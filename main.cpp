#include <iostream>
#include "compress.h"
#include "decompress.h"

int main() {
    HuffmanCompressor compressor;
    HuffmanDecompressor decompressor;

    int choice;
    std::string inputFile, outputFile;

    std::cout << "1. Compress\n";
    std::cout << "2. Decompress\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter input file name: ";
        std::cin >> inputFile;

        std::cout << "Enter compressed file name: ";
        std::cin >> outputFile;

        compressor.compress(inputFile, outputFile);
        std::cout << "Compression completed.\n";
    }
    else if (choice == 2) {
        std::cout << "Enter compressed file name: ";
        std::cin >> inputFile;

        std::cout << "Enter output file name: ";
        std::cin >> outputFile;

        decompressor.decompress(inputFile, outputFile);
        std::cout << "Decompression completed.\n";
    }
    else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
