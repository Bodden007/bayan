#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <boost/crc.hpp>

#ifndef PRIVATE_BUFFER_SIZE
#define PRIVATE_BUFFER_SIZE 1024
#endif

std::streamsize const buffer_size = PRIVATE_BUFFER_SIZE;

class crc
{
public:
    std::size_t crcHash(std::filesystem::path inData);
};
