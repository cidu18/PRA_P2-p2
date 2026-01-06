bin/testTableEntry: testTableEntry.cpp TableE.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
bin/testHashTable: testHashTable.cpp TableE.h ../PRA_P1/ListLinked.h Dict.h
	mkdir -p bin
	g++ -o bin/tesHashTable testHashTable.cpp
clean:
	rm -rf *.o *.gch bin
