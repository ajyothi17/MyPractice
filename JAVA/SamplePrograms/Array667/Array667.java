public class Array667
{
	public int array667(int[] arr) throws Exception{
		
		if(arr.length < 1)
			throw new Exception("no elements in array");

		int count = 0;

		for(int index = 0; index < arr.length; index++){
			
			if((index + 1) == arr.length)
				break;

			if(((arr[index] == 6) && (arr[index + 1] == 6)) || ((arr[index] == 6) && (arr[index + 1] == 7)))
				count++;
		}

		return count;
	}
}
