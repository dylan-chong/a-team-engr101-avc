OBJS=Controller.o NetworkController.o CameraController.o IRController.o MotorController.o PidController.o
OBJSDIR=build/

all: main mainTest

main : $(OBJS)
	$(PRE) $(CC) $(CFLAGS) src/main.cpp $(OBJSDIR)Controller.o $(OBJSDIR)NetworkController.o $(OBJSDIR)MotorController.o $(OBJSDIR)IRController.o $(OBJSDIR)CameraController.o $(OBJSDIR)PidController.o -o build/main 
	
mainTest : $(OBJS)
	$(PRE) $(CC) $(CFLAGS) tests/mainTest.cpp $(OBJSDIR)Controller.o $(OBJSDIR)NetworkController.o $(OBJSDIR)MotorController.o $(OBJSDIR)IRController.o $(OBJSDIR)CameraController.o  $(OBJSDIR)PidController.o -o build/mainTest

Controller.o : src/Controller.h src/Controller.cpp
	$(PRE) $(CC) $(CFLAGS) -c src/Controller.cpp -o $(OBJSDIR)Controller.o
	
NetworkController.o : $(OBJSDIR)Controller.o src/NetworkController.h src/NetworkController.cpp
	$(PRE) $(CC) $(CFLAGS) -c src/NetworkController.cpp -o $(OBJSDIR)NetworkController.o
	
MotorController.o : $(OBJSDIR)Controller.o src/MotorController.h src/MotorController.cpp
	$(PRE) $(CC) $(CFLAGS) -c src/MotorController.cpp -o $(OBJSDIR)MotorController.o
	
IRController.o : $(OBJSDIR)Controller.o src/IRController.h src/IRController.cpp
	$(PRE) $(CC) $(CFLAGS) -c src/IRController.cpp -o $(OBJSDIR)IRController.o
	
CameraController.o : $(OBJSDIR)Controller.o src/CameraController.h src/CameraController.cpp
	$(PRE) $(CC) $(CFLAGS) -c src/CameraController.cpp -o $(OBJSDIR)CameraController.o
	
PidController.o : $(OBJSDIR)Controller.o src/PidController.h src/PidController.cpp
	$(PRE) $(CC) $(CFLAGS) -c src/PidController.cpp -o $(OBJSDIR)PidController.o
	