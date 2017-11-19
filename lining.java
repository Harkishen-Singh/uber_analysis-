import java.util.*;
import java.io.*;
import java.lang.*;
import javax.swing.*;


public class lining extends JFrame{

	public Formatter x;
	public Scanner scan_file;
	int c=1;
	String extract;
	public String name="";
	public boolean t=true;
	public void create() {
		while(t) {
		name=JOptionPane.showInputDialog("Enter the name of the text file you want to save the new format");
		name=name+".txt";
		try {
			x=new Formatter(name);
			t=false;
		}
		catch(Exception e) {
			System.out.println("You had an error");
			
		}
		}
		
		
	}
	
	public void openFile() {
		t=true;
		while(t) {
		name=JOptionPane.showInputDialog("Enter the name of the file to be analysed");
		name=name+".txt";
		t=true;
		
		try {
			scan_file=new Scanner(new File(name));
			t=false;
		}
		catch(Exception e) {
			System.out.println("You entered the Wrong Input. Retry Again!");
			
		}
		}
		while(scan_file.hasNext()) {
			extract=scan_file.nextLine();
			System.out.println("Extract file = "+ extract);
			String g;
			int e=0,b=0;
			int l=extract.length();
			for(int i=0;i<l;i++)
			{
				char ch=extract.charAt(i);
				if(ch=='.')
				{
					b=e;
					e=i;
					g=extract.substring(b+1, e+1);
					g=g+"\r\n";
					System.out.println(g);
					x.format("%s", g);
				}
			}
			e=0;b=0;
			
		}
		t=true;
		
	}
	public void closing() {
		x.close();
		scan_file.close();
	}
}
