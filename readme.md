# Distance Vector Routing (DVR)

This repository contains implementations of the Distance Vector Routing (DVR) algorithm for network simulations. The algorithms implemented include variations to simulate different scenarios such as count-to-infinity, poisoned reverse, and split horizon techniques.

## Table of Contents
- [Overview](#overview)
- [Files](#files)
- [How the Code Works](#how-the-code-works)
- [Setup and Compilation](#setup-and-compilation)
- [Running the Code](#running-the-code)
- [Cleaning Up](#cleaning-up)

## Overview

Distance Vector Routing (DVR) is a dynamic routing algorithm where each router shares its routing table with its immediate neighbors. This repository demonstrates the behavior of the DVR algorithm under different conditions, including:
- **Count-to-Infinity Problem**: Demonstrates how a network can face delays in routing updates due to infinite metric loops.
- **Poisoned Reverse**: An approach that helps to mitigate routing loops by informing neighbors about unreachable routes.
- **Split Horizon**: Another technique to avoid routing loops by not sharing routes back in the direction they were learned from.

## Files

The repository includes the following source files:
- `CountToInf.cpp`: Simulates the DVR algorithm and demonstrates the count-to-infinity problem.
- `DVR.cpp`: A basic implementation of the DVR algorithm.
- `PoisonedReverse.cpp`: Implements the DVR algorithm with the poisoned reverse technique.
- `SplitHorizon.cpp`: Implements the DVR algorithm with the split horizon technique.

## How the Code Works

Each file defines a class `DistanceVectorRouting`, which:
- Initializes a network graph with a set of nodes and weighted edges.
- Runs the DVR algorithm to compute the shortest path between nodes.
- Updates routing tables iteratively until no further changes occur.
- Simulates the removal of edges (e.g., link failures) and observes how the algorithm adapts to changes.
- Uses specific techniques (like poisoned reverse and split horizon) to handle potential routing loops.

### Main Functions:
- `runDVRAlgorithm()`: Runs the basic DVR algorithm.
- `runDVRAlgorithmWithPoisonedReverse()`: Runs the DVR algorithm with poisoned reverse.
- `runDVRAlgorithmWithSplitHorizon()`: Runs the DVR algorithm with split horizon.
- `removeEdge(int src, int dest)`: Simulates link failure between two nodes.

## Setup and Compilation

### Prerequisites
- **Compiler**: Make sure you have `g++` installed. You can use `MinGW-w64` for Windows.
- **Make**: You need `mingw32-make` or similar to use the provided `Makefile`.

### Steps to Install MinGW-w64:
1. Download and install `MinGW-w64` from [MinGW-w64.org](https://www.mingw-w64.org/).
2. Add `MinGW` to your system path:
   - Go to *Control Panel* > *System* > *Advanced system settings* > *Environment Variables*.
   - Find the `Path` variable, click *Edit*, and add the path to `MinGW` (e.g., `C:\mingw-w64\bin`).

### Compilation
1. Open *Command Prompt* or *Git Bash*.
2. Navigate to the project directory:
```bash
   cd C:\path\to\your\repo
   ```
3. Compile the code using mingw32-make:
```bash
    mingw32-make
```

### Cleaning Up
To remove the compiled executables and clean up the directory, use the following command:
```bash
    mingw32-make clean
```

