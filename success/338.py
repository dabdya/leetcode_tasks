class Solution:
    def countBits(self, n: int) -> List[int]:
        """Есть простая идея за время O(nlogn), онованная на переводе десятичного числа
        в двоичное за логарифм. Но есть подход лучше. Пусть f(n) - количество единиц в числе n.
        Теперь достаточно заметить что:
            f(n) = f(n/2) если n делится пополам, и f(n/2)+1 в ином случае. Почему так?
            Если всопмнить способ перевода в двоичную систему счисления, основанную на делении в столбик, то:
            6|2 -> 0
              3|2 -> 1
                1|2 -> 1
                  0
                  
            Здесь легко прослеживается эта идея, а если число бы было 7, то целая часть на втором шаге
            была бы снова 3, но перед этим добавился бы остаток в виде 1, что увеличивает число единиц.
            """
        if n == 0:
            return [0]
        dp = [0]*(n+1)
        dp[1] = 1
        
        for i in range(2,n+1):
            dp[i] = dp[i//2]
            if i % 2 != 0:
                dp[i] += 1
        
        return dp