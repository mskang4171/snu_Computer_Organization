#include <chrono>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>

#define read_csr(reg) ({unsigned long __tmp; asm volatile ("csrr %0, " #reg : "=r"(__tmp)); __tmp; })

#define rMAX 16 // range of each element in the matrix

using namespace std;

/*  Function 1: MatrixMultiplication8()
    TODO: Optimize matrix-matrix multiplication,
          when the matrix size is [8 x 8].
*/
#ifdef Matrix8
void MatrixMultiplication8(vector<vector<int>> &A,
                           vector<vector<int>> &B,
                           vector<vector<int>> &C)
{
  for (uint32_t i = 0; i < 8; i++)
  {
    for (uint32_t k = 0; k < 8; k++)
    {
      C[i][0] += A[i][k] * B[k][0];
      C[i][1] += A[i][k] * B[k][1];
      C[i][2] += A[i][k] * B[k][2];
      C[i][3] += A[i][k] * B[k][3];
      C[i][4] += A[i][k] * B[k][4];
      C[i][5] += A[i][k] * B[k][5];
      C[i][6] += A[i][k] * B[k][6];
      C[i][7] += A[i][k] * B[k][7];
    }
  }
}
#endif

/*  Function 2: MatrixMultiplication16   
    TODO: Optimize matrix-matrix multiplication,
          when the matrix size is [16 x 16].
*/
#ifdef Matrix16
void MatrixMultiplication16(vector<vector<int>> &A,
                            vector<vector<int>> &B,
                            vector<vector<int>> &C)
{
  for (uint32_t a = 0; a < 16; a += 16)
  {
    for (uint32_t b = 0; b < 16; b += 16)
    {
      for (uint32_t i = 0; i < 16; i++)
      {
        for (uint32_t k = b; k < b + 16; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
          C[i][a + 8] += A[i][k] * B[k][a + 8];
          C[i][a + 9] += A[i][k] * B[k][a + 9];
          C[i][a + 10] += A[i][k] * B[k][a + 10];
          C[i][a + 11] += A[i][k] * B[k][a + 11];
          C[i][a + 12] += A[i][k] * B[k][a + 12];
          C[i][a + 13] += A[i][k] * B[k][a + 13];
          C[i][a + 14] += A[i][k] * B[k][a + 14];
          C[i][a + 15] += A[i][k] * B[k][a + 15];
        }
      }
    }
  }
}
#endif

/*  Function 3: MatrixMultiplication64 
    TODO: Optimize matrix-matrix multiplication,
          when the matrix size is [64 x 64].
*/
#ifdef Matrix64
void MatrixMultiplication64(vector<vector<int>> &A,
                            vector<vector<int>> &B,
                            vector<vector<int>> &C)

{
  for (uint32_t a = 0; a < 64; a += 8)
  {
    for (uint32_t b = 0; b < 64; b += 8)
    {
      for (uint32_t i = 0; i < 64; i++)
      {
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
        i++;
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
        i++;
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
        i++;
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
        i++;
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
        i++;
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
        i++;
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
        i++;
        for (uint32_t k = b; k < b + 8; k++)
        {
          C[i][a] += A[i][k] * B[k][a];
          C[i][a + 1] += A[i][k] * B[k][a + 1];
          C[i][a + 2] += A[i][k] * B[k][a + 2];
          C[i][a + 3] += A[i][k] * B[k][a + 3];
          C[i][a + 4] += A[i][k] * B[k][a + 4];
          C[i][a + 5] += A[i][k] * B[k][a + 5];
          C[i][a + 6] += A[i][k] * B[k][a + 6];
          C[i][a + 7] += A[i][k] * B[k][a + 7];
        }
      }
    }
  }
}

#endif

