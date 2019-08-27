public class EndUp
{
	public String endUp(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string... String cannot be empty");
		}

		if(str.length() <= 3)
			return str.toUpperCase();

		return str.substring(0, str.length() - 3) + str.substring(str.length() - 3, str.length()).toUpperCase();
	}
}
