//
//  main.c
//  算法Demo
//
//  Created by 刘红波 on 2017/4/5.
//  Copyright © 2017年 flex. All rights reserved.
//

#include <stdio.h>

/* 快速排序*/

//int a[101],n;//定义全局变量，这两个变量需要在子函数中使用
////从小到大
//void quicksort(int left,int right){
//    int i,j,t,temp;
//    if (left > right) {
//        return;
//    }
//    temp = a[left];//temp存的就是基准数
//    i = left;
//    j = right;
//    while (i != j) {
//        //顺序很重要，要先从右往左找 比基准数小
//        while (a[j]>= temp && i< j) {
//            j--;
//        }
//        
//        //在从左往右找 比基准数大
//        while (a[i] <= temp && i<j) {
//            i++;
//        }
//        
//        //交换两个数在数组中的位置 在哨兵 i 和 j没有相遇的时候
//        if(i < j){
//            t = a[i];
//            a[i] = a[j];
//            a[j] = t;
//        }
//        
//    }
//    
//    //最终让基准数归位
//    a[left] = a[i];
//    a[i] = temp;
//    
//    quicksort(left, i-1);//继续处理左边的，这是一个递归的过程
//    quicksort(i+1, right);
//}

//int i;
////读入数据
//scanf("%d",&n);
//for(i=0;i<=n-1;i++)
//scanf("%d",&a[i]);
//
//quicksort(0,n-1); //快速排序调用
////输出排序后的结果
//for(i=0;i<=n-1;i++)
//printf("%d ",a[i]);
//getchar();getchar();

/*
void QQHaoma(){
    int q[102] = {0,6,3,1,7,5,8,9,2,4},head,tail;
    //初始化 队列
    head = 1;
    tail = 10;//队列中已经有9个元素了,tail指向队尾的后一个位置
    while (head < tail) { //当队列不为空的时候执行
        //打印队首并将队首出队
        printf("%d ",q[head]);
        head++;
        
        //先将新队首的数添加到队尾
        q[tail] = q[head];
        tail++;
        
        //再将队首出队
        head++;
    }
     getchar();getchar();
}
 */

/*
 队列的实现
void queueDemo(){
    struct queue {
        int data[100];//队列的主题，用来存储内容
        int head;//头部
        int tail; //对列尾部
    };
    
    struct queue q;
    int i;
    //初始化队列
    q.head = 1;
    q.tail = 1;
    for (i = 1; i<=9; i++) {
        //依次向队列中插入9个数
        scanf("%d",&q.data[q.tail]);
        q.tail++;
    }
    
    while (q.head < q.tail) {
        //打印队首并将队首出对
        printf("%d ",q.data[q.head]);
        q.head++;
        
        //将新对首的数据添加到队列尾部
        q.data[q.tail] = q.data[q.head];
        q.tail++;
        //再将对首出对
        q.head++;
    }
    
    getchar();getchar();
    
}
*/
/*
void isHuiWenZiFu(){//是否是回文字符
    char a[101],s[101];
    int i,len,mid,next,top;
    gets(a);//读入一行字符串
    len = strlen(a);
    mid = len/2 -1;//求字符串的中点
    top = -1;//栈初始化
    //将mid的前的字符一次入栈
    for(i = 0; i<= mid ; i++){
        top +=1;
        s[top] = a[i];
    }
    //判断字符串的长度是奇数还是偶数 并找出需要进行字符匹配的起始下标
    if(len%2 == 0){
        next = mid + 1;
    }else{
        next = mid + 2;
    }
    //开始匹配
    for(i= next; i<= len - 1; i++){
        if (a[i] != s[top]) {
            break;
        }
        top--;
    }
    
    //如果top的值是0 择说明栈内所欲的字符都是一一匹配了
    if(top < 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}
 */

