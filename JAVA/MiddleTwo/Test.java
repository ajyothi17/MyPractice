public class Test
{
	public static void main(String[] args){
		
		try{
			
			MiddleTwo obj = new MiddleTwo();

			String str = "HelloWorld";
			System.out.println("middle two of given string " + str + ":" + obj.middleTwo(str));

			str = "a";
			System.out.println("middle two of given string " + str + ":" + obj.middleTwo(str));

			str = "ab";
			System.out.println("middle two of given string " + str + ":" + obj.middleTwo(str));

			str = "xyz";
			System.out.println("middle two of given string " + str + ":" + obj.middleTwo(str));

			str = "hello\ngood\nmorning";
			System.out.println("middle two of given string " + str + ":" + obj.middleTwo(str));

			str = null;
			//str = "";
			System.out.println("middle two of given string " + str + ":" + obj.middleTwo(str));

		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			
			exp.printStackTrace();
		}
	}
}
