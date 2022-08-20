//rain trapping  using two poiner appraoch O(n)
int waterTrapped(vector<int> v)
{
	if (v.size() < 3) // there should be atleast 3 bars two form a container
	{
		return 0;
	}
	int i = 0, j = v.size() - 1, w = 0; // i, j - two pointer approach
	int l = 0, r = 0; // left max & right max
	while (i <= j)
	{
		if (l <= r) // when left max is less than right max
		{
			if (v[i] < l) // when i'th bar is smaller than left largest bar
			{
				w += l - v[i];
			}
			else // else make this as new largest left bar
			{
				l = v[i];
			}
			i++; // incrementing left pointer
		}
		else // when right max is less than left max
		{
			if (v[j] < r) // similarlly doing as above for right pointer
			{
				w += r - v[j];
			}
			else
			{
				r = v[j];
			}
			j--; // decrementing right pointer
		}
	}
	return w;
}

