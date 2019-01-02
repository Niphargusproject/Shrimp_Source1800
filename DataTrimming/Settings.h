#pragma once
//#include "Form1.h"
#include "ProbeNumber.h"

namespace DataTrimming {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
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
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  lblDateOn;

	private: System::Windows::Forms::Button^  btnExit;
	public: System::Windows::Forms::Label^  lblInterval;
	public: System::Windows::Forms::Label^  lblTempCal;
	public: System::Windows::Forms::Label^  lblNiphVersionSetting;

	public: System::Windows::Forms::Label^  lblMedianVal;
	public: System::Windows::Forms::Label^  lblMeasureCount;
	public: System::Windows::Forms::Label^  lblIDSonde;
	public: System::Windows::Forms::Label^  lblDateOnConnect;
	public: System::Windows::Forms::Label^  lblBattery;
	public: 
	public: System::Windows::Forms::Label^  lblTemperature;

	public: 




	public: 
	protected: 

	public:
		int ProbeNum;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
			this->lblDateOn = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->lblInterval = (gcnew System::Windows::Forms::Label());
			this->lblTempCal = (gcnew System::Windows::Forms::Label());
			this->lblNiphVersionSetting = (gcnew System::Windows::Forms::Label());
			this->lblMedianVal = (gcnew System::Windows::Forms::Label());
			this->lblMeasureCount = (gcnew System::Windows::Forms::Label());
			this->lblIDSonde = (gcnew System::Windows::Forms::Label());
			this->lblDateOnConnect = (gcnew System::Windows::Forms::Label());
			this->lblBattery = (gcnew System::Windows::Forms::Label());
			this->lblTemperature = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblDateOn
			// 
			this->lblDateOn->AutoSize = true;
			this->lblDateOn->Location = System::Drawing::Point(35, 34);
			this->lblDateOn->Name = L"lblDateOn";
			this->lblDateOn->Size = System::Drawing::Size(93, 13);
			this->lblDateOn->TabIndex = 0;
			this->lblDateOn->Text = L"Date and time On:";
			this->lblDateOn->Click += gcnew System::EventHandler(this, &Settings::lblDateOn_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(41, 330);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"&Close";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Settings::btnExit_Click);
			// 
			// lblInterval
			// 
			this->lblInterval->AutoSize = true;
			this->lblInterval->Location = System::Drawing::Point(35, 92);
			this->lblInterval->Name = L"lblInterval";
			this->lblInterval->Size = System::Drawing::Size(48, 13);
			this->lblInterval->TabIndex = 2;
			this->lblInterval->Text = L"Interval :";
			// 
			// lblTempCal
			// 
			this->lblTempCal->AutoSize = true;
			this->lblTempCal->Location = System::Drawing::Point(35, 121);
			this->lblTempCal->Name = L"lblTempCal";
			this->lblTempCal->Size = System::Drawing::Size(99, 13);
			this->lblTempCal->TabIndex = 3;
			this->lblTempCal->Text = L"Temperature offset:";
			// 
			// lblNiphVersionSetting
			// 
			this->lblNiphVersionSetting->AutoSize = true;
			this->lblNiphVersionSetting->Location = System::Drawing::Point(35, 150);
			this->lblNiphVersionSetting->Name = L"lblNiphVersionSetting";
			this->lblNiphVersionSetting->Size = System::Drawing::Size(85, 13);
			this->lblNiphVersionSetting->TabIndex = 4;
			this->lblNiphVersionSetting->Text = L"Firmwire version:";
			// 
			// lblMedianVal
			// 
			this->lblMedianVal->AutoSize = true;
			this->lblMedianVal->Location = System::Drawing::Point(35, 179);
			this->lblMedianVal->Name = L"lblMedianVal";
			this->lblMedianVal->Size = System::Drawing::Size(149, 13);
			this->lblMedianVal->TabIndex = 5;
			this->lblMedianVal->Text = L"Number of records for median:";
			// 
			// lblMeasureCount
			// 
			this->lblMeasureCount->AutoSize = true;
			this->lblMeasureCount->Location = System::Drawing::Point(35, 208);
			this->lblMeasureCount->Name = L"lblMeasureCount";
			this->lblMeasureCount->Size = System::Drawing::Size(132, 13);
			this->lblMeasureCount->TabIndex = 6;
			this->lblMeasureCount->Text = L"Current number of records:";
			// 
			// lblIDSonde
			// 
			this->lblIDSonde->AutoSize = true;
			this->lblIDSonde->Location = System::Drawing::Point(35, 295);
			this->lblIDSonde->Name = L"lblIDSonde";
			this->lblIDSonde->Size = System::Drawing::Size(76, 13);
			this->lblIDSonde->TabIndex = 7;
			this->lblIDSonde->Text = L"Probe number:";
			// 
			// lblDateOnConnect
			// 
			this->lblDateOnConnect->AutoSize = true;
			this->lblDateOnConnect->Location = System::Drawing::Point(35, 63);
			this->lblDateOnConnect->Name = L"lblDateOnConnect";
			this->lblDateOnConnect->Size = System::Drawing::Size(133, 13);
			this->lblDateOnConnect->TabIndex = 8;
			this->lblDateOnConnect->Text = L"Date and time on connect:";
			// 
			// lblBattery
			// 
			this->lblBattery->AutoSize = true;
			this->lblBattery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblBattery->Location = System::Drawing::Point(38, 237);
			this->lblBattery->Name = L"lblBattery";
			this->lblBattery->Size = System::Drawing::Size(51, 13);
			this->lblBattery->TabIndex = 9;
			this->lblBattery->Text = L"Battery:";
			// 
			// lblTemperature
			// 
			this->lblTemperature->AutoSize = true;
			this->lblTemperature->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblTemperature->Location = System::Drawing::Point(38, 266);
			this->lblTemperature->Name = L"lblTemperature";
			this->lblTemperature->Size = System::Drawing::Size(127, 13);
			this->lblTemperature->TabIndex = 10;
			this->lblTemperature->Text = L"Current Temperature:";
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(313, 377);
			this->Controls->Add(this->lblTemperature);
			this->Controls->Add(this->lblBattery);
			this->Controls->Add(this->lblDateOnConnect);
			this->Controls->Add(this->lblIDSonde);
			this->Controls->Add(this->lblMeasureCount);
			this->Controls->Add(this->lblMedianVal);
			this->Controls->Add(this->lblNiphVersionSetting);
			this->Controls->Add(this->lblTempCal);
			this->Controls->Add(this->lblInterval);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->lblDateOn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Settings";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lblDateOn_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void Settings_Load(System::Object^  sender, System::EventArgs^  e) {
				 //int Day;
				 //int Month;
				 //int Year;

				 //Day=Convert::ToInt16(DataTrimming::Form1->N.day_on);
				 
				 //this->lblDateOn->Text=L"Date On:"+Convert::ToString(N.day_on);
			 }
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void btnAdvancedSetting_Click(System::Object^  sender, System::EventArgs^  e) {
				//String ^ niphargusParam;
				ProbeNumber ^form4 = gcnew ProbeNumber(); 

				//form4->lblCurrentProbeNumber->Text="Current Probe #:"+Convert::ToString(ProbeNum);
				form4->tboxProbeNumber->Text=Convert::ToString(ProbeNum);

				//array<unsigned char>^ bufferDI = {'#'};
				//this->serialPort1->Write(bufferDI,0,1);
				//niphargusParam = this->serialPort1->ReadLine();
				/*if(niphargusParam->Length<5)
				{
					niphargusParam=this->serialPort1->ReadLine();
				}*/
				form4->ShowDialog();
				if(form4->iflag==1)
				{
					ProbeNum=form4->ModifiedNumber;
					this->lblIDSonde->Text="Probe number: "+Convert::ToString(ProbeNum);
				}
			 }
};
}
