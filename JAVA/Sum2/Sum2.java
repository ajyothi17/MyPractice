public class Sum2
{
	public int sum2(int[] arr) throws Exception{
		
		if(arr.length <= 0)
			throw new Exception("invalid array size");
		
		if(arr.length == 1)
			return arr[0];

		int sum = 0;
		for(int index = 0; index < 2; index++)
			sum += arr[index];

		return sum;
	}
}
