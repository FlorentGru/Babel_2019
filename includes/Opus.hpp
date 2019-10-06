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

class Opus {
public:
    Opus(std::vector<float> data);
    ~Opus();

    bool createEncoder();
    bool createDecoder();

    float *getDecodedData() const;

    bool encodeData(std::vector<float> data);
    bool decodeData();

private:
    OpusEncoder *encode;
    OpusDecoder *decode;
    unsigned char *dataEncoded;
    float *dataDecoded;
    int err;
    std::vector<float> audioInput;
};

#endif