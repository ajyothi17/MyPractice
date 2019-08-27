public class DelDel
{
	public String delDel(String str) throws Exception{

		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string... string cannot be null or empty");
		}
		
		if(str.contains("del")){
			
			if(1 == str.indexOf("del"))
				return "" + str.substring(0, 1) + str.substring(4, str.length());
		}

		return str;
	}
}
