// isa.h
#ifndef ISA_H
#define ISA_H

#include <stdint.h>
#include <isa_if.h>
#include <operand.h>


//Blue Print
typedef struct {
    const char *memonic; 
    uint8_t opcode;   
    ISA_type instruction_type;
    void (*EXE)(void *operand);         // run time isa exe function pointer
}ISA_t;

//statically defined instructions for all 16 of them 
extern const ISA_t ISA_LUT[ISA_OP_COUNT];

//Ins fetch by the CPU, operand is resolved.
typedef struct {
    uint8_t opcode;
    union {
        OperandR r;
        OperandI i;
        OperandJ j;
    } operand;
    const ISA_t *entry;  // points to isa_table[opcode]
}ISA_rt;


#endif //isa.h


