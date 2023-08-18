#include "../includes/crc.hpp"

std::size_t crc::crcHash(std::filesystem::path inData)
{

    boost::crc_32_type result;
    std::ifstream ifs(inData, std::ios_base::binary);
    if (ifs)
    {
        do
        {
            char buffer[buffer_size];

            ifs.read(buffer, buffer_size);
            result.process_bytes(buffer, ifs.gcount());
        } while (ifs);
    }
    else
    {
        std::cerr << "Failed to open file " << std::endl;
    }
    // TODO change
    // std::cout << std::hex << result.checksum() << std::endl;
    return result.checksum();
}