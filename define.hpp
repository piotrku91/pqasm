enum class opCodes : uint_fast8_t
{
    MOV = 0b00001,
};

enum class operandsCodes : uint_fast8_t
{
    RegisterAfromPointerContent = 0b000,
    RegisterBfromPointerContent = 0b001,
    RegisterAfromOperand = 0b100,
    RegisterBfromOperand = 0b101,
    StoreInRAMfromRegisterA = 0b110,
    StoreInRAMfromRegisterB = 0b111
};

enum class AnalyzeErrors
{
    OK,
    UnknownCommand,
    SyntaxError,
    VariableOverflow
};