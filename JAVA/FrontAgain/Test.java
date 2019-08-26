public class Test
{
	public static void main(String[] args){
		
		try{
			
			FrontAgain obj = new FrontAgain();

			String str = "HelloWorld";
			if(obj.frontAgain(str))
				System.out.println("the first two chars of given string " + str + " appears in the last two");
			
			else
				System.out.println("the first two chars of given string " + str + " does not appear in the last two");
							

			str = "a";
			if(obj.frontAgain(str))
				System.out.println("the first two chars of given string " + str + " appears in the last two");
			
			else
				System.out.println("the first two chars of given string " + str + " does not appear in the last two");

			str = "ab";
			if(obj.frontAgain(str))
				System.out.println("the first two chars of given string " + str + " appears in the last two");
			
			else
				System.out.println("the first two chars of given string " + str + " does not appear in the last two");

			str = "edited";
			if(obj.frontAgain(str))
				System.out.println("the first two chars of given string " + str + " appears in the last two");
			
			else
				System.out.println("the first two chars of given string " + str + " does not appear in the last two");
			
			str = null;
			//str = "";
			if(obj.frontAgain(str))
				System.out.println("the first two chars of given string " + str + " appears in the last two");
			
			else
				System.out.println("the first two chars of given string " + str + " does not appear in the last two");

		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			
			exp.printStackTrace();
		}
	}
}
