class Tri extends shape{
	private double a;
	private double h4a;//µ×aÉÏ¸ß
	
	void setA(double a) {
		this.a=a;
	}
	
	void setH4A(double h) {
		this.h4a=h;
	}
	
	double getArea() {
		double Area=0;
		Area=a*h4a*0.5;
		return Area;
	}
	

}