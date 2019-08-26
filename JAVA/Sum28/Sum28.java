public class Sum28
{
	public boolean sum28(int[] arr){
		
		int sum = 0;

		for(int index = 0; index < arr.length; index++){
			
			if(arr[index] == 2)
				sum += arr[index];
		}

		if(sum == 8)
			return true;

		return false;
	}
}
