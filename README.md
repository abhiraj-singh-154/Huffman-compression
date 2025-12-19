# Huffman Compression (C++)
## Project Overview
Huffman Compression is a C++ implementation of the Huffman Coding algorithm — a classic lossless data compression technique. The program reads a file, builds a Huffman tree based on character frequencies, compresses the file into a binary format, and can also decompress it back to the original file.
## Theory
Huffman coding starts by counting how often each symbol appears in the data. Each symbol is treated as a leaf node with its frequency. The two symbols with the lowest frequencies are repeatedly combined to form a new node whose frequency is the sum of both. This process continues until a single binary tree is formed. Binary codes are then assigned by traversing the tree, typically using 0 for a left edge and 1 for a right edge. The generated codes ensure that no symbol’s code is a prefix of another, allowing correct and lossless decoding.

