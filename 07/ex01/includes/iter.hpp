template<typename T, typename F>
void	iter(T *arr, int len, F f) {
	if (!arr)
		return;
	for (int i = 0; i < len; i++) {
		f(arr[i]);
	}
}
