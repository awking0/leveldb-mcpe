#ifndef STORAGE_LEVELDB_INCLUDE_ZLIB_COMPRESSOR_H_
#define STORAGE_LEVELDB_INCLUDE_ZLIB_COMPRESSOR_H_

#include "leveldb/export.h"
#include "leveldb/compressor.h"
#include <cassert>

namespace leveldb {

class DLLX ZlibCompressorBase : public Compressor {
public:
	int inflate(const char* input, size_t length, ::std::string &output) const;

	const int compressionLevel;
	const bool raw;

    virtual ~ZlibCompressorBase() = default;

	ZlibCompressorBase(char uniqueCompressionID, int compressionLevel, bool raw) :
		Compressor(uniqueCompressionID),
		compressionLevel(compressionLevel),
		raw(raw)
	{
		assert(compressionLevel >= -1 && compressionLevel <= 9);
	}

	virtual void compressImpl(const char* input, size_t length, ::std::string& output) const override;

	virtual bool decompress(const char* input, size_t length, ::std::string &output) const override;

private:

	int _window() const;

};

class DLLX ZlibCompressor : public ZlibCompressorBase {
public:
	static const int SERIALIZE_ID = 2;

	ZlibCompressor(int compressionLevel = -1) :
		ZlibCompressorBase(SERIALIZE_ID, compressionLevel, false) {}
};

class DLLX ZlibCompressorRaw : public ZlibCompressorBase {
public:
	static const int SERIALIZE_ID = 4;

	ZlibCompressorRaw(int compressionLevel = -1) :
		ZlibCompressorBase(SERIALIZE_ID, compressionLevel, true) {}
};

}

#endif // STORAGE_LEVELDB_INCLUDE_ZLIB_COMPRESSOR_H_