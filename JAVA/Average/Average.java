public class Average
{
	public float averageAcrossArrays(int[] arr1, int[] arr2) throws Exception{
	
		if(arr1.length < 1 || arr2.length < 1)
			throw new Exception("no elements in given array");

		float sum = 0;
		int index = 0;

		for(index = 0; (index < arr1.length ) && (index < arr2.length); index++){
			
			sum += arr1[index] + arr2[index];
		}
	
		int temp = index;

		while(index < arr1.length){
			sum += arr1[index++];
		}

		index = temp;
		while(index < arr2.length){
			sum += arr2[index++];
		}

		return sum / (arr1.length + arr2.length);
	}
}
