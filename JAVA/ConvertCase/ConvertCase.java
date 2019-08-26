public class ConvertCase
{
	public String convertCase(String str) throws Exception{

		if(str.equals("") || str.equals(null))
			throw new Exception("invalid string... string cannot be empty or null");

		char[] chArr = str.toCharArray();

		for(int index = 0; index < chArr.length; index++){
			
			chArr[index] = (char)(chArr[index] ^ 32);
		}

		return String.valueOf(chArr);
	}
}
