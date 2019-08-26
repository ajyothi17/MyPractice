public class MakeAbba
{
	public String makeAbba(String str1, String str2) throws Exception{
		
		if((str1.equals(null)) || (str2.equals(null)) || (str1.equals("")) || (str2.equals(""))){
			throw new Exception("invalid string... String cannot be empty or null");
		}

		return str1 + str2 + str2 + str1;
	}
}
