#include "fileops.hpp"



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
                      std::cout << actualDataObject->getLineNumber() <<  std::endl;
                      Line = actualDataObject->getData();
                      fileObject.write(reinterpret_cast<char *>(&Line), sizeof(Line));
                  });
    fileObject.close();
    return true;
}