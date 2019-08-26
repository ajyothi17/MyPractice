public class FindSum
{
	public double findSum(int num)
	{
		double res = 0.0;
		int i = 1;

		while(num != 0)
		{
			res += Math.pow((num%10), i);
			num /= 10;
			i++;
		}

		return res;
	}
}
