/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Opus.cpp
*/

#include "Opus.hpp"

bool Opus::encodeData(std::vector<float> data)
{
    float *myfloat = &data[0];
    this->err = opus_encode_float(this->encode, myfloat, FRAME_SIZE, this->dataEncoded, MAX_SIZE);
    if (this->err < 0)
        return (false);
    return (true);
}

bool Opus::decodeData()
{
    this->err = opus_decode_float(this->decode, this->dataEncoded, MAX_SIZE ,this->dataDecoded, FRAME_SIZE, 0);
    if (this->err < 0)
        return (false);
    return (true);
}

bool Opus::createEncoder()
{
    this->encode = opus_encoder_create(SAMPLE_RATE, 2, OPUS_APPLICATION_AUDIO, &this->err);
    if (err < 0) {
        std::cout << "Can't create Encoder" << std::endl;
        return (false);
    }
    this->dataEncoded = new unsigned char[1000];
    return (true);
}

bool Opus::createDecoder()
{
    this->decode = opus_decoder_create(SAMPLE_RATE, 2, &this->err);
    if (err < 0) {
        std::cout << "Can't create Decoder" << std::endl;
        return (false);
    }
    return (true);
}

float *Opus::getDecodedData() const
{
    return this->dataDecoded;
}

Opus::Opus()
{
    if (this->createEncoder() == false) {
        std::cout << "Matter with Encoder" << std::endl;
        exit(84);
    }
    if (this->createDecoder() == false) {
        std::cout << "Matter with Decoder" << std::endl;
        exit(84);
    }
}

Opus::~Opus() {}

int main()
{
    return (0);
}