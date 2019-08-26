public class More14
{
	public boolean more14(int[] arr){
		
		if(arr.length <= 4)
			return false;

		int count = 0;

		for(int index = 0; index < arr.length; index++){
			
			if((arr[index] == 1)){
				count++;

				if(count > 4)
					return true;
			}
		}

		return false;
	}
}
