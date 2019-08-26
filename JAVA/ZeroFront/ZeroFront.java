public class ZeroFront
{
	public int[] zeroFront(int[] arr){
		
		if(arr.length < 2){
			return arr;
		}

		int temp = 0;
		int tempIndex = 0;

		for(int index = 0; index < arr.length; index++){
	
			if(arr[index] == 0){
				
				temp = arr[index];
				arr[index] = arr[tempIndex];
				arr[tempIndex] = temp;

				tempIndex++;
			}
		}

		return arr;
	}
}
