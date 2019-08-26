public class CountXX
{
	public int countXX(String str) throws Exception{

		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string");
		}
		
		int count = 0;

		str = str.toLowerCase();

		for(int index = 0; index < str.length(); index++){
			
			if(index < str.length() - 1){
					
				if((str.charAt(index) == 'x') && (str.charAt(index + 1) == 'x'))
					count++;
			}
		}

		return count;	
	}
}
