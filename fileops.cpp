#include "fileops.hpp"
AnalyzeErrors filePQAsmManager::Analyze()
{
    std::cout << "Analizing file to compile ..." << std::endl;
    std::string Instruction;
    std::string Operand1;
    std::string Operand2;

    for (auto &currentLine : content)
    {
        size_t findIndex;
        size_t lastIndex;
        if (currentLine[0] != '#')
        {
            // INSTRUCTION READ
            findIndex = currentLine.find(" ");
            if (findIndex != std::string::npos)
            {
                Instruction = currentLine.substr(0, findIndex);
                lastIndex = findIndex;
            }
            else
            {
                return AnalyzeErrors::SyntaxError;
            };
            // OPERAND READ
            findIndex = currentLine.find(",", lastIndex);
            if (findIndex != std::string::npos)
            {
                Operand1 = currentLine.substr(lastIndex, currentLine.size() - findIndex - 2);
                lastIndex = findIndex;
            }
            else
            {
                return AnalyzeErrors::SyntaxError;
            };
            // OPERAND READ

            Operand2 = currentLine.substr(lastIndex, currentLine.size());
        }
    }

    std::cout << Instruction << Operand1 << Operand2 << std::endl;

    return AnalyzeErrors::OK;
}

bool filePQAsmManager::readFileToVector(std::string filename)
{
    std::ifstream input(filename.c_str());
    std::string linestr;
    if (!input)
        return false;
    while (std::getline(input, linestr))
    {
        if (linestr.size() > 0)
            content.push_back(linestr);
    }
    input.close();
    return true;
}

bool filePQAsmManager::saveToBin(const std::string &filename)
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
                      //std::cout << actualDataObject->getLineNumber() << std::endl;
                      Line = actualDataObject->getData();
                      fileObject.write(reinterpret_cast<char *>(&Line), sizeof(Line));
                  });
    fileObject.close();
    std::cout << "Compilation success to " << filename << std::endl;
    return true;
}