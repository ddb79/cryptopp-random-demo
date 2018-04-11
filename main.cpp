
#include <iostream>
#include <sstream>
#include <iomanip>

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

int main() {
    std::cout << "== random demo ==" << std::endl;

    const int size = 5*1024*1024;
    byte rand[size];

    AutoSeededRandomPool prng;
    prng.GenerateBlock(rand, size);

    int fmtSize = size;
    if (size > 128) {
        fmtSize = 128;
    }
    std::cout << "rand1: " << fmtBytesToHex(rand, fmtSize) << std::endl;

    if (size > 128) {
        std::cout << "rand2: " << fmtBytesToHex(&rand[size-128], 128) << std::endl;
    }

    return 0;
}