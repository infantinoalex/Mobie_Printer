CC = g++

Printer: SimplisticController.o Motor.o PrinterHead.o main.o
	$(CC) -o botball_user_program main.o Motor.o PrinterHead.o SimplisticController.o -lwallaby

main.o: main.cpp
	$(CC) -c main.cpp

SimplisticController.o: SimplisticController.cpp ../includes/SimplisticController.hpp
	$(CC) -c SimplisticController.cpp

Motor.o: Motor.cpp ../includes/Motor.hpp
	$(CC) -c PrinterHead/Motor.cpp

PrinterHead.o: PrinterHead.cpp ../includes/PrinterHead.hpp ../includes/Motor.hpp
	$(CC) -c PrinterHead/PrinterHead.cpp


clean:
	rm botball_user_program *.o
