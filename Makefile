bin/testBSTreeDict: testBSTreeDict.cpp Dict.h BStree.h TableE.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp
bin/testTableEntry: testTableEntry.cpp TableE.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
bin/testHashTable: testHashTable.cpp TableE.h ../PRA_P1/ListLinked.h Dict.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp
bin/testBSTree: testBSTree.cpp BStree.h BSNode.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp
clean:
	rm -rf *.o *.gch bin
