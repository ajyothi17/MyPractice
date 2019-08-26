public class StrConcat{
	
	public boolean checkString(String str){
		
		if((str.equals(null)) || (str.equals("")))
			return true;

		return false;
	}

	public String concatString(String str1, String str2) throws Exception{

		try{
			if((checkString(str1)) || (checkString(str2))){
				throw new Exception("invalid string");
			}	
		
		}

		catch(Exception exp){
			System.out.println("in StrConcat, " + exp.getMessage());
			throw exp;
		}
		
		return str1 + " " + str2;
	}

}
