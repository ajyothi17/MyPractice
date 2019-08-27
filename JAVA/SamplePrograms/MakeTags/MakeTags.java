public class MakeTags
{
	public String makeTags(String tag, String word) throws Exception{
		
		if((tag.equals("")) || (tag.equals(null)) || (word.equals("")) || (word.equals(null))){
			
			throw new Exception("invalid string");
		}

		return "<" + tag + ">" + word + "</" + tag + ">";
	}
}
