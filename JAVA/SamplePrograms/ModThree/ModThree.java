public class ModThree
{
	public boolean modThree(int[] arr){
		
		int eCount = 0;
		int oCount = 0;

		for(int index = 0; index < arr.length; index++){
			
			if((arr[index] % 2) == 0)	
				eCount++;

			else
				oCount++;
		}

		if((eCount == 3) || (oCount == 3))
			return true;

		return false;
	}
}
