enum class opCodes : uint_fast8_t
{
    MOV = 0b00001,
};

enum class operandsCodes : uint_fast8_t
{
    BtoA = 0b000,
    AtoB = 0b001,
    MemToA = 0b010,
    AToMem = 0b011,
    DataToA = 0b100
};