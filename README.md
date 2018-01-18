# SJTU-OJ
### 1000. A+B Problem
`Description`      
作为所有 Online Judge 的传统题目，你只需读两个整数，输出即可，保证输入的数绝对值不超过1000。      
`Input Format`    
一行,两个空格隔开的整数A,B。    
`Output Format`   
一个数A+B。  
`Sample Input`    

	3 2  
`Sample Output`   

	5  
### 1001. 二哥摘苹果
`题目描述`  
二哥平日喜欢自己种一些东西，并以此为写程序和看电影之外的最大爱好。最近，二哥种的一棵苹果树到了采摘的时候，但是由于二哥身高的限制，有些苹果太高摘不到。于是二哥借来了一个凳子，踩在上面可以摘到更多的苹果。  
二哥是一个懒于行动的人，他想在摘苹果之前知道自己能摘到多少苹果，如果实在太少（苹果树很茂盛，主要是由于身高原因），他宁可坐在树下等苹果自己掉下来砸到头上。  
`输入格式`  
输入共有两行。  
第1行有3个整数，分别表示二哥的身高、凳子的高度和苹果的个数n。  
第2行有n个整数，分别表示每个苹果的高度。  
`输出格式`  
输出一个整数m，表示二哥最多能摘到的苹果的个数为m。  
`说明`  
对于全部数据：高度为1000以下的正整数，苹果的个数1≤n≤1000。  
`Sample Input`

	177 40 10
	180 151 152 193 168 255 278 303 211 217
`Sample Output`

	7
### 1002. 二哥种花生
`Description`  
二哥在自己的后花园里种了一些花生，也快到了收获的时候了。这片花生地是一个长度为L、宽度为W的矩形，每个单位面积上花生产量都是独立的。他想知道，对于某个指定的区域大小，在这么大的矩形区域内，花生的产量最大会是多少。  
`Input Format`  
第1行有2个整数，长度L和宽度W。  
第2行至第L+1行，每行有W个整数，分别表示对应的单位面积上的花生产量A（ 0≤A<10 ）。  
第L+2行有2个整数，分别是指定的区域大小的长度a和宽度b。  
`Output Format`  
输出一个整数m，表示在指定大小的区域内，花生最大产量为m。  
`Sample Input`

	4 5
	1 2 3 4 5
	6 7 8 0 0
	0 9 2 2 3
	3 0 0 0 1
	3 3
`Sample Output`

	38
`样例解释`  
左上角：38 = (1+2+3) + (6+7+8) + (0+9+2)  
`数据范围`  
对于30%的数据： 1≤L,W≤100；  
对于100%的数据： 1≤L,W≤1000。  
全部区域大小满足：1≤a≤L，1≤b≤W。  
