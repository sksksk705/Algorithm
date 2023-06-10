import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int tc = 1;tc <= t;++tc) {
			int n = sc.nextInt();
			int m = sc.nextInt();			
			
			int check = (1<<n) - 1;
			
			if((m & check) == check) 
				System.out.println("#"+tc+" "+"ON");
			else
				System.out.println("#"+tc+" "+"OFF");
				
		}
	}
}