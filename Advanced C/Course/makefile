TARGET = course.exe
SOURCE_FILE = main10

all: $(TARGET)
	echo Deleting object files...
	rm *.o
	$(TARGET) -help -i -a -n

$(TARGET): $(SOURCE_FILE).o
	gcc -o $(TARGET) $(SOURCE_FILE).o

$(SOURCE_FILE).o: $(SOURCE_FILE).c
	gcc -c -o $(SOURCE_FILE).o $(SOURCE_FILE).c

clean:
	rm *.o
	rm $(TARGET).exe