int tree2d[1026][1026];

void add2d(int x, int y, int value) {
	for (int i = x; i < 1026; i += (i & -i)) {
		for (int j = y; j < 1026; j += (j & -j)) {
			tree2d[i][j] += value;
		}
	}
}

int sum2d(int x, int y) {
	int ret = 0;

	for (int i = x; i > 0; i -= (i & -i)) {
		for (int j = y; j > 0; j -= (j & -j)) {
			ret += tree2d[i][j];
		}
	}

	return ret;
}

int query2d(int x1, int y1, int x2, int y2) {
	return sum2d(x2, y2) - sum2d(x1 - 1, y2) - sum2d(x2, y1 - 1) + sum2d(x1 - 1, y1 - 1);
}

void update2d(int x, int y, int value) {
	add2d(x, y, value);
}

void update2d2(int x, int y, int value) {
	int current = query2d(x, y, x, y);
	add2d(x, y, value - current);
}
