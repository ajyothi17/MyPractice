import java.util.Arrays;

public class SortArray
{
	public int[] sortArray(int[] arr) throws Exception{
		
		if(arr.length < 1)
			throw new Exception("no elements in the given array");

		if(arr.length == 1)
			return arr;

		Arrays.sort(arr);

		return arr;
	}
}
