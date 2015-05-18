{
	double br_l;
	double br_q;
	//2*br_q*br_l = 0.0017
	//3*br_l+5*3*br_q = 1
	//br_l = (0.0017/2)/br_q
	//3*(0.0017/2)+15*br_q*br_q = br_q
	double C = 3*(0.0017/2);
	double A = 15.;
	double B = -1.;
	double Delta = (B*B) - 4*A*C;
	double r1 = (-B + sqrt(Delta))/(2*A);
	double r2 = (-B - sqrt(Delta))/(2*A);	
	br_q = r1;
	br_l = (0.0017/2)/br_q;
	cout<<2*br_q*br_l<<endl;
	cout<<3*br_l+5*3*br_q<<endl;
	cout<<"-------"<<endl;
	br_q = r2;
	br_l = (0.0017/2)/br_q;
	cout<<2*br_q*br_l<<endl;
	cout<<3*br_l+5*3*br_q<<endl;
	cout<<"-------"<<endl;	
	
	double h_xsec_ggF = 19300 ; //fb
	double braa = 0.1;
	double brmmbb = 2*br_q*br_l;
	double IL = 19.7;
	cout<<h_xsec_ggF * braa * brmmbb <<endl;
	cout<<h_xsec_ggF * braa * brmmbb * IL<<endl;	
}
