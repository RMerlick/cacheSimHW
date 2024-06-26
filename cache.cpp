#include "cache_sim.h"
#include <iostream>
#include <vector>
using namespace std;

class CacheSim
{
private:
    vector<Entry> cache;
    int numEntries;
public:
    CacheSim(int entries)
    {
        numEntries = entries;
        cache = vector<Entry>(numEntries);
    }

    //simulates memory to find whether the address would be a hit or a miss
    bool access(int address)
    {
        address = binaryToDecimal(address);

        int index = address % numEntries;
        int tag = address / numEntries;

        if (!(cache[index].validBit) || (cache[index].tag != tag))
        {
            cache[index].tag = tag;
            cache[index].validBit = true;
            return false;
        }

        return true;
    }

    int binaryToDecimal(int addr)
    {
        int binary = addr;
        int decimal = 0;
        int base = 1;
    
        int temp = binary;
        while (temp) {
            int lastDigit = temp % 10;
            temp = temp / 10;
    
            decimal += lastDigit * base;
    
            base = base * 2;
        }
    
        return decimal;
    }
};