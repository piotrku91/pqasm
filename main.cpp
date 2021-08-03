#include <fstream>
#include <vector>
#include <algorithm>
#include "DataBlock.hpp"


bool saveToBin(const std::string &filename, std::vector<std::shared_ptr<DataBlock>> &ProgramData)
{
    std::ofstream fileObject(filename, std::ios::out | std::ios::binary);
    if ((!fileObject) || (ProgramData.empty()))
    {
        return false;
    };

    std::for_each(ProgramData.begin(), ProgramData.end(), [&fileObject](auto actualDataObject)
                  {
                      uint_fast8_t Line = 0x00;
                      if (isTargetClassObject<DataBlock, Instruction>(actualDataObject.get()))
                      {
                          Line = isTargetClassObject<DataBlock, Instruction>(actualDataObject.get())->getHeader();
                          fileObject.write(reinterpret_cast<char *>(&Line), sizeof(Line));
                      };

                      Line = actualDataObject->getData();
                      fileObject.write(reinterpret_cast<char *>(&Line), sizeof(Line));
                  });
    fileObject.close();
    return true;
}

int main(int paramCount, char *params[])
{
    std::vector<std::shared_ptr<DataBlock>> Program;

    Program.push_back(DataBlock::createData<Instruction>(Instruction(opCodes::MOV, operandsCodes::AtoB, 0xFF)));
    Program.push_back(DataBlock::createData<Instruction>(Instruction(opCodes::MOV, operandsCodes::MemToA, 0xFF)));
    Program.push_back(DataBlock::createData<Instruction>(Instruction(opCodes::MOV, operandsCodes::DataToA, 0xFF)));

    for (char z : "test") {
     Program.push_back(DataBlock::createData<DataBlock>(DataBlock(static_cast<int>(z))));
    };
     

    std::cout << paramCount << " " << params[0] << std::endl;
    saveToBin("test.bin", Program);
    Program.clear();
}