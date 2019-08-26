public class ReverseArray
{
	public int[] reverseArray(int[] arr) throws Exception{

		if(arr.length < 1){
			throw new Exception("no elements in the given array");
		}

		if(arr.length == 1)
			return arr;

		int start = 0;
		int end = arr.length - 1;

		while(start < end){

			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;

			start++;
			end--;
		}

		return arr;
	}
}
