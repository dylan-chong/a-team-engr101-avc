OBJS=Controller.o NetworkController.o CameraController.o IRController.o MotorController.o
OBJSDIR=build/

all: main mainTest

main : $(OBJS)
	$(CC) $(CFLAGS) src/main.cpp $(OBJSDIR)Controller.o $(OBJSDIR)NetworkController.o $(OBJSDIR)MotorController.o $(OBJSDIR)IRController.o $(OBJSDIR)CameraController.o -o build/main
	
mainTest : $(OBJS)
	$(CC) $(CFLAGS) tests/mainTest.cpp $(OBJSDIR)Controller.o $(OBJSDIR)NetworkController.o $(OBJSDIR)MotorController.o $(OBJSDIR)IRController.o $(OBJSDIR)CameraController.o -o build/mainTest

Controller.o : src/Controller.h src/Controller.cpp
	$(CC) $(CFLAGS) -c src/Controller.cpp -o $(OBJSDIR)Controller.o
	
NetworkController.o : $(OBJSDIR)Controller.o src/NetworkController.h src/NetworkController.cpp
	$(CC) $(CFLAGS) -c src/NetworkController.cpp -o $(OBJSDIR)NetworkController.o
	
MotorController.o : $(OBJSDIR)Controller.o src/MotorController.h src/MotorController.cpp
	$(CC) $(CFLAGS) -c src/MotorController.cpp -o $(OBJSDIR)MotorController.o
	
IRController.o : $(OBJSDIR)Controller.o src/IRController.h src/IRController.cpp
	$(CC) $(CFLAGS) -c src/IRController.cpp -o $(OBJSDIR)IRController.o
	
CameraController.o : $(OBJSDIR)Controller.o src/CameraController.h src/CameraController.cpp
	$(CC) $(CFLAGS) -c src/CameraController.cpp -o $(OBJSDIR)CameraController.o
	