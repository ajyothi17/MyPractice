public class Fix32
{
	public int[] fix32(int[] arr){
		
		if(arr.length <= 2){
			return arr;
		}

		for(int index = 0; index < arr.length - 1; index++){
		
			if((arr[index] == 2) && (arr[index + 1] == 3)){
			
				arr[++index] = 0;
			}
		}

		return arr;
	}
}
