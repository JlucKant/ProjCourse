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

System::Void ProjCourse::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chart1->Series[0]->Points->Clear();
	float t[1000], Uvx[1000], Uvix[1000];
	int n = 1000;
	float tn = 15, tk = 100, t1 = 30, t2 = 60;
	float a = 50, b = 0.07, c = 0.1;
	float dt = (tk - tn) / (n - 1);
	//making the array of time
	for (int i = 0; i < n; i++) {
		t[i] = tn + i * dt;
	}

	//making array of Uvx
	for (int i = 0; i < n; i++) {
		if (t[i] <= t1) Uvx[i] = a * (1 - exp(-b * (t[i] - tn)));
		else if (t1 < t[i] && t[i] <= t2) Uvx[i] = a * (1 - exp(-b * (t1 - tn)));
		else Uvx[i] = a * (1 - exp(-b * (t1 - tn))) * exp(-c * (t[i] - t2));
		this->chart1->Series[0]->Points->AddXY(t[i],Uvx[i]);
	}

	//making array of Uvix
	for (int i = 0; i < n; i++) {
		if (Uvx[i] < 15) Uvix[i] = (7.f / 3.f) * Uvx[i];
		else Uvix[i] = 35;
	}
	
}
