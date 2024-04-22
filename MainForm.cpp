#include "MainForm.h"
#include <cmath>
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ProjCourse::MainForm form;
	Application::Run(% form);
}

//searching maximum
float funcmax(int n, float* U) {
	float Umax = 0;
	for (int i = 0; i < n; i++) {
		if (U[i] > Umax) Umax = U[i];
	}
	return Umax;
}


//count parameter 
float parameter(float* U, float Umax, int n, float dt) {
	float U1 = U[n] + 0.9 * (Umax - U[n]);
	float U2 = U[n] + 0.1 * (Umax - U[n]);
	float dlit = 0;
	for (int i = 0; i < n + 1; i++)
		if (U[i] < U1 && U[i] > U2 && U[i + 1] < U[i]) dlit += dt;
	return dlit;
}

//making the array of time
void timeArray(float* t, int n) {
	float tn = 15, tk = 100;
	float dt = (tk - tn) / (n - 1);
	for (int i = 0; i < n; i++) {
		t[i] = tn + i * dt;
	}
}

//making array of Uvx
void UvxArray(float* Uvx, float* t, int n) {
	float tn = 15, tk = 100, t1 = 30, t2 = 60;
	float a = 50, b = 0.07, c = 0.1;
	for (int i = 0; i < n; i++) {
		if (t[i] <= t1) Uvx[i] = a * (1 - exp(-b * (t[i] - tn)));
		else if (t1 < t[i] && t[i] <= t2) Uvx[i] = a * (1 - exp(-b * (t1 - tn)));
		else Uvx[i] = a * (1 - exp(-b * (t1 - tn))) * exp(-c * (t[i] - t2));

	}
}

//making array of Uvix
void UvixArray(float* Uvix, float* Uvx, int n) {
	for (int i = 0; i < n; i++) {
		if (Uvx[i] < 15) Uvix[i] = (7.f / 3.f) * Uvx[i];
		else Uvix[i] = 35;

	}
}



//calculating fault
void fault(float tk, float tn, int n, int massive,float fault_) {
	float fault=fault_;
	float p = 1;
	float param = pow(2.f, 20.f);

	while (p >= fault) {
		float* Uvx = new float[n];
		float* Uvix = new float[n];
		float* t = new float[n];
		float dt = (tk - tn) / (n - 1);
		timeArray(t, n);
		float param1;
		if (massive == 1) {
			UvxArray(Uvx, t, n);
			param1 = parameter(Uvx, funcmax(n, Uvx), n - 1, dt);
		}
		else {
			UvxArray(Uvx, t, n);
			UvixArray(Uvix, Uvx, n);
			param1 = parameter(Uvx, funcmax(n, Uvix), n - 1, dt);
		}

		p = fabs(param - param1) / param1;

		param = param1;
		n *= 2;
	}
}
System::Void ProjCourse::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chart1->Series[0]->Points->Clear();
	this->chart2->Series[0]->Points->Clear();
	int n;
	float fault_;
	try {
		n = Int32::Parse(textBox1->Text);
		if (n < 2 || n >1000) e;
		else {
			fault_ = float::Parse(textBox5->Text);
			float* Uvx = new float[n];
			float* Uvix = new float[n];
			float* t = new float[n];
			float tn = 15, tk = 100;

			timeArray(t, n);
			UvxArray(Uvx, t, n);
			UvixArray(Uvix, Uvx, n);
			for (int i = 0; i < n; i++) {
				this->chart1->Series[0]->Points->AddXY(t[i], Uvx[i]);
				this->chart2->Series[0]->Points->AddXY(t[i], Uvix[i]);
				this->textBox2->Text += t[i].ToString() + "\t" + Uvx[i].ToString() + "\t" + Uvix[i].ToString()+"\n";
			}

			fault(tk, tn, n, 1, fault_);
			fault(tk, tn, n, 2, fault_);
		}
	}
	catch (FormatException^ e) {
		MessageBox::Show("Некорректный ввод", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	
	
}
//System::Void ProjCourse::MainForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
//	try {
//		int a = Int32::Parse(textBox1->Text);
//	}
//	catch (FormatException^) {
//		textBox1->Text = "";
//	}
//}
//
//System::Void ProjCourse::MainForm::textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
//
//}