bool isPowerOf2(int n)
{
	return (n & (n - 1)) == 0;
}