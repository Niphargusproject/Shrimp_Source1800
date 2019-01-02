#pragma once

namespace DataTrimming {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ProbeNumber
	/// </summary>
	public ref class ProbeNumber : public System::Windows::Forms::Form
	{
	public:
		ProbeNumber(void)
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
		~ProbeNumber()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  lblCurrentProbeNumber;
	protected: 
	private: System::Windows::Forms::Button^  btnModify;
	private: System::Windows::Forms::Button^  btnExit;

	public: System::Windows::Forms::TextBox^  tboxProbeNumber;

	public: 
		int ModifiedNumber;
		int iflag;
	private: System::Windows::Forms::Label^  lblCaution;
	public: 
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
			this->lblCurrentProbeNumber = (gcnew System::Windows::Forms::Label());
			this->btnModify = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->tboxProbeNumber = (gcnew System::Windows::Forms::TextBox());
			this->lblCaution = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblCurrentProbeNumber
			// 
			this->lblCurrentProbeNumber->AutoSize = true;
			this->lblCurrentProbeNumber->Location = System::Drawing::Point(46, 78);
			this->lblCurrentProbeNumber->Name = L"lblCurrentProbeNumber";
			this->lblCurrentProbeNumber->Size = System::Drawing::Size(85, 13);
			this->lblCurrentProbeNumber->TabIndex = 0;
			this->lblCurrentProbeNumber->Text = L"Current Probe #:";
			// 
			// btnModify
			// 
			this->btnModify->BackColor = System::Drawing::Color::Red;
			this->btnModify->Location = System::Drawing::Point(263, 73);
			this->btnModify->Name = L"btnModify";
			this->btnModify->Size = System::Drawing::Size(75, 23);
			this->btnModify->TabIndex = 1;
			this->btnModify->Text = L"Modify";
			this->btnModify->UseVisualStyleBackColor = false;
			this->btnModify->Click += gcnew System::EventHandler(this, &ProbeNumber::btnModify_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(263, 138);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &ProbeNumber::btnExit_Click);
			// 
			// tboxProbeNumber
			// 
			this->tboxProbeNumber->Location = System::Drawing::Point(146, 75);
			this->tboxProbeNumber->Name = L"tboxProbeNumber";
			this->tboxProbeNumber->Size = System::Drawing::Size(89, 20);
			this->tboxProbeNumber->TabIndex = 4;
			// 
			// lblCaution
			// 
			this->lblCaution->AutoSize = true;
			this->lblCaution->Location = System::Drawing::Point(32, 35);
			this->lblCaution->Name = L"lblCaution";
			this->lblCaution->Size = System::Drawing::Size(397, 13);
			this->lblCaution->TabIndex = 5;
			this->lblCaution->Text = L"! IF YOU MODIFY THE PROBE NUMBER EXISTING DATA WILL BE DELETED! ";
			this->lblCaution->Click += gcnew System::EventHandler(this, &ProbeNumber::lblCaution_Click);
			// 
			// ProbeNumber
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(441, 192);
			this->Controls->Add(this->lblCaution);
			this->Controls->Add(this->tboxProbeNumber);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnModify);
			this->Controls->Add(this->lblCurrentProbeNumber);
			this->Name = L"ProbeNumber";
			this->Text = L"ProbeNumber";
			this->Load += gcnew System::EventHandler(this, &ProbeNumber::ProbeNumber_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void btnModify_Click(System::Object^  sender, System::EventArgs^  e) {
				//ProbeNum = 5;
			 ModifiedNumber=Convert::ToInt32(tboxProbeNumber->Text);
			 iflag=1;
				this->Close();
		 }
private: System::Void ProbeNumber_Load(System::Object^  sender, System::EventArgs^  e) {
			 //Form1::createNIPHA();
			 iflag = 0;

		 }
private: System::Void lblCaution_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
