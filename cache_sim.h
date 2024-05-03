#ifndef CACHE_SIM_H
#define CACHE_SIM_H

class Entry
{
public:
    bool validBit;
    int tag;

    Entry()
    {
        validBit = false;
        tag = 0;
    }
};
#endif