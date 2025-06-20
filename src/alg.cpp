// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzMaxValue(uint64_t num) {
  uint64_t max_value = num;
    
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = num * 3 + 1;
    }
        
    if (num > max_value) {
      max_value = num;
    }
  }
  return max_value;
}

uint64_t collatzLen(uint64_t num) {
  unsigned int length = 1; 

  while (num != 1) {
    if (num % 2 == 0) (num /= 2);
    else (num = num * 3 + 1);
    length++;
  }
  return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  if (maxlen == nullptr || lbound < 2 || lbound > rbound) {
    *maxlen = 0;
    return 0;
  }

  unsigned int max_length = 0;
  unsigned int result_num = 0;

  for (uint64_t num = lbound; num <= rbound; ++num) {
    unsigned int current_len = collatzLen(num);

    if (current_len > max_length) {
      max_length = current_len;
      result_num = num;
    }
  }

  *maxlen = max_length;
  return result_num;
}

