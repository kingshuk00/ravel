#ifndef OTFIMPORTER_H
#define OTFIMPORTER_H

#include "rawtrace.h"
#include "otf.h"

class OTFImporter
{
public:
    OTFImporter(const char* otf_file);
    ~OTFImporter();
    RawTrace * importOTF();

    static int handleDefTimerResolution(void * userData, uint32_t stream, uint64_t ticksPerSecond);
    static int handleDefFunction(void * userData, uint32_t stream, uint32_t func,
                                 const char* name, uint32_t funcGroup, uint32_t source);

    unsigned long long ticks_per_second;

private:
    void readRawTrace();
    void setHandlers();

    const char * filename;
    OTF_FileManager * fileManager;
    OTF_Reader * otfReader;
    OTF_HandlerArray * handlerArray;

    RawTrace * rawtrace;

};

#endif // OTFIMPORTER_H