void jieZhuGanGame(){
    //创建一个栈
    struct stack{
        int data[10];
        int top;
    };
    //创建一个队列
    struct queue{
        int data[1000];
        int head;
        int tail;
    };
    
    struct queue q1,q2;
    struct stack s;
    int i,t;
    int book[10];
    //初始化队列q1 和 q2 为空 此时两人 手中还没有牌
    q1.head = 1; q1.tail = 1;
    q2.head = 1; q2.tail = 1;
    //初始化栈 s为空 最开始的时候桌上也没有牌
    s.top = 0;
    //初始化用来标记数组,用来标记哪些牌已经在桌上
    for(i = 1;i<=9;i++){
        book[i] = 0;
    }
    
    //依次向队列中插入6个数
    //小哼手上的6张牌
    for (i=1;i<=6;i++) {
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }
    
    //小哈手上的6张牌
    for(i = 1;i<=6; i++){
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    
    while (q1.head < q1.tail && q2.head < q2.tail) {//当队列不为空时执行循环
        t = q1.data[q1.head];//小哼出一张牌
        //判断小哼当前打出的牌是否能赢牌
        if(book[t] == 0){//表明桌面上没有牌面是t的牌
            //小哼此轮没有赢牌
            q1.head++;//打出了一张牌
            s.top++;
            s.data[s.top] = t;//再把打出去的牌放到桌面上 即入栈
            book[t] = 1;//标记桌上现在已经有牌面是t的牌
        }else{
            //小哼此轮可以赢牌
            q1.head++;//小哼已经打出一张牌，所以要把打出的牌出队
            q1.data[q1.tail] = t;//紧接着把打出的牌放贷手中牌的末尾
            q1.tail++;
            while (s.data[s.top] != t) {//把桌面上的牌放到手中牌的末尾
                book[s.data[s.top]] = 0;//取消标记
                q1.data[q1.tail] = s.data[s.top];//依次放入对尾
                q1.tail++;
                s.top--;//栈中少了一张牌，所以栈顶要减一
            }
        }
        
        t = q2.data[q2.head];//小哈出一张牌
        //判断小哈当前打出牌是否能赢
        if(book[t] == 0){//表明桌面上没有牌面为t的牌
            //小哈此轮没有赢牌
            q2.head++;//把牌打出 出对
            s.top++;
            s.data[s.top] = t;//打出的牌到桌面上 入栈
            book[t] = 1;//标记桌面上有了这张牌
        }else{
            //小哈此轮可以赢牌
            q2.head++;//小哈已经打出一张牌，所以要把打出的牌出队
            q2.data[q2.tail] = t;//紧接着把打出的牌放到手中牌的末尾
            q2.tail++;
            while(s.data[s.top]!=t) //把桌上可以赢得的牌依次放到手中牌的 尾
            {
                book[s.data[s.top]]=0;//取消标记
                q2.data[q2.tail]=s.data[s.top];//依次放入队尾
                q2.tail++;
                s.top--;
            }
            
        }

    }
    
    
    
    if(q2.head==q2.tail)
    {
        printf("小哼win\n");
        printf("小哼当前手中的牌是");
        for(i=q1.head;i<=q1.tail-1;i++){
            printf(" %d",q1.data[i]);
        }
        if(s.top>0) //如果桌上有牌则依次输出桌上的牌
        {
            printf("\n桌上的牌是");
            for(i=1;i<=s.top;i++)
                printf(" %d",s.data[i]);
        }else{
            printf("\n桌上已经没有牌了");
        }
    }else{
        printf("小哈win\n");
        printf("小哈当前手中的牌是");
        for(i=q2.head;i<=q2.tail-1;i++){
            printf(" %d",q2.data[i]);
        }
        if(s.top>0) //如果桌上有牌则依次输出桌上的牌
        {
            printf("\n桌上的牌是");
            for(i=1;i<=s.top;i++)
                printf(" %d",s.data[i]);
        }else{
            printf("\n桌上已经没有牌了");
        }

    }
     getchar();getchar();
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    QQ号码算法 仿队列
//    QQHaoma();
    
    //回文字符
//    isHuiWenZiFu();
    
    //接竹杆
    jieZhuGanGame();
      return 0;
}

/*
///桶排序  时间复杂度 O（m+n）
 
 
int book[1001],i,j,t,n;
for (i = 0; i <= 1000; i++) {
    book[i] = 0;
}

scanf("%d",&n);//输入一个数n 表示接下来有n个数

for(i = 1; i<= n ;i++){//读入n 个数
    scanf("%d",&t);//把每一个数读到t中
    book[t]++ ;//进行计数，对编号为t的桶放入一个小旗子
}

for(i = 1000;i>0;i--){//一次判断编号是1000--0的桶
    for(j = 1;j<=book[i];j++){ //出现了几次标记 就将桶的编号打印几次
        printf("%d",i);
    }
}

getchar();
getchar();
 */


/*
 
 ///冒泡排序  时间复杂度 O(n的平方)
 
 int a[100],i,j,t,n;
 scanf("%d",&n); //输入一个数n 表示接下来有n个数
 for (i = 1; i <= n; i++) { //循环读入n个数到数组a中
 scanf("%d",&a[i]);
 }
 for (i =1; i<= n-1; i++) { //n个数只进行 n-1次排序
 
 for(j = 1;j<=n-i;j++){ //从第1位开始比较直到最后一个尚未归位的数
 
 if(a[j] > a[j+1]){  //比较大小并交换
 t = a[j];
 a[j] = a[j+1];
 a[j+1] = t;
 }
 }
 }
 
 
 for(i=1;i<=n;i++) //输出结果
 printf("%d ",a[i]);
 getchar();getchar();

 
*/

/*
 冒泡 学生排序 自己改进 从零开始
 
 struct student {
 char name[21];
 char score;
 };//建立一个存储学信息的结构体
 struct student a[100],t;
 int i,j,n;
 scanf("%d",&n);
 for (i = 0;  i<= n-1; i++) {
 scanf("%s %s",a[i].name,&a[i].score);
 }
 for (i=1; i<=n-1; i++) { //一共需要几个数归为
 for (j=0; j<n-i; j++) { //归为的时候要经过几次比较
 if (a[j].score < a[j+1].score) {
 t = a[j];
 a[j] = a[j+1];
 a[j+1] = t;
 }
 }
 }
 
 for(i=0;i<=n-1;i++)//输出人名
 printf("%s\n",a[i].name);
 getchar();getchar();

 
 */
