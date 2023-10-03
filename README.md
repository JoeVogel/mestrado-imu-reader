# mestrado-imu-reader

This repository contains an implementation of a program to read the [VectorNav VN-300 IMU sensor](https://www.vectornav.com/products/detail/vn-300) data and convert it to the [SmartData MotionVector](https://lisha.ufsc.br/SDAV+-+SmartData+Model) for Autonomous Vehicles development

## Program file

This is a C++ project, copied from VectorNav library and inside the [/examples/imu_reader](./examples/imu_reader) is the main sourcecode [main.cpp](./examples/imu_reader/main.cpp)

You can use Make to compile the file to generate the [imu_reader](./examples/imu_reader/imu_reader) executable to your Operational System.

Execute this command inside [imu_reader](./examples/imu_reader/) to compile the runnable file:

	make .

And then, execute the [imu_reader](./examples/imu_reader/imu_reader) file with the command below (on Linux):

	./imu_reader