public class NotAlone
{
	public int[] notAlone(int[] arr, int val){
		
		if(arr.length == 1)
			return arr;

		for(int index = 1; index < (arr.length - 1); index++){
			
			if(arr[index] == val){
				
				if((arr[index - 1] != val) && (arr[index + 1] != val)){
					
					if((arr[index - 1]) > (arr[index + 1]))
						arr[index] = arr[index - 1];

					else
						arr[index] = arr[index + 1];
				}
			}
		} 
		
		return arr;
	}
}
