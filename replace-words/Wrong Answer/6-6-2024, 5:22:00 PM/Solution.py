// https://leetcode.com/problems/replace-words

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        book = {}
        for word in dictionary: 
            book[word] = True

        ans = []
        words = sentence.split()
        for word in words:
            done = False
            for i in range(len(word)):
                if word[0:i] in book:
                    ans += word[0:i]
                    done = True

            if not done:
                ans += word

        return ' '.join(ans)