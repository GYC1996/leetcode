//0,1,...,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
//
//例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

// 解题思路
// 0~n-1 中的 n 个数中，指定一个数 m ，删除第一个元素之后， 序列变成如下   ，删除的元素记为 k ，第一个一般为 m - 1 
// 0 1 ... k-1  k+1 k+2 n-1
// 根据规则 把 k + 1 之后的数字移到前面 形成序列如下
// k+1 k+2 ... n-1 0 1 2 ... k-1
// 对这个序列重新做一个映射
// k+1 k+2 ... n-1    0    1    2    ...   k-1
//  0   1     n-k-2                        n-2
// 定义如上的映射为 p(x) = (x - (k+1)) % n
// 逆映射为 p(y) = (y + (k+1)) % n 
// 设置 k = （m-1） % n；
// 因此 p(y) = (y+m) % n 这里的 p(y) 是0 1 - n-1 对应的数字 
// f(n,m)最后剩余的数字一定是 f'(n-1, m) 最后剩余的数字
// 每次递归为删完一个元素之后的数组元素进行递归 
 
//设置删除的元素为 x  x=f(m,n)
 
class Solution {
public:
    int f(int n, int m){
        if (n == 1){
            return 0;
        }
        int x = f(n-1, m);
        return (m + x) % n;
    }
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
}; 
