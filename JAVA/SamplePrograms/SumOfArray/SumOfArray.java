public class SumOfArray
{
	public long addElement(int[] arr){
		
		long sum = 0;

		for(int index = 0; index < arr.length; index++){
			sum += arr[index];
		}

		return sum;
	}
}
