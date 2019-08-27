public class ShiftLeft
{
	public int[] shiftLeft(int[] arr) throws Exception{
	
		if(arr.length < 1)
			throw new Exception("no elements in given array");

		int temp = arr[0];

		for(int index = 0; index < arr.length - 1; index++){
			
			arr[index]  = arr[index + 1];
		}

		arr[arr.length - 1] = temp;

		return arr;
	}
}
