#ifndef DICT_H
#define DICT_H

#include <iostream>
#include <string>
#include <ostream>

template <typename T>

class Dict {
	
	public:
	virtual  void insert(std::string key, T value) = 0;
	virtual T search(std::string key) = 0; 
	virtual T remove(std::string key) = 0; 
	
	virtual int entries();




};

#endif
