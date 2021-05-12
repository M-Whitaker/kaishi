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

class Audio {
 private:
  ALCdevice* device;
  ALCcontext* context;
  unsigned int sourceid, bufferid;
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
