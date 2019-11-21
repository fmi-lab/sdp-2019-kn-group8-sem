#include <iostream>

template<typename K, typename V> 
  class HashNode 
{ 
    public: 
    V value; 
    K key; 
      
    HashNode(K key, V value) 
    { 
        this->value = value; 
        this->key = key; 
    } 
}; 


template<typename K, typename V> 
class HashMap 
{ 
    HashNode<K,V> **arr; 
    int capacity; 
    int size; 
    HashNode<K,V> *dummy; 
  
    public:  HashMap() 
    { 
        capacity = 20; 
        size=0; 
        arr = new HashNode<K,V>*[capacity]; 
          
        for(int i=0 ; i < capacity ; i++) 
            arr[i] = nullptr; 
          
        dummy = new HashNode<K,V>(-1, -1); 
    } 

    // the simplest possible hash funciton. 
    int hashCode(K key) 
    { 
        return key % capacity; 
    } 
      
    void insertNode(K key, V value) 
    { 
        HashNode<K,V> *temp = new HashNode<K,V>(key, value); 
          
        int hashIndex = hashCode(key); 
          
        //find next free space  
        while(arr[hashIndex] != nullptr && arr[hashIndex]->key != key 
               && arr[hashIndex]->key != -1) 
        { 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //if new node to be inserted increase the current size 
        if(arr[hashIndex] == nullptr || arr[hashIndex]->key == -1) 
            size++; 
        if (arr[hashIndex]->key == key) {
            arr[hashIndex] = temp; 
        } else {
            std::cerr << "ERROR: my hashtable is full" << std::endl;
            // TODO: increase capacity and rehash
        }
    } 
      
    V deleteNode(int key) 
    { 
        int hashIndex = hashCode(key); 
          
        while(arr[hashIndex] != nullptr) 
        { 
            if(arr[hashIndex]->key == key) 
            { 
                HashNode<K,V> *temp = arr[hashIndex]; 
                arr[hashIndex] = dummy; 
                size--; 
                return temp->value; 
            } 
            hashIndex++; 
            hashIndex %= capacity; 
  
        } 
        return nullptr; 
    } 
      
    V get(int key) 
    { 
        int hashIndex = hashCode(key); 
        int counter=0; 
        while(arr[hashIndex] != nullptr) 
        {    int counter =0; 
             if(counter++>capacity)  
                return nullptr;         
            if(arr[hashIndex]->key == key) 
                return arr[hashIndex]->value; 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        return nullptr; 
    } 
      
    int sizeofMap() 
    { 
        return size; 
    } 

    bool isEmpty() 
    { 
        return size == 0; 
    }
       
}; 
