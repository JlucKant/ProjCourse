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


System::Void ProjCourse::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	float p = 1;
	int n;
	float param = pow(2.f, 20.f);
	float fault;
	this->textBox3->Text = "";
	try {
		fault = float::Parse(textBox5->Text);
		if (fault > 1) { MessageBox::Show("Values out of range!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning); textBox5->Text = ""; }
		else {
			if (this->textBox1->Text != "") {
				n = Int32::Parse(this->textBox1->Text);
			}
			else n = 11;
			this->textBox3->Text += "N\tParameter\tFault\r\n";
			while (p >= fault) {
				float* Uvx = new float[n];
				float* Uvix = new float[n];
				float* t = new float[n];
				float tn = 15, tk = 100;
				float dt = (tk - tn) / (n - 1);
				timeArray(t, n);
				float param1;
				UvxArray(Uvx, t, n);
				UvixArray(Uvix, Uvx, n);
				param1 = parameter(Uvix, funcmax(n, Uvix), n - 1, dt);

				p = fabs(param - param1) / param1;
				this->textBox3->Text += n + "\t" + param + "\t" + p + "\r\n";
				param = param1;
				n *= 2;
				delete[] t;
				delete[] Uvx;
				delete[] Uvix;
			}
		}
	}
	catch (...) {
		MessageBox::Show("Incorrect types of data!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		textBox5->Text = "";
	}
	
}

System::Void ProjCourse::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chart1->Series[0]->Points->Clear();
	this->chart2->Series[0]->Points->Clear();
	textBox2->Text = "";
	int n;
	try {
		n = Int32::Parse(textBox1->Text);
		if (n < 2 || n >1000) { MessageBox::Show("Values out of range!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning); textBox1->Text = ""; textBox5->Text = ""; }
		else {
			float* Uvx = new float[n];
			float* Uvix = new float[n];
			float* t = new float[n];
			float tn = 15, tk = 100;
			this->textBox2->Text += "N\tt\tUvx\tUvix\r\n";
			timeArray(t, n);
			UvxArray(Uvx, t, n);
			UvixArray(Uvix, Uvx, n);
			for (int i = 0; i < n; i++) {
				this->chart1->Series[0]->Points->AddXY(t[i], Uvx[i]);
				this->chart2->Series[0]->Points->AddXY(t[i], Uvix[i]);
				this->textBox2->Text += (i + 1).ToString() + "\t" + ((float(round(t[i] * 100)) / 100.f)).ToString() + "\t" + ((float(round(Uvx[i] * 100)) / 100.f)).ToString() + "\t" + ((float(round(Uvix[i] * 100)) / 100.f)).ToString() + "\r\n";
				
			}
			this->chart1->ChartAreas[0]->AxisX->Interval = 5;
			this->chart2->ChartAreas[0]->AxisX->Interval = 5;
			this->chart1->ChartAreas[0]->AxisX->Maximum = t[n - 1];
			this->chart1->ChartAreas[0]->AxisX->Minimum = t[0];
			this->chart2->ChartAreas[0]->AxisX->Maximum = t[n - 1];
			this->chart2->ChartAreas[0]->AxisX->Minimum = t[0];
			
			
			delete[] t;
			delete[] Uvx;
			delete[] Uvix;

		}
	}
	catch (FormatException^ e) {
		MessageBox::Show("Incorrect types of data!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		textBox5->Text = "";
		textBox1->Text = "";
	}	
}

System::Void ProjCourse::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Author: Dementiev Mikhail Evgenievich\nGroup: IKVT-31\nVariant: 129", "Course work", MessageBoxButtons::OK, MessageBoxIcon::Information);

}

