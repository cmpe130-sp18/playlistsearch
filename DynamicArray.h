#ifndef DYNAMICARRAY
#define DYNAMICARRAY
#include "Song.h"
#include <iostream>
#include <string>

using namespace std;

class DynamicArray
{
	public:
		DynamicArray();
		DynamicArray(int maxSongs);
		Song* push_back(string title, string artist, string durationString, int playListTime, int maxSongs);
		size_t size();
		int getCapacity();
		Song& operator[](int index);
		~DynamicArray();
	private:
		int numSongs, capacity, Log;
		Song* songs; 
};
#endif // !DYNAMICARRAY
#pragma once
