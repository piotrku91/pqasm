#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>
#include "DataBlock.hpp"
#include <string>


class filePQAsmManager
{
    private:
    std::vector<std::string> content;
    std::vector<std::shared_ptr<DataBlock>> ProgramData;
    

public:
    AnalyzeErrors Analyze();
    bool readFileToVector(std::string filename);
    bool saveToBin(const std::string &filename);

    std::vector<std::shared_ptr<DataBlock>>& getProgramData() {return ProgramData;} 
};