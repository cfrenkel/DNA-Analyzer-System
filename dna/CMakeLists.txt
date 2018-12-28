cmake_minimum_required(VERSION 3.12)
project(dna)

set(CMAKE_CXX_STANDARD 98)

add_executable(dna main.cpp DNAReader.cpp DNAReader.h DNAWriter.cpp DNAWriter.h dna_seq.cpp dna_seq.h)