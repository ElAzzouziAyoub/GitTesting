CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRC = main.cpp Resource.cpp Container.cpp Pod.cpp Server.cpp KubernetesCluster.cpp Cloud_Util.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
