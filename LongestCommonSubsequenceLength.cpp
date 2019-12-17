/************************************************************************************************/
/***** Application of Dynamic Programming to find length of Longest Common Subsequence **********/

// Longest Common Subsequence
// Input: 
// X: ABCBDAB
// Y: BDCABA
// Length of LCS is 4 (BCAB, BCBA and BDAB)


//             | 0                                          if i == 0 or j == 0
// LCS[i][j] = | LCS[i – 1][j – 1] + 1                      if X[i-1] == Y[j-1]
//             | Max(LCS[i – 1][j], LCS[i][j – 1])      if X[i-1] != Y[j-1]


#include <iostream>
#include <string.h>

int max(int a, int b) {
	return a>b?a:b;
}

int ary[1000][1000];

int LCS(char X[1000], char Y[1000]) {
	int m, n;
	m = strlen(X);
	n = strlen(Y);
	
	for(int i=0; i<=m; i++)
		ary[i][0] = 0;
	for(int i=0; i<=n; i++)
		ary[0][i] = 0;
	
	int max_len = 0;
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++) 
		{
			if (X[i-1] == Y[j-1])
				ary[i][j] = ary[i-1][j-1] + 1;
			else
				ary[i][j] = max(ary[i-1][j], ary[i][j-1]);
				
			if ( max_len < ary[i][j] )
				max_len = ary[i][j];
		}
	
	return max_len;	
}

int main()
{
	char X[] = "ABCBDAB";
	char Y[] = "BDCABA";
	std::cout<<"LCS is "<<LCS(X, Y)<<std::endl;
	
	int m = strlen(X);
	int n = strlen(Y);
	std::cout<<std::endl;
	for(int i=0; i<=m; i++, std::cout<<std::endl)
	    for(int j=0; j<=n; j++)
	        std::cout<<ary[i][j]<<" ";
	
	return 0;
}