public class Unlucky1
{
	public boolean unlucky1(int[] nums){
		
		for(int index = 0;  index < nums.length; index++){
			
			if((nums[index] == 1) && (nums[index + 1] == 3))
				return true;
		}

		return false;
	}
}
