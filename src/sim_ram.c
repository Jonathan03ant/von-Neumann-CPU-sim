#include "sim_ram.h"
#include "ISA.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void init_RAM(RAM *ram)
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        ram->cell[i].value = 0;
        ram->cell[i].free = true;
    }
}

int read_memory_cell(const RAM *ram, int index)
{
    if (index < 0  || index > RAM_SIZE)
    {
        printf("__ERR_readMem: unknown Memory cell index '%d'\n", index);
        return -1;
    }

    return ram->cell[index].value;
}

int write_to_memory_cell(RAM *ram, int index, int value)
{
    if (index < 0  || index > RAM_SIZE)
    {
        printf("__ERR_writeToMem: unknown Memory cell index '%d'\n", index);
        return -1;
    }
    
    ram->cell[index].value = value;
    return 0;
}


void print_RAM(const RAM *ram)
{
    printf("┌─────── SIMULATED RAM ───────┐\n");
    printf("| Addr | Value  | In Use      |\n");
    printf("|------|--------|-------------|\n");

    for (int i = 0; i < RAM_SIZE; i++) {
        printf("| %4d | [%04d] |    %s       |\n",
               i,
               ram->cell[i].value,
               ram->cell[i].free ? "YES" : "NO");
    }

    printf("└─────────────────────────────┘\n");
}

//First fit memory allocation algorithm for now
    // check start = 0, look Ram[0 + program size]
    // if we have in use, skip
        // then try start = 1, look Ram[1 + program size]
int load_program(RAM *ram, const int program[], int size)
{
    // check if RAM has enough available size
        // if not return error
    // get the index of the ram, for now lets assume we neeed a staight cell space(not jumpig)
    // store the program
    // return the first pointer of the program start
}