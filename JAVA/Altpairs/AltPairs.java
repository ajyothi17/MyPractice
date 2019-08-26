public class AltPairs
{
	public String altPairs(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string");
		}

		String newStr = "";

		for(int index = 0; index < str.length(); index += 4){
				
			if(index < str.length() - 1)
				newStr = newStr + str.charAt(index) + str.charAt(index + 1);

			else
				newStr = newStr + str.charAt(index); 
		}

		return newStr;
	}
}
