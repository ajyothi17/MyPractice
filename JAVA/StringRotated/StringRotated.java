public class StringRotated
{
	public boolean isStringRotated(String str1, String str2) throws Exception{
		
		if((str1.equals("")) || (str2.equals("")) || (str1.equals(null)) || (str2.equals(null))){
		
			throw new Exception("invalid string... string cannot be empty or null");
		}

		if(str1.length() != str2.length())
			return false;

		if((str1 + str1).contains(str2))
			return true;

		return false;
	}
}
