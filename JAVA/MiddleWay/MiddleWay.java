public class MiddleWay
{
	public int[] middleWay(int[] arr1, int[] arr2) throws Exception{
		
		if((arr1.length != 3) || (arr2.length != 3))
			throw new Exception("invalid array length... array length should be 3");

		int[] newArr = new int[2];

		newArr[0] = arr1[1];
		newArr[1] = arr2[1];

		return newArr;
	}
}
