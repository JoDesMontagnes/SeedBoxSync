CC=g++
CFLAGS=-W -Wall
LDFLAGS=
LIB=
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC = SeedBoxSync

all : clean
	make $(EXEC)
	

$(EXEC) : $(OBJS)
	$(CC) $(LDFLAGS) $(SRC)  -o $(EXEC) $(LIB)

clean:
	rm -rf *.o $(EXEC)
			
