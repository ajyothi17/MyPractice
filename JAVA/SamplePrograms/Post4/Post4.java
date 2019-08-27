public class Post4
{
	public int[] post4(int[] arr) throws Exception{
	
		if(arr.length < 1)	
			throw new Exception("no elements in the given array");

		if((arr.length == 1) || (arr[arr.length - 1] == 4))
			return arr;

		int pos = 0;

		for(int index = arr.length - 1; index >= 0; index--){
			if(arr[index] == 4){
				pos = index;
				break;
			}
		}

		int[] newArr = new int[arr.length - pos - 1];

		int newIndex = 0;

		pos++;

		while(pos < arr.length)
			newArr[newIndex++] = arr[pos++];

		return newArr;
	}
}
