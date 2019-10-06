/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** audio.cpp
*/

#include <stdio.h>
#include <math.h>
#include "Audio.hpp"
#include "Opus.hpp"

PaError Audio::initInput()
{
    this->dataInput.frameIndex = 0;
    this->dataInput.maxFrameIndex = this->totalFrames;
    for (int i = 0; i < this->numSamples; i++) {
        this->dataInput.recordedSamples.push_back(0);
    };
    this->inputParameters.device = Pa_GetDefaultInputDevice();
    if (this->inputParameters.device == paNoDevice) {
        printf("No Input Device\n");
        return(paNoDevice);
    }
    this->inputParameters.channelCount = 2;
    this->inputParameters.sampleFormat = paFloat32;
    this->inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    this->inputParameters.hostApiSpecificStreamInfo = nullptr;
    this->err = Pa_OpenStream(
        &this->streamInput,
        &this->inputParameters,
        nullptr,
        RATE,
        FRAMES,
        paClipOff,
        recordCallback,
        &this->dataInput
    );
    if (this->err != paNoError) {
        std::cout << "OpenStream\n";
        return (this->err);
    }
    return (paNoError);
}

PaError Audio::initOutput()
{
    this->dataOutput.maxFrameIndex = this->totalFrames;
    this->dataOutput.frameIndex = 0;
    for (int i = 0; i < this->numSamples; i++) {
        this->dataOutput.recordedSamples.push_back(0);
    };
    this->outputParameters.device = Pa_GetDefaultOutputDevice();
    if (this->outputParameters.device == paNoDevice) {
        printf("No Output Device\n");
        return (paNoDevice);
    }
    this->outputParameters.channelCount = 2;
    this->outputParameters.sampleFormat = paFloat32;
    this->outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    this->outputParameters.hostApiSpecificStreamInfo = nullptr;
    this->err = Pa_OpenStream(
        &this->streamOutput,
        nullptr,
        &this->outputParameters,
        RATE,
        FRAMES,
        paClipOff,
        playCallback,
        &this->dataOutput
    );
    if (this->err != paNoError) {
        std::cout << "OpenStream\n";
        return(this->err);
    }

    return (paNoError);
}

Audio::Audio()
{
    this->err = paNoError;
    this->totalFrames = 4 * RATE;
    this->numSamples = this->totalFrames * 2;
    this->err = Pa_Initialize();
    if (this->err != paNoError) {
        std::cout << "Initialize\n";
        Pa_Terminate();
        exit(84);
    }
    if (this->initInput() != paNoError) {
        std::cout << "Init Inputs\n";
        Pa_Terminate();
        exit(84);
    }
    if (this->initOutput() != paNoError) {
        std::cout << "Init Outputs\n";
        Pa_Terminate();
        exit(84);
    }
}

Audio::~Audio()
{
    this->err = Pa_CloseStream(this->streamInput);
    if (this->err != paNoError) {
        std::cout << "CloseStream Input\n";
        Pa_Terminate();
        exit(84);
    }
    this->err = Pa_CloseStream(this->streamOutput);
    if (this->err != paNoError) {
        std::cout << "CloseStream Output\n";
        Pa_Terminate();
        exit(84);
    }
    Pa_Terminate();
}

int Audio::recordCallback(const void *inputBuffer, void *outputBuffer,
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
    if (inputBuffer == nullptr) {
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

int Audio::playCallback(const void *inputBuffer, void *outputBuffer,
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
    static_cast<void>(outputBuffer);
    static_cast<void>(timeInfo);
    static_cast<void>(statusFlags);
    static_cast<void>(userData);

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
    this->err = Pa_StartStream(this->streamInput);
    if (this->err != paNoError) {
        std::cout << "OpenStream Input\n";
        return this->err;
    }
    std::cout << "Recording\n";
    while ((err = Pa_IsStreamActive(this->streamInput)) == 1) {
        // Pa_Sleep(1000);
    }
    if (this->err < 0) {
        std::cout << "IsActiveStream Input\n";
        return (this->err);
    }
    this->err = Pa_StopStream(this->streamInput);
    if (this->err != paNoError) {
        std::cout << "StopStream Input";
        return (this->err);
    }
    // std::cout << "SIZE INPUT: " << this->dataInput.recordedSamples.size() << std::endl;
    this->dataOutput.recordedSamples = this->dataInput.recordedSamples;
    return (paNoError);
}

PaError Audio::playOutput()
{
    this->dataOutput.frameIndex = 0;
    if (this->streamInput) {
        this->err = Pa_StartStream(this->streamOutput);
        if (this->err != paNoError) {
            std::cout << "OpenStream Output\n";
            return (this->err);
        }
        std::cout << "Waiting for playback to finish\n";
        while ((err = Pa_IsStreamActive(this->streamOutput)) == 1) {
            // Pa_Sleep(100);
        }
        if (this->err < 0) {
            std::cout << "IsActiveStream Output\n";
            return(this->err);
        }
        this->err = Pa_StopStream(this->streamOutput);
        if (this->err != paNoError) {
            std::cout << "StopStream Output";
            return (this->err);
        }
    }
    this->reset();
    return (paNoError);
}

void Audio::reset()
{
    this->dataInput.frameIndex = 0;
    this->dataInput.recordedSamples.clear();
    for (int i = 0; i < this->numSamples; i++) {
        this->dataInput.recordedSamples.push_back(0);
    };
    this->dataOutput.frameIndex = 0;
    this->dataOutput.recordedSamples.clear();
    for (int i = 0; i < this->numSamples; i++) {
        this->dataOutput.recordedSamples.push_back(0);
    };
}

std::vector<float> Audio::getInputData() const
{
    return (this->dataInput.recordedSamples);
}

std::vector<float> Audio::getOutputData() const
{
    return (this->dataOutput.recordedSamples);
}

void Audio::setOutputData(float *vect, unsigned long size)
{
    std::vector<float> myVect;

    for (int i = 0; i < size; i++) {
        myVect.push_back(vect[i]);
    }
    this->dataOutput.recordedSamples = myVect;
    // std::cout << "SIZE OUTPUT: " << this->dataOutput.recordedSamples.size() <<  std::endl;
}

//Main to use PortAudio
//Some opus functionnalities are in comments because it doesnt work

// int main(void)
// {
//     Audio port;
//     Opus opus;

//     if (port.recordInput() != paNoError) {
//         Pa_Terminate();
//         std::cout << "Input matter\n";
//         return (84);
//     }
//     // opus.setAudioInput(port.getInputData());
//     // opus.encodeData();
//     // // std::cout << "CALL DECODE\n";
//     // opus.decodeData();
//     // // std::cout << "DECODE DONE\n";
//     // port.setOutputData(opus.getDecodedData(), opus.getSize());
//     // // if (port.getInputData() == port.getOutputData()) {
//     // //     std::cout << "MEME DATA !!!!" << std::endl;
//     // // } else {
//     // //     std::cout << "PAS LA MEME DATA !!" << std::endl;
//     // // }
//     // // std::cout << "SET DATA FOR PLAYBACK\n";
//     if (port.playOutput() != paNoError) {
//         Pa_Terminate();
//         std::cout << "Output matter\n";
//         return (84);
//     }
//     return (0);
// }