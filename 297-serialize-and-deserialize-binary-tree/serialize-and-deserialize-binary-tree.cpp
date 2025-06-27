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
    void serializeHelper(TreeNode* node, string& data){
        if(!node){
            data += "null,";
            return;
        }
        data += to_string(node->val) + ",";
        serializeHelper(node->left, data);
        serializeHelper(node->right, data);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serializeHelper(root, data);
        return data;
    }

    TreeNode* deserializeHelper(queue<string>& nodes){
        string nodeString = nodes.front();
        nodes.pop();
        if(nodeString == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(nodeString));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string node;
        while(getline(ss, node, ',')) nodes.push(node);
        return deserializeHelper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));