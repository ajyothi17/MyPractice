public class Has12
{
	public boolean has12(int[] arr){

		boolean flag = false;

		for(int index1 = 0; index1 < arr.length; index1++){
			
			if(arr[index1] == 1){

				for(int index2 = index1 + 1; index2 < arr.length; index2++){
					
					if(arr[index2] == 2){
						flag = true;
						break;
					}
				}
			}

			if(flag)
				break;
		}

		return flag;
	}
}
