CC = g++

Printer: Controller.o CustomExceptions.o ColorImageConverter.o Image.o Helper.o Motor.o PrinterHead.o main.o
	$(CC) -o Printer main.o CustomExceptions.o Motor.o PrinterHead.o Image.o ColorImageConverter.o Controller.o Helper.o

main.o: main.cpp
	$(CC) -c main.cpp

Controller.o: Controller/Controller.cpp
	$(CC) -c Controller/Controller.cpp

CustomExceptions.o: Exception/CustomExceptions.cpp
	$(CC) -c Exception/CustomExceptions.cpp

ColorImageConverter.o: Image/ColorImageConverter.cpp
	$(CC) -c Image/ColorImageConverter.cpp

Image.o: Image/Image.cpp
	$(CC) -c Image/Image.cpp

Helper.o: Helper.cpp
	$(CC) -c Helper.cpp

Motor.o: PrinterHead/Motor.cpp
	$(CC) -c PrinterHead/Motor.cpp

PrinterHead.o: PrinterHead/PrinterHead.cpp
	$(CC) -c PrinterHead/PrinterHead.cpp


clean:
	rm Printer *.o
