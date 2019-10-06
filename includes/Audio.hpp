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
    void giveData();
    PaError InitInput();
    PaError InitOutput();
    std::vector<float> getInputData() const;
    void setOutputData(std::vector<float> vect);

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