#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <boost/crc.hpp>

#ifndef PRIVATE_BUFFER_SIZE
#define PRIVATE_BUFFER_SIZE 1024
#endif

std::streamsize const buffer_size = PRIVATE_BUFFER_SIZE;

/**
 * @brief Hash sum calculation class
 *
 * Hash sum calculation class , with connection of boost crc 32 library
 *
 *\include crc.cpp
 */

class crc
{
public:
    /**
     * @brief Hash sum calculation
     *
     * @param inData File path
     * @return std::size_t Hash sum
     */
    std::size_t crcHash(std::filesystem::path inData);
};
