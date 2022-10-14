#  密码学第一次作业
  
##  1.
  
###  （a）
  
  
1. **shift:**
  
   **Gen:** chooses a uniform <img src="https://latex.codecogs.com/gif.latex?k"/> depend on security parameter
  
   **Enc:** <img src="https://latex.codecogs.com/gif.latex?c_i%20=%20(m_i%20+%20k)&#x5C;;%20mod%20&#x5C;;%20256"/> 
  
   **Dec:** <img src="https://latex.codecogs.com/gif.latex?m_i%20=%20(c_i%20-%20k)&#x5C;;%20mod%20&#x5C;;%20256"/>
  
2. **Vigenere ciphers**
  
   **Gen:** Choose a random period: this can be chosen uniformly in a fixed set of some size, or it can be chosen according to some valid probability distribution over the integers (e.g., assign the length <img src="https://latex.codecogs.com/gif.latex?5+i"/> with probability <img src="https://latex.codecogs.com/gif.latex?2^{-i}"/>). Denote the chosen period by <img src="https://latex.codecogs.com/gif.latex?t"/>. For <img src="https://latex.codecogs.com/gif.latex?i=0,...,t-1"/> choose uniform <img src="https://latex.codecogs.com/gif.latex?k_i"/> in <img src="https://latex.codecogs.com/gif.latex?&#x5C;{1,...,255&#x5C;}"/>. Output the key <img src="https://latex.codecogs.com/gif.latex?k=k_0,...k_{t-1}"/>
  
   **Enc:** Given a plaintext <img src="https://latex.codecogs.com/gif.latex?p%20=%20p_0,...,%20p_n"/> and a key <img src="https://latex.codecogs.com/gif.latex?k%20=%20k_0,...,k_{t−1}"/>,set <img src="https://latex.codecogs.com/gif.latex?c_i%20:=%20[p_i%20+%20k_i&#x5C;;mod%20&#x5C;;t]&#x5C;;%20mod&#x5C;%20256]"/>. Output <img src="https://latex.codecogs.com/gif.latex?c_0,...c_n"/>.
  
   **Dec:** Given a ciphertext <img src="https://latex.codecogs.com/gif.latex?c_0,...c_n"/> and a key  , set <img src="https://latex.codecogs.com/gif.latex?p_i%20:=%20[c_i%20-%20k_i&#x5C;;mod%20&#x5C;;t]&#x5C;;%20mod&#x5C;%20256]"/>. Output <img src="https://latex.codecogs.com/gif.latex?p%20=%20p_0,...,%20p_n"/>
  
###  （b）
  
  
1. **shift:**
  
   Ask for the encryption of any plaintext character <img src="https://latex.codecogs.com/gif.latex?p"/> and let <img src="https://latex.codecogs.com/gif.latex?c"/> be the ciphertext character returned; the key is simply <img src="https://latex.codecogs.com/gif.latex?k%20:=%20[c%20−p%20&#x5C;;mod&#x5C;;%20256]"/>.
  
2. **Vigenere ciphers**
  
   If the period <img src="https://latex.codecogs.com/gif.latex?t"/> is known then the encryption of a plaintext of length <img src="https://latex.codecogs.com/gif.latex?t"/> (consecutive) suffices to recover the entire key.
  
##  2.
  
  
Encryption scheme <img src="https://latex.codecogs.com/gif.latex?Π"/> is perfectly secret,so <img src="https://latex.codecogs.com/gif.latex?Π"/> is indistinguishable.
Thus, we have <img src="https://latex.codecogs.com/gif.latex?Pr[M%20=%20m%20|C%20=%20c]%20%20=%20Pr[M%20=%20m]"/> and <img src="https://latex.codecogs.com/gif.latex?Pr[M%20=%20m&#x27;%20|C%20=%20c]%20%20=%20Pr[M%20=%20m&#x27;]"/>
  
