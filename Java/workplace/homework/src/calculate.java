public class calculate{
	
	
	public static void main(String[] args) {
		Cri C1 = new Cri();
		Tri T1 = new Tri();
		stylidium sd1 =new stylidium();
		stylidium sd2 =new stylidium();
		
		C1.setR(2.0);
		T1.setA(2.0);
		T1.setH4A(2.0);
		sd1.setBottom(C1);
		sd1.setH(3.0);
		sd2.setBottom(T1);
		sd2.setH(3.0);
		
		double C1Area=C1.getArea();
		double T1Area=T1.getArea();		
		double sd1Vol=sd1.getVol();
		double sd2Vol=sd2.getVol();
		
		System.out.println("����ԲC1���뾶Ϊ2");
		System.out.println("���Ϊ��");
		System.out.println(C1Area);
		System.out.println("����������T1��һ�ױ߳�Ϊ2�����ϸ�Ϊ2");		
		System.out.println("���Ϊ��");
		System.out.println(T1Area);
		System.out.println("������C1Ϊ���棬��Ϊ3��Բ��");
		System.out.println("���Ϊ��");
		System.out.println(sd1Vol);
		System.out.println("������T1Ϊ���棬��Ϊ3��������");
		System.out.println("���Ϊ��");
		System.out.println(sd2Vol);		
		
		
	}

}


