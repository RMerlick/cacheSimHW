#include <iostream>
#include <fstream>
#include <string>

#include "cache_sim.h"
#include "cache.cpp"

using namespace std;

// code needs to be ran with this command after making, 
// ./cache_sim numEntries(int) associativity(int, mult 2) inputFileName

int main(int argc, char *argv[])
{
    //checking for the correct number of input parameters
    if(argc != 4){
        cout << "Invalid input amount, please review requirements.";
        return 0;
    }

    int numEntries = stoi(argv[1]);
    int associativity = stoi(argv[2]);

    ifstream fin;
    fin.open(argv[3]);
    
    //makes sure the file is properly read
    if(!fin){
        cout << "There was an error opening the file";
        return -1;
    }
    //makes sure the given enteries and associativity are correctly given
    if ((numEntries % 2 != 0) || (numEntries % associativity != 0))
    {
        cout << "Invalid input, please review input requirements.";
        return -2;
    }

    //creates the cache
    CacheSim cache(numEntries);
    
    //initializing the variables to make the table/perform the actions
    int addr;
    int curr = 1;
    bool hitOrMiss;

    ofstream fout;
    fout.open("cache_sim_output");

    //makes sure the file can be written to
    if(!fout){
        cout << "There was an error writing to the file, please check permissions";
        return -3;
    }

    fout << "IND ADDR : HIT/MISS\n"; 
    while (fin >> addr)
    {
        hitOrMiss = cache.access(addr);
        fout << curr << " | " << cache.binaryToDecimal(addr) << ": ";
        fout << (!hitOrMiss ? "MISS\n" : "HIT\n");
        curr++;
    }

    fin.close();
    fout.close();
    return 0;
}