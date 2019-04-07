#include <math.h>
#include <stdio.h>
#include <iostream>

const int maxn = 99999;
bool not_prime[maxn];
int prime[maxn / 2], cnt;

void init() {
  memset(not_prime, 0, sizeof(not_prime));
  for (int i = 2; i < maxn; i++) {
    if (!not_prime[i]) prime[cnt++] = i;
    for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
      not_prime[i * prime[j]] = 1;
      if (!(i % prime[j])) break;
    }
  }
}
int main(int argc, char const *argv[]) {
  init();
  for (size_t i = 0; i < cnt; i++) {
    for (size_t j = 0; j < cnt; j++) {
      //   if ((uint64_t)prime[i] * (uint64_t)prime[j] == 7140229933) {
      //     printf("x=%d y=%d\n", prime[i], prime[j]);
      //     return 0;
      //   }
      if ((uint64_t)prime[i] * (uint64_t)prime[j] / 1000 == 6541367) {
        printf("x=%d y=%d\n", prime[i], prime[j]);
      }
    }
  }
  return 0;
}