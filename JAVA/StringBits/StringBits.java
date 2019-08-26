public class StringBits
{
	public String stringBits(String str) throws Exception{
		
		if(str.equals("") || str.equals(null)){
			
			throw new Exception("invalid string");
		}

		String newStr = "";

		for(int index = 0; index < str.length(); index += 2){
			
			newStr += str.charAt(index); 
		}

		return newStr;
	}
}
