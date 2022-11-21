public  class stylidium {
	private shape Bottom;
	private double h=0;
	
	
	
	void setBottom(shape X) {
		this.Bottom=X;
	}
	
	void setH(double h) {
		this.h=h;
	}
	
	double getVol() {
		double Vol=0;
		double BArea=0;
		BArea = Bottom.getArea();
		Vol=BArea*h;
		return Vol;
	}
	
	
	
}