public class BubbleSortDescend
{
	public int[] bubbleSortDescend(int[] arr) throws Exception{
		
		if(arr.length < 1){
			throw new Exception("no elements in the given array");
		}

		if(arr.length == 1)
			return arr;

		int iteration = arr.length;

		while(iteration-- >= 0){

			for(int index = 0; index < arr.length - 1; index++){

				if(arr[index] < arr[index + 1]){
					
					int temp = arr[index];
					arr[index] = arr[index + 1];
					arr[index + 1] = temp;
				}
			}
		}

		return arr;
	}
}
