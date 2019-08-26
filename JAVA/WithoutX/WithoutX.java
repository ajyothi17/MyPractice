public class WithoutX
{
	public String withoutX(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){	
			throw new Exception("invalid string");
		}

		int len = str.length();
		str = str.toLowerCase();

		if(len == 1){
			
			if(str.charAt(0) == 'x')
				return "";

			return str;
		}

		if((str.charAt(0) == 'x') && (str.charAt(len - 1) == 'x')){

			return str.substring(1, len - 1);
		}

		if(str.charAt(0) == 'x')
			return str.substring(1, len);

		if(str.charAt(len -1) == 'x')
			return str.substring(0, len - 1);

		return str;
	}
}
