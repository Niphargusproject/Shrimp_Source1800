#pragma once

namespace DataTrimming {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Start
	/// </summary>
	public ref class Start : public System::Windows::Forms::Form
	{
	public:
		Start(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblEndAcquisitionTitle;
	protected: 

	private: System::Windows::Forms::Button^  btnStart;
	protected: 

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  lblInterval;
	private: System::Windows::Forms::NumericUpDown^  numSeconds;

	private: System::Windows::Forms::TabControl^  tabStartMeasurements;
	private: System::Windows::Forms::TabPage^  tabInterval;
	private: System::Windows::Forms::TabPage^  tabCalendar;
	private: System::Windows::Forms::TabPage^  tabAdvancedsettings;
	private: System::Windows::Forms::NumericUpDown^  numMinutes;

	private: System::Windows::Forms::Label^  lblSecond;
	private: System::Windows::Forms::Label^  lblMinutes;
	private: System::Windows::Forms::Label^  lblDays;
	private: System::Windows::Forms::NumericUpDown^  numDays;

	private: System::Windows::Forms::Label^  lblHours;
	private: System::Windows::Forms::NumericUpDown^  numHours;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label1;


	public: 
		int numdat;  //Number of possible measurements
		int intervalTotal;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int intervalSeconds;
		int intervalMinutes;
		int intervalHours;
		int intervalDays;
	private: System::Windows::Forms::Label^  lblEndAcquisition;
	private: System::Windows::Forms::Label^  label2;




		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblEndAcquisitionTitle = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->lblInterval = (gcnew System::Windows::Forms::Label());
			this->numSeconds = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabStartMeasurements = (gcnew System::Windows::Forms::TabControl());
			this->tabInterval = (gcnew System::Windows::Forms::TabPage());
			this->lblEndAcquisition = (gcnew System::Windows::Forms::Label());
			this->lblDays = (gcnew System::Windows::Forms::Label());
			this->numDays = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblHours = (gcnew System::Windows::Forms::Label());
			this->numHours = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblMinutes = (gcnew System::Windows::Forms::Label());
			this->numMinutes = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblSecond = (gcnew System::Windows::Forms::Label());
			this->tabCalendar = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->tabAdvancedsettings = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numSeconds))->BeginInit();
			this->tabStartMeasurements->SuspendLayout();
			this->tabInterval->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numDays))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numHours))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numMinutes))->BeginInit();
			this->tabCalendar->SuspendLayout();
			this->tabAdvancedsettings->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblEndAcquisitionTitle
			// 
			this->lblEndAcquisitionTitle->AutoSize = true;
			this->lblEndAcquisitionTitle->Location = System::Drawing::Point(37, 85);
			this->lblEndAcquisitionTitle->Name = L"lblEndAcquisitionTitle";
			this->lblEndAcquisitionTitle->Size = System::Drawing::Size(101, 13);
			this->lblEndAcquisitionTitle->TabIndex = 0;
			this->lblEndAcquisitionTitle->Text = L"Measurements until:";
			// 
			// btnStart
			// 
			this->btnStart->Enabled = false;
			this->btnStart->Location = System::Drawing::Point(550, 266);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"&Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Start::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(456, 266);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"&Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Start::button2_Click);
			// 
			// lblInterval
			// 
			this->lblInterval->AutoSize = true;
			this->lblInterval->Location = System::Drawing::Point(37, 43);
			this->lblInterval->Name = L"lblInterval";
			this->lblInterval->Size = System::Drawing::Size(45, 13);
			this->lblInterval->TabIndex = 3;
			this->lblInterval->Text = L"Interval:";
			this->lblInterval->Click += gcnew System::EventHandler(this, &Start::label1_Click);
			// 
			// numSeconds
			// 
			this->numSeconds->Location = System::Drawing::Point(95, 39);
			this->numSeconds->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numSeconds->Name = L"numSeconds";
			this->numSeconds->Size = System::Drawing::Size(50, 20);
			this->numSeconds->TabIndex = 4;
			this->numSeconds->ValueChanged += gcnew System::EventHandler(this, &Start::numSeconds_ValueChanged);
			// 
			// tabStartMeasurements
			// 
			this->tabStartMeasurements->Controls->Add(this->tabInterval);
			this->tabStartMeasurements->Controls->Add(this->tabCalendar);
			this->tabStartMeasurements->Controls->Add(this->tabAdvancedsettings);
			this->tabStartMeasurements->Location = System::Drawing::Point(12, 12);
			this->tabStartMeasurements->Name = L"tabStartMeasurements";
			this->tabStartMeasurements->SelectedIndex = 0;
			this->tabStartMeasurements->Size = System::Drawing::Size(617, 248);
			this->tabStartMeasurements->TabIndex = 5;
			// 
			// tabInterval
			// 
			this->tabInterval->Controls->Add(this->lblEndAcquisition);
			this->tabInterval->Controls->Add(this->lblDays);
			this->tabInterval->Controls->Add(this->numDays);
			this->tabInterval->Controls->Add(this->lblHours);
			this->tabInterval->Controls->Add(this->numHours);
			this->tabInterval->Controls->Add(this->lblMinutes);
			this->tabInterval->Controls->Add(this->numMinutes);
			this->tabInterval->Controls->Add(this->lblSecond);
			this->tabInterval->Controls->Add(this->numSeconds);
			this->tabInterval->Controls->Add(this->lblInterval);
			this->tabInterval->Controls->Add(this->lblEndAcquisitionTitle);
			this->tabInterval->Location = System::Drawing::Point(4, 22);
			this->tabInterval->Name = L"tabInterval";
			this->tabInterval->Padding = System::Windows::Forms::Padding(3);
			this->tabInterval->Size = System::Drawing::Size(609, 222);
			this->tabInterval->TabIndex = 0;
			this->tabInterval->Text = L"Interval";
			this->tabInterval->UseVisualStyleBackColor = true;
			// 
			// lblEndAcquisition
			// 
			this->lblEndAcquisition->AutoSize = true;
			this->lblEndAcquisition->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblEndAcquisition->Location = System::Drawing::Point(146, 85);
			this->lblEndAcquisition->Name = L"lblEndAcquisition";
			this->lblEndAcquisition->Size = System::Drawing::Size(63, 13);
			this->lblEndAcquisition->TabIndex = 12;
			this->lblEndAcquisition->Text = L"undefined";
			// 
			// lblDays
			// 
			this->lblDays->AutoSize = true;
			this->lblDays->Location = System::Drawing::Point(502, 43);
			this->lblDays->Name = L"lblDays";
			this->lblDays->Size = System::Drawing::Size(31, 13);
			this->lblDays->TabIndex = 11;
			this->lblDays->Text = L"Days";
			// 
			// numDays
			// 
			this->numDays->Location = System::Drawing::Point(451, 39);
			this->numDays->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->numDays->Name = L"numDays";
			this->numDays->Size = System::Drawing::Size(50, 20);
			this->numDays->TabIndex = 10;
			this->numDays->ValueChanged += gcnew System::EventHandler(this, &Start::numDays_ValueChanged);
			// 
			// lblHours
			// 
			this->lblHours->AutoSize = true;
			this->lblHours->Location = System::Drawing::Point(391, 43);
			this->lblHours->Name = L"lblHours";
			this->lblHours->Size = System::Drawing::Size(35, 13);
			this->lblHours->TabIndex = 9;
			this->lblHours->Text = L"Hours";
			// 
			// numHours
			// 
			this->numHours->Location = System::Drawing::Point(340, 39);
			this->numHours->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {23, 0, 0, 0});
			this->numHours->Name = L"numHours";
			this->numHours->Size = System::Drawing::Size(50, 20);
			this->numHours->TabIndex = 8;
			this->numHours->ValueChanged += gcnew System::EventHandler(this, &Start::numHours_ValueChanged);
			// 
			// lblMinutes
			// 
			this->lblMinutes->AutoSize = true;
			this->lblMinutes->Location = System::Drawing::Point(271, 43);
			this->lblMinutes->Name = L"lblMinutes";
			this->lblMinutes->Size = System::Drawing::Size(44, 13);
			this->lblMinutes->TabIndex = 7;
			this->lblMinutes->Text = L"Minutes";
			// 
			// numMinutes
			// 
			this->numMinutes->Location = System::Drawing::Point(220, 39);
			this->numMinutes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {59, 0, 0, 0});
			this->numMinutes->Name = L"numMinutes";
			this->numMinutes->Size = System::Drawing::Size(50, 20);
			this->numMinutes->TabIndex = 6;
			this->numMinutes->ValueChanged += gcnew System::EventHandler(this, &Start::numMinutes_ValueChanged);
			// 
			// lblSecond
			// 
			this->lblSecond->AutoSize = true;
			this->lblSecond->Location = System::Drawing::Point(146, 43);
			this->lblSecond->Name = L"lblSecond";
			this->lblSecond->Size = System::Drawing::Size(49, 13);
			this->lblSecond->TabIndex = 5;
			this->lblSecond->Text = L"Seconds";
			// 
			// tabCalendar
			// 
			this->tabCalendar->Controls->Add(this->label1);
			this->tabCalendar->Controls->Add(this->dateTimePicker1);
			this->tabCalendar->Location = System::Drawing::Point(4, 22);
			this->tabCalendar->Name = L"tabCalendar";
			this->tabCalendar->Padding = System::Windows::Forms::Padding(3);
			this->tabCalendar->Size = System::Drawing::Size(609, 222);
			this->tabCalendar->TabIndex = 1;
			this->tabCalendar->Text = L"Calendar";
			this->tabCalendar->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"NOT YET IMPLEMENTED";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(27, 54);
			this->dateTimePicker1->MinDate = System::DateTime(2013, 5, 9, 0, 0, 0, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 0;
			// 
			// tabAdvancedsettings
			// 
			this->tabAdvancedsettings->Controls->Add(this->label2);
			this->tabAdvancedsettings->Location = System::Drawing::Point(4, 22);
			this->tabAdvancedsettings->Name = L"tabAdvancedsettings";
			this->tabAdvancedsettings->Size = System::Drawing::Size(609, 222);
			this->tabAdvancedsettings->TabIndex = 2;
			this->tabAdvancedsettings->Text = L"Advanced settings";
			this->tabAdvancedsettings->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(43, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"No Yet Implemented";
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(641, 315);
			this->Controls->Add(this->tabStartMeasurements);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnStart);
			this->Name = L"Start";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Timespan";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Start::Start_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numSeconds))->EndInit();
			this->tabStartMeasurements->ResumeLayout(false);
			this->tabInterval->ResumeLayout(false);
			this->tabInterval->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numDays))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numHours))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numMinutes))->EndInit();
			this->tabCalendar->ResumeLayout(false);
			this->tabCalendar->PerformLayout();
			this->tabAdvancedsettings->ResumeLayout(false);
			this->tabAdvancedsettings->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 intervalTotal=0;
				 this->Close();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void numSeconds_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 intervalSeconds = Convert::ToInt32(numSeconds->Value);
			 upDateInterval();
		 }
private: void upDateInterval()
		  {
			  DateTime now = System::DateTime::Now;
			  intervalTotal = (intervalSeconds+intervalMinutes*60+intervalHours*3600+intervalDays*86400)*numdat;
			  DateTime dateend = now.AddSeconds(intervalTotal);
			  
			  if(intervalTotal!=0)
			  {
				  lblEndAcquisition->Text="  "+Convert::ToString(dateend.DayOfWeek)+" "+Convert::ToString(dateend);
				  btnStart->Enabled=true;
			  }
			  else
			  {
				  lblEndAcquisition->Text="undefined";
				  btnStart->Enabled=false;
			  }
		  }
private: System::Void numMinutes_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 intervalMinutes = Convert::ToInt32(numMinutes->Value);
			 upDateInterval();
		 }
private: System::Void numHours_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 intervalHours = Convert::ToInt32(numHours->Value);
			 upDateInterval();
		 }
private: System::Void numDays_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 intervalDays = Convert::ToInt32(numDays->Value);
			 upDateInterval();
		 }
private: System::Void Start_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
