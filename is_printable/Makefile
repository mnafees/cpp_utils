CXX=g++
CXXFLAGS=-std=c++17

all: example ;

example: example.cpp is_printable.hpp
	@$(CXX) $(CXXFLAGS) example.cpp -o example

clean:
	@rm example