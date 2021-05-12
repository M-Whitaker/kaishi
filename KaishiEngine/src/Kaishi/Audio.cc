//
// Created by Matt Whitaker on 04/05/2021.
//

#include <Audio.h>

namespace Kaishi {

bool isBigEndian()
{
  int a = 1;
  return !((char*)&a)[0];
}

int convertToInt(char* buffer, int len)
{
  int a = 0;
  if (!isBigEndian())
    for (int i = 0; i<len; i++)
      ((char*)&a)[i] = buffer[i];
  else
    for (int i = 0; i<len; i++)
      ((char*)&a)[3 - i] = buffer[i];
  return a;
}

char* loadWAV(const char* fn, int *channels, int *sampleRate, int *bps, int *size)
{
  char buffer[4];
  std::ifstream in(fn, std::ios::binary);
  in.read(buffer, 4);
  if (strncmp(buffer, "RIFF", 4) != 0)
  {
    printf("this is not a valid WAVE file\n");
    return nullptr;
  }
  in.read(buffer, 4);
  in.read(buffer, 4);      //WAVE
  in.read(buffer, 4);      //fmt
  in.read(buffer, 4);      //16
  in.read(buffer, 2);      //1
  in.read(buffer, 2);
  *channels = convertToInt(buffer, 2);
  in.read(buffer, 4);
  *sampleRate = convertToInt(buffer, 4);
  in.read(buffer, 4);
  in.read(buffer, 2);
  in.read(buffer, 2);
  *bps = convertToInt(buffer, 2);
  in.read(buffer, 4);      //data
  in.read(buffer, 4);
  *size = convertToInt(buffer, 4);
  char* data = new char[*size];
  in.read(data, *size);
  return data;
}

Audio::Audio() {
  int channel, sampleRate, bps, size;
  data = loadWAV("../../../assets/test.wav", &channel, &sampleRate, &bps, &size);

  device = alcOpenDevice(nullptr);
  if (!device)
  {
    printf("cannot open sound card\n");
    return;
  }
  context = alcCreateContext(device, nullptr);
  if (!context) {
    printf("cannot open context\n");
    return;
  }
  alcMakeContextCurrent(context);

  unsigned int format;
  alGenBuffers(1, &bufferid);
  if (channel == 1) {
    if (bps == 8) {
      format = AL_FORMAT_MONO8;
    }
    else {
      format = AL_FORMAT_MONO16;
    }
  }
  else {
    if (bps == 8) {
      format = AL_FORMAT_STEREO8;
    }
    else {
      format = AL_FORMAT_STEREO16;
    }
  }
  alBufferData(bufferid, format, data, size, sampleRate);
  alGenSources(1, &sourceid);
  alSourcei(sourceid, AL_BUFFER, bufferid);
}
Audio::~Audio() {
  alDeleteSources(1, &sourceid);
  alDeleteBuffers(1, &bufferid);

  alcDestroyContext(context);
  alcCloseDevice(device);
  delete[] data;
}
void Audio::play() {
  // TODO(M-Whitaker): Check if AL_PLAYING
  alSourcePlay(sourceid);
}

}  // namespace Kaishi
