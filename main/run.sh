#!/bin/bash
COPTIONS=""
echo "Do you want to print all debug info? (y/n)"
read debug
if test "debug" = "y"; then
	COPTIONS="$COPTIONS -Wall"
fi
echo "Do you want to include the E101 liburary? (y/n)"
read lib
if test "$lib" = "y"; then
	COPTIONS="$COPTIONS -Llib -lE101"
fi
make CFLAGS="$COPTIONS" CC="g++"
echo "Do you want to run tests? (y/n)"
read tests
if test "$tests" = "y"; then
	sudo build/mainTest
	echo "Tests run."
else
	echo "Tests not run."	
fi
echo "Do you want to run the program? (y/n)"
read run
if test "$run" = "y"; then
	sudo build/main
	echo "Program run."
else 
	echo "Program not run."
fi
