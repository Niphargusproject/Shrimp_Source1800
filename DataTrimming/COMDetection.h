#pragma once

namespace DataTrimming {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for COMDetection
	/// </summary>
	public ref class COMDetection : public System::Windows::Forms::Form
	{
	public:
		COMDetection(void)
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
		~COMDetection()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblCOMDetection;
	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(COMDetection::typeid));
			this->lblCOMDetection = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblCOMDetection
			// 
			this->lblCOMDetection->AutoSize = true;
			this->lblCOMDetection->Location = System::Drawing::Point(146, 26);
			this->lblCOMDetection->Name = L"lblCOMDetection";
			this->lblCOMDetection->Size = System::Drawing::Size(172, 13);
			this->lblCOMDetection->TabIndex = 0;
			this->lblCOMDetection->Text = L"Searching COM Port ... please wait";
			// 
			// COMDetection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 67);
			this->Controls->Add(this->lblCOMDetection);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"COMDetection";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"COMDetection";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
