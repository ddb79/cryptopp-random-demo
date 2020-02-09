
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

#include "../cryptopp/osrng.h"
using namespace CryptoPP;
using CryptoPP::AutoSeededRandomPool;

std::string fmtBytesToHex( const byte* bytes, int size) {
    std::ostringstream os;
    for(size_t i = 0; i < size; ++i) {
        os << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << (int) bytes[i];
    }
    os << std::dec;
    return os.str();
}

void usage(char * pgm) {
    std::cout << std::endl << pgm << " <filename> <size>" << std::endl << std::endl;
}

void saveRand(const std::string fileName, const byte rand[], const int size) {
    std::ofstream oFile;
    if (! oFile.is_open()) {
        oFile.open(fileName, std::ios::out | std::ios::binary);
    }
    oFile.write((char *) rand, size);
    oFile.close();
}

int main(int argc, char** argv) {
    if (argc != 3) {
        usage(argv[0]);
        exit(0);
    }
    std::string fileName = std::string(argv[1]);
    size_t sz;
    int size = std::stoi(argv[2], &sz);
    std::cout << "random create - file: " << fileName << " - size: " << size << std::endl;

    byte rand[size];
    AutoSeededRandomPool prng;
    prng.GenerateBlock(rand, size);

    int fmtSize = size;
    if (size > 128) {
        fmtSize = 128;
    }
    // print the beginning of the hex number in hex
    std::cout << "rand head: " << fmtBytesToHex(rand, fmtSize) << std::endl;

    if (size > 128) {
        // print the ending of the hex number in hex
        std::cout << "rand tail: " << fmtBytesToHex(&rand[size-128], 128) << std::endl;
    }

    saveRand(fileName, rand, size);
    std::cout << "success rand data saved: " << size << std::endl;

    return 0;
}
