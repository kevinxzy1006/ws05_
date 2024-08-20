#include "Orchestra.h"
#include <iostream>

// constructors
Orchestra::Orchestra() : max_Size(0), current_Size(0), musician(nullptr) {}
Orchestra::Orchestra(int size) : max_Size(size), current_Size(0)
{
    if (size > 0)
    {
        musician = new Musician[max_Size];
    }
    else
    {
        musician = nullptr;
    }
}

// Destructor
Orchestra::~Orchestra()
{
    delete[] musician;
}

// returns the number of musicians who have joined the orchestra
int Orchestra::get_current_number_of_members()
{
    return current_Size;
}

// returns true if any musician in the orchestra plays the specified instrument
// otherwise returns false
bool Orchestra::has_instrument(std::string instrument)
{
    for (int i = 0; i < current_Size; i++)
    {
        if (musician[i].get_instrument() == instrument)
        {
            return true;
        }
    }
    return false;
}

// Returns the array of members
Musician *Orchestra::get_members()
{
    return musician;
}

// Adds a new musician to the orchestra if there is space
bool Orchestra::add_musician(Musician &new_musician)
{
    if (current_Size < max_Size)
    {
        musician[current_Size++] = new_musician;
        return true;
    }
    return false;
}