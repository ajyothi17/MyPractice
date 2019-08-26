public class WithoutEnd2
{
	public String withoutEnd2(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string... String cannot be null or empty");
		}

		if(str.length() < 3){
			throw new Exception("invalid string length");
		}

		return str.substring(1, (str.length() - 1));
	}
}
