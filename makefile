CC=g++
CFLAGS=-W -Wall
LDFLAGS=
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC = SeedBoxSync

all : clean
	make $(EXEC)
	

$(EXEC) : $(OBJS)
	$(CC) $(LDFLAGS) $(SRC) -o $@ 

clean:
	rm -rf *.o $(EXEC)
			
