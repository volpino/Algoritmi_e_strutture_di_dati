#include "lists.h"
#include "test_functions.h"

#define DIM 10

using namespace std;

ListsGraph<int> g = ListsGraph<int>(DIM);

int main() {
  test_functions(g);
}
