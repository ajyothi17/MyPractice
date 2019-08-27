public class CopyEvens
{
	public int[] copyEvens(int[] arr, int count) throws Exception{

		if((count <= 0) || (count > arr.length))
			throw new Exception("count should be atleast 1 or less than equal to " + arr.length);

		int[] newArr = new int[count];
		int newCount = 0;

		for(int index = 0; index < arr.length; index++){
			
			if(((arr[index] % 2) == 0) && (newCount != count)){
				newArr[newCount] = arr[index];
				newCount++;
			}
		}
		
		if(newCount != count)
			throw new Exception("given array contains only " + newCount + " no. of even elements");

		return newArr;
	}
}
