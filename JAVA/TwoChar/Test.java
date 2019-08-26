public class Test
{
	public static void main(String[] args){
		
		try{
			
			TwoChar obj = new TwoChar();
			
			String str = "hello";

			System.out.println("given string " + str + " given index -2 " + obj.twoChar(str, -2));			
			System.out.println("given string " + str + " given index 0 " + obj.twoChar(str, 0));			
			System.out.println("given string " + str + " given index 2 " + obj.twoChar(str, 2));			
			System.out.println("given string " + str + " given index 3 " + obj.twoChar(str, 3));			
			System.out.println("given string " + str + " given index 4 " + obj.twoChar(str, 4));			
			System.out.println("given string " + str + " given index 5 " + obj.twoChar(str, 5));			

			str = null;
			//str = "";
			System.out.println("given string " + str + " given index 5 " + obj.twoChar(str, 5));			
			
		}
	
		catch(Exception exp){
			
			System.out.println("Caught Exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
