public class ZeroMax
{
	public int[] zeroMax(int[] nums){

		int max;
		
		for(int index1 = 0; index1 < nums.length; index1++){
			
			max = 0;
			if(nums[index1] == 0){
				
				for(int index2 = index1; index2 < nums.length; index2++){
					
					if((nums[index2] % 2) != 0)
						max = Math.max(max, nums[index2]);
				}

				nums[index1] = max;
			}
		}

		return nums;
	}
}
