PROBLREM: https://leetcode.com/problems/decode-ways/
/*
FEEDBACK (KYU NI HUA)
at first mere se ye sawal ni hua


1.given a string of numbers....mujhe samjh ni aa raha ki uske corresponding possible number combination kaise generate karen
eg for 226 ...we can generate (2,2,6) ,(22,6) , (6,22)
2.for a given value how to get its corresponding key in a map
*/



/*OSERVATIONS
kind of backtracking question bol sakte ho
1.recursion lag raha yahan pe .....  now the question is ye kaise pata chala....
A.coz for every element in string we have "choice" ki usko len ki ni.....so jab bhi haamare pass choice ho then think about recursion
B.question me bola hai return the number of ways to decode it.....so jab bhi no of ways ki bat ho think about recursion 👀
*/

