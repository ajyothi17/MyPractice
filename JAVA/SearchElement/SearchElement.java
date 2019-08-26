public class SearchElement
{
	public boolean searchElement(int[] arr, int numToSearch){
		
		for(int index = 0; index < arr.length; index++){
			
			if(arr[index] == numToSearch){
				return true;
			}

		}

		return false;
	}
}
