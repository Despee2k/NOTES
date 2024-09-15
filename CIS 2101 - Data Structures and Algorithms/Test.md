```c
#include <stdio.h>

int main(void){
  int given = 16;
  int copy = given;
  int result = 0;
  int FSB = 0;
  int pos = 1;
  
  while (given > 0){
    FSB = (given & 1) * pos;
    result += FSB;
    given >>= 1;
    pos *= 10;
  }
  
  printf("Given: %d\n", copy);
  printf("Result: %d\n", result);
  
  return 0;
}
```

```c
#include <stdio.h>

int main(void){
  int given = 8;

  int MSB;
  for(int i = sizeof(int) * 8-1; i >= 0; i--){
    MSB = 1 << i;
    printf("%d", (given & MSB) > 0);
    if(i % 4 == 0) printf(" ");
  }
}
```