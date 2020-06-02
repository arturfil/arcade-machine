CXX=g++ -w -std=c++11 -Wfatal-errors
EXEC=arcade

all: build run

build: 
	$(CXX) ./src/*.cpp ./src/Utils/*.cpp  ./src/Graphics/*.cpp \
	-lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf \
	-o $(EXEC)

run:
	./$(EXEC)

clean: 
	rm -f $(EXEC)