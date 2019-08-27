public class Only14
{
	public boolean only14(int[] arr){
		
		for(int index = 0; index < arr.length; index++){
			
			if((arr[index] != 1) && (arr[index] != 4)){
				return false;
			}
		}

		return true;
	}
}
