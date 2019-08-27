public class HaveThree
{
	public boolean haveThree(int[] arr){
		
		int count = 0;

		for(int index = 0; index < arr.length; index++){
			
			if(arr[index] == 3){
				count++;
			}
		}		

		if(count == 3){
			return true;
		}

		return false;
	}
}
