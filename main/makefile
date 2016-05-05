all: main tests

main:src/main.cpp src/Controller.h src/NetworkController.h src/CameraController.h src/IRController.h src/MotorController.h
	sudo $(CC) -o build/main -c src/main.cpp $(CFLAGS)
	
tests:tests/mainTest.cpp tests/CameraControllerTest.h tests/IRControllerTest.h tests/MotorControllerTest.h tests/NetworkControllerTest.h  src/Controller.h src/NetworkController.h src/CameraController.h src/IRController.h src/MotorController.h
	sudo $(CC) -o build/mainTest -c tests/mainTest.cpp $(CFLAGE)