every message <img src="https://latex.codecogs.com/gif.latex?m,m&#x27;%20∈M"/>,we can get <img src="https://latex.codecogs.com/gif.latex?Pr[M%20=%20m]=Pr[M%20=%20m&#x27;]"/>
  
So <img src="https://latex.codecogs.com/gif.latex?Pr[M=m|C=c]=Pr[M=m&#x27;|C=c]"/>
  
##  3.
  
  
###  （a）
  
  
Perfect security equals <img src="https://latex.codecogs.com/gif.latex?Pr[Enc_K(M%20=%20m)=c]=%20Pr[Enc_K(M%20=%20m&#x27;)=c]"/>
  
If the message is <img src="https://latex.codecogs.com/gif.latex?0"/>, then the ciphertext is <img src="https://latex.codecogs.com/gif.latex?0"/> if and only if <img src="https://latex.codecogs.com/gif.latex?k%20∈{0,%205}"/>. So <img src="https://latex.codecogs.com/gif.latex?Pr[Enc_K%20(0)%20=%200]%20=%201&#x2F;3"/>. If the message is <img src="https://latex.codecogs.com/gif.latex?1"/>, then the ciphertext is <img src="https://latex.codecogs.com/gif.latex?0"/> if and only if <img src="https://latex.codecogs.com/gif.latex?k%20=%204"/>. So
<img src="https://latex.codecogs.com/gif.latex?Pr[Enc_K(1)=0]=1&#x2F;6&#x5C;neq%20Pr[Enc_K(0)=0]"/>
###  （b）
  
  
Prove that this is perfectly secret by analogy with the one-time pad. 
  
##  4.
  
  
（a）Define <img src="https://latex.codecogs.com/gif.latex?A"/> as follows: <img src="https://latex.codecogs.com/gif.latex?A"/> outputs <img src="https://latex.codecogs.com/gif.latex?m_0%20=%20aab"/> and <img src="https://latex.codecogs.com/gif.latex?m_1%20=%20abb"/>. When given a ciphertext <img src="https://latex.codecogs.com/gif.latex?c"/>, it outputs <img src="https://latex.codecogs.com/gif.latex?0"/> if the first character of <img src="https://latex.codecogs.com/gif.latex?c"/> is the same as the second character of <img src="https://latex.codecogs.com/gif.latex?c"/>, and outputs <img src="https://latex.codecogs.com/gif.latex?1"/> otherwise. Compute <img src="https://latex.codecogs.com/gif.latex?Pr[PrivK^{eav}_{A,Π}%20=%201]"/>.
  
（b）Construct and analyze an adversary <img src="https://latex.codecogs.com/gif.latex?A^′"/> for which <img src="https://latex.codecogs.com/gif.latex?Pr[PrivK^{eav}_{A&#x27;,Π}%20=%201]"/> is greater than your answer from part (a).
  
##  5
  
  
If <img src="https://latex.codecogs.com/gif.latex?s=0^n"/>,then <img src="https://latex.codecogs.com/gif.latex?G(s)=0^{2n}"/>, while <img src="https://latex.codecogs.com/gif.latex?TRG(s)%20=%20&#x5C;{0,1&#x5C;}^{2n}"/>,  for the attacker, it is no indistinguishable . so it is no a pseudorandom genenerator.
  
##  6
  
  
（a）<img src="https://latex.codecogs.com/gif.latex?F^′"/> is a pseudorandom function. A formal proof is omitted, butrelies on the observation that distinct queries to <img src="https://latex.codecogs.com/gif.latex?F^′_k"/> result in distinct
queries to <img src="https://latex.codecogs.com/gif.latex?F_k"/>
  
（b）<img src="https://latex.codecogs.com/gif.latex?F^′"/> is not a pseudorandom function. To see this, consider queryingon the two inputs <img src="https://latex.codecogs.com/gif.latex?0^{n−1}"/> and <img src="https://latex.codecogs.com/gif.latex?0^{n−2}1"/>. We have
<p align="center"><img src="https://latex.codecogs.com/gif.latex?F^′_k(0^{n−1})=F_k(0^n)||F_k(0^{n−1}1)"/></p>  
  
