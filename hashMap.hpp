//
// Created by Brynn Maleryn on 11/5/24.
//

#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include "hashNode.hpp"

class hashMap {
	friend class makeSeuss;
	string first; // for first keyword for printing to a file
	int numKeys;
	int mapSize;
	bool h1; // if true, first hash function used, otherwise second hash function is used
	bool c1; //if true, first collision method used, otherwise second collision method is used.
	int collisionct1;  //count of original collisions (caused by the hashing function used)
	int collisionct2; //count of secondary collisions (caused by the collision handling method used)
	hashNode **map;
	int primes[25];
public:
	hashMap(bool hash1, bool coll1);
	void addKeyValue(string k, string v);
	int getIndex(string k);
	int calcHash(string k);
	int calcHash2(string k);


	void getClosestPrime();
	void reHash();
	int collHash1(int h, int i, string key);
int collHash2(int h, int i, string k);
	int findKey(string k);
	void printMap();
};

#endif //HASHMAP_HPP_