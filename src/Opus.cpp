/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Opus.cpp
*/

#include "Opus.hpp"

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

Opus::~Opus()
{
    opus_encoder_destroy(this->encode);
    opus_decoder_destroy(this->decode);
}


bool Opus::encodeData()
{
    float *myfloat = &this->audioInput[0];
    // float *myfloat = new float[FRAME_SIZE * 2 * sizeof(float)];
    // for (size_t i = 0; i < FRAME_SIZE * 2 * sizeof(float); i++) {
    //     myfloat[i] = this->audioInput.at(i);
    // }

    //debug
    // for (int i = 0; i < FRAME_SIZE * 2 *sizeof(float); i++) {
    //     std::cout << "AudioInput: " << this->audioInput.at(i) << std::endl;
    //     std::cout << "myfloat: " << myfloat[i] << std::endl;
    // }
    this->err = opus_encode_float(this->encode, myfloat, FRAME_SIZE, this->dataEncoded, MAX_SIZE);
    if (this->err < 0)
        std::cout << "Can't encode Float" << std::endl;
        return (false);
    return (true);
}

bool Opus::decodeData()
{
    // this->size = FRAME_SIZE * 2 * sizeof(float);
    this->size = this->audioInput.size();
    // std::cout << "FRAME_SIZE * 2 * sizeof(float): " << FRAME_SIZE * 2 * sizeof(float) << std::endl;
    this->dataDecoded = new float[this->size];
    // std::cout << "SIZE: " << this->audioInput.size() << std::endl;
    this->err = opus_decode_float(this->decode, this->dataEncoded, MAX_SIZE ,this->dataDecoded, FRAME_SIZE, 0);
    if (this->err < 0) {
        std::cout << "Can't decode Float" << std::endl;
        return (false);
    }
    return (true);
}

bool Opus::createEncoder()
{
    this->encode = opus_encoder_create(SAMPLE_RATE, 2, OPUS_APPLICATION_AUDIO, &this->err);
    if (err < 0) {
        std::cout << "Can't create Encoder" << std::endl;
        return (false);
    }
    this->dataEncoded = new unsigned char[MAX_SIZE];
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

unsigned char *Opus::getDataEncoded() const
{
    return this->dataEncoded;
}

unsigned long Opus::getSize() const
{
    return this->size;
}

void Opus::setAudioInput(std::vector<float> data)
{
    this->audioInput = data;
}
