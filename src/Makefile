CC = g++

Printer: SimplisticController.o Motor.o PrinterHead.o main.o
	$(CC) -o botball_user_program main.o Motor.o PrinterHead.o SimplisticController.o -lwallaby

main.o: main.cpp
	$(CC) -c main.cpp

SimplisticController.o: Controller/SimplisticController.cpp Controller/SimplisticController.hpp
	$(CC) -c Controller/SimplisticController.cpp

Motor.o: PrinterHead/Motor.cpp PrinterHead/Motor.hpp
	$(CC) -c PrinterHead/Motor.cpp

PrinterHead.o: PrinterHead/PrinterHead.cpp PrinterHead/PrinterHead.hpp PrinterHead/Motor.hpp
	$(CC) -c PrinterHead/PrinterHead.cpp


clean:
	rm botball_user_program *.o
