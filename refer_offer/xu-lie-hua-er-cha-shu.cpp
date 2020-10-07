//请实现两个函数，分别用来序列化和反序列化二叉树

// 使用 ostringstream 和 istringstream
// ostringstream 相当于创建一个输入流，然后可以通过 to_str() 转为string类型
// istringstream 可以绑定一行字符串，然后以空格为分隔符把该行分隔开来

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // if (root == NULL){
        //     return "";
        // }
        queue<TreeNode*>q;
        ostringstream ss;
        q.push(root);
        TreeNode *t;
        while (!q.empty()){
            t = q.front();
            q.pop();
            if (t){
                ss << t->val << " ";
                cout << t->val << " ";
                q.push(t -> left);
                q.push(t -> right);
            }
            else{
                ss << "null ";
                cout << "null ";
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // return NULL;
        istringstream is(data);
        string val;
        vector<TreeNode *>v;
        while (is >> val){
            if (val == "null"){
                v.push_back(NULL);
            }
            else{
                v.push_back(new TreeNode(stoi(val)));
            }
        }
        int i = 0; // 用来指向父节点
        int j = 1; // 用来指向子节点
        for (i = 0; i < v.size(); i++){
            if (v[i] == NULL){
                continue;
            }
            else{
                if (j < v.size())
                    v[i] -> left = v[j++];
                if (j < v.size())
                    v[i] -> right = v[j++];
            }
        }
        return v[0];
    }
};

/*
一个先解码后编码的过程 
解码变成一个序列
编码将序列返回成树 
*/ 

/*
也可以变成一个先变序列，后通过序列进行建树
*/ 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        stack<TreeNode *>s;
        s.push(root);
        TreeNode *t;
        // 先序遍历 
        while (!s.empty()){
            t = s.top();
            s.pop();
            if (t){
                ss << t->val << " ";
                cout << t->val << " ";
                s.push(t -> right);
                s.push(t -> left);
            }
            else{
                ss << "null ";
                cout << "null ";
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    // 建树代码 
    TreeNode* createTree(istringstream & ss){
        TreeNode *root;
        // istringstream ss(data);
        string val;
        ss >> val;
        if (val == "null"){
            root = NULL;
        }
        else{
            root = new TreeNode(stoi(val));
            root -> left = createTree(ss);
            root -> right = createTree(ss);
        }
        return root;
    }
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        string val;
        TreeNode *head = createTree(ss);
        return head;
    }
};
