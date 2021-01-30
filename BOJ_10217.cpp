#include<iostream>
#include<cstring>

int main() {
	int tc;
	std::cin >> tc;
	while(tc--)
	{
		int N, M, K;
		std::cin >> N >> M >> K;
		int cnt[105]={}, where[105][10005]={}, cost[105][10005]={}, time[105][10005]={};
		for(int from, to, c, t; K--; )
		{
			std::cin >> from >> to >> c >> t;
			where[from][cnt[from]] = to;
			cost[from][cnt[from]] = c;
			time[from][cnt[from]] = t;
			cnt[from]++;
		}


		int dp[105][10005]; // dp[i][j] = min time going i airport using <=j cost
		memset(dp, -1, sizeof(dp));
		dp[1][0] = 0;

		for(int i=1; i<=M; i++)
			for(int j=1; j<=N; j++)
				for(int k=0; k<cnt[j]; k++)
				{
				    int from = j, to = where[j][k];
					if(i >= cost[from][k] && dp[from][i - cost[from][k]] != -1)
					{
						int tmp = dp[from][i - cost[from][k]] + time[from][k];

						if(dp[to][i] == -1 || tmp < dp[to][i])
							dp[to][i] = tmp;
					}
				}

		int ans = 1<<30;
		for(int i=1; i<=M; i++)
		    if(dp[N][i] != -1 && dp[N][i] < ans)
		        ans = dp[N][i];

		if(ans == 1<<30) std::cout << "Poor KCM\n";
		else std::cout << ans << '\n';
	}
	return 0;
}