#pragma once
#include <string>
#include <memory>

namespace bayan {
    enum HashAlgorithmType
    {
	    CRC32,
	    MD5
    };

    class IHasher 
    {
        public:
            virtual std::string getDigest(const char* buf, size_t buf_size) = 0;
    };

    class Crc32 : public IHasher 
    {
        public:
            std::string getDigest(const char* buf, size_t buf_size) override;
    };

    class Md5 : public IHasher 
    {
        public:
            std::string getDigest(const char* buf, size_t buf_size) override;
    };
};
