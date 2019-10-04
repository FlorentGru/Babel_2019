/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** audio.cpp
*/

#include <stdio.h>
#include <math.h>
#include "Audio.hpp"


Audio::Audio()
{
    this->err = paNoError;
    this->totalFrames = 8 * RATE;
    this->data.maxFrameIndex = this->totalFrames;
    this->data.frameIndex = 0;
    this->numSamples = this->totalFrames * 2;
    for (int i = 0; i < this->numSamples; i++ ) { 
        this->data.recordedSamples.push_back(0);
    };
    this->err = Pa_Initialize();
    if (this->err != paNoError) {
        Pa_Terminate();
        exit(84);
    }
    this->inputParameters.device = Pa_GetDefaultInputDevice();
    if (this->inputParameters.device == paNoDevice) {
        printf("No Input Device\n");
        Pa_Terminate();
        exit (84);
    }
    this->inputParameters.channelCount = 2;
    this->inputParameters.sampleFormat = paFloat32;
    this->inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
    this->inputParameters.hostApiSpecificStreamInfo = NULL;

    this->outputParameters.device = Pa_GetDefaultOutputDevice();
    if (this->outputParameters.device == paNoDevice) {
        printf("No Output Device\n");
        Pa_Terminate();
        exit(84);
    }
    this->data.frameIndex = 0;
    this->outputParameters.channelCount = 2;
    this->outputParameters.sampleFormat =  paFloat32;
    this->outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    this->outputParameters.hostApiSpecificStreamInfo = NULL;
}

Audio::~Audio() {}

static int recordCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags,
                        void *userData)
{
    paData *data = static_cast<paData*>(userData);
    const float *rptr = static_cast<const float*>(inputBuffer);
    float *wptr = static_cast<float *>(&data->recordedSamples[data->frameIndex * 2]);
    long framesToCalc = 0;
    long i = 0;
    int finished = 0;
    unsigned long framesLeft = data->maxFrameIndex - data->frameIndex;
//hopla les warnings
    static_cast<void>(outputBuffer);
    static_cast<void>(timeInfo);
    static_cast<void>(statusFlags);
    static_cast<void>(userData);

    if (framesLeft < framesPerBuffer) {
        framesToCalc = framesLeft;
        finished = paComplete;
    }
    else {
        framesToCalc = framesPerBuffer;
        finished = paContinue;
    }
    if (inputBuffer == NULL) {
        for (i = 0 ; i < framesToCalc; i++) {
            *wptr++ = 0.0f;
            *wptr++ = 0.0f;
        }
    } else {
        for (i = 0 ; i < framesToCalc; i++) {
            *wptr++ = *rptr++;
            *wptr++ = *rptr++;
        }
    }
    data->frameIndex += framesToCalc;
    return finished;
}

static int playCallback(const void *inputBuffer, void *outputBuffer,
                        unsigned long framesPerBuffer,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags,
                        void *userData)
{
    paData *data = static_cast<paData *>(userData);
    float *rptr = static_cast<float *>(&data->recordedSamples[data->frameIndex * 2]);
    float *wptr = static_cast<float *>(outputBuffer);
    unsigned int i;
    int finished;
    unsigned int framesLeft = data->maxFrameIndex - data->frameIndex;
//hopla les warnings
    // static_cast<void>(outputBuffer);
    // static_cast<void>(timeInfo);
    // static_cast<void>(statusFlags);
    // static_cast<void>(userData);

    if (framesLeft < framesPerBuffer) {
        for (i = 0; i < framesLeft; i++) {
            *wptr++ = *rptr++;
            *wptr++ = *rptr++;
        }
        for (; i < framesPerBuffer; i++) {
            *wptr++ = 0;
            *wptr++ = 0;
        }
        data->frameIndex += framesLeft;
        finished = paComplete;
    } else {
        for (i = 0; i < framesPerBuffer; i++) {
            *wptr++ = *rptr++;
            *wptr++ = *rptr++;
        }
        data->frameIndex += framesPerBuffer;
        finished = paContinue;
    }
    return finished;
}

PaError Audio::recordInput()
{
    this->err = Pa_OpenStream(
        &this->stream,
        &this->inputParameters,
        NULL,
        RATE,
        FRAMES,
        paClipOff,
        recordCallback,
        &this->data
    );
    if (this->err != paNoError)
        return this->err;
    this->err = Pa_StartStream(this->stream);
    if (this->err != paNoError)
        return this->err;
    std::cout << "Recording\n";
    while ((err = Pa_IsStreamActive(this->stream)) == 1) {
        Pa_Sleep(1000);
        std::cout << "index = " << data.frameIndex << std::endl;
    }
    if (this->err < 0)
        return (this->err);
    this->err = Pa_CloseStream(stream);
    if (this->err != paNoError)
        return (this->err);
    return (paNoError);
}

PaError Audio::playOutput()
{
    this->data.frameIndex = 0;
    this->err = Pa_OpenStream(
        &this->stream,
        NULL,
        &this->outputParameters,
        RATE,
        FRAMES,
        paClipOff,
        playCallback,
        &this->data
    );
    if (this->err != paNoError) {
        return (this->err);
    }
    if (this->stream) {
        this->err = Pa_StartStream(this->stream);
        if (this->err != paNoError)
            return (this->err);
        std::cout << "Waiting for playback to finish\n";
        while ((err = Pa_IsStreamActive(this->stream)) == 1) {
            Pa_Sleep(100);
        }
        if (this->err < 0)
            return(this->err);
        this->err = Pa_CloseStream(this->stream);
        if (this->err != paNoError)
            return (this->err);

    }
    return (paNoError);
}

paData Audio::getData() const 
{
    return (this->data);
}

int main(void)
{
    Audio port;

    if (port.recordInput() != paNoError) {
        Pa_Terminate();
        return (84);
    }
    if (port.playOutput() != paNoError) {
        Pa_Terminate();
        return (84);
    }
    return (0);
}