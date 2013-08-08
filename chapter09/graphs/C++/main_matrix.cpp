#include "matrix.h"
#include "test_functions.h"

#define DIM 10

using namespace std;

MatrixGraph<int> g = MatrixGraph<int>(DIM);

int main() {
  test_functions(g);
}
