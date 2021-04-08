#include <iostream>
#include <iterator>
#include <list>

/*
    Design a HashSet without using any built-in hash table libraries.

    Implement MyHashSet class:

    void add(key) Inserts the value key into the HashSet.
    bool contains(key) Returns whether the value key exists in the HashSet or not.
    void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

class MyHashSet {
public:
    int BUCKET_SIZE; //No. Buckets
    float LOAD_FACTOR;
    int size;
    std::list<int> *table; //Pointer to Array of Buckets
    
    MyHashSet() {
        BUCKET_SIZE = 16; //Default
        LOAD_FACTOR = 0.75;
        size = 0;
        table = new std::list<int>[BUCKET_SIZE];
    }
    
    int getHash(int k){
        return k % BUCKET_SIZE;
    }
    
    void add(int key) {
        
        if(!contains(key)){
            int index = getHash(key);
            table[index].push_back(key);
            size++;
            if((float)++size/(float)BUCKET_SIZE > LOAD_FACTOR){
                reHash();
            }
        }
    }
    
    void reHash(){
        std::cout << "Rehashing Started..." << std::endl;
        
        //Save Current Bucket List
        std::list<int> *temp = table;
        //Increase BucketSize
        BUCKET_SIZE *= 2;
        //Create New List
        table = new std::list<int>[BUCKET_SIZE];
        //Reset Size
        size = 0;
        
        //Iterate Through Old List and Re-Add
        std::list<int>::iterator it;
        for(int i = 0; i < BUCKET_SIZE/2; i++){
            for (it = temp[i].begin(); it != temp[i].end(); it++) {
                add(*it);
            }
        }
        //Delete Old List
        delete[] temp;
    }
    
    void remove(int key) {
        int index = getHash(key);
        
        //Find Key Within Bucket
        std::list<int>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key){
                break;
            }
        }
        //If Found, Erase
        if(it != table[index].end()){
            table[index].erase(it);
            size--;
        }
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = getHash(key);
        
        //Find Key Within Bucket
        std::list<int>::iterator it;
        for(it = table[index].begin(); it != table[index].end(); it++){
            if(*it == key){
                break;
            }
        }
        
        //If Found, True
        if(it != table[index].end()){
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */