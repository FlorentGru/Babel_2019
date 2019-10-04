/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** PortAudio.hpp
*/

#ifndef _AUDIO_HPP_
#define _AUDIO_HPP_

#include "portaudio.h"
#include <vector>
#include <iostream>
#include <cstdio>

#define RATE            44100
#define FRAMES          512

typedef struct {
    int frameIndex;  /* Index into sample array. */
    int maxFrameIndex;
    std::vector<float> recordedSamples;
} paData;

class Audio {
public:
    Audio();
    ~Audio();

    paData getData() const;
    PaError recordInput();
    PaError playOutput();

private:
    paData data;
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    PaStream *stream;
    PaError err;
    int totalFrames;
    int numSamples;
};

#endif