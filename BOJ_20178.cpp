#include <stdio.h>

int n;
int A[500][500], B[500][500];

void XOR(int x, int y)
{
	int i;

	for(i=0; i<n; i++){
		A[x][i] ^= A[y][i];
		B[x][i] ^= B[y][i];
	}
}

int main()
{
	int i, j;

	scanf("%d", &n);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &A[i][j]);
	for(i=0; i<n; i++)
		B[i][i] = 1;

	for(i=0; i<n; i++){
		if(A[i][i] == 0){
			for(j=i+1; j<n; j++){
				if(A[j][i] == 1){
					XOR(i, j);
					break;
				}
			}
			if(j == n){
				printf("-1");
				return 0;
			}
		}

		for(j=0; j<n; j++){
			if(i == j)
				continue;
			if(A[j][i] == 1)
				XOR(j, i);
		}
	}

	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			if(B[i][j])
				printf("%d ", j+1);
		printf("\n");
	}

	return 0;
}
