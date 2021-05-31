//
// Created by Matt Whitaker on 04/05/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_AUDIO_H_
#define KAISHIENGINE_INCLUDE_KAISHI_AUDIO_H_

#include "kaipch.h"

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
//#include <AL/alut.h>

#include <unistd.h>

namespace Kaishi {

typedef struct AudioFile {
  int channel;
  int sampleRate;
  int bps;
  int size;
} AudioFile;

class Audio {
 private:
  ALCdevice* device;
  ALCcontext* context;
  ALuint source = 0;
  ALuint buffer = 0;
  char* data;
 public:
  Audio();
  ~Audio();
  void loadWAVFile(const char *filename);
  void play();
  void pause();
};

}  // Kaishi

#endif // KAISHIENGINE_INCLUDE_KAISHI_AUDIO_H_
