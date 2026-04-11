class TrieNode {
    public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i= 0; i<26; i++){
            children[i] = NULL;
        }
        endOfWord = false;
    }
};
class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string word , int j , TrieNode* root){
        TrieNode* curr = root;

        for(int i = j ; i< word.size(); i++){
            char c = word[i];
            if (c == '.'){
                for (auto child : curr->children){
                    if (child != NULL && dfs(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            }else{
                if(curr->children[c-'a'] == NULL){
                    return false;
                }
                curr = curr->children[c-'a'];
            }
        }
        return curr->endOfWord;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int i = c-'a';
            if (curr->children[i] == NULL){
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
        return;
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }


};
