public class FindAverageAcrossArrays
{
	public double findAverageAcrossArrays(int arr1[], int arr2[]) throws Exception
	{
		if((arr1.length < 1) && (arr2.length < 1))
            throw new Exception("no elements in array");

		double res = 0.0;

		for(int index = 0; index < arr1.length; index++)
		{
			res += arr1[index];
		}
		
		for(int index = 0; index < arr2.length; index++)
		{
			res += arr2[index];
		}

		res /= (arr1.length + arr2.length);

		return res;
	}	
}
