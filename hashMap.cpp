//
// Created by Brynn Maleryn on 11/5/24.
//
#include "hashMap.hpp"
#include "hashNode.hpp"
#include <iostream>

using namespace std;


hashMap::hashMap(bool hash1, bool coll1) {
   numKeys = 0;
   collisionct1 = 0;
   collisionct2 = 0;
   h1 = hash1;
   c1 = coll1;
   mapSize = 100;
   map = new hashNode *[mapSize];
   for(int i = 0; i < mapSize; i++) {
      map[i] = NULL;
   }
}
void hashMap::addKeyValue(string k, string v) {
   int index = getIndex(k);
   hashNode *nodeAtIndex = map[index];
   if(nodeAtIndex == NULL) {
      map[index] = new hashNode(k);
      map[index]->addValue(v);
   }else {
      if(nodeAtIndex->keyword == k) {
         map[index]->addValue(v);
      }
   }
   numKeys++;
   if(((float)numKeys/(float)mapSize) > 0.7) {
      reHash();
   }
   // //printMap();
   // float a = (float)numKeys/mapSize;
   // if (a >=0.7) {
   //    reHash();
   // }
   // int index = getIndex(k);
   // if(map[index] != NULL && map[index]->keyword == k) {
   //   map[index]->addValue(v);
   // }else {
   //    map[index] = new hashNode(k, v);
   //    numKeys++;
   // }
}

int hashMap::getIndex(string k) {
   int index = 0;
   if(h1) {
      index = calcHash(k);
   }else {
      index = calcHash2(k);
   }
   hashNode *nodeAtIndex = map[index];
   int ct = 0;
   while(true) {
      if(nodeAtIndex == NULL || nodeAtIndex->keyword == k) {
         return index;
      }
      if(ct == 0) {
         collisionct1++;
      }
      if(c1) {
         index = collHash1(index, ct, k); //NATE
      }else {
         index = collHash2(index, ct, k); //NATE
      }
      nodeAtIndex = map[index];
      collisionct2++;
      ct++;
   }
   // int hash= 0;
   // if(h1) {
   //       hash = calcHash(k);
   // }else {
   //    hash = calcHash2(k);
   // }
   // while(true) {
   //    if(map[hash] == NULL || map[hash]->keyword == k) {
   //       return hash;
   //    }
   //    if(c1) {
   //       hash = collHash1(hash, k);
   //    }else {
   //       hash = collHash2(to_string(hash));
   //    }
   // }
   // if(map[hash] != NULL) {
   //    if(c1) {
   //       hash = collHash1(hash, k);
   //    }else {
   //       hash = collHash2(to_string(hash));
   //    }
   // }
   // return hash;
}


int hashMap::calcHash(string k) {
   //add ascii
   int total = 0;
   for(int i = 0; i < k.length(); i++) {
      total += int(k[i]);
   }
   total = total%mapSize;
   return total;
}


int hashMap::calcHash2(string k) {
   int total = 0;
   for(int i = 0; i < k.length(); i++) {
      total += int(k[i]) * int(k[i]);
   }
   total = total % mapSize;
   return total;
   // int total = 0;
   // for(int i = 0; i < k.length(); i++) {
   //    total +=  int(k[i]) * pow(27,i);
   // }
   // return total%mapSize;
}

bool isPrime(int n) {
   if(n == 1) {
      return false;
   }
   for(int i = 2; i<n; i++) {
      if(n % i == 0) {
         return false;
      }
   }
   return true;
}

void hashMap::getClosestPrime() {
   mapSize *= 2;
   while(true) {
      mapSize++;
      if(isPrime(mapSize)) {
         break;
      }
   }
   // binary search and prime array
   // int target = mapSize*2;
   // int left = 0;
   // int right = 24;
   // while(left<=right) {
   //    int mid = left+(right-left)/2;
   //    if(primes[mid] < target && primes[mid + 1] > target) {
   //       mapSize = primes[mid+1];
   //    }else if(primes[mid] < target) {
   //       left = mid + 1;
   //    }else if(primes[mid] > target) {
   //       right = mid - 1;
   //    }
   // }
}

void hashMap::reHash() {
   int oldSize = mapSize;
   hashNode **oldMap = map;
   getClosestPrime();
   map = new hashNode *[mapSize];
   for(int i = 0; i < mapSize; i++) {
      map[i] = NULL;
   }
   numKeys = 0;
   for(int i = 0; i < oldSize; i++) {
      if(oldMap[i] != NULL) {
         for(int j = 0; j < oldMap[i]->currSize; j++) {
            string key = oldMap[i]->keyword;
            string value = oldMap[i]->values[j];
            addKeyValue(key, value);
         }
      }
   }
   delete[] oldMap;
}
      //
      // int hash= 0;
      // for(int i = 0; i < oldSize; i++) {
      //    if(h1) {
      //       hash = calcHash(oldMap[i]->keyword);
      //    }else {
      //       hash = calcHash2(oldMap[i]->keyword);
      //    }
      //    if(map[hash] != NULL) {
      //       if(c1){
      //          hash = collHash1(hash, oldMap[i]->keyword);
      //       }else{
      //          hash = collHash2(to_string(hash));
      //       }
      //    }
      //    map[hash] = oldMap[i];




int hashMap::collHash1(int h, int i, string key) {
   return (h + i)%mapSize;
}


int hashMap::collHash2(int h, int i, string k) {
   return (h + i * i) % mapSize;
}

int hashMap::findKey(string k) {
   int index;
   if(h1) {
      index = calcHash(k);
   }else {
      index = calcHash2(k);
   }
   if(map[index] == NULL) {
      return -1;
   }
   int ct = 0;
   while(map[index]->keyword != k) {
      if(c1) {
         index = collHash1(index, ct, k);
      }else {
         index = collHash2(index, ct, k);
      }
   }
   return index;
}


void hashMap::printMap() {
   // //check the values too
   // for(int i = 0;i<mapSize;i++) {
   //    if(map[i] != NULL) {
   //       cout<<map[i]->keyword << ": ";
   //       for(int j = 0; j< map[i]->currSize; j++) {
   //          cout<< j;
   //          cout<< map[i]->values[j];
   //       }
   //       cout<<endl;
   //    }
   // }
}
