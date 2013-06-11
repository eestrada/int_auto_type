CXX ?= c++
CXXFLAGS := -std=c++11 -pedantic -g -Wall -I./ -I./inc/ -I./src/

BINDIR := ./bin
OBJDIR := ./obj
SRCDIR := ./src
INCDIR := ./inc

BIN := $(BINDIR)/test.bin
ARGS := 

SRCS :=  $(wildcard $(SRCDIR)/*.cpp)
INCS :=  $(wildcard $(INCDIR)/*.h*)

OBJS := $(patsubst %.cpp,%.o,$(SRCS))
OBJS := $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(OBJS))


.PHONY : run test clean memcheck

run : $(BIN)
	$(BIN) $(ARGS)

test : clean memcheck

clean :
	@ echo "Removing generated files"
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)

memcheck : $(BIN)
	@ echo "Running valgrind to check for memory leaks"
	valgrind --tool=memcheck --leak-check=yes --max-stackframe=5000000 \
	--show-reachable=yes $(BIN) $(ARGS)
	@ echo

$(BIN) : $(OBJS) $(SRCS) $(INCS)
	@ echo "Compiling binary"
	@- mkdir -p $(BINDIR)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)
	@ echo

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCS)
	@- mkdir -p $(OBJDIR)
	@ #echo 'Creating object file "'$@'" From source file "'$<'".'
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@ echo

