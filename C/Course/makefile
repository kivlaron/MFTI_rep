TARGET = course.exe
SOURCE_FILE = Course

all: $(TARGET)
	echo Deleting object files...
	rm *.o
	$(TARGET) -f temperature_big.csv -m 5

$(TARGET): $(SOURCE_FILE).o temp_functions.o
	gcc -o $(TARGET) $(SOURCE_FILE).o temp_functions.o

$(SOURCE_FILE).o: $(SOURCE_FILE).c
	gcc -c -o $(SOURCE_FILE).o $(SOURCE_FILE).c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	rm *.o
	rm $(TARGET).exe