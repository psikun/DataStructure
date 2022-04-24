/**
* @author: SiKun
* @date: 2022/4/24 14:04
* @description: KMP匹配算法
*/

#define MAXLEN 255     // 定义串的最大长度
typedef struct {
    char ch[MAXLEN];   // 每个分量存储一个字符
    int length;        // 串的实际长度
} String;


/**
 * 获取next数组
 * @param T 模式串
 * @param next 引用传递，next数组
 */
void get_next(String T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            next[i] = j;        // 若pi=pj，则next[j+1]=next[j]+1
        } else {
            j = next[j];        // 否则令j = next[j]，循环继续
        }
    }
}

/**
 * 获取nextval数组
 * @param T 模式串
 * @param nextval   引用传递，nextval数组
 */
void get_nextval(String T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            if (T.ch[i] != T.ch[j]) {
                nextval[i] = j;
            } else {
                nextval[i] = nextval[j];
            }
        } else {
            j = nextval[j];
        }
    }

}


/**
 * KMP算法,O(m+n)
 * @param S 主串
 * @param T 模式串
 * @param next next数组
 * @return 下标
 */
int Index_KMP(String S, String T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;                                // 继续比较后续字符串
            j++;
        } else {
            j = next[j];                        // 模式串向右移动
        }
    }
    if (j > T.length) {
        return i - T.length;                    // 匹配成功
    } else {
        return 0;
    }
}