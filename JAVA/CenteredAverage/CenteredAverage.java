public class CenteredAverage
{
	public int centeredAverage(int[] arr) throws Exception{
	
		if(arr.length < 3)
			throw new Exception("array length should be atleast 3");

		int min = arr[0];
		int max = arr[0];
		int sum = 0;

		for(int index = 0; index < arr.length; index++){
			
			if(arr[index] < min)
				min = arr[index];
			
			if(arr[index] > max)
				max = arr[index];

			sum += arr[index];
		}

		return (sum - max -min)/ (arr.length - 2);
	}
}
