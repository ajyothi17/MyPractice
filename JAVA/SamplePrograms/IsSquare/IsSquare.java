public class IsSquare
{
	public boolean isSquare(int num)
	{
		int res = (int)Math.sqrt(num);

		if((res * res) == num)
		{
			return true;
		}

		return false;
	}
}
