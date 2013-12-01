CC=g++
CFLAGS=  -O3 -c -Wall -pedantic -Wextra
#CFLAGS=  -g -c -Wall -pedantic -Wextra
#LDFLAGS= -L/usr/X11R6/lib -lm -lpthread -lX11
#LDFLAGS=  -lX11 -lm -lpthread
SOURCES=Ccel.o Genome.o Protein.o Gene.o GRN.o Chemspace.o
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) 
test: $(OBJECTS) test.cpp
	$(CC)  $(OBJECTS)  test.cpp -o $@ $(LDFLAGS)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
