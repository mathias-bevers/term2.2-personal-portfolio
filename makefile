# To intergrade with vs-code look at https://hackernoon.com/how-to-set-up-c-debugging-in-vscode-using-a-makefile

CC = g++
CFLAGS = -g -Wall
SFFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = main.o game.o player.o gameObject.o settings.o scene.o sceneManager.o gameScene.o ball.o hit.o physicsObject.o
TARGET = program.out
BUILD_DIR = build/

all: reset main move

reset:
	-rm -rf ./$(BUILD_DIR)*.out
	-rm -rf ./$(BUILD_DIR)*.log 

move:
	mv *.o $(BUILD_DIR)
	-mv *.out $(BUILD_DIR)
	cp -r assets/ build/

# To run SFML add flags '-lsfml-graphics -lsfml-window -lsfml-system'
main: $(OBJECTS)
	$(CC) -g -o $(TARGET) $(OBJECTS) src/tools/easylogging++.cc $(SFFLAGS)

main.o: game.o
	$(CC) $(CFLAGS) -c main.cpp

game.o: player.o sceneManager.o settings.o
	$(CC) $(CFLAGS) -c src/game.cpp

player.o: gameObject.o
	$(CC) $(CFLAGS) -c src/player.cpp

ball.o: gameObject.o
	$(CC) $(CFLAGS) -c src/ball.cpp

gameObject.o:
	$(CC) $(CFLAGS) -c src/core/gameObject.cpp

scene.o: gameObject.o
	$(CC) $(CFLAGS) -c src/core/scene.cpp

sceneManager.o: scene.o
	$(CC) $(CFLAGS) -c src/core/sceneManager.cpp

hit.o:
	$(CC) $(CFLAGS) -c src/core/physics/hit.cpp

physicsObject.o:
	$(CC) $(CFLAGS) -c src/core/physics/physicsObject.cpp

gameScene.o: scene.o player.o ball.o
	$(CC) $(CFLAGS) -c src/scenes/gameScene.cpp

settings.o:
	$(CC) $(CFLAGS) -c src/tools/settings.cpp