

#include <ostream>
#include <iostream>
#include <string>

template <typename T>

class TableEntry {

	public:
	
	 std::string key;
	 T value;
	 TableEntry(std::string key, T value) : key(key), value(value){
		 this->key = key;
		 this->value = value;
	 }

	 TableEntry(std::string key){
	 
		 key;
	 }
	 TableEntry(){
	 
		 key = "";
	 }

	 friend bool operator==(const TableEntry<T> &t1, const TableEntry<T> &t2){
		return t1.key == t2.key;		
	 } 
	 
	 friend bool operator!=(const TableEntry<T> &t1, const TableEntry<T> &t2){
	 	return t1.key != t2.key;
	 }
	 
	 friend std::ostream& operator <<(std::ostream &out, const TableEntry<T> &te ){
	 	out << "Clave:" << te.key << "->" << te.value << std::endl; 
		return out;
	 }

};


























