#ifndef STORAGE_LEVELDB_INCLUDE_SNAPPY_COMPRESSOR_H_
#define STORAGE_LEVELDB_INCLUDE_SNAPPY_COMPRESSOR_H_

#include "leveldb/export.h"
#include "leveldb/compressor.h"

namespace leveldb {

class DLLX SnappyCompressor : public Compressor
{
public:

	static const char SERIALIZE_ID = 1;

    virtual ~SnappyCompressor() {}

	SnappyCompressor() :
		Compressor(SERIALIZE_ID) {}

	virtual void compressImpl(const char* input, size_t length, ::std::string& output) const override;

	virtual bool decompress(const char* input, size_t length, ::std::string& output) const override;
};

}

#endif // STORAGE_LEVELDB_INCLUDE_SNAPPY_COMPRESSOR_H_
