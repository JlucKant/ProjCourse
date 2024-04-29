#pragma once

namespace ProjCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox3;




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->AxisX->Title = L"time, c";
			chartArea1->AxisX2->TitleForeColor = System::Drawing::Color::Transparent;
			chartArea1->AxisY->Title = L"Uin, B";
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(39, 30);
			this->chart1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->chart1->Name = L"chart1";
			series1->BorderColor = System::Drawing::Color::Transparent;
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Black;
			series1->Legend = L"Legend1";
			series1->Name = L"Uin";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(784, 423);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1436, 305);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(286, 53);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// chart2
			// 
			chartArea2->AxisX->Title = L"time, c";
			chartArea2->AxisY->Title = L"Uout, B";
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(39, 462);
			this->chart2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->chart2->Name = L"chart2";
			series2->BorderColor = System::Drawing::Color::Transparent;
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Black;
			series2->Legend = L"Legend1";
			series2->Name = L"Uout";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(784, 423);
			this->chart2->TabIndex = 3;
			this->chart2->Text = L"chart2";
			this->chart2->Click += gcnew System::EventHandler(this, &MainForm::chart2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1436, 177);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(284, 31);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1432, 147);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(289, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Amount of points (1<n<1000)";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1516, 234);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 25);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Fault (n < 1)";
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(1436, 264);
			this->textBox5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(284, 31);
			this->textBox5->TabIndex = 9;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox5_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->Location = System::Drawing::Point(832, 62);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(558, 391);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(1642, 844);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 48);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Author";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1436, 369);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(286, 53);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Calculate fault";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(832, 30);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(558, 31);
			this->textBox4->TabIndex = 13;
			this->textBox4->Text = L"N               t             Uin           Uout";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(832, 462);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(558, 31);
			this->textBox7->TabIndex = 15;
			this->textBox7->Text = L"N            Parameter                  Fault";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->Location = System::Drawing::Point(832, 494);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox3->Size = System::Drawing::Size(558, 391);
			this->textBox3->TabIndex = 14;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1754, 909);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chart2_Click(System::Object^ sender, System::EventArgs^ e) {
	}




private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}



private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
