// This code is for 430.322 Project #

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define nMAX 64
#define iMAX 1
#define rMAX 128

#define read_csr(reg) ({uint64_t __tmp; asm volatile ("csrr %0, " #reg : "=r"(__tmp)); __tmp; })

void your_sort(uint32_t array[], int n);

asm(".globl	your_sort\n\
your_sort:\n\
	li	a5,1\n\
	ble	a1,a5,.sort_1\n\
	addiw	a7,a1,-1\n\
	addi	a6,a0,4\n\
	li	a1,0\n\
.sort_6:\n\
	lw	a2,0(a6)\n\
	mv	a5,a6\n\
.sort_3:\n\
	lw	a4,-4(a5)\n\
	mv	a3,a5\n\
	bleu	a4,a2,.sort_4\n\
	sw	a4,0(a5)\n\
	addi	a5,a3,-4\n\
	bne	a0,a5,.sort_3\n\
	mv	a3,a0\n\
.sort_4:\n\
	sw	a2,0(a3)\n\
	addiw	a1,a1,1\n\
	addi	a6,a6,4\n\
	bne	a1,a7,.sort_6\n\
.sort_1:\n\
	ret\n\
	.size	your_sort, .-your_sort");

// Reference code (Bubble sort)
void bubble_sort(uint32_t array[])
{
    int i, j;
    uint32_t temp;
    for (i = 0; i < (nMAX - 1); i++)
    {
        for (j = 0; j < (nMAX - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Check the sorted results between
// reference code and your code implemented.
void check(uint32_t array1[], uint32_t array2[])
{
    int i;
    uint32_t temp = 0;
    for (i = 0; i < nMAX; i++)
    {
        if (array1[i] != array2[i])
        {
            printf("Error : Wrong at array random_num[%d]\n", i);
            temp = 1;
        }
    }
    if (temp == 0)
    {
        printf("Success!\n");
    }
}

int main()
{
    int i, j;
    uint32_t random_nums[nMAX] = {
        0,
    };
    uint32_t your_nums[nMAX] = {
        0,
    };

    uint64_t start_inst, end_inst;
    uint64_t start_cycle, end_cycle;

    srand(0);
    for (i = 0; i < iMAX; i++)
    {
        for (j = 0; j < nMAX; j++)
        {
            random_nums[j] = rand() % rMAX;
            your_nums[j] = random_nums[j];
        }
        bubble_sort(random_nums);

        start_inst = read_csr(instret); // read the current instruction count from instret csr register.
        start_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.

        //** run your function **//
        your_sort(your_nums, nMAX);
        //***********************//

        end_inst = read_csr(instret); // read the current instruction count from instret csr register.
        end_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.

        printf("Instruction counts = %ld\n", end_inst - start_inst);
        printf("Execution cycles = %ld\n", end_cycle - start_cycle);
        printf("IPC = %f\n", ((float)((double)(end_inst - start_inst)) / ((double)(end_cycle - start_cycle))));

        check(random_nums, your_nums);
    }

    return 0;
}
