public class Lucky13
{
	public boolean lucky13(int[] arr) throws Exception{

		if(arr.length < 1)
			throw new Exception("no elements in the given array");

		for(int index = 0; index < arr.length; index++){
			if((arr[index] == 1) || (arr[index] == 3))
				return false;
		}

		return true;
	}
}
