//��ʵ�������������ֱ��������л��ͷ����л�������

// ʹ�� ostringstream �� istringstream
// ostringstream �൱�ڴ���һ����������Ȼ�����ͨ�� to_str() תΪstring����
// istringstream ���԰�һ���ַ�����Ȼ���Կո�Ϊ�ָ����Ѹ��зָ�����

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
        int i = 0; // ����ָ�򸸽ڵ�
        int j = 1; // ����ָ���ӽڵ�
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
һ���Ƚ�������Ĺ��� 
������һ������
���뽫���з��س��� 
*/ 

/*
Ҳ���Ա��һ���ȱ����У���ͨ�����н��н���
*/ 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        stack<TreeNode *>s;
        s.push(root);
        TreeNode *t;
        // ������� 
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
    // �������� 
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
