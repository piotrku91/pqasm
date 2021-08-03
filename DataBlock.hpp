#pragma once

#include <iostream>
#include <memory>
#include "define.hpp"

class DataBlock
{
protected:
    uint_fast8_t Data_;

public:
  template <typename T>
    static std::shared_ptr<DataBlock> createData(T&& Args) //factory function
    {
        return std::make_shared<T>(Args);
    }

    virtual uint_fast8_t getData() { return Data_; };
    DataBlock(uint_fast8_t Data) : Data_{Data} {};
};

class Instruction : public DataBlock
{
private:
    uint_fast8_t opCode_;
    uint_fast8_t operandsCodes_;

public:
    Instruction(opCodes opCode, operandsCodes operandsCodes, uint_fast8_t Data) : DataBlock{Data}, opCode_{static_cast<uint_fast8_t>(opCode)}, operandsCodes_{static_cast<uint_fast8_t>(operandsCodes)} {};
    uint_fast8_t getHeader() { return ((opCode_ << 3) | (operandsCodes_)); };
};

template <typename T, typename T2> // Functions checks if object pointer is specify type of derived class object
static T2 *isTargetClassObject(T *derivedClass)
{
    T *test = derivedClass;
    T2 *cast_test = dynamic_cast<T2 *>(test);
    if (cast_test)
    {
        return cast_test;
    };
    return nullptr;
}