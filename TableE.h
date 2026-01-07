

#include <ostream>
#include <iostream>
#include <string>

template <typename V>

class TableEntry {

	public:
  friend bool operator<(const TableEntry<V>& te1, const TableEntry<V>& te2) {
            return te1.key < te2.key;
        }

  friend bool operator>(const TableEntry<V>& te1, const TableEntry<V>& te2) {
            return te1.key > te2.key;
        }
	
	 std::string key;
	 V value;
	 TableEntry(std::string key, V value) : key(key), value(value){
		 this->key = key;
		 this->value = value;
	 }

	 TableEntry(std::string key){
	 
		 this->key = key;
	 }
	 TableEntry(){
	 
		 key = "";
	 }

	 friend bool operator==(const TableEntry<V> &t1, const TableEntry<V> &t2){
		return t1.key == t2.key;		
	 } 
	 
	 friend bool operator!=(const TableEntry<V> &t1, const TableEntry<V> &t2){
	 	return t1.key != t2.key;
	 }
	 
	 friend std::ostream& operator <<(std::ostream &out, const TableEntry<V> &te ){
	 	out << "Clave:" << te.key << "->" << te.value << std::endl; 
		return out;
	 }

};


























