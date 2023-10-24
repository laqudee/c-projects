// 通过指针获取zippo的信息
#include <stdio.h>

int main(void)
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    int(*pz)[2];
    pz = zippo;
    printf("  pz = %p,   pz + 1 = %p\n", pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    printf(" *pz = %p,  *pz + 1 = %p\n", *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf(" *pz[0] = %d\n", *pz[0]);
    printf("  **pz = %d\n", **pz);
    printf("    pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));

    return 0;
}

/** result
  pz = 00000051939ffa00,   pz + 1 = 00000051939ffa08
pz[0] = 00000051939ffa00, pz[0] + 1 = 00000051939ffa04
 *pz = 00000051939ffa00,  *pz + 1 = 00000051939ffa04
pz[0][0] = 2
 *pz[0] = 2
  **pz = 2
    pz[2][1] = 3
*(*(pz+2) + 1) = 3
*/

/*
zippo[m][n] == *(*(zippo + m) + n)
pz[m][n] == *(*pz + m) + n)
*/