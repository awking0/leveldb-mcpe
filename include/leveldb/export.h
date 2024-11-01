#ifndef STORAGE_LEVELDB_INCLUDE_EXPORT_H_
#define STORAGE_LEVELDB_INCLUDE_EXPORT_H_

#ifdef LEVELDB_SHARED
    #ifdef WIN32
        #ifdef LEVELDB_IMPLEMENTATION
        #define DLLX __declspec(dllexport)
        #else
        #define DLLX __declspec(dllimport)
        #endif
    #else
        #define DLLX
    #endif
#else
    #define DLLX
#endif

#endif  // STORAGE_LEVELDB_INCLUDE_EXPORT_H_
