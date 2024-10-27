# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Executable names
EXECS = CountToInf DVR PoisonedReverse SplitHorizon

# Source files
SOURCES = CountToInf.cpp DVR.cpp PoisonedReverse.cpp SplitHorizon.cpp

# Default target
all: $(EXECS)

# Rules for each executable
CountToInf: CountToInf.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

DVR: DVR.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

PoisonedReverse: PoisonedReverse.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

SplitHorizon: SplitHorizon.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up generated files
clean:
	del /Q CountToInf.bin CountToInf.exe DVR.bin DVR.exe PoisonedReverse.bin PoisonedReverse.exe SplitHorizon.bin SplitHorizon.exe *.o

# Run specific executable
run-%: %
	./$<

# Phony targets
.PHONY: all clean run-%
