public class ScoresIncreasing
{
	public boolean scoresIncreasing(int[] scores) throws Exception{

		if(scores.length < 1){
			throw new Exception("given array is empty");
		}

		for(int index = 0; index < scores.length - 1; index++){
			
			if(scores[index] > scores[index + 1])
				return false;
		}

		return true;
	}
}
