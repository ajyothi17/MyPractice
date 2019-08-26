import java.util.Arrays;

public class FindMinimum
{
	public int findMinimum(int[] arr) throws Exception{
		
		if(arr.length < 1)
			throw new Exception("no elements in the given array");

		if(arr.length == 1)
			return arr[0];

		Arrays.sort(arr);

		return arr[0];
	}
}
