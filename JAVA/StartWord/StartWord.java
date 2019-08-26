public class StartWord
{
	public String startWord(String str, String word) throws Exception{
		
		if((str.equals(null)) || (str.equals("")) || (word.equals(null)) || (word.equals(""))){
			throw new Exception("invalid string... string cannot be null or empty");
		}

		if((word.equals(str.substring(0, word.length()))) || (word.substring(1, word.length()).equals(str.substring(1, word.length())))){
			
			return str.substring(0, word.length());
		}

		return str;
	}
}
