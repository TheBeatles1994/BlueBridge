# 八大排序算法对比
![](八大排序算法对比.png)

# 快排时间复杂度

1. 最优情况下，每次都是一半一半往下进行，此时时间复杂度为O(nlogn)
2. 在最坏的情况下，待排序的序列为正序或者逆序，每次划分只得到一个比上一次划分少一个记录的子序列。如果递归树画出来，它就是一棵斜树。如果递归树画出来，它就是一棵斜树。
3. 最坏情况的解决思路是：partion函数使用随机定位（或者取三种中的任意一个数，并将中间数与第一个数交换）