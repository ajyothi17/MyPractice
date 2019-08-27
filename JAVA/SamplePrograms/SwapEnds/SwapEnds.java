public class SwapEnds
{
	public int[] swapEnds(int[] arr) throws Exception{
		
		if(arr.length < 1)
			throw new Exception("no elements in the given array");

		if(arr.length == 1)
			return arr;

		int tempVar;

		tempVar = arr[0];
		arr[0] = arr[arr.length - 1];
		arr[arr.length - 1] = tempVar;

		return arr;
	}
}
