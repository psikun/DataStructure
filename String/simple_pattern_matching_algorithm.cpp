/**
* @author: SiKun
* @date: 2022/4/24 13:51
* @description: 朴素模式匹配算法
*/

#define MAXLEN 255     // 定义串的最大长度
typedef struct {
    char ch[MAXLEN];   // 每个分量存储一个字符
    int length;        // 串的实际长度
} SString;

/**
 * 朴素模式匹配算法
 * @param S 主串
 * @param T 模式串
 * @return 下标
 */
int index(SString S, SString T) {
    int i = 1, j = 1;       // 两个个子串的指针，从1开始
    while (i <= S.length && j <= T.length) {    // 当两个字符串都没有超出范围时循环
        if (S.ch[i] == T.ch[j]) {               // 当前位置字符相等，指针++；
            i++;
            j++;
        } else {                                // 指针位置不相等，j指针回退到1，i指针回退到主串下一个长度为j的子串开头
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) {                         // 当j超出长度后，说明全部匹配完成，返回第一个字符下标
        return i - T.length;
    } else {
        return 0;                               // 未匹配到，返回0；
    }
}
