public class EvenOddArray
{
	public int[] evenOddArray(int[] arr){
		
		int left = 0;
		int right = arr.length - 1;

		while(left < right){
			
			while((arr[left] % 2 == 0) && (left < right))
				left++;

			while((arr[right] % 2 == 1) && (left < right))
				right--;

			if(left < right){
				
				arr[left] = arr[left] + arr[right];
				arr[right] = arr[left] - arr[right];
				arr[left] = arr[left] - arr[right];
			}
		}

		return arr;
	}
}
