// TC : O(2^n)
// SC : O(n)

#include <stdio.h>
void findSubset(int S[], int n, int d, int subset[], int size, int sum);
int main() {
	int S[] = {1, 2, 5, 6, 8};
	int n = sizeof(S) / sizeof(S[0]);
	int d = 9;
	int subset[n];
	int size = 0;
	int sum = 0;
	findSubset(S, n, d, subset, size, sum);
	
	return 0;
}

void findSubset(int S[], int n, int d, int subset[], int size, int sum) {
	if (sum == d) {
	printf("{");
	for (int i = 0; i < size; i++) {
		printf("%d", subset[i]);
		if (i < size - 1) {
			printf(",");
		}
	}
	printf("}\n");
	return;
}
if (sum > d || n == 0) {
	return;
}
	subset[size] = S[0];
	findSubset(S + 1, n - 1, d, subset, size + 1, sum + S[0]);
	findSubset(S + 1, n - 1, d, subset, size, sum);
}