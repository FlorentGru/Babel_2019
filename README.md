# Babel

A Skype using different library like Qt or Port Audio

## How to compile on Linux

Do the command : "mkdir build && cd build && conan install .. && cmake .. -G "Unix Makefiles" && cmake -build . && make && cd bin"

## How to compile on Windows

mkdir build
cd build
conan install ..
cmake ..
After that you have to open the solution in 'build' with Visual Code to build the 2 executable.
Go to the directory 'bin' in 'build' to find the two executables.

## How to execute on Linux

Execute the command : "sudo ./babel_server port" to open the server
Execute the command : "./babel_client ip_address port" to open the client interface

## How to execute on Windows

Execute the command : "sudo ./babel_server.exe port" to open the server
Execute the command : "./babel_client.exe ip_address port" to open the client interface