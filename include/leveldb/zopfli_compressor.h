#ifndef STORAGE_LEVELDB_INCLUDE_ZOPFLI_COMPRESSOR_H_
#define STORAGE_LEVELDB_INCLUDE_ZOPFLI_COMPRESSOR_H_

#include "leveldb/export.h"
#include "leveldb/compressor.h"

namespace leveldb {

class DLLX ZopfliCompressor : public Compressor {
public:
	static const int SERIALIZE_ID = 2; //Same as ZLib since it is a replacement

	ZopfliCompressor() : Compressor(SERIALIZE_ID) {}

    virtual ~ZopfliCompressor() = default;

	virtual void compressImpl(const char* input, size_t length, ::std::string& output) const override;

	virtual bool decompress(const char* input, size_t length, ::std::string &output) const override;

private:
};

}

#endif