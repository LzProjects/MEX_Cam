CC=g++
INCL=
LIBS=-lstdc++ `pkg-config --libs opencv`
CFLAGS=-std=c++11 `pkg-config --cflags opencv`

OBJ=obj/

TARGETS = main

all:	$(TARGETS)



#
# application
#

main.o:	main.cpp 
	$(CC) $(INCL) $(CFLAGS) -c  main.cpp -o $(OBJ)main.o

main:	main.o 
	$(CC) -o main  $(OBJ)main.o  $(LIBS)  $(CFLAGS)



#
# unit tests


#
# additional processes
#

doc:
	doxygen Doxyfile

#cleaning up
clean:
	rm -r $(OBJ)*.o  *.xml  *~ $(TARGETS) DOXYGENDOC
