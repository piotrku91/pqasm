#include "fileops.hpp"
#include <map>
#include <string>

std::map<std::string, uint_fast8_t> opCodesMap{
    {"MOV", static_cast<uint_fast8_t>(opCodes::MOV)}};

int main(int paramCount, char *params[])
{
    std::cout << "\n" << "pqasm for 8 bit computer v0.1a\n" << "----------------------------" << "\n\n";
    filePQAsmManager fileOperator;
    fileOperator.readFileToVector("code.txt");
    fileOperator.Analyze();
    // fileOperator.getProgramData().push_back(DataBlock::createData<Instruction>(Instruction(opCodesMap["MOV"], operandsCodes::RegisterAfromPointerContent, 0xFF)));
    // fileOperator.getProgramData().push_back(DataBlock::createData<Instruction>(Instruction(opCodesMap["MOV"], operandsCodes::RegisterBfromPointerContent, 0xFF)));
    // fileOperator.getProgramData().push_back(DataBlock::createData<Instruction>(Instruction(opCodesMap["MOV"], operandsCodes::StoreInRAMfromRegisterA, 0xFF)));

    // for (char z : "test")
    // {
    //     fileOperator.getProgramData().push_back(DataBlock::createData<DataBlock>(DataBlock(static_cast<int>(z))));
    // };

    std::cout << paramCount << " " << params[0] << std::endl;
    fileOperator.saveToBin("test.bin");
    fileOperator.getProgramData().clear();
    std::cout << "Done." << std::endl;
}