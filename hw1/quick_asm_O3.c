// This code is for 430.322 Project #2
// Student ID        : 20xx - xxxxx
// Student name      :
// Student email     :

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define nMAX 64
#define iMAX 1
#define rMAX 128

#define read_csr(reg) ({uint64_t __tmp; asm volatile ("csrr %0, " #reg : "=r"(__tmp)); __tmp; })

void your_sort(uint32_t array[], int left, int right);

asm(".global your_sort\n\
your_sort:\n\
bge	a1,a2,.sort_13\n\
addi	sp,sp,-48\n\
sd	s1,24(sp)\n\
sd	s2,16(sp)\n\
sd	s3,8(sp)\n\
sd	ra,40(sp)\n\
sd	s0,32(sp)\n\
mv	s2,a2\n\
mv	s3,a0\n\
addiw	s1,a2,1\n\
.sort_9:\n\
	slli	a2,a1,2\n\
	add	a2,s3,a2\n\
	lw	a7,0(a2)\n\
	mv	t3,a2\n\
	mv	a4,s1\n\
	mv	t1,a1\n\
.sort_3:\n\
	addiw	t1,t1,1\n\
	blt	s2,t1,.sort_4\n\
	lw	a5,4(t3)\n\
	bltu	a5,a7,.sort_5\n\
.sort_4:\n\
	addi	a5,a4,-1\n\
	slli	a5,a5,2\n\
	add	a5,s3,a5\n\
	j	.sort_7\n\
.sort_17:\n\
	addi	a5,a5,-4\n\
	bgeu	a7,a3,.sort_6\n\
.sort_7:\n\
	mv	s0,a4\n\
	addiw	a4,a4,-1\n\
	lw	a3,0(a5)\n\
	mv	a6,a5\n\
	ble	a1,a4,.sort_17\n\
.sort_6:\n\
	blt	t1,a4,.sort_18\n\
	lw	a5,0(a2)\n\
	sw	a3,0(a2)\n\
	mv	a0,s3\n\
	addiw	a2,s0,-2\n\
	sw	a5,0(a6)\n\
	call	your_sort\n\
	ble	s2,s0,.sort_19\n\
	mv	a1,s0\n\
	j	.sort_9\n\
.sort_18:\n\
	lw	a5,4(t3)\n\
	sw	a3,4(t3)\n\
	sw	a5,0(a6)\n\
.sort_5:\n\
	addi	t3,t3,4\n\
	j	.sort_3\n\
.sort_19:\n\
	ld	ra,40(sp)\n\
	ld	s0,32(sp)\n\
	ld	s1,24(sp)\n\
	ld	s2,16(sp)\n\
	ld	s3,8(sp)\n\
	addi	sp,sp,48\n\
	jr	ra\n\
.sort_13:\n\
	ret");

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
    your_sort(your_nums, 0, nMAX - 1);
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
