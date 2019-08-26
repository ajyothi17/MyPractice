public class Either24
{
	public boolean either24(int[] arr) throws Exception{
		
		boolean has22 = false;
		boolean has44 = false;

		for(int index = 0; index < (arr.length - 1); index++){
				
			if((arr[index] == 2) && (arr[index + 1] == 2))
				has22 = true;

			if((arr[index] == 4) && (arr[index + 1] == 4))
				has44 = true;
		}

		if(has22 ^ has44)
			return true;

		return false;
	}
}
