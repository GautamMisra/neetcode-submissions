/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*, Node*>& mp){
        if(mp.count(node))      //if nodes clone exist
            return mp[node];    //return it
        Node* clone=new Node(node->val);     //else make new clone
        mp[node] = clone;       //push clone into map
        for (Node* neighbor : node->neighbors){    //for every neighbour
            clone->neighbors.push_back(dfs(neighbor,mp));  //clone and push into map
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        if(node==nullptr)
            return{};
        return dfs(node, mp);
    }
};
