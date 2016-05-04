#mainTest : tests/mainTest.cpp
#	sudo $(CC) -o mainTest tests/mainTest.cpp $(CFLAGS)

build/Controller.o : src/Controller.cpp
	sudo $(CC) -g -o build/Controller.o src/Controller.cpp $(CFLAGS)

build/CameraController.o : src/CameraController.cpp
	sudo $(CC) -g -o build/CameraController.o src/CameraController.cpp build/Controller.o  $(CFLAGS)
	
#build/IRController.o : src/IRController.cpp
#	sudo $(CC) -g -o build/IRController.o src/CameraController.cpp build/Controller.o $(CFLAGS)
#	
#build/MotorController.o : src/MotorController.cpp
#	sudo $(CC) -g -o build/MotorController.o src/CameraController.cpp build/Controller.o $(CFLAGS)
#	
#build/NetworkController.o : src/NetworkController.cpp
#	sudo $(CC) -g -o build/NetworkController.o src/CameraController.cpp build/Controller.o $(CFLAGS)

build/main:src/main.cpp
	sudo $(CC) -o build/ain src/main.cpp build/CameraController.o $(CFLAGS)