/* Naive matrix multiplication function as a baseline */
void NaiveMatrixMultiplication(vector<vector<int>> &A,
                               vector<vector<int>> &B,
                               vector<vector<int>> &C)
{
  for (uint32_t i = 0; i < A.size(); i++) // A.size() : A row #
  {
    for (uint32_t j = 0; j < B[0].size(); j++) // B[0].size() : B col #
    {
      for (uint32_t k = 0; k < B.size(); k++) // B.size() : B row(= A col) #
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// Used for checking results between your matrix multiplication and naive matrix multiplication.
void CorrectionCheck(vector<vector<int>> &C_ref, vector<vector<int>> &C)
{
  int temp = 0;
  for (uint32_t i = 0; i < C.size(); i++)
  {
    for (uint32_t j = 0; j < C.size(); j++)
    {
      if (C_ref[i][j] == C[i][j])
        ;
      else
      {
        cout << "wrong " << (int)C.size() << " multiplication terminate program ";
        cout << "C : " << C_ref[i][j] << " , C_your : " << C[i][j];
        cout << " on (i,j) = (" << i << "," << j << ")" << endl;
        temp += 1;
        continue;
      }
    }
  }
  if (temp == 0)
  {
    cout << "Success!! " << endl;
  }
  else
  {
    cout << "Total Error: " << temp << endl;
  }
}

void MatrixMultiplication(vector<vector<int>> &A,
                          vector<vector<int>> &B,
                          vector<vector<int>> &C)
{
  // Print matrix shape
  std::cout << "Start Matrix Multiplication : Optimized" << std::endl;
  std::cout << "[ " << A.size() << " x " << A[0].size() << " ] x [ " << B.size()
            << " x " << B[0].size() << " ] = [ " << C.size() << " x "
            << C[0].size() << " ]" << std::endl;

  uint32_t start_inst, end_inst;
  uint32_t start_cycle, end_cycle;

  switch (A.size())
  {
#ifdef Matrix8
  case 8:
    start_inst = read_csr(instret); // read the current instruction count from instret csr register.
    start_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.
    MatrixMultiplication8(A, B, C);
    end_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.
    end_inst = read_csr(instret); // read the current instruction count from instret csr register.
    break;
#endif
#ifdef Matrix16
  case 16:
    start_inst = read_csr(instret); // read the current instruction count from instret csr register.
    start_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.
    MatrixMultiplication16(A, B, C);
    end_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.
    end_inst = read_csr(instret); // read the current instruction count from instret csr register.
    break;
#endif
#ifdef Matrix64
  case 64:
    start_inst = read_csr(instret); // read the current instruction count from instret csr register.
    start_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.
    MatrixMultiplication64(A, B, C);
    end_cycle = read_csr(cycle);  // read the current cycle from cycle csr register.
    end_inst = read_csr(instret); // read the current instruction count from instret csr register.
    break;
#endif
  default:
    std::cout << "There is a problem with the matrix size. Please "
                 "enter the correct size. Ex: 8, 16, 64."
              << std::endl;
    break;
  }

  std::cout << "Matrix Multiplication done" << std::endl;
  std::cout << "Instruction counts = " << (end_inst - start_inst) << std::endl;
  std::cout << "Execution cycles   = " << (end_cycle - start_cycle) << std::endl;
  std::cout << "IPC = " << ((float)((double)(end_inst - start_inst)) / ((double)(end_cycle - start_cycle))) << std::endl;
}

/* Insert random values into the matrix  */
void randomInit(vector<vector<int>> &data)
{
  srand(0);

  for (int i = 0; i < data.size(); ++i) // data.size(): row size
  {
    for (int j = 0; j < data[i].size(); j++) // data[i].size(): column size
    {
      data[i][j] = rand() % rMAX;
    }
  }
}

int main(int argc, char **argv)
{
  int matrix_size = 0;
  char *option;
  if (argc < 2)
  {
    cout << "Please insert arguments" << endl;
  }
  else
  {
    matrix_size = atoi(argv[1]);
    option = argv[2];
  }

  //-------------------Matrix Declarations--------------------//
  vector<vector<int>> A(matrix_size, vector<int>(matrix_size));
  vector<vector<int>> B(matrix_size, vector<int>(matrix_size));
  vector<vector<int>> C(matrix_size, vector<int>(matrix_size));
  vector<vector<int>> C_ref(matrix_size, vector<int>(matrix_size));

  //---Init---//
  randomInit(A);
  randomInit(B);

  //-----Run Baseline------//
  if (strcmp(option, "all") == 0)
  {
    C_ref.resize(A.size());
    for (uint32_t i = 0; i < A.size(); i++)
    {
      C_ref[i].resize(B[0].size(), 0);
    }
    NaiveMatrixMultiplication(A, B, C_ref);
  }

  //-----Run Optimized------//
  if (strcmp(option, "opt") == 0 || strcmp(option, "all") == 0)
  {
    C.resize(A.size());
    for (uint32_t i = 0; i < A.size(); i++)
    {
      C[i].resize(B[0].size(), 0);
    }
    MatrixMultiplication(A, B, C);
  }

  //-----Functionaliry_Check-----//
  if (strcmp(option, "all") == 0)
  {
    CorrectionCheck(C_ref, C);
  }
  return 0;
}
