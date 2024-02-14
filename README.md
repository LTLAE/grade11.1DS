GZHU grade 11 data structure experiments personal backup  
====
This repository is created for personal backup.  
Highly NOT recommand using codes in this repo to submit homework.  

experiment 1  
---
* 1.1 线性表的链表实现：遍历、查找、插入、删除、翻转  
（1）用随机函数生成10个3位整数（100~999），把这些整数存于链表中  
（2）输出链表的内容   
（3）读入一个整数，查看该整数是否在表中，若在，输出其位置（首位置为1）    
（4）读入一个整数，以及要插入的位置，把该整数插入到链表中，输出链表的内容（要求判断输入的位置是否合理）   
（5）读入一个整数，若该整数在链表里，删除该整数，输出链表的内容  
（6）把链表的内容翻转，输出链表的内容    
* 1.2 栈的链式存储结构实现：入栈、出栈  
（1）用随机函数生成10个3位整数（100~999），把这些整数应用入栈操作存于堆栈中，在入栈接口处设置断点①，按“F5”启动调试，按“F10”逐句执行，直到数据全部入栈。程序暂停时观察栈顶数据和栈顶位置   
（2）应用出栈操作输出堆栈的内容，在出栈接口处设置断点②，按“F5”启动调试，按“F10”逐句执行，直到所有数据完全出栈，程序暂停时观察栈顶数据和栈顶位置的变化  
* 1.3 队列的链式存储结构的实现：入队、出队  
（1）用随机函数生成10个3位整数（100~999），把这些整数应用入队操作存于队列中  
（2）输出队列的内容  
（3）把队列的内容翻转，应用出队操作输出队列的内容  
* 1.4 线性表、栈和队列的应用实现  
&nbsp;&nbsp;1.4.1 用随机函数生成10个3位整数（100~999），把这些整数存于单链表中，然后读入一个整数，以该值为基准把单链表分割为两部分，所有小于该值的结点排在大于或等于该值的结点之前。   
&nbsp;&nbsp;1.4.2 假设一个字符串中包含的圆括号 ( )可以按任意次序嵌套使用。编写判别给定表达式中所含括号是否正确配对的算法，如果是合法嵌套则返回为true，如果是不合法嵌套则返回为false。   
&nbsp;&nbsp;1.4.3 用栈求解迷宫从入口到出口的所有路径。   
&nbsp;&nbsp;1.4.4 用队列求解迷宫从入口到出口的最短路径。

experiment 2 NOT DONE YET  
---
* 1 二叉树的基本操作算法实现  
（1）利用二叉树字符串创建二叉树的二叉链式存储结构：A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))  
（2）输出该二叉树  
（3）输出‘H’节点的左、右孩子结点值  
（4）输出该二叉树的结点个数、叶子结点个数、二叉树的度和高度  
* 2 二叉树的各种遍历算法实现  
&nbsp;&nbsp;实现上述二叉树的先序、中序和后序遍历的递归和非递归算法  
* 3 线索二叉树的遍历   
&nbsp;&nbsp;中序线索化上述二叉树并找出根结点的前驱和后继   
* 4 构造哈夫曼树和哈夫曼编码的算法实现  
&nbsp;&nbsp;统计下面一段英文的不同字符个数和每个字符的出现频率，利用统计数据构造构造哈夫曼树和哈夫曼编码。要求：利用构造的哈夫曼编码对下文进行压缩和解压后，与原文一样

>The Chinese official said he viewed the Trump Presidency not as an aberration but as the product of a failing political system. This jibes with other accounts. The Chinese leadership believes that the United States, and Western democracies in general, haven’t risen to the challenge of a globalized economy, which necessitates big changes in production patterns, as well as major upgrades in education and public infrastructure. In Trump and Trumpism, the Chinese see an inevitable backlash to this failure.

**Here, I don't know anything while have nothing to say about the paragraph above. It just the requirment of the experiment.**

experiment 3  
---
* 1 图的邻接表和邻接矩阵存储  
&nbsp;&nbsp;建立下图的邻接表或邻接矩阵，并输出之；  
<img width="215" alt="image" src="https://github.com/Endermen359872/grade11DS/assets/78783001/d4852ec6-f1ff-40c4-9642-903a9163b9be"><br>
* 2 图的各种遍历算法实现  
&nbsp;&nbsp;以0结点为起点实现上述图的深度优先和广度优先遍历算法；  
* 3 最小生成树的算法实现  
&nbsp;&nbsp;利用普里姆（Prim）算法或克鲁斯卡尔(Kruskal)算法求上图的最小生成树，算法实现代码必须有注释。  
* 4 最短路径的算法实现  
&nbsp;&nbsp;利用狄克斯特拉（Dijkstra）算法求上图中0结点到其它结点的最短路径，算法实现代码必须有注释。  

experiment 4  
---
* 1 各种排序算法的实现  
&nbsp;&nbsp;用随机函数生成16个2位正整数（10~99），实现直接插入排序、选择排序、冒泡排序、双向冒泡排序、快速排序、堆排序、二路归并排序算法，输出排序中间过程、统计关键字的比较次数和记录的移动次数。
* 2 各种查找算法实现  
（1）顺序查找：使用数组或链表结构。用随机函数生成16个不重复的字母（’a’~’z’），键盘输入待查找的字母，返回查找成功与否，若成功则返回该字母所在的位置（序号），并计算比较次数。  
（2）折半查找：用数组实现，查找前元素先排序。计算比较次数。分别用查找成功、不成功进行测试。  
（3）二叉排序树：手工输入10个字母，生成一棵二叉排序树，用递归算法打印树结构或分别输出先序和中序遍历序列以确认其结构。键盘输入待查找的字母，计算比较次数。分别用查找成功、不成功进行测试。  

Course design  
---
* 通讯录管理系统设计（难度系数 1.4）  
目前手机电话、qq、微信等应用中都有通讯录，请设计一个通讯录管理系统。通讯者信息包括姓名、电话、qq号、微信号、email地址等内容。请实现如下功能：  
（1） 通讯录的建立（并按照姓氏的第一个字母排序）；  
（2） 通讯者信息的插入（并能够检查重复者）；  
（3） 通讯者信息的查询（按照姓名查询）；  
（4） 通讯者信息的修改；  
（5） 通讯者信息的删除；  
（6） 通讯者信息的输出；  
（7） 退出管理系统。  
* 基本要求  
设计合适的数据结构和算法编写程序完成上述功能，并具有主控菜单，能够按照菜单选项进行功能操作。
