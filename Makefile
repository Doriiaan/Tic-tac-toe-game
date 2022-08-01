# Specific part of the Makefile
EXEC=game

CC=g++	# compilateur
CFLAGS=-std=c++20 -Werror -Wextra -Wall	# options compilateur
LDFLAGS=	# edition de lien

SRC = $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)	# fichiers .o -> fichiers.cpp


ifeq ($(DEBUG),yes)	#mode debug=yes
	CFLAGS += -g
	LDFLAGS =
else
	CFLAGS += -O3 -DNDEBUG
	LDFLAGS =
endif


all: $(EXEC)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)


.PHONY: clean

clean:
	@rm -rf src/*.o
	@rm $(EXEC)

