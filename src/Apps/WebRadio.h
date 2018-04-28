#include "M5StackSAM.h"
#include "AudioFileSourceICYStream.h"
#include "AudioFileSourceBuffer.h"
#include "AudioGeneratorMP3a.h"
#include "AudioOutputI2S.h"

class WebRadioClass
{
  public:
    WebRadioClass();
    ~WebRadioClass();
    void Run();

  private:
    void getvolume();
    void setVolume(int *v);
    void FreeResources();
    
    const char *URL = "http://astreaming.europafm.ro:8000/europafm_mp3_64k";
    
    const int preallocateBufferSize = 16384;
    int SignalStrength;
    unsigned long now;
    unsigned long lastcheck;
    bool play = true;
    bool upd = true;

    AudioGeneratorMP3a *mp3;
    AudioFileSourceICYStream *file;
    AudioFileSourceBuffer *buff;
    AudioOutputI2S *out;
    AudioStatus *stat;
};