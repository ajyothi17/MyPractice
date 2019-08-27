public class CountVowels
{
	public int countVowel(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid String");
		}

		str = str.toLowerCase();
		int count = 0;

		for(int index = 0; index < str.length(); index++){
			
			char ch = str.charAt(index);
			if((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'))
				count++;
		}
		
		return count;
	}
}
