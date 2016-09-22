EXE = mp1
OBJS = mp1.cpp bfs.o dfs.o greedy.o

COMPILER = g++
COMPILER_OPTS = -c -g -std=c++11 -Wall -pedantic -Werror
LINKER = g++

all : $(EXE) 

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) -o $(EXE)

bfs.o : bfs.h bfs.cpp
	$(COMPILER) $(COMPILER_OPTS) bfs.cpp

dfs.o : dfs.h dfs.cpp
	$(COMPILER) $(COMPILER_OPTS) dfs.cpp

greedy.o : greedy_search.h greedy.cpp
	$(COMPILER) $(COMPILER_OPTS) greedy.cpp
	
clean :
	-rm -f *.o $(EXE)