CXX = g++
INCLUDES = -I ../../include
CPPFLAGS = -Wall

SOURCES = main.cpp motionVector.cpp

all: imu_reader

clean:
	rm -f main.o motionVector.o imu_reader
	cd ../.. && make clean

imu_reader: main.o motionVector.o ../../build/bin/libvncxx.a
	$(CXX) -o imu_reader main.o motionVector.o -L ../../build/bin -lvncxx -lpthread

../../build/bin/libvncxx.a:
	cd ../.. && make

main.o: main.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

motionVector.o: motionVector.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $< -o $@