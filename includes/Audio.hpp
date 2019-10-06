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
// #define RATE            48000
#define FRAMES          512

typedef struct {
    int frameIndex;
    int maxFrameIndex;
    std::vector<float> recordedSamples;
} paData;

class Audio {
public:
    Audio();
    ~Audio();

    PaError recordInput();
    PaError playOutput();
    void reset();
    PaError initInput();
    PaError initOutput();
    std::vector<float> getInputData() const;
    std::vector<float> getOutputData() const;
    void setOutputData(float *, unsigned long);

    static int recordCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags,
                        void *userData);
    static int playCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags,
                        void *userData);

private:
    paData dataInput;
    paData dataOutput;
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    PaStream *streamInput;
    PaStream *streamOutput;
    PaError err;
    int totalFrames;
    int numSamples;
};

#endif