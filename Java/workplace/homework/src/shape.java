import java.util.*;
import java.lang.Math;

public class shape{
	
	
	public static void main(String[] args) {
		int selction=0;
		Scanner scan = new Scanner(System.in);
		while(true) {
			System.out.println("1.Բ�����");
			System.out.println("2.Բ�����");
			System.out.println("3.�˳�");
			System.out.println("ѡ��");
			
			selction=scan.nextInt();
			if(selction == 3) {
				System.out.println("done");
				break;
			}
			if(selction == 1) {
				calcuShape Cri = new calcuShape();
				System.out.println("�뾶��");
				double r=scan.nextDouble();
				
				Cri.setR(r);
				double S=Cri.getArea();
				
				System.out.println(S);
				System.out.println("done");
				
				
			}//Բ���
			
			if(selction == 2) {
				calcuShape CyLder = new calcuShape();
				System.out.println("�뾶��");
				double r=scan.nextDouble();
				System.out.println("�߶ȣ�");
				double h=scan.nextDouble();
				
				CyLder.setR(r);
				CyLder.setH(h);
				
				double V=CyLder.getVol();
				
				System.out.println(V);
				System.out.println("done");
				
				
			}//�������
			
			
			
			
		}
		scan.close();
	}
}

 class calcuShape{
	
	private double r=0;
	private double h=0;
	
	public void setR(double r) {
		this.r=r;
	}
	public void setH(double h) {
		this.h=h;
	}
	
	public double getArea() {
		double Area=0;
		Area = r*r*Math.PI;
		return Area;
	}
	
	public double getVol() {
		double Vol=0;
		Vol = r*r*Math.PI*h;
		return Vol;
	}

	
}