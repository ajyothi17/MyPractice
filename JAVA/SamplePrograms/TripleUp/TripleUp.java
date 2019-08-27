public class TripleUp
{
	public boolean tripleUp(int[] arr){
		
		for(int index = 0; index < (arr.length - 2); index++){
			
			if((arr[index + 1] == arr[index] + 1) && (arr[index + 2] == arr[index] + 2)){
				return true;
			}
		}

		return false;
	}
}
