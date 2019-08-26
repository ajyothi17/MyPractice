public class FrontBack 
{
	public String frontBack(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid String");
		}

		int len = str.length();

		if(len >= 2){
			return (str.charAt(len - 1)) + (str.substring(1, len - 1)) + (str.charAt(0));
		}

		return str;
	}
}
