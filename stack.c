#include <stdio.h>
#include <stdlib.h>

#define Infile   "incoming.dat"
#define Outfile  "outgoing.dat"
#define intCount 128000  /* 128,000 */

void other_task1() { /*...*/ }
void other_task2() { /*...*/ }

void process_data(const char* infile,
          const char* outfile,
          const unsigned n) {
  int nums[n];
  FILE* input = fopen(infile, "r");
  if (NULL == infile) return;
  FILE* output = fopen(outfile, "w");
  if (NULL == output) {
    fclose(input);
    return;
  }

  fread(nums, n, sizeof(int), input); /* read input data */
  unsigned i;
  for (i = 0; i < n; i++) {
    if (1 == (nums[i] & 0x1))  /* odd parity? */
      nums[i]--;               /* make even */
  }
  fclose(input);               /* close input file */

  fwrite(nums, n, sizeof(int), output);
  fclose(output);
}

int main() {
  process_data(Infile, Outfile, intCount);
  
  /** now perform other tasks **/
  other_task1(); /* automatically released stack storage available */
  other_task2(); /* ditto */
  
  return 0;
}