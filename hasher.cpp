#include "hasher.h"
#include <boost/crc.hpp>
#include <boost/uuid/detail/md5.hpp>

std::string bayan::Crc32::getDigest(const char* buf, size_t buf_size)
{
        boost::crc_32_type crc_hash;
        crc_hash.process_bytes(buf, buf_size);
        return std::to_string(crc_hash.checksum());
};

std::string bayan::Md5::getDigest(const char* buf, size_t buf_size) 
{
        boost::uuids::detail::md5 md5_hash;
        md5_hash.process_bytes(buf, buf_size);
        boost::uuids::detail::md5::digest_type digest;
        md5_hash.get_digest(digest);
        return std::string(reinterpret_cast<char*>(&digest));
};
