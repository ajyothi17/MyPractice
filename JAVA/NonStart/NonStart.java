public class NonStart
{
	public String nonStart(String str1, String str2) throws Exception{
		
		if((str1.equals(null)) || (str1.equals("")) || (str2.equals(null)) || (str2.equals(""))){
			throw new Exception("invalid string... String empty");
		}

		if(str1.length() == 1)
			return str2.substring(1, str2.length());

		if(str2.length() == 1)
			return str1.substring(1, str1.length());

		return str1.substring(1, str1.length()) + str2.substring(1, str2.length());
	}
}
