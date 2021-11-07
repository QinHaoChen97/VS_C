#
# @lc app=leetcode.cn id=208 lang=python3
#
# [208] 实现 Trie (前缀树)
#

# @lc code=start
class Trie:

    def __init__(self):
        self.children=[None]*26 #26个英文字母
        self.isend=False

    def insert(self, word: str) -> None:
        node=self
        for s in word:
            ch=ord(s)-ord('a')
            if not node.children[ch]: #不存在则创建新的
                node.children[ch]=Trie()
            node=node.children[ch]
        node.isend=True #说明到当前字母可以组成一个单词

    def search_pre(self,prefix: str) -> "Trie":
        node=self
        for s in prefix:
            ch=ord(s)-ord('a')
            if not node.children[ch]: #存在则继续搜索，否则返回
                return None
            node=node.children[ch]
        return node #当前前缀存在

    def search(self, word: str) -> bool:
        node=self.search_pre(word)
        if node != None and node.isend==True:
            return True
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        node=self.search_pre(prefix)
        return node != None



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end

