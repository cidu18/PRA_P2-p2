#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../PRA_P1/ListLinked.h"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableE.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n; 
        int max;
        ListLinked<TableEntry<V>>** table;
        
        int h(std::string key) {
          int suma = 0; 
          for(char c : key){
            suma += static_cast<int>(c);
          }
          return suma % max; 
        }

    public:
        void insert(std::string key, V value) override {
          int pos = h(key);
          for (int i = 0; i < table[pos]->size(); i++) {
            if (table[pos]->get(i).key == key) {
              throw std::runtime_error("La llave '" + key + "' ya existe.");
            }
          }
          TableEntry<V> newEntry(key, value);
          table[pos]->prepend(newEntry);
          n++;
        }

        V search(std::string key) override {
          int pos = h(key);
          for (int i = 0; i < table[pos]->size(); i++) {
            TableEntry<V> entry = table[pos]->get(i);
            if (entry.key == key) {
              return entry.value;
            }
          }
          throw std::runtime_error("Key not found in dictionary");
        }

        V remove(std::string key) override {
          int pos = h(key);
      
          for (int i = 0; i < table[pos]->size(); i++) {
            if (table[pos]->get(i).key == key) {
              V value = table[pos]->get(i).value;
              table[pos]->remove(i);
              n--;
              return value;
            }
          }
          throw std::runtime_error("Key not found for removal");
        }
        int entries(){
          return n;
        }

        HashTable(int size){
          n = 0;
          max = size;
          table = new ListLinked<TableEntry<V>>*[max];
          for(int i=0; i < max; i++){
            table[i] = new ListLinked<TableEntry<V>>();
          }
        }

        ~HashTable(){
          for(int i = 0; i < max ; i++){
            delete table[i];
          }
          delete[] table;
        }

        int capacity(){
            return max;
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << std::endl;
            out << "================" << std::endl;
            for (int i = 0; i < th.max; i++) {
              out << "== Cubeta " << i << " ==" << std::endl;
              out << *(th.table[i]) << std::endl; 
            }
            out << "================" << std::endl;
            return out;
        }

        V operator[](std::string key){
          return search(key); // 
        }    
};

#endif