and
<p align="center"><img src="https://latex.codecogs.com/gif.latex?F^′_k(0^{n−2}1)=F_k(0^{n-1}1)||F_k(0^{n−2}1^2)"/></p>  
  
note that the second half of <img src="https://latex.codecogs.com/gif.latex?F^′_k(0^{n−1})"/> is equal to the first half of <img src="https://latex.codecogs.com/gif.latex?F^′_k(0^{n−2}1)"/>.
  
Formally, define the following attacker <img src="https://latex.codecogs.com/gif.latex?A"/> given <img src="https://latex.codecogs.com/gif.latex?1^n"/> and access to some function <img src="https://latex.codecogs.com/gif.latex?g"/>:
  
<u><img src="https://latex.codecogs.com/gif.latex?A^g(1^n):"/></u>
  
+ Query  <img src="https://latex.codecogs.com/gif.latex?y_0%20=%20g(0^{n−1})"/> and <img src="https://latex.codecogs.com/gif.latex?y_1%20=%20g(0^{n−2}1)"/>
+ Output <img src="https://latex.codecogs.com/gif.latex?1"/> if and only if the second half of <img src="https://latex.codecogs.com/gif.latex?y_0"/> is equal to the first half of <img src="https://latex.codecogs.com/gif.latex?y_1"/>
  
As shown above, we have <img src="https://latex.codecogs.com/gif.latex?Pr_{k←&#x5C;{0,1&#x5C;}^n}%20[A^{F^′_k(&#x5C;cdot)}(1^n)%20=%201]%20=%201"/>. But when <img src="https://latex.codecogs.com/gif.latex?g"/> is a random function then <img src="https://latex.codecogs.com/gif.latex?y_0"/> and <img src="https://latex.codecogs.com/gif.latex?y_1"/> are independent, uniform strings of length <img src="https://latex.codecogs.com/gif.latex?2n"/> , and so the probability that the secondhalf of <img src="https://latex.codecogs.com/gif.latex?y_0"/> is equal to the first half of <img src="https://latex.codecogs.com/gif.latex?y_1"/> is exactly <img src="https://latex.codecogs.com/gif.latex?2^{−n}"/>. Thus, <img src="https://latex.codecogs.com/gif.latex?Pr_{f←Func}%20[A^{f(&#x5C;cdot)}(1^n)%20=%201]%20=%202^{−n}"/>, and the difference
<p align="center"><img src="https://latex.codecogs.com/gif.latex?|Pr_{k←&#x5C;{0,1&#x5C;}^n}%20[A^{F^′_k(&#x5C;cdot)}(1^n)%20=%201]%20-Pr_{f←Func}%20[A^{f(&#x5C;cdot)}(1^n)%20=%201]|"/></p>  
  
is not negligible.
  
##  7
  
  
（a）This scheme does not even have indistinguishable encryptions in the presence of an eavesdropper because the ciphertext doesn’t depend on the key. An eavesdropper can easily compute <img src="https://latex.codecogs.com/gif.latex?m"/> from <img src="https://latex.codecogs.com/gif.latex?c%20=%20⟨r,%20s⟩"/> by computing <img src="https://latex.codecogs.com/gif.latex?m%20:=%20G(r)%20⊕s"/>.
  
（b）This scheme has indistinguishable encryptions in the presence of an eavesdropper. To see this, note that <img src="https://latex.codecogs.com/gif.latex?F_k(0^n)"/> is pseudorandom and so a proof of this fact follows from the proof of Theorem 3.18. The scheme is not CPA-secure because encryption is deterministic
  
（c）This scheme is CPA-secure. A proof of this is very similar to the proof of Theorem 3.31 except that Repeat denotes the event that <img src="https://latex.codecogs.com/gif.latex?r−1"/>,<img src="https://latex.codecogs.com/gif.latex?r"/> or <img src="https://latex.codecogs.com/gif.latex?r%20+%201"/> is chosen in another ciphertext.
  