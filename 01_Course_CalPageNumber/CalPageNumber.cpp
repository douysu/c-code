// @author 憨豆酒 YinDou https://github.com/douysu
//
// 算法课程作业（一）：
// 数字统计问题：一本书的页码依次从1开始直到n，计算出全书页码中分别
// 用到多少次数字0,1,2,3,4,5,6,7,8,9
//
// @version1 20200310 YinDou 初次完成题目
// 参考：https://www.w3xue.com/exp/article/20189/1964.html

#include <cmath>
#include <cstdio>

int main() {
    int count[10];
    int i, j, k, L;
    int n, len, m;
    while (scanf_s("%d", &n) != EOF) {
        m = n;
        L = ceil(log10(n + 1));
        for (i = 0; i < 10; i++) 
            count[i] = 0;
        for (j = 0; j < L; j++) {
            len = ceil(log10(m + 1));
            //从高位到低位取个位数的值 
            k = m / pow(10.0, len - 1);
            //从K*len的数值 0-9出现的次数 
            for (i = 0; i < 10; i++) 
                count[i] += k * (len - 1) * pow(10.0, len - 2);
            //在高位小于数值K的数字出现的次数 
            for (i = 0; i < k; i++) 
                count[i] += pow(10.0, len - 1);
            //在高位数值K出现的次数 
            count[k] += m - k * pow(10.0, len - 1) + 1;
            //去掉以计算的高位 
            m = m - k * pow(10.0, len - 1);
        }
        //去掉前导0 
        for (i = 0; i < L; i++)
            count[0] -= pow(10.0, i);
        for (i = 0; i < 10; i++) 
            printf("%d\n", count[i]);
    }
         return 0;
}