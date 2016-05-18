#!/bin/bash
COPTIONS=""
MAKEPREFIX="sudo"
echo "Do you want to print all debug info? (y/n)"
read debug
if test "debug" = "y"; then
	COPTIONS="$COPTIONS -Wall"
fi
echo "Is it on the simulator? (y/n)"
read lib
if test "$lib" = "y"; then
	COPTIONS="$COPTIONS -L/usr/lib -lE101"
	MAKEPREFIX=""
fi
make CFLAGS="$COPTIONS" CC="g++" PRE="$MAKEPREFIX"
echo "Do you want to run tests? (y/n)"
read tests
if test "$tests" = "y"; then
	if [["$MAKEPREFIX" = "sudo"]]; then
		sudo build/mainTest
	else
		build/mainTest
	fi
	echo "Tests run."
else
	echo "Tests not run."	
fi
echo "Do you want to run the program? (y/n)"
read run
if test "$run" = "y"; then
	if [["$MAKEPREFIX" = "sudo"]]; then
		sudo build/main
	else
		build/main
	fi
	echo "Program run."
else 
	echo "Program not run."
fi
