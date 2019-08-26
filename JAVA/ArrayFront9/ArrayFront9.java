public class ArrayFront9
{
	public boolean arrayFront9(int[] arr){
		
		if(arr.length < 4){
			return false;
		}

		for(int index = 0; index < 4; index++){
			
			if(arr[index] == 9)
				return true;
		}

		return false;
	}
}
