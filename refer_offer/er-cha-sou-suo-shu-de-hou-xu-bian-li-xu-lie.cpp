//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
//如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同

class Solution {
public:
    bool judge(vector<int>& postorder, int begin, int end){
        int m, i = 0;
        if (begin >= end){
            return true;
        }
        for (i = begin; i < end; i++){
            if (postorder[i] > postorder[end]){
                m = i; // m 为 右子树的起点 
                break;
            }
        }
        for (i = m; i < end && postorder[i] > postorder[end]; i++) ;	 
        return  (i == end) && judge(postorder, begin, m-1) && judge(postorder, m, end-1) ;
    }
    bool verifyPostorder(vector<int>& postorder) {
        int begin = 0;
        int end = postorder.size()-1;
        return judge(postorder, begin, end);
    }
};

/*
二叉搜索树的特点是 左子树小于根节点，右子树大于根节点
末端为根节点，通过对比与根节点的大小定位左右子树 
然后递归判断 
*/
