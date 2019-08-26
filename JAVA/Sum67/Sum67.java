public class Sum67
{
	public int sum67(int[] arr) throws Exception{
		
		if(arr.length <= 0)
			throw new Exception("invalid array size");

		int flag = 0;
		int sum = 0;
		
		for(int index = 0; index < arr.length; index++){
			
			if(arr[index] == 6)
				flag = 1;

			if(flag == 0)
				sum += arr[index];

			if(arr[index] == 7)
				flag = 0;
		}
	
		if(flag != 0)
			throw new Exception("invalid input array, every 6 should be followed by 7");
		return sum;
	}
}
