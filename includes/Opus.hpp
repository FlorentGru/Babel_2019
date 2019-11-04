/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Opus.hpp
*/

#ifndef OPUS_HPP
#define OPUS_HPP

#include "opus.h"
#include <vector>
#include <iostream>
#include <stdbool.h>
#include <cstring>

#define FRAME_SIZE 960
#define SAMPLE_RATE 48000
#define MAX_SIZE 1000

class IOpus {
public:
    virtual bool encodeData() = 0;
    virtual bool decodeData() = 0;
};

class Opus : public IOpus {
public:
    Opus();
    ~Opus();

    bool encodeData();
    bool decodeData();

    bool createEncoder();
    bool createDecoder();

    float *getDecodedData() const;
    unsigned char *getDataEncoded() const;
    unsigned long getSize() const;

    void setAudioInput(std::vector<float> data);

private:
    OpusEncoder *encode;
    OpusDecoder *decode;
    unsigned char *dataEncoded;
    float *dataDecoded;
    int err;
    unsigned long size;
    std::vector<float> audioInput;
};

#endif