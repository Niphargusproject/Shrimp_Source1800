
#pragma once


#include "Settings.h"
#include "Downloading.h"
#include "COMDetection.h"
#include "niphargus.h"
#include "Start.h"
#include "Splashscreen.h"
#include <Windows.h>
#using <mscorlib.dll>




	


namespace DataTrimming {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Text;
	using namespace Microsoft::Win32;

	
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::ComponentModel::IContainer^  components;

	public:
		int PreviousProbeNumber;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		// My variables
		String ^ strline;
		String ^ strSubString;
		static NIPHARGUS ^N = gcnew NIPHARGUS;

		DateTime date1;
		String ^ strDateTime;
		static String^ delimStr = ",	; "; //List of delimiters applied during parsing file or serial communication
		static String^ delimStr2 = "\n";
		static String^ delimStr3 = "<>;";
		static int firstLine;
		bool endReadingFile;
		String ^ fileContent;
		String ^ fileStatuts;
		static array<Char>^ delimiter = delimStr->ToCharArray();
		static array<Char>^ separator = delimStr2->ToCharArray();
		static array<Char>^ delimiter3 = delimStr3->ToCharArray();
		static int nData = 26000;
		int nDataMax;
		double niphVersion;
		bool bIsDetected;
		double AutoMaxX;
		double AutoMinX;
		double AutoMaxY;
		double AutoMinY;
		double tempMin;
		double tempMax;
		DateTime dateMin;
		DateTime dateMax;
		static array<DateTime^>^ recordedDateTime = gcnew array<DateTime^>(nData);
		static array<Double^>^ temperature = gcnew array<Double^>(nData);

		
		//array<Double^>^ initYvalues = gcnew array<Double^>(2);
		//initYvalues = gcnew array<Double^>(2);
		static array<Double>^ initYvalues = {0.0,20.0};

		//initYvalues[0]=Convert::ToDouble("0.0");
		//initYvalues[1]=Convert::ToDouble("20.0");
		DateTime xMin;
		DateTime xMax;
		double yMin;
		double yMax;

		
	//NIPHARGUS N = gcnew NIPHARGUS;


	private: System::IO::Ports::SerialPort^  serialPort1;




	private: System::Windows::Forms::CheckBox^  chkAutoScale;

	private: System::Windows::Forms::Label^  lblXmin;
	private: System::Windows::Forms::Label^  lblXmax;
	private: System::Windows::Forms::Label^  lblYmin;
	private: System::Windows::Forms::Label^  lblYmax;
	private: System::Windows::Forms::TextBox^  tboxXmin;
	private: System::Windows::Forms::TextBox^  tboxXmax;

	private: System::Windows::Forms::TextBox^  tboxYmax;
	private: System::Windows::Forms::Button^  btnUpdate;

	private: System::Windows::Forms::Label^  lblComment1;
	private: System::Windows::Forms::TextBox^  tbxComment1;
	private: System::Windows::Forms::Label^  lblComment2;
	private: System::Windows::Forms::TextBox^  tbxComment2;


	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;


	private: System::Windows::Forms::Label^  lblFileStatuts;
	private: System::Windows::Forms::CheckBox^  chkHeaderToFile;

private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::TextBox^  tboxYmin;
private: System::Windows::Forms::Button^  btnExit;
private: System::Windows::Forms::Button^  btnLoadData;
private: System::Windows::Forms::Button^  btnSaveData;
private: System::Windows::Forms::Button^  btnDetect;
private: System::Windows::Forms::Button^  bntDisconnect;
private: System::Windows::Forms::Label^  lblDetectedCOMPort;
private: System::Windows::Forms::Button^  btnSetting;
private: System::Windows::Forms::ProgressBar^  progressBar1;
private: System::Windows::Forms::Button^  btnDownload;
private: System::Windows::Forms::Button^  btnStart;
private: System::Windows::Forms::Label^  lblCOM;
private: System::Windows::Forms::ComboBox^  cBoxCom;
private: System::Windows::Forms::Label^  lblBaudRate;
private: System::Windows::Forms::ComboBox^  cBoxBaud;
private: System::Windows::Forms::CheckBox^  chBoxCom;
private: System::Windows::Forms::Label^  lblManualCOM;
private: System::Windows::Forms::Label^  lblNiphVersion;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::GroupBox^  groupBox2;












	private: System::Windows::Forms::DataVisualization::Charting::Chart^  plt1;

			 
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->plt1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->chkAutoScale = (gcnew System::Windows::Forms::CheckBox());
			this->lblXmin = (gcnew System::Windows::Forms::Label());
			this->lblXmax = (gcnew System::Windows::Forms::Label());
			this->lblYmin = (gcnew System::Windows::Forms::Label());
			this->lblYmax = (gcnew System::Windows::Forms::Label());
			this->tboxXmin = (gcnew System::Windows::Forms::TextBox());
			this->tboxXmax = (gcnew System::Windows::Forms::TextBox());
			this->tboxYmax = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->lblComment1 = (gcnew System::Windows::Forms::Label());
			this->tbxComment1 = (gcnew System::Windows::Forms::TextBox());
			this->lblComment2 = (gcnew System::Windows::Forms::Label());
			this->tbxComment2 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->lblFileStatuts = (gcnew System::Windows::Forms::Label());
			this->chkHeaderToFile = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tboxYmin = (gcnew System::Windows::Forms::TextBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnLoadData = (gcnew System::Windows::Forms::Button());
			this->btnSaveData = (gcnew System::Windows::Forms::Button());
			this->btnDetect = (gcnew System::Windows::Forms::Button());
			this->bntDisconnect = (gcnew System::Windows::Forms::Button());
			this->lblDetectedCOMPort = (gcnew System::Windows::Forms::Label());
			this->btnSetting = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->btnDownload = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->lblCOM = (gcnew System::Windows::Forms::Label());
			this->cBoxCom = (gcnew System::Windows::Forms::ComboBox());
			this->lblBaudRate = (gcnew System::Windows::Forms::Label());
			this->cBoxBaud = (gcnew System::Windows::Forms::ComboBox());
			this->chBoxCom = (gcnew System::Windows::Forms::CheckBox());
			this->lblManualCOM = (gcnew System::Windows::Forms::Label());
			this->lblNiphVersion = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->plt1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// plt1
			// 
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::Chocolate;
			chartArea1->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->AxisX->Title = L"Date";
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::Chocolate;
			chartArea1->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->AxisY->Title = L"Temperature";
			chartArea1->Name = L"ChartArea1";
			this->plt1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->plt1->Legends->Add(legend1);
			this->plt1->Location = System::Drawing::Point(24, 25);
			this->plt1->Name = L"plt1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Transparent;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			this->plt1->Series->Add(series1);
			this->plt1->Size = System::Drawing::Size(692, 361);
			this->plt1->TabIndex = 0;
			this->plt1->Text = L"Plot";
			this->plt1->AxisViewChanged += gcnew System::EventHandler<System::Windows::Forms::DataVisualization::Charting::ViewEventArgs^ >(this, &Form1::plt1_AxisViewChanged);
			this->plt1->MarginChanged += gcnew System::EventHandler(this, &Form1::plt1_MarginChanged);
			this->plt1->Click += gcnew System::EventHandler(this, &Form1::plt1_Click);
			this->plt1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::plt1_Paint);
			// 
			// chkAutoScale
			// 
			this->chkAutoScale->AutoSize = true;
			this->chkAutoScale->Checked = true;
			this->chkAutoScale->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkAutoScale->Enabled = false;
			this->chkAutoScale->Location = System::Drawing::Point(13, 17);
			this->chkAutoScale->Name = L"chkAutoScale";
			this->chkAutoScale->Size = System::Drawing::Size(103, 17);
			this->chkAutoScale->TabIndex = 7;
			this->chkAutoScale->Text = L"Auto scale chart";
			this->chkAutoScale->UseVisualStyleBackColor = true;
			this->chkAutoScale->CheckedChanged += gcnew System::EventHandler(this, &Form1::chkAutoScale_CheckedChanged);
			// 
			// lblXmin
			// 
			this->lblXmin->AutoSize = true;
			this->lblXmin->Enabled = false;
			this->lblXmin->Location = System::Drawing::Point(13, 59);
			this->lblXmin->Name = L"lblXmin";
			this->lblXmin->Size = System::Drawing::Size(33, 13);
			this->lblXmin->TabIndex = 7;
			this->lblXmin->Text = L"X-min";
			// 
			// lblXmax
			// 
			this->lblXmax->AutoSize = true;
			this->lblXmax->Enabled = false;
			this->lblXmax->Location = System::Drawing::Point(13, 120);
			this->lblXmax->Name = L"lblXmax";
			this->lblXmax->Size = System::Drawing::Size(36, 13);
			this->lblXmax->TabIndex = 8;
			this->lblXmax->Text = L"X-max";
			// 
			// lblYmin
			// 
			this->lblYmin->AutoSize = true;
			this->lblYmin->Enabled = false;
			this->lblYmin->Location = System::Drawing::Point(13, 178);
			this->lblYmin->Name = L"lblYmin";
			this->lblYmin->Size = System::Drawing::Size(33, 13);
			this->lblYmin->TabIndex = 9;
			this->lblYmin->Text = L"Y-min";
			// 
			// lblYmax
			// 
			this->lblYmax->AutoSize = true;
			this->lblYmax->Enabled = false;
			this->lblYmax->Location = System::Drawing::Point(13, 237);
			this->lblYmax->Name = L"lblYmax";
			this->lblYmax->Size = System::Drawing::Size(36, 13);
			this->lblYmax->TabIndex = 12;
			this->lblYmax->Text = L"Y-max";
			// 
			// tboxXmin
			// 
			this->tboxXmin->Enabled = false;
			this->tboxXmin->Location = System::Drawing::Point(13, 76);
			this->tboxXmin->Name = L"tboxXmin";
			this->tboxXmin->Size = System::Drawing::Size(147, 20);
			this->tboxXmin->TabIndex = 9;
			this->tboxXmin->Enter += gcnew System::EventHandler(this, &Form1::tboxXmin_Enter);
			// 
			// tboxXmax
			// 
			this->tboxXmax->Enabled = false;
			this->tboxXmax->Location = System::Drawing::Point(13, 137);
			this->tboxXmax->Name = L"tboxXmax";
			this->tboxXmax->Size = System::Drawing::Size(144, 20);
			this->tboxXmax->TabIndex = 10;
			this->tboxXmax->TextChanged += gcnew System::EventHandler(this, &Form1::tboxXmax_TextChanged);
			this->tboxXmax->Enter += gcnew System::EventHandler(this, &Form1::tboxXmax_Enter);
			// 
			// tboxYmax
			// 
			this->tboxYmax->Enabled = false;
			this->tboxYmax->Location = System::Drawing::Point(13, 254);
			this->tboxYmax->Name = L"tboxYmax";
			this->tboxYmax->Size = System::Drawing::Size(144, 20);
			this->tboxYmax->TabIndex = 12;
			this->tboxYmax->Enter += gcnew System::EventHandler(this, &Form1::tboxYmax_Enter);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Enabled = false;
			this->btnUpdate->Location = System::Drawing::Point(35, 290);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(97, 23);
			this->btnUpdate->TabIndex = 8;
			this->btnUpdate->Text = L"&Update chart";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Form1::btnUpdate_Click);
			// 
			// lblComment1
			// 
			this->lblComment1->AutoSize = true;
			this->lblComment1->Location = System::Drawing::Point(13, 333);
			this->lblComment1->Name = L"lblComment1";
			this->lblComment1->Size = System::Drawing::Size(57, 13);
			this->lblComment1->TabIndex = 13;
			this->lblComment1->Text = L"Comment1";
			// 
			// tbxComment1
			// 
			this->tbxComment1->Location = System::Drawing::Point(13, 357);
			this->tbxComment1->Name = L"tbxComment1";
			this->tbxComment1->Size = System::Drawing::Size(141, 20);
			this->tbxComment1->TabIndex = 14;
			// 
			// lblComment2
			// 
			this->lblComment2->AutoSize = true;
			this->lblComment2->Location = System::Drawing::Point(13, 384);
			this->lblComment2->Name = L"lblComment2";
			this->lblComment2->Size = System::Drawing::Size(57, 13);
			this->lblComment2->TabIndex = 15;
			this->lblComment2->Text = L"Comment2";
			// 
			// tbxComment2
			// 
			this->tbxComment2->Location = System::Drawing::Point(13, 408);
			this->tbxComment2->Name = L"tbxComment2";
			this->tbxComment2->Size = System::Drawing::Size(138, 20);
			this->tbxComment2->TabIndex = 16;
			// 
			// lblFileStatuts
			// 
			this->lblFileStatuts->AutoSize = true;
			this->lblFileStatuts->BackColor = System::Drawing::Color::White;
			this->lblFileStatuts->Location = System::Drawing::Point(638, 67);
			this->lblFileStatuts->Name = L"lblFileStatuts";
			this->lblFileStatuts->Size = System::Drawing::Size(71, 13);
			this->lblFileStatuts->TabIndex = 19;
			this->lblFileStatuts->Text = L"<File Statuts>";
			// 
			// chkHeaderToFile
			// 
			this->chkHeaderToFile->AutoSize = true;
			this->chkHeaderToFile->Checked = true;
			this->chkHeaderToFile->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkHeaderToFile->Location = System::Drawing::Point(13, 440);
			this->chkHeaderToFile->Name = L"chkHeaderToFile";
			this->chkHeaderToFile->Size = System::Drawing::Size(109, 17);
			this->chkHeaderToFile->TabIndex = 20;
			this->chkHeaderToFile->Text = L"Add header to file";
			this->chkHeaderToFile->UseVisualStyleBackColor = true;
			this->chkHeaderToFile->CheckedChanged += gcnew System::EventHandler(this, &Form1::chkHeaderToFile_CheckedChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->tboxYmin);
			this->panel2->Controls->Add(this->chkHeaderToFile);
			this->panel2->Controls->Add(this->lblXmax);
			this->panel2->Controls->Add(this->chkAutoScale);
			this->panel2->Controls->Add(this->btnExit);
			this->panel2->Controls->Add(this->lblXmin);
			this->panel2->Controls->Add(this->tbxComment2);
			this->panel2->Controls->Add(this->lblYmin);
			this->panel2->Controls->Add(this->lblComment2);
			this->panel2->Controls->Add(this->lblYmax);
			this->panel2->Controls->Add(this->tbxComment1);
			this->panel2->Controls->Add(this->tboxXmin);
			this->panel2->Controls->Add(this->lblComment1);
			this->panel2->Controls->Add(this->tboxXmax);
			this->panel2->Controls->Add(this->btnUpdate);
			this->panel2->Controls->Add(this->tboxYmax);
			this->panel2->Location = System::Drawing::Point(722, 4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(173, 563);
			this->panel2->TabIndex = 21;
			// 
			// tboxYmin
			// 
			this->tboxYmin->Enabled = false;
			this->tboxYmin->Location = System::Drawing::Point(13, 205);
			this->tboxYmin->Name = L"tboxYmin";
			this->tboxYmin->Size = System::Drawing::Size(144, 20);
			this->tboxYmin->TabIndex = 21;
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(16, 521);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(138, 23);
			this->btnExit->TabIndex = 6;
			this->btnExit->Text = L"E&xit Shrimp";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Form1::btnExit_Click);
			// 
			// btnLoadData
			// 
			this->btnLoadData->Location = System::Drawing::Point(13, 82);
			this->btnLoadData->Name = L"btnLoadData";
			this->btnLoadData->Size = System::Drawing::Size(174, 23);
			this->btnLoadData->TabIndex = 5;
			this->btnLoadData->Text = L"&Load log from .csv file";
			this->btnLoadData->UseVisualStyleBackColor = true;
			this->btnLoadData->Click += gcnew System::EventHandler(this, &Form1::btnLoadData_Click);
			// 
			// btnSaveData
			// 
			this->btnSaveData->Location = System::Drawing::Point(13, 53);
			this->btnSaveData->Name = L"btnSaveData";
			this->btnSaveData->Size = System::Drawing::Size(174, 23);
			this->btnSaveData->TabIndex = 4;
			this->btnSaveData->Text = L"&Save log to .csv file";
			this->btnSaveData->UseVisualStyleBackColor = true;
			this->btnSaveData->Click += gcnew System::EventHandler(this, &Form1::btnSaveData_Click);
			// 
			// btnDetect
			// 
			this->btnDetect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDetect->Location = System::Drawing::Point(110, 32);
			this->btnDetect->Name = L"btnDetect";
			this->btnDetect->Size = System::Drawing::Size(156, 23);
			this->btnDetect->TabIndex = 1;
			this->btnDetect->Text = L"&Connect Niphargus";
			this->btnDetect->UseVisualStyleBackColor = true;
			this->btnDetect->Click += gcnew System::EventHandler(this, &Form1::btnDetect_Click);
			// 
			// bntDisconnect
			// 
			this->bntDisconnect->Enabled = false;
			this->bntDisconnect->Location = System::Drawing::Point(110, 61);
			this->bntDisconnect->Name = L"bntDisconnect";
			this->bntDisconnect->Size = System::Drawing::Size(156, 23);
			this->bntDisconnect->TabIndex = 2;
			this->bntDisconnect->Text = L"Disconnec&t";
			this->bntDisconnect->UseVisualStyleBackColor = true;
			this->bntDisconnect->Click += gcnew System::EventHandler(this, &Form1::bntDisconnect_Click);
			// 
			// lblDetectedCOMPort
			// 
			this->lblDetectedCOMPort->AutoSize = true;
			this->lblDetectedCOMPort->Location = System::Drawing::Point(145, 133);
			this->lblDetectedCOMPort->Name = L"lblDetectedCOMPort";
			this->lblDetectedCOMPort->Size = System::Drawing::Size(126, 13);
			this->lblDetectedCOMPort->TabIndex = 17;
			this->lblDetectedCOMPort->Text = L"No Niphargus connected";
			this->lblDetectedCOMPort->Click += gcnew System::EventHandler(this, &Form1::lblDetectedCOMPort_Click);
			// 
			// btnSetting
			// 
			this->btnSetting->Enabled = false;
			this->btnSetting->Location = System::Drawing::Point(13, 51);
			this->btnSetting->Name = L"btnSetting";
			this->btnSetting->Size = System::Drawing::Size(162, 23);
			this->btnSetting->TabIndex = 3;
			this->btnSetting->Text = L"Check current se&ttings";
			this->btnSetting->UseVisualStyleBackColor = true;
			this->btnSetting->Click += gcnew System::EventHandler(this, &Form1::btnSetting_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(110, 133);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(29, 13);
			this->progressBar1->TabIndex = 18;
			// 
			// btnDownload
			// 
			this->btnDownload->Enabled = false;
			this->btnDownload->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDownload->ForeColor = System::Drawing::Color::Green;
			this->btnDownload->Location = System::Drawing::Point(13, 24);
			this->btnDownload->Name = L"btnDownload";
			this->btnDownload->Size = System::Drawing::Size(174, 23);
			this->btnDownload->TabIndex = 7;
			this->btnDownload->Text = L"&Download from Niphargus";
			this->btnDownload->UseVisualStyleBackColor = true;
			this->btnDownload->Click += gcnew System::EventHandler(this, &Form1::btnDownload_Click);
			// 
			// btnStart
			// 
			this->btnStart->Enabled = false;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(13, 22);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(162, 23);
			this->btnStart->TabIndex = 8;
			this->btnStart->Text = L"Start &new logging";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// lblCOM
			// 
			this->lblCOM->AutoSize = true;
			this->lblCOM->Location = System::Drawing::Point(11, 10);
			this->lblCOM->Name = L"lblCOM";
			this->lblCOM->Size = System::Drawing::Size(56, 13);
			this->lblCOM->TabIndex = 20;
			this->lblCOM->Text = L"COM Port:";
			// 
			// cBoxCom
			// 
			this->cBoxCom->Enabled = false;
			this->cBoxCom->FormattingEnabled = true;
			this->cBoxCom->Location = System::Drawing::Point(14, 77);
			this->cBoxCom->Name = L"cBoxCom";
			this->cBoxCom->Size = System::Drawing::Size(74, 21);
			this->cBoxCom->TabIndex = 21;
			this->cBoxCom->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cBoxCom_SelectedIndexChanged);
			this->cBoxCom->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::cBoxCom_KeyDown);
			this->cBoxCom->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::cBoxCom_MouseClick);
			// 
			// lblBaudRate
			// 
			this->lblBaudRate->AutoSize = true;
			this->lblBaudRate->Enabled = false;
			this->lblBaudRate->Location = System::Drawing::Point(11, 114);
			this->lblBaudRate->Name = L"lblBaudRate";
			this->lblBaudRate->Size = System::Drawing::Size(58, 13);
			this->lblBaudRate->TabIndex = 22;
			this->lblBaudRate->Text = L"Baud Rate";
			// 
			// cBoxBaud
			// 
			this->cBoxBaud->Enabled = false;
			this->cBoxBaud->FormattingEnabled = true;
			this->cBoxBaud->Location = System::Drawing::Point(14, 130);
			this->cBoxBaud->Name = L"cBoxBaud";
			this->cBoxBaud->Size = System::Drawing::Size(74, 21);
			this->cBoxBaud->TabIndex = 23;
			this->cBoxBaud->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cBoxBaud_SelectedIndexChanged);
			// 
			// chBoxCom
			// 
			this->chBoxCom->AutoSize = true;
			this->chBoxCom->Checked = true;
			this->chBoxCom->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chBoxCom->Location = System::Drawing::Point(14, 26);
			this->chBoxCom->Name = L"chBoxCom";
			this->chBoxCom->Size = System::Drawing::Size(48, 17);
			this->chBoxCom->TabIndex = 24;
			this->chBoxCom->Text = L"Auto";
			this->chBoxCom->UseVisualStyleBackColor = true;
			this->chBoxCom->CheckedChanged += gcnew System::EventHandler(this, &Form1::chBoxCom_CheckedChanged);
			// 
			// lblManualCOM
			// 
			this->lblManualCOM->AutoSize = true;
			this->lblManualCOM->Enabled = false;
			this->lblManualCOM->Location = System::Drawing::Point(14, 55);
			this->lblManualCOM->Name = L"lblManualCOM";
			this->lblManualCOM->Size = System::Drawing::Size(42, 13);
			this->lblManualCOM->TabIndex = 25;
			this->lblManualCOM->Text = L"Manual";
			// 
			// lblNiphVersion
			// 
			this->lblNiphVersion->AutoSize = true;
			this->lblNiphVersion->Location = System::Drawing::Point(107, 95);
			this->lblNiphVersion->Name = L"lblNiphVersion";
			this->lblNiphVersion->Size = System::Drawing::Size(92, 13);
			this->lblNiphVersion->TabIndex = 26;
			this->lblNiphVersion->Text = L"Firmware version :";
			this->lblNiphVersion->Click += gcnew System::EventHandler(this, &Form1::lblNiphVersion_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->lblNiphVersion);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->lblManualCOM);
			this->panel1->Controls->Add(this->chBoxCom);
			this->panel1->Controls->Add(this->cBoxBaud);
			this->panel1->Controls->Add(this->lblBaudRate);
			this->panel1->Controls->Add(this->cBoxCom);
			this->panel1->Controls->Add(this->lblCOM);
			this->panel1->Controls->Add(this->progressBar1);
			this->panel1->Controls->Add(this->lblDetectedCOMPort);
			this->panel1->Controls->Add(this->bntDisconnect);
			this->panel1->Controls->Add(this->btnDetect);
			this->panel1->Location = System::Drawing::Point(24, 392);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(692, 175);
			this->panel1->TabIndex = 3;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Controls->Add(this->btnDownload);
			this->groupBox2->Controls->Add(this->btnSaveData);
			this->groupBox2->Controls->Add(this->btnLoadData);
			this->groupBox2->Location = System::Drawing::Point(284, 10);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(199, 117);
			this->groupBox2->TabIndex = 23;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Data log management";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->btnStart);
			this->groupBox1->Controls->Add(this->btnSetting);
			this->groupBox1->Location = System::Drawing::Point(499, 10);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(186, 117);
			this->groupBox1->TabIndex = 22;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Niphargus setup";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(898, 588);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->lblFileStatuts);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->plt1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Shrimp";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &Form1::Form1_Layout);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->plt1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {

				 Application::Exit();
			 }
	private: System::Void btnLoadData_Click(System::Object^  sender, System::EventArgs^  e) {
			tempMin = 999.9;
			tempMax = -999.9;

		    openFileDialog1->Filter = "csv files (*.csv)|*.csv";
			openFileDialog1->Title = "Open a file";

			if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->plt1->Series[0]->Points->Clear();

				try
				{
					System::IO::StreamReader ^sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
												
					array<String^>^ lines;
					array<String^>^ words;
					bool res = false;
					String ^ FullPath;
					String ^ newSeriesName;
										
					FullPath = Convert::ToString(openFileDialog1->FileName);

					int position = FullPath->LastIndexOf('\\');
					newSeriesName = FullPath->Substring(position + 1);
					this->plt1->Series[0]->Name = newSeriesName;
					this->lblFileStatuts->Text="File";
					this->plt1->Series[newSeriesName]->Color=System::Drawing::Color::Green;

					fileContent = sr->ReadToEnd();
					
					lines = fileContent->Split(separator);

					// Manage an header in the file and potentialy fullfil the N-Structure
					res = ManageHeader(lines);
					if(!res)
					{
						//firstLine = 2;
						this->chkHeaderToFile->Checked=false;
					}


					for(int i = firstLine; i<=lines->Length;i++)
					{
						words = lines[i-2]->Split(delimiter);
						strDateTime=words[0]+" "+words[1];
						if(DateTime::TryParse(strDateTime,date1))
						{
							recordedDateTime[i-firstLine]=date1;
							temperature[i-firstLine]=Convert::ToDouble(words[2]);
							this->plt1->Series[newSeriesName]->Points->AddXY(date1,words[2]);
						}
						else
						{
							MessageBox::Show("ERROR while reading file");
							endReadingFile=true;
						}
						if(i==firstLine)
						{
							tempMin=Convert::ToDouble(temperature[i-firstLine]);
							tempMax=Convert::ToDouble(temperature[i-firstLine]);
							dateMin=date1;
							dateMax=date1;
						}
						else
						{
							if(Convert::ToDouble(temperature[i-firstLine])<tempMin) tempMin=Convert::ToDouble(temperature[i-firstLine]);
							if(Convert::ToDouble(temperature[i-firstLine])>tempMax) tempMax=Convert::ToDouble(temperature[i-firstLine]);
							if(date1<dateMin) dateMin=date1;
							if(date1>dateMax) dateMax=date1;
						}
					}
					
					sr->Close();
					

					AutoMaxX = -999;
					AutoMinX = -999;
					AutoMaxY = tempMax;
					AutoMinY = tempMin;
					this->chkAutoScale->Checked=true;
					Application::DoEvents();
					double tata = this->plt1->ChartAreas[0]->AxisX->Maximum;
					DateTime dt = DateTime::FromOADate(tata);
					tboxXmax->Text = Convert::ToString(dt);
					tata = this->plt1->ChartAreas[0]->AxisX->Minimum;
					dt = DateTime::FromOADate(tata);
					tboxXmin->Text = Convert::ToString(dt);
					this->plt1->ChartAreas[0]->AxisY->Maximum::set(AutoMaxY);
					tboxYmax->Text = Convert::ToString(AutoMaxY);
					this->plt1->ChartAreas[0]->AxisY->Minimum::set(AutoMinY);
					tboxYmin->Text = Convert::ToString(AutoMinY);
					this->chkAutoScale->Enabled=true;
					Application::DoEvents();

				}	
				catch(System::IO::IOException ^)
				{
					MessageBox::Show("Impossible to load this file\nA file with the same name is probably opened by another application\n\nPlease close this file before to try again to save","ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
				}

			}	
		}

		
private: System::Void chkAutoScale_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(chkAutoScale->Checked)
			 {
				this->lblXmin->Enabled = false;
				this->lblXmax->Enabled = false;
				this->lblYmin->Enabled = false;
				this->lblYmax->Enabled = false;
				this->tboxXmin->Enabled = false;
				this->tboxXmax->Enabled = false;
				this->tboxYmin->Enabled = false;
				this->tboxYmax->Enabled = false;
				this->btnUpdate->Enabled = false;
				
				/*double tata = this->plt1->ChartAreas[0]->AxisX->Maximum;
				if(AutoMaxX==0.0) AutoMaxX=tata;
				tata = this->plt1->ChartAreas[0]->AxisX->Minimum;
				if(AutoMinX==0.0) AutoMinX=tata;
				tata = this->plt1->ChartAreas[0]->AxisY->Maximum;
				if(AutoMaxY==0.0) AutoMaxY=tata;
				tata = this->plt1->ChartAreas[0]->AxisY->Minimum;
				if(AutoMinY==0.0) AutoMinY=tata;*/
				this->plt1->ChartAreas[0]->AxisY->Minimum::set(tempMin);
				this->tboxYmin->Text=Convert::ToString(tempMin);
				this->plt1->ChartAreas[0]->AxisY->Maximum::set(tempMax);
				this->tboxYmax->Text=Convert::ToString(tempMax);
				double dbleftbound = dateMin.ToOADate();
				
				this->plt1->ChartAreas[0]->AxisX->Minimum::set(dbleftbound);
				this->tboxXmin->Text = Convert::ToString(dateMin);
				double dbrightbound = dateMax.ToOADate();
				this->plt1->ChartAreas[0]->AxisX->Maximum::set(dbrightbound);
				this->tboxXmax->Text = Convert::ToString(dateMax);

			 }
			 else
			 {
				this->lblXmin->Enabled = true;
				this->lblXmax->Enabled = true;
				this->lblYmin->Enabled = true;
				this->lblYmax->Enabled = true;
				this->tboxXmin->Enabled = true;
				this->tboxXmax->Enabled = true;
				this->tboxYmin->Enabled = true;
				this->tboxYmax->Enabled = true;
				this->lblXmin->Enabled = true;
				this->btnUpdate->Enabled = true;
			 }
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			 Application::DoEvents();
			 Splashscreen ^form4 = gcnew Splashscreen();
			 form4->Show();
			 Application::DoEvents();
			 Sleep(1000);
			 array<String ^>^ serialPortsList= nullptr;
			 DateTime now = System::DateTime::Now;
			 DateTime date2 = now.AddDays(-100);
			 this->plt1->Series[0]->Points->AddXY(now,"0.0");
			 this->plt1->Series[0]->Points->AddXY(date2,"40.0");
			 this->lblFileStatuts->Text="";


			 form4->Opacity=0.75;
			 serialPortsList = SerialPort::GetPortNames();
			 for each(String^ port in serialPortsList) // Loop through all existing serialPorts
			 {
				this->cBoxCom->Items->Add(port);
			 }
			//this->cBoxBaud->Items->Add(9600);
			 this->cBoxBaud->Items->Add(19200);
			 //this->cBoxBaud->Items->Add(38400);
			 this->cBoxBaud->Items->Add(57600);
			 this->cBoxBaud->Items->Add(115200);
			 this->cBoxBaud->SelectedIndex=0;
			 Sleep(1000);


			 form4->Close();

		 }
private: System::Void plt1_MarginChanged(System::Object^  sender, System::EventArgs^  e) {
			 //MessageBox::Show("Hola");
		 }
private: System::Void plt1_AxisViewChanged(System::Object^  sender, System::Windows::Forms::DataVisualization::Charting::ViewEventArgs^  e) {
			 
			  MessageBox::Show("Invalid value","ERROR");
		 }
private: System::Void plt1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		 }
private: System::Void btnUpdate_Click(System::Object^  sender, System::EventArgs^  e) {

			 double dbleftbound;
			 double dbrightbound;
			 double topbound;
			 double bottombound;
			 DateTime leftbound;
			 DateTime rightbound;

			 try
			 {
				topbound = Convert::ToDouble(tboxYmax->Text);
				bottombound = Convert::ToDouble(tboxYmin->Text);
				leftbound = Convert::ToDateTime(tboxXmin->Text);
				rightbound = Convert::ToDateTime(tboxXmax->Text);
			 }
			 catch(System::FormatException ^)
			 {
				 MessageBox::Show("Formatting error of introduced date","Format ERROR", MessageBoxButtons::OK,MessageBoxIcon::Error);
			 }

			 dbleftbound = leftbound.ToOADate();
			 dbrightbound = rightbound.ToOADate();
			 
			 if(topbound>bottombound && dbrightbound>dbleftbound)
			 {
				 this->plt1->ChartAreas[0]->AxisY->Maximum::set(topbound);
				 this->plt1->ChartAreas[0]->AxisY->Minimum::set(bottombound);
				 this->plt1->ChartAreas[0]->AxisX->Minimum::set(Convert::ToDouble(dbleftbound));
				 this->plt1->ChartAreas[0]->AxisX->Maximum::set(Convert::ToDouble(dbrightbound));
			 }
			 else
			 {
				 MessageBox::Show("Margins Error","ERROR");
			 }
		 }
private: System::Void tboxXmin_Enter(System::Object^  sender, System::EventArgs^  e) {
			 	DateTime dateTmp;
				if(DateTime::TryParse(tboxXmin->Text,dateTmp))
					xMin = Convert::ToDateTime(tboxXmin->Text);
				else
				{
					 MessageBox::Show("Invalid value","ERROR");
					 tboxXmin->Text = Convert::ToString(xMin);
				}
		 }
private: System::Void tboxXmax_Enter(System::Object^  sender, System::EventArgs^  e) {
			 	DateTime dateTmp;

				if(DateTime::TryParse(tboxXmax->Text,dateTmp))
					xMax = Convert::ToDateTime(tboxXmax->Text);
				else
				{
					MessageBox::Show("Invalid value","ERROR");
					tboxXmax->Text = Convert::ToString(xMax);
				}
		 }
private: System::Void btnDetect_Click(System::Object^  sender, System::EventArgs^  e) {

				String ^ getCOMAnswer;
				String ^ strExpected;
				COMDetection ^form4 = gcnew COMDetection();
				int nbBaudRate = 0;
				int tryBaudRate = 0;
				int icount = 0;
				int inkk = 0;
				String ^ s;

				array<String ^>^ serialPorts= gcnew array<String ^>(30);

				RegistryKey ^ rk = Registry::LocalMachine;
				RegistryKey ^ rk2 = rk->OpenSubKey("HARDWARE");
				RegistryKey ^ rk3 = rk2->OpenSubKey("DEVICEMAP");
				RegistryKey ^ rk4 = rk3->OpenSubKey("SERIALCOMM");


				array<String ^>^ key4 = rk4->GetValueNames();
				for(int ill=0;ill<key4->Length;ill++)
				{
					//MessageBox::Show("Substring = "+key4[ill]->Substring(0,11));
					if(key4[ill]->Length>=12)
					{
						if(key4[ill]->Substring(0,11)=="\\Device\\VCP")
						{
							s = safe_cast<String^>(key4[ill]);
							serialPorts[inkk] = Convert::ToString(rk4->GetValue(s));
							inkk=inkk+1;
						}
				
					}
				}


				rk4->Close();
				rk3->Close();
				rk2->Close();
				rk->Close();





				bIsDetected = false;
				//NIPHARGUS N;
				
				strExpected = "NIPHARGUS";
				int lastComma = 0;

				// Manual detection

				if(!chBoxCom->Checked)
				{
				if(cBoxCom->Text!="")
				{
					try  //begin try #1
					{
						if(!this->serialPort1->IsOpen)
						{
							this->serialPort1->PortName=cBoxCom->Text;
							this->serialPort1->BaudRate=System::Convert::ToInt32(cBoxBaud->Text);
							this->serialPort1->Parity=Parity::None;
							this->serialPort1->StopBits=StopBits::One;
							this->serialPort1->DataBits=8;
							this->serialPort1->Handshake= Handshake::None;
														
							try //begin try #2
							{
								this->serialPort1->Open();
								this->serialPort1->ReadTimeout = 5000;
								this->serialPort1->WriteTimeout= 2000;


								try // begin try #3
								{
									array<unsigned char>^ buffer0 = {'?'};
									this->serialPort1->Write(buffer0,0,1);
									getCOMAnswer=this->serialPort1->ReadLine();
									if(getCOMAnswer->Length>=9)
									{
										if(getCOMAnswer->Length==10)
										{
											nDataMax = 6500;
											niphVersion = 1.0;
										}
										else
										{
											nDataMax = findNDataMax(getCOMAnswer);
											niphVersion = findNiphVersion(getCOMAnswer)/1000.0;
										}
										if(getCOMAnswer->Substring(0,9) == strExpected)
										{
											createNIPHA();
											bIsDetected = true;
											if(N->measure_counter!=0)
											{
												this->lblDetectedCOMPort->Text="NIPHARGUS #"+Convert::ToString(N->IDSonde)+" detected on port: "+cBoxCom->Text+"---> number of records ="+Convert::ToString(N->measure_counter);
												this->btnDownload->Enabled=true;
												this->btnSetting->Enabled=true;
												this->btnStart->Enabled=true;
												this->chkAutoScale->Enabled=true;
											}
											else
											{
												this->lblDetectedCOMPort->Text="NIPHARGUS #"+Convert::ToString(N->IDSonde)+" detected on port: "+cBoxCom->Text+"---> No record";
												this->btnDownload->Enabled=false;
												this->btnSetting->Enabled=true;
												this->btnStart->Enabled=true;
												this->chkAutoScale->Enabled=false;
											}
											//this->lblDetectedCOMPort->Text="NIPHARGUS #"+N.IDSonde+" detected on port: "+port;
											this->progressBar1->Value=100;
											this->bntDisconnect->Enabled = true;
											this->btnDetect->Enabled = false;
											this->lblNiphVersion->Text = "Firmware version : "+Convert::ToString(niphVersion);
										}
									}
									else
									{
										this->serialPort1->Close();
									}
								}
								catch(TimeoutException ^) //first catch try #3
								{
									this->serialPort1->Close();
								}
								catch(UnauthorizedAccessException^) //second catch try #3
								{
									this->lblDetectedCOMPort->Text=L"No detected niphargus or already opened by another application";
								}
							}
							catch(System::IO::IOException^) //catch try #2
							{	
								this->serialPort1->Close();
							}


						}
					}  // End try #1
					catch(Win32Exception ^)  // catch try #1
					{
						bIsDetected=false;
						this->lblDetectedCOMPort->Text=L"No detected niphargus or already opened by another application";
					}
				}
				else
				{
					MessageBox::Show("No COM port selected");
				}
				if(!bIsDetected) MessageBox::Show("No Niphargus detected or already opened by another application", "Detection", MessageBoxButtons::OK,MessageBoxIcon::Error);
				}
				else  //Automatic selection of Niphargus COM port
				{
					nbBaudRate = this->cBoxBaud->Items->Count;
					form4->Show();
					try  // begin try # 1
					{

						if(inkk!=0)
						{
							for(int iv = 0;iv<inkk;iv++)
							{
								String^ port = serialPorts[iv];
								if(bIsDetected==false)
								{
									this->cBoxCom->Items->Clear();
									this->cBoxCom->Items->Add(port);
									this->cBoxCom->SelectedIndex = 0;
								}

								try // begin try # 2
								{
									for(int iBaud=0;iBaud<nbBaudRate;iBaud++)
									{
										if((!this->serialPort1->IsOpen) && bIsDetected == false)
										{
											cBoxBaud->SelectedIndex = iBaud;
											tryBaudRate=System::Convert::ToInt32(cBoxBaud->Text);
											//MessageBox::Show("Tried baud rate = "+Convert::ToString(tryBaudRate));
											this->serialPort1->PortName=port;
											this->serialPort1->BaudRate=tryBaudRate;
											this->serialPort1->Open();
											this->serialPort1->ReadTimeout=2000;
											this->serialPort1->WriteTimeout= 2000;

											try  // begin try # 3
											{

												this->serialPort1->WriteLine("?");
												getCOMAnswer=this->serialPort1->ReadLine();
												if(getCOMAnswer->Length==10)
												{
													nDataMax = 6500;
													niphVersion = 1.0;
												}
												else
												{
													nDataMax = findNDataMax(getCOMAnswer);
													niphVersion = findNiphVersion(getCOMAnswer)/1000.0;
												}

												if(getCOMAnswer->Length>=9)
												{
													createNIPHA();
													bIsDetected = true;
														if(N->measure_counter!=0)
														{
															this->lblDetectedCOMPort->Text="NIPHARGUS #"+Convert::ToString(N->IDSonde)+" detected on port: "+cBoxCom->Text+"---> number of records ="+Convert::ToString(N->measure_counter);
															this->btnDownload->Enabled=true;
															this->btnSetting->Enabled=true;
															this->btnStart->Enabled=true;
															this->chkAutoScale->Enabled=true;
														}
														else
														{
															this->lblDetectedCOMPort->Text="NIPHARGUS #"+Convert::ToString(N->IDSonde)+" detected on port: "+cBoxCom->Text+"---> No record";
															this->btnDownload->Enabled=false;
															this->btnSetting->Enabled=true;
															this->btnStart->Enabled=true;
															this->chkAutoScale->Enabled=false;
														}
														//this->lblDetectedCOMPort->Text="NIPHARGUS #"+N.IDSonde+" detected on port: "+port;
														this->progressBar1->Value=100;
														this->bntDisconnect->Enabled = true;
														this->btnDetect->Enabled = false;
														this->lblNiphVersion->Text = "Firmware version : "+Convert::ToString(niphVersion);

												}
												else
												{
													this->serialPort1->Close();
												}
											}  // end try # 3
											catch(TimeoutException ^)  // first catch try # 3
											{
												this->serialPort1->Close();
											}
											catch(UnauthorizedAccessException^) //second catch try #3
											{
												this->serialPort1->Close();
												this->lblDetectedCOMPort->Text=L"No detected niphargus or already opened by another application";
											}
									}  // end if "is COM port already open
								}
							} // end try # 2
							catch(System::IO::IOException^)  // catch try # 2
							{	
								this->serialPort1->Close();
							}
							catch(UnauthorizedAccessException^) //second catch try #3
							{
							  //Do nothing	
							}
						}  // End loop through all COM ports
					}
				}  // End try #1
				catch(Win32Exception ^)  // catch try #1
				{
					this->serialPort1->Close();
					bIsDetected=false;
					this->lblDetectedCOMPort->Text=L"No detected niphargus or already opened by another application";
				}
				form4->Close();
				if(!bIsDetected)
				{
					this->serialPort1->Close();
					this->cBoxCom->Items->Clear();
					this->cBoxCom->Items->Add("");
					this->cBoxCom->SelectedIndex=0;
					this->cBoxBaud->SelectedIndex=0;
					if(!bIsDetected) MessageBox::Show("No Niphargus detected or already opened by another application", "Detection", MessageBoxButtons::OK,MessageBoxIcon::Error);
				}
				if(bIsDetected)
				{
					if((Convert::ToDouble(N->voltage)/1000) < 2.5)
					{
						MessageBox::Show("Battery voltage too low:\n\n   - You can download data anyway\n   - You will need to change battery before restart new test","Low battery",MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
					}


				}
			}  // End else case for automatic detection

		 }
private: System::Void btnSaveData_Click(System::Object^  sender, System::EventArgs^  e) {

			String ^tmpstr;
			String ^colName;
			String ^messageCorrectionTemp;
			SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "CSV File|*.csv";
			saveFileDialog1->Title = "Save results";
			saveFileDialog1->ShowDialog();
			int j;
			unsigned char iChTempCor[6];
			_int32 iTempCorrection;
			double fTempCorrection;
			double tmpTemperature;
			Encoding^ ascii = Encoding::ASCII;
			
			// If the file name is not an empty string, open it for saving.
			if(saveFileDialog1->FileName != "")
			{
				//System::IO::FileStream ^ fs = safe_cast<System::IO::FileStream^>(saveFileDialog1->OpenFile());
				try
				{

					System::IO::StreamWriter ^ fs = gcnew System::IO::StreamWriter(saveFileDialog1->OpenFile(),ascii);
					if(this->chkHeaderToFile->Checked)
					{
						// OpenXMLTag arguments OpenXMLTag(String^ "Tag",String ^"Text",int tagorder,bool returncarriage)
						fs->Write(OpenXMLTag("Header","",0,true));
						fs->Write(OpenXMLTag("ID-NIPHARGUS","NIPHARGUS #"+Convert::ToString(N->IDSonde),1,false));
						fs->Write(CloseXMLTag("ID-NIPHARGUS"));
						fs->Write(OpenXMLTag("Date_on",Convert::ToString(N->day_on)+"/"+Convert::ToString(N->month_on)+"/"+Convert::ToString(N->year_on),1,false));
						fs->Write(CloseXMLTag("Date_on"));
						fs->Write(OpenXMLTag("Interval",Convert::ToString(N->interval),1,false));
						fs->Write(CloseXMLTag("Interval"));
						fs->Write(OpenXMLTag("Voltage",Convert::ToString((Convert::ToDouble(N->voltage))/1000.0),1,false)+" V");
						fs->Write(CloseXMLTag("Voltage"));
						//fs->Write(OpenXMLTag("Crystal_calibration",Convert::ToString(N->crystal_cal),1,false));
						//fs->Write(CloseXMLTag("Crystal_calibration"));
						fs->Write(OpenXMLTag("Number_records_median",Convert::ToString(N->median_values),1,false));
						fs->Write(CloseXMLTag("Number_records_median"));
						fs->Write(OpenXMLTag("Number_of_records",Convert::ToString(N->measure_counter),1,false));
						fs->Write(CloseXMLTag("Number_of_records"));
						fs->Write(OpenXMLTag("Firmware version",Convert::ToString(niphVersion),1,false));
						fs->Write(CloseXMLTag("Firmware version"));
						fs->Write(CloseXMLTag("Header"));
						fs->Write(OpenXMLTag("COMMENT1",this->tbxComment1->Text,0,false));
						fs->Write(CloseXMLTag("COMMENT1"));
						fs->Write(OpenXMLTag("COMMENT2",this->tbxComment2->Text,0,false));
						fs->Write(CloseXMLTag("COMMENT2"));
						fs->Write("\n");
				
					}
					
					if(niphVersion>1.5)
					{
						array<unsigned char>^ bufferTempCorrection = {')'};
						this->serialPort1->Write(bufferTempCorrection,0,1);
						for(j=0;j<6;j++)
						{
							iChTempCor[j]=this->serialPort1->ReadByte();
						}
						//iTempCorrection= (Convert::ToInt32(iChTempCor[0])<<24) & (iChTempCor[1]<<16) & (iChTempCor[2]<<8) & iChTempCor[3];
						iTempCorrection = Convert::ToInt32(iChTempCor[0]<<24) | Convert::ToInt32(iChTempCor[1]<<16) | Convert::ToInt32(iChTempCor[2]<<8) | Convert::ToInt32(iChTempCor[3]);
						fTempCorrection = Convert::ToDouble(iTempCorrection);
						fTempCorrection = fTempCorrection/1000.0;
					
						messageCorrectionTemp = L"(*) These values correspond to a calibrated/corrected temperature values vs a thermistor at 10 Celsius deg.\n The correction for this Niphargus probe was measured to: "+Convert::ToString(fTempCorrection)+" Celsius deg\n\n\n";
						fs->Write(messageCorrectionTemp);
						// Column header
						colName = "DateTime;MeasuredTemp;CorrectedTemp(*)\n";
						fs->Write(colName);
					}
					for(int i=0; i<=(N->measure_counter-1);i++)
					{
						if(niphVersion>1.5)
						{
							tmpTemperature=Convert::ToDouble(temperature[i])+fTempCorrection;
							tmpstr=Convert::ToString(recordedDateTime[i])+";"+Convert::ToString(temperature[i])+";"+Convert::ToString(tmpTemperature)+"\n";
						}
						if(niphVersion<=1.4)
						{
							tmpstr=Convert::ToString(recordedDateTime[i])+";"+Convert::ToString(temperature[i])+"\n";
						}
						
						fs->Write(tmpstr);
					}
					fs->Close();
					lblFileStatuts->Text="Saved";
				}
				catch(System::IO::IOException ^)
				{
					MessageBox::Show("Impossible to save the file\nA file with the same name is probably opened by another application\n\nPlease close this file before to try again to save","ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
				}
			}
 
		 }
private: System::Void bntDisconnect_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serialPort1->Close();
			 this->lblDetectedCOMPort->Text=L"No Niphargus";
			 this->btnDetect->Enabled=true;
			 this->bntDisconnect->Enabled=false;
			 this->btnDownload->Enabled=false;
			 this->btnSetting->Enabled=false;
			 this->btnStart->Enabled=false;
			 this->progressBar1->Value= 0;
		 }
private: System::Void lblDetectedCOMPort_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

public: void createNIPHA()
		 {
			 String ^ niphargusParam;
			 //NIPHARGUS NN;
			
			 int tmpYear_on;
			 int tmpMonth_on;
			 int tmpDay_on;
			 int tmpHour_on;
			 int tmpMinute_on;
			 int tmpSecond_on;
			 int tmpYear_current;
			 int tmpMonth_current;
			 int tmpDay_current;
			 int tmpHour_current;
			 int tmpMinute_current;
			 int tmpSecond_current;
			 int tmpInterval;
			 int tmpTemp_cal;
			 int tmpCrystal_cal;
			 int tmpMedian_val;
			 int tmpMeasure_counter;
			 int tmpTemp_current;
			 int tmpVoltage;
			 int tmpIDSonde;
			 int tmpIDSonde2;
			 int lengthstrParam;
								
			array<unsigned char>^ bufferDI = {'#'};
			this->serialPort1->Write(bufferDI,0,1);
			//this->serialPort1->WriteLine("#");
			niphargusParam = this->serialPort1->ReadLine();
			if(niphargusParam->Length<5)
			{
				niphargusParam=this->serialPort1->ReadLine();
			}

			 //MessageBox::Show(niphargusParam);

			 lengthstrParam = niphargusParam->Length;
			 if(lengthstrParam==0) MessageBox::Show("ERROR reading Niphargus param");
			 
			 if(lengthstrParam!=0)
			 {
				 			 
				strSubString= niphargusParam;  // strSubString is a GLOBAL ^String used to pass string from functions to functions
			 
				try
				{
					if(niphVersion>1.5)
					{
						tmpYear_on = ParseData()+2000;
						tmpMonth_on = ParseData();
						tmpDay_on = ParseData();
						tmpHour_on = ParseData();
						tmpMinute_on = ParseData();
						tmpSecond_on = ParseData();
						tmpYear_current = ParseData()+2000;
						tmpMonth_current = ParseData();
						tmpDay_current = ParseData();
						tmpHour_current = ParseData();
						tmpMinute_current = ParseData();
						tmpSecond_current = ParseData();
						tmpInterval = ParseData();
						tmpTemp_cal = ParseData();
						tmpIDSonde = ParseData();
						tmpMedian_val = ParseData();
						tmpMeasure_counter = ParseData();
						tmpTemp_current = ParseData();
						tmpVoltage= ParseData();

						tmpIDSonde2 = Convert::ToInt32(strSubString);
					}
					if(niphVersion<=1.4)
					{
						tmpYear_on = ParseData()+2000;
						tmpMonth_on = ParseData();
						tmpDay_on = ParseData();
						tmpHour_on = ParseData();
						tmpMinute_on = ParseData();
						tmpSecond_on = ParseData();
						tmpYear_current = ParseData()+2000;
						tmpMonth_current = ParseData();
						tmpDay_current = ParseData();
						tmpHour_current = ParseData();
						tmpMinute_current = ParseData();
						tmpSecond_current = ParseData();
						tmpInterval = ParseData();
						tmpTemp_cal = ParseData();
						tmpCrystal_cal = ParseData();
						tmpMedian_val = ParseData();
						tmpMeasure_counter = ParseData();
						tmpTemp_current = ParseData();
						tmpVoltage= ParseData();

						tmpIDSonde = Convert::ToInt16(strSubString);			
					
					}
				}
				catch(System::FormatException ^)
				{
					MessageBox::Show("Niphargus clock is undefined\nProbably first initialization or battery replacement\n\nShrimp will proceed to a clock(re-)initialization\n", "Install information", MessageBoxButtons::OK,MessageBoxIcon::Information);
					strSubString= niphargusParam;
					//tmpInterval=RetrieveOtherParams(13);
					tmpInterval=0;
					//tmpTemp_cal=RetrieveOtherParams(14);
					tmpTemp_cal = 0;
					//tmpCrystal_cal=RetrieveOtherParams(15);
					tmpCrystal_cal = 0;
					//tmpMedian_val=RetrieveOtherParams(16);
					tmpMedian_val = 10;
					//tmpMeasure_counter=RetrieveOtherParams(17);
					tmpMeasure_counter=0;
					tmpTemp_current =RetrieveOtherParams(18);
					tmpVoltage = RetrieveOtherParams(19);
					tmpIDSonde=RetrieveOtherParams(20);
					DateTime now = System::DateTime::Now;
					tmpYear_on = now.Year;
					tmpMonth_on = now.Month;
					tmpDay_on = now.Day;
					tmpHour_on = now.Hour;
					tmpMinute_on = now.Minute;
					tmpSecond_on = now.Second;
				}

			 }

			//NIPHARGUS NN ={tmpYear_on,tmpMonth_on,tmpDay_on,tmpHour_on,tmpMinute_on,tmpSecond_on,tmpInterval,tmpTemp_cal,tmpCrystal_cal,tmpMedian_val,tmpMeasure_counter,tmpIDSonde};
			 N->year_on = tmpYear_on;
			 N->month_on = tmpMonth_on;
			 N->day_on = tmpDay_on;
			 N->hour_on = tmpHour_on;
			 N->minute_on = tmpMinute_on;
			 N->second_on = tmpSecond_on;
			 N->year_current = tmpYear_current;
			 N->month_current = tmpMonth_current;
			 N->day_current = tmpDay_current;
			 N->hour_current = tmpHour_current;
			 N->minute_current = tmpMinute_current;
			 N->second_current = tmpSecond_current;
			 N->interval = tmpInterval;
			 N->temp_cal = tmpTemp_cal;
			 N->crystal_cal = tmpCrystal_cal;
			 N->median_values = tmpMedian_val;
			 N->measure_counter = tmpMeasure_counter;
			 N->IDSonde = tmpIDSonde;
			 N->voltage = tmpVoltage;
			 N->temperature_current = tmpTemp_current;
			// NIPHARGUS NN = new NIPHARGUS;
			 bIsDetected= true;
			return;
			//return NN;
		 }

private: int ParseData()
		 {
			int curIndex;
			int strLength;
			int returnValue;
			curIndex = strSubString->IndexOf(',');
			strLength =  strSubString->Length;
  			returnValue = Convert::ToInt32(strSubString->Substring(0,curIndex));
			strSubString = strSubString->Substring(curIndex+1,(strLength-(curIndex+1)));

			return returnValue;
		 }
private: int RetrieveOtherParams(int OtherParamIndex)
		  {
			  int curIndex = 0;
			  int previousIndex = 0;
			  int returnValue;
			  String ^ tmpString;
			  int strLength;

			  tmpString=strSubString;
			  
			  for(int i=0;i<(OtherParamIndex-1);i++)
			  {
				curIndex=tmpString->IndexOf(',');
				strLength= tmpString->Length;
				tmpString = tmpString->Substring(curIndex+1,(strLength-(curIndex+1)));
			  }
			  curIndex=tmpString->IndexOf(',');
			  if(curIndex!=-1)
			  {
				returnValue = Convert::ToInt32(tmpString->Substring(0,curIndex));
			  }
			  else
			  {
				  strLength=tmpString->Length;
				  returnValue = Convert::ToInt32(tmpString->Substring(0,strLength));
			  }
			  
			  return returnValue;
		  }
private: System::Void btnSetting_Click(System::Object^  sender, System::EventArgs^  e) {

			createNIPHA();
			Settings ^form2 = gcnew Settings(); 
			String ^DayFormatted;
			String ^MonthFormatted;
			String ^YearFormatted;
			String ^HourFormatted;
			String ^MinuteFormatted;
			String ^SecondFormatted;
			String ^ areUpdatingOK;
			unsigned char iChTempCor[6];
			_int32 iTempCorrection;
			double fTempCorrection;
			int j;

			int tmpYear_on;
			String ^ chtmpYear_on;
			unsigned char ch2tmpYear_on;
			int tmpMonth_on;
			String ^ chtmpMonth_on;
			unsigned char ch2tmpMonth_on;
			int tmpDay_on;
			String ^ chtmpDay_on;
			unsigned char ch2tmpDay_on;
			int tmpHour_on;
			String ^ chtmpHour_on;
			unsigned char ch2tmpHour_on;
			int tmpMinute_on;
			String ^ chtmpMinute_on;
			unsigned char ch2tmpMinute_on;
			int tmpSecond_on;
			String ^ chtmpSecond_on;
			unsigned char ch2tmpSecond_on;
			int tmpYear_current;
			int tmpMonth_current;
			int tmpDay_current;
			int tmpHour_current;
			int tmpMinute_current;
			int tmpSecond_current;
			int tmpInterval;
			int tmpTemp_cal;
			int tmpCrystal_cal;
			int tmpMedian_val;
			int tmpCounter;
			int tmpVoltage;
			int tmpIDSonde;

			if(N->day_on<10)
			{
				DayFormatted = "0"+Convert::ToString(N->day_on);
			}
			else
			{
				DayFormatted = Convert::ToString(N->day_on);
			}

			if(N->month_on<10)
			{
				MonthFormatted = "0"+Convert::ToString(N->month_on);
			}
			else
			{
				MonthFormatted = Convert::ToString(N->month_on);
			}

			if(N->hour_on<10)
			{
				HourFormatted = "0"+Convert::ToString(N->hour_on);
			}
			else
			{
				HourFormatted = Convert::ToString(N->hour_on);
			}

			if(N->minute_on<10)
			{
				MinuteFormatted = "0"+Convert::ToString(N->minute_on);
			}
			else
			{
				MinuteFormatted = Convert::ToString(N->minute_on);
			}

			if(N->second_on<10)
			{
				SecondFormatted = "0"+Convert::ToString(N->second_on);
			}
			else
			{
				SecondFormatted = Convert::ToString(N->second_on);
			}


			YearFormatted=Convert::ToString(N->year_on);

			form2->lblDateOn->Text = "Date & Time on: "+DayFormatted+"/"+MonthFormatted+"/"+YearFormatted+" "+HourFormatted+":"+MinuteFormatted+":"+SecondFormatted;

			if(N->day_current<10)
			{
				DayFormatted = "0"+Convert::ToString(N->day_current);
			}
			else
			{
				DayFormatted = Convert::ToString(N->day_current);
			}

			if(N->month_current<10)
			{
				MonthFormatted = "0"+Convert::ToString(N->month_current);
			}
			else
			{
				MonthFormatted = Convert::ToString(N->month_current);
			}

			if(N->hour_current<10)
			{
				HourFormatted = "0"+Convert::ToString(N->hour_current);
			}
			else
			{
				HourFormatted = Convert::ToString(N->hour_current);
			}

			if(N->minute_current<10)
			{
				MinuteFormatted = "0"+Convert::ToString(N->minute_current);
			}
			else
			{
				MinuteFormatted = Convert::ToString(N->minute_current);
			}

			if(N->second_current<10)
			{
				SecondFormatted = "0"+Convert::ToString(N->second_current);
			}
			else
			{
				SecondFormatted = Convert::ToString(N->second_current);
			}
			// Feed the right panel with the existing temperature correction
			if(niphVersion>1.5)
			{
				array<unsigned char>^ bufferTempCorrection = {')'};
				this->serialPort1->Write(bufferTempCorrection,0,1);
				for(j=0;j<6;j++)
				{
					iChTempCor[j]=this->serialPort1->ReadByte();
				}
				//iTempCorrection= (Convert::ToInt32(iChTempCor[0])<<24) & (iChTempCor[1]<<16) & (iChTempCor[2]<<8) & iChTempCor[3];
				iTempCorrection = Convert::ToInt32(iChTempCor[0]<<24) | Convert::ToInt32(iChTempCor[1]<<16) | Convert::ToInt32(iChTempCor[2]<<8) | Convert::ToInt32(iChTempCor[3]);
				fTempCorrection = Convert::ToDouble(iTempCorrection);
				fTempCorrection = fTempCorrection/1000.0;
			}
			if(niphVersion<=1.4)
			{
				fTempCorrection = 0.0;
			}
			//txtBoxTempCorrection->Text=Convert::ToString(fTempCorrection);
			//this->lblNiphVersion->Text = "Firmware version : "+Convert::ToString(niphVersion);

			form2->lblDateOnConnect->Text = "Date and time on connect: "+DayFormatted+"/"+MonthFormatted+"/"+YearFormatted+" "+HourFormatted+":"+MinuteFormatted+":"+SecondFormatted;;
			form2->lblInterval->Text = "Interval: "+Convert::ToString(N->interval);
			//form2->lblTempCal->Text = "Temperature offset: "+Convert::ToString(N->temp_cal);
			form2->lblTempCal->Text = "Temperature offset: "+Convert::ToString(fTempCorrection);
			//form2->lblCrystalCal->Text= "Crystal calibration: "+Convert::ToString(N->crystal_cal);
			form2->lblNiphVersionSetting->Text= "Firmware version: "+Convert::ToString(niphVersion);
			form2->lblMedianVal->Text="Number of records for median: "+Convert::ToString(N->median_values);
			form2->lblMeasureCount->Text="Current number of records: "+Convert::ToString(N->measure_counter);
			form2->lblIDSonde->Text="Probe number: "+Convert::ToString(N->IDSonde);
			form2->ProbeNum=N->IDSonde;
			PreviousProbeNumber=N->IDSonde;
			double tmpvoltage=0.000;
			tmpvoltage=Convert::ToDouble(N->voltage);
			tmpvoltage=tmpvoltage/1000;
			form2->lblBattery->Text="Battery: "+String::Format("{0:F3}",tmpvoltage)+" V";

			double tmptemperature=0.000;
			tmptemperature=Convert::ToDouble(N->temperature_current);
			tmptemperature=tmptemperature/1000;
			form2->lblTemperature->Text="Current Temperature: "+String::Format("{0:F3}",tmptemperature)+" °C";
			form2->ShowDialog();
			
			if(PreviousProbeNumber!=form2->ProbeNum)
			{

				//MessageBox::Show("Modification occurred");
				N->IDSonde=form2->ProbeNum;
				DateTime now= System::DateTime::Now;
				
				if(N->measure_counter!=0)
				{
					this->lblDetectedCOMPort->Text="NIPHARGUS #"+Convert::ToString(N->IDSonde)+" detected on port: "+cBoxCom->Text+"---> number of records ="+Convert::ToString(N->measure_counter);
				}
				else
				{
					this->lblDetectedCOMPort->Text="NIPHARGUS #"+Convert::ToString(N->IDSonde)+" detected on port: "+cBoxCom->Text+"---> No record";
				}

				tmpYear_on=now.Year-2000;
				chtmpYear_on = String::Format("0x{0}",tmpYear_on);
				ch2tmpYear_on = Convert::ToInt16(chtmpYear_on,16);

				tmpMonth_on=now.Month;
				chtmpMonth_on = String::Format("0x{0}",tmpMonth_on);
				ch2tmpMonth_on = Convert::ToInt16(chtmpMonth_on,16);

				tmpDay_on=now.Day;
				chtmpDay_on = String::Format("0x{0}",tmpDay_on);
				ch2tmpDay_on = Convert::ToInt16(chtmpDay_on,16);

				tmpHour_on=now.Hour;
 				chtmpHour_on = String::Format("0x{0}",tmpHour_on);
				ch2tmpHour_on = Convert::ToInt16(chtmpHour_on,16);
				
				tmpMinute_on=now.Minute;
				chtmpMinute_on = String::Format("0x{0}",tmpMinute_on);
				ch2tmpMinute_on = Convert::ToInt16(chtmpMinute_on,16);

				tmpSecond_on=now.Second;
				chtmpSecond_on = String::Format("0x{0}",tmpSecond_on);
				ch2tmpSecond_on = Convert::ToInt16(chtmpSecond_on,16);
				
				tmpInterval = N->interval;
				tmpTemp_cal = N->temp_cal;
				tmpCrystal_cal = N->crystal_cal;
				tmpMedian_val = N->median_values;
				tmpIDSonde = N->IDSonde;

				if(this->serialPort1->IsOpen)
				{
					array<unsigned char>^ buffer0 = {0x24};  //Send Hex ascii code for symbol '$'
					this->serialPort1->Write(buffer0,0,1);
					array<unsigned char>^ buffer1 = {ch2tmpYear_on};
					this->serialPort1->Write(buffer1,0,1);
					array<unsigned char>^ buffer2 = {ch2tmpMonth_on};
					this->serialPort1->Write(buffer2,0,1);
					array<unsigned char>^ buffer3 = {ch2tmpDay_on};
					this->serialPort1->Write(buffer3,0,1);
					array<unsigned char>^ buffer4 ={ch2tmpHour_on};
					this->serialPort1->Write(buffer4,0,1);
					array<unsigned char>^ buffer5 ={ch2tmpMinute_on};
					this->serialPort1->Write(buffer5,0,1);
					array<unsigned char>^ buffer6 ={ch2tmpSecond_on};
					this->serialPort1->Write(buffer6,0,1);

					array<unsigned char>^ buffer7 ={tmpInterval>>8};// interval1
					this->serialPort1->Write(buffer7,0,1);
					array<unsigned char>^ buffer8 ={tmpInterval & 0xFF};//interval2
					this->serialPort1->Write(buffer8,0,1);
					array<unsigned char>^ buffer9 ={tmpTemp_cal>>8}; //temp_cal1
					this->serialPort1->Write(buffer9,0,1);
					array<unsigned char>^ buffer10 ={tmpTemp_cal & 0xFF}; //temp_cal2
					this->serialPort1->Write(buffer10,0,1);
					
					array<unsigned char>^ buffer11 ={tmpIDSonde>>8};
					this->serialPort1->Write(buffer11,0,1);
					array<unsigned char>^ buffer12 ={tmpIDSonde & 0xFF};
					this->serialPort1->Write(buffer12,0,1);
					array<unsigned char>^ buffer13 ={tmpMedian_val};  //median_val
					this->serialPort1->Write(buffer13,0,1);
					array<unsigned char>^ buffer14 ={tmpIDSonde};  //IDSonde
					this->serialPort1->Write(buffer14,0,1);

					areUpdatingOK = this->serialPort1->ReadLine();

					if(areUpdatingOK->Substring(0,2) == "OK")
					{
						MessageBox::Show("Niphargus number updated","Info",MessageBoxButtons::OK,MessageBoxIcon::Information);
					}
					else
					{
						MessageBox::Show("Problem during initialization of Niphargus","ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
					}
				}
					
			}


		 }
private: System::Void btnDownload_Click(System::Object^  sender, System::EventArgs^  e) {
			
			String ^ newSeriesName = "NIPHARGUS #"+Convert::ToString(N->IDSonde);
			Downloading ^form3 = gcnew Downloading();

			int j,iflag;
			unsigned char iCh[10];
			String ^ year;
			String ^ month;
			String ^ day;
			String ^ hour;
			String ^ minute;
			String ^ second;
			//signed long T;
			int T;
			double Temp;
			
			int icounter = 0;
			int inc = 0;
			array <String^>^words;
			//array<DateTime^>^ recordedDateTime = gcnew array<DateTime^>(nData);
			//array<Double^>^ temperature = gcnew array<Double^>(nData);
			tempMin=99999;
			tempMax=-999;
			double tempCurrent;
			int iDownLoadProgress = 0;
			iflag = 0;



			try
			{
				if(this->serialPort1->IsOpen)
				{					
					this->serialPort1->ReadTimeout = 5000;
					this->serialPort1->WriteTimeout = 1000;
					array<unsigned char>^ buffer0 = {'>'};  //Send Hex ascii code for symbol '>'
					this->serialPort1->Write(buffer0,0,1);
					if(niphVersion<1.4)
					{
						fileContent= this->serialPort1->ReadLine();
						while(fileContent->Substring(0,3) != "END")
						{
							AutoMaxX = -999;
							AutoMinX = -999;
							AutoMaxY = -999;
							AutoMinY = -999;

							words = fileContent->Split(delimiter);
							inc++;
							if(icounter==2)
							{
								form3->Show();

							}
							if(icounter>2 && inc==(N->measure_counter/100))
							{
								inc=0;
								iDownLoadProgress=Convert::ToInt32(((Convert::ToDouble(icounter))/(Convert::ToDouble(N->measure_counter)))*100);
								form3->progressBar1->Value=iDownLoadProgress;
								form3->label1->Text = "Downloading ... "+Convert::ToString(iDownLoadProgress)+"% done";
							}
							if(words->Length>1)
							{
								recordedDateTime[icounter]=DateTime(Convert::ToInt32(words[3])+2000,Convert::ToInt32(words[2]),Convert::ToInt32(words[1]),Convert::ToInt32(words[4]),Convert::ToInt32(words[5]),Convert::ToInt32(words[6]));
								temperature[icounter]=Convert::ToDouble(words[7])/1000.00;
								tempCurrent=*temperature[icounter];
								if(tempCurrent < tempMin) tempMin=*temperature[icounter];
								if(tempCurrent > tempMax) tempMax=*temperature[icounter];
								//this->plt1->Series[newSeriesName]->Points->AddXY(recordedDateTime[icounter],temperature[icounter]);
								icounter++;
							}
						
							fileContent= this->serialPort1->ReadLine();
						}
					}
					if(niphVersion>=1.5)
					{
						// Following sequence Close and Open is necessary to avoid error if user presses twice on download button
						//this->serialPort1->Close();
						//this->serialPort1->Open();
						do{
							for(j=0;j<10 & iflag==0;j++)
							{
								//iCh[j]=this->serialPort1->ReadChar();
								iCh[j]=this->serialPort1->ReadByte();
								if(j>=4)
								{
									if(iCh[2]==69 & iCh[3]==78 & iCh[4]==68) iflag=1;
								}

							}
							

							inc++;
							if(icounter==2)
							{
								form3->Show();
							}
							if(icounter>2 && inc==(N->measure_counter/100))
							{
								inc=0;
								iDownLoadProgress=Convert::ToInt32(((Convert::ToDouble(icounter))/(Convert::ToDouble(N->measure_counter)))*100);
								form3->progressBar1->Value=iDownLoadProgress;
								form3->label1->Text = "Downloading ... "+Convert::ToString(iDownLoadProgress)+"% done";
							}
							if(iflag==0)
							{
								recordedDateTime[icounter]=DateTime(convertByte(iCh[0])+2000,convertByte(iCh[1]),convertByte(iCh[2]),convertByte(iCh[3]),convertByte(iCh[4]),convertByte(iCh[5]));
								T=(iCh[9]<<24)|(iCh[8]<<16)|(iCh[7]<<8)|iCh[6];
								temperature[icounter]=Convert::ToDouble(T)/1000.00;
								tempCurrent=*temperature[icounter];
								if(tempCurrent < tempMin) tempMin=*temperature[icounter];
								if(tempCurrent > tempMax) tempMax=*temperature[icounter];
								//this->plt1->Series[newSeriesName]->Points->AddXY(recordedDateTime[icounter],temperature[icounter]);
								icounter++;
							}
						} while(iflag==0);

						//Both following lines are required to read trailer character ASCII 13 & 10 and to set-up back for the following reading
						iCh[5]=this->serialPort1->ReadByte();
						iCh[6]=this->serialPort1->ReadByte();
					}
					form3->Close();

					// Following sequence Close and Open is necessary to avoid error if user presses twice on download button
					//this->serialPort1->Close();
					//this->serialPort1->Open();
				}
				else
				{
					MessageBox::Show("Port COM closed");
					this->progressBar1->Value=0;
					this->btnDetect->Enabled = true;
					this->bntDisconnect->Enabled = false;
					this->btnDownload->Enabled = false;
					this->btnSetting->Enabled=false;
					this->btnStart->Enabled=false;
				}
			}
			catch(TimeoutException ^)
			{
						//this->serialPort1->Close();
				//MessageBox::Show("Number of data = "+Convert::ToString(icounter));
			}
			if(icounter>=1)
			{
				this->plt1->Series[0]->Points->Clear();
				this->plt1->Series[0]->Name = newSeriesName;
				this->plt1->Series[newSeriesName]->Color=System::Drawing::Color::Green;
				for(int i=0;i<icounter;i++)
				{
					this->plt1->Series[newSeriesName]->Points->AddXY(recordedDateTime[i],temperature[i]);
					if(i==0)
					{
						tempMin=*temperature[i];
						tempMax=*temperature[i];
						dateMin=*recordedDateTime[i];
						dateMax=*recordedDateTime[i];
					}
					else
					{
						if(*temperature[i]<tempMin) tempMin=*temperature[i];
						if(*temperature[i]>tempMax) tempMax=*temperature[i];
						if(*recordedDateTime[i]<dateMin) dateMin = *recordedDateTime[i];
						if(*recordedDateTime[i]>dateMax) dateMax = *recordedDateTime[i];
					}
				}
				this->lblFileStatuts->Text="Not saved";
				this->chkAutoScale->Checked=true;
				Application::DoEvents();
				double tata = this->plt1->ChartAreas[0]->AxisX->Maximum;
				DateTime dt = DateTime::FromOADate(tata);
				tboxXmax->Text = Convert::ToString(dt);
				tata = this->plt1->ChartAreas[0]->AxisX->Minimum;
				dt = DateTime::FromOADate(tata);
				tboxXmin->Text = Convert::ToString(dt);
				this->plt1->ChartAreas[0]->AxisY->Maximum::set(tempMax);
				tboxYmax->Text = Convert::ToString(tempMax);
				this->plt1->ChartAreas[0]->AxisY->Minimum::set(tempMin);
				tboxYmin->Text = Convert::ToString(tempMin);
				this->chkAutoScale->Enabled=true;
				Application::DoEvents();	
			
			}
			if(icounter<1)
			{
				MessageBox::Show("Niphargus has recorded less than 2 values that can not be plotted","ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
			}

		 }
private: System::Void plt1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: String^ OpenXMLTag(String^ tag,String^ tag2,int order,bool returncarriage)
		 {
				String ^ tmp;
				String ^ tmp2;
				String ^ returncar="";
				if(returncarriage) returncar="\n";
				if(order>0)
				{
					for(int i=0;i<=order;i++) tmp2+="\t";
				}
				else
				{
					tmp2="";
				}
				tmp=tmp2+"<"+tag+">"+tag2+returncar;
				return tmp;
		 }
private: String^ CloseXMLTag(String^ tag)
{
	String ^ tmp;
	tmp="</"+tag+">\n";
	return tmp;
}
private: bool ManageHeader(array<String^>^ lines)
{
	int i = 0;
	int nOpenXML = 0;
	int nCloseXML = 0;

	bool res = false;
	String^ tmp;
	String^ tmp2;
	array<String^>^ words;

	for(i = 0; i<lines->Length;i++)
	{
		//if(lines[i]=="<Header>") res = true;
		nOpenXML = 0;
		nCloseXML = 0;
		words=lines[i]->Split(delimiter3);
		for (int j = 0; j<words->Length;j++)
		{
			if(words[j]=="Header") res=true;
			if(words[j]=="ID-NIPHARGUS")
			{
				nOpenXML = j;
			}
			if(words[j]=="/ID-NIPHARGUS")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				int l = tmp->IndexOf("#");
				//int l2 = tmp->Length;
				tmp2= tmp->Substring(l+1);
				N->IDSonde = Convert::ToInt32(tmp2);
			}
			if(words[j]=="Date_on")
			{
				nOpenXML = j;
			}
			if(words[j]=="/Date_on")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				int l = tmp->IndexOf("/");
				int l2 = tmp->LastIndexOf("/");
				String^ tmpYear = tmp->Substring(l2+1);
				String^ tmpMonth = tmp->Substring(l+1,(l2-l)-1);
				String^ tmpDay = tmp->Substring(0,l);
				N->year_on = Convert::ToInt32(tmpYear);
				N->month_on = Convert::ToInt32(tmpMonth);
				N->day_on = Convert::ToInt32(tmpDay);
				N->hour_on = 0;
				N->minute_on = 0;
				N->second_on = 0;
			}
			if(words[j]=="Interval")
			{
				nOpenXML = j;
			}
			if(words[j]=="/Interval")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				N->interval = Convert::ToInt32(tmp);
			}
			if(words[j]=="Temperature_Offset")
			{
				nOpenXML = j;
			}
			if(words[j]=="/Temperature_Offset")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				N->temp_cal = Convert::ToInt32(tmp);
			}
			if(words[j]=="Crystal_calibration")
			{
				nOpenXML = j;
			}
			if(words[j]=="/Crystal_calibration")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				N->crystal_cal = Convert::ToInt32(tmp);
			}
			if(words[j]=="Number_records_median")
			{
				nOpenXML = j;
			}
			if(words[j]=="/Number_records_median")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				N->median_values = Convert::ToInt32(tmp);
			}
			if(words[j]=="Number_of_records")
			{
				nOpenXML = j;
			}
			if(words[j]=="/Number_of_records")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				N->measure_counter = Convert::ToInt32(tmp);
			}
			if(words[j]=="COMMENT1")
			{
				nOpenXML = j;
			}
			if(words[j]=="/COMMENT1")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				tbxComment1->Text=tmp;
			}
			if(words[j]=="COMMENT2")
			{
				nOpenXML = j;
			}
			if(words[j]=="/COMMENT2")
			{
				nCloseXML = j;
				tmp = "";
				for(int ijk = nOpenXML+1; ijk<nCloseXML; ijk++) tmp=tmp+words[ijk];
				tbxComment2->Text=tmp;
				firstLine=i+2;
			}
			if(words[0]=="" && words->Length==1) //Blank lines
			{
				firstLine= firstLine+1;
			}

			if(words[0]=="DateTime")
			{
				firstLine= i+2;
			}

		}
	}
	return res;
}

private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 int tmpYear_on;
			 String ^ chtmpYear_on;
			 unsigned char ch2tmpYear_on;
			 int tmpMonth_on;
			 String ^ chtmpMonth_on;
			 unsigned char ch2tmpMonth_on;
			 int tmpDay_on;
			 String ^ chtmpDay_on;
			 unsigned char ch2tmpDay_on;
			 int tmpHour_on;
			 String ^ chtmpHour_on;
			 unsigned char ch2tmpHour_on;
			 int tmpMinute_on;
			 String ^ chtmpMinute_on;
			 unsigned char ch2tmpMinute_on;
			 int tmpSecond_on;
			 String ^ chtmpSecond_on;
			 unsigned char ch2tmpSecond_on;
			 int tmpYear_current;
			 int tmpMonth_current;
			 int tmpDay_current;
			 int tmpHour_current;
			 int tmpMinute_current;
			 int tmpSecond_current;
			 int tmpInterval;
			 int tmpTemp_cal;
			 int tmpCrystal_cal;
			 int tmpMedian_val;
			 int tmpCounter;
			 int tmpVoltage;
			 int tmpIDSonde;



			 String ^ strCommands;
			 String ^ areSettingsOK;
			 String ^ message = "Data not saved. Do you want to overwrite data anyway?";
			 String ^ caption = "Data not SAVED";
			 MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			 MessageBoxIcon icon = MessageBoxIcon::Exclamation;
			 System::Windows::Forms::DialogResult result;
	 	 
			 Start ^form3 = gcnew Start(); 
			form3->numdat = nDataMax;
			form3->ShowDialog();

			if(form3->intervalTotal!=0)
			{
				N->interval = (form3->intervalTotal)/nDataMax;
				//MessageBox::Show(Convert::ToString(N->interval));
				//strCommands=L"";
				DateTime now= System::DateTime::Now;
				
				try
				{
				 tmpYear_on=now.Year-2000;
				 chtmpYear_on = String::Format("0x{0}",tmpYear_on);
				 ch2tmpYear_on = Convert::ToInt16(chtmpYear_on,16);

				 tmpMonth_on=now.Month;
				 chtmpMonth_on = String::Format("0x{0}",tmpMonth_on);
				 ch2tmpMonth_on = Convert::ToInt16(chtmpMonth_on,16);

				 tmpDay_on=now.Day;
				 chtmpDay_on = String::Format("0x{0}",tmpDay_on);
				 ch2tmpDay_on = Convert::ToInt16(chtmpDay_on,16);

				 tmpHour_on=now.Hour;
 				 chtmpHour_on = String::Format("0x{0}",tmpHour_on);
				 ch2tmpHour_on = Convert::ToInt16(chtmpHour_on,16);

				 tmpMinute_on=now.Minute;
				 chtmpMinute_on = String::Format("0x{0}",tmpMinute_on);
				 ch2tmpMinute_on = Convert::ToInt16(chtmpMinute_on,16);

				 tmpSecond_on=now.Second;
				 chtmpSecond_on = String::Format("0x{0}",tmpSecond_on);
				 ch2tmpSecond_on = Convert::ToInt16(chtmpSecond_on,16);

				 tmpInterval = N->interval;

				 tmpTemp_cal = N->temp_cal;
				 tmpCrystal_cal = N->crystal_cal;
				 tmpMedian_val = N->median_values;
				 //tmpCounter = N->measure_counter;
				 //tmpVoltage = N->voltage;
				 tmpIDSonde = N->IDSonde;
				 

				  if(this->serialPort1->IsOpen)
				  {
					    createNIPHA();
						if((Convert::ToDouble(N->voltage)/1000) > 2.5)
						{

							if(this->lblFileStatuts->Text=="Not saved" || this->lblFileStatuts->Text=="")
							{
								result = MessageBox::Show(this,message,caption,buttons,icon);
								if(result==System::Windows::Forms::DialogResult::Yes)
								{
									if(niphVersion>1.5)
									{
										array<unsigned char>^ buffer0 = {0x24};  //Send Hex ascii code for symbol '$'
										this->serialPort1->Write(buffer0,0,1);
										array<unsigned char>^ buffer1 = {ch2tmpYear_on};
										//array<unsigned char>^ buffer1 = {19};
										this->serialPort1->Write(buffer1,0,1);
										array<unsigned char>^ buffer2 = {ch2tmpMonth_on};
										//array<unsigned char>^ buffer2 = {5};
										this->serialPort1->Write(buffer2,0,1);
										array<unsigned char>^ buffer3 = {ch2tmpDay_on};
										//array<unsigned char>^ buffer3 = {20};
										this->serialPort1->Write(buffer3,0,1);
										array<unsigned char>^ buffer4 ={ch2tmpHour_on};
										//array<unsigned char>^ buffer4 ={17};
										this->serialPort1->Write(buffer4,0,1);
										array<unsigned char>^ buffer5 ={ch2tmpMinute_on};
										//array<unsigned char>^ buffer5 ={32};
										this->serialPort1->Write(buffer5,0,1);
										array<unsigned char>^ buffer6 ={ch2tmpSecond_on};
										//array<unsigned char>^ buffer6 ={0};
										this->serialPort1->Write(buffer6,0,1);

										array<unsigned char>^ buffer7 ={tmpInterval>>8};// interval1
										this->serialPort1->Write(buffer7,0,1);
										array<unsigned char>^ buffer8 ={tmpInterval & 0xFF};//interval2
										this->serialPort1->Write(buffer8,0,1);
										array<unsigned char>^ buffer9 ={tmpTemp_cal>>8}; //temp_cal1
										this->serialPort1->Write(buffer9,0,1);
										array<unsigned char>^ buffer10 ={tmpTemp_cal & 0xFF}; //temp_cal2
										this->serialPort1->Write(buffer10,0,1);
										//array<unsigned char>^ buffer11 ={tmpCrystal_cal>>8}; //crystal_cal1
										//this->serialPort1->Write(buffer11,0,1);
										array<unsigned char>^ buffer12={tmpIDSonde>>8};
										this->serialPort1->Write(buffer12,0,1);
										array<unsigned char>^ buffer13={tmpIDSonde & 0xFF};
										this->serialPort1->Write(buffer13,0,1);

										array<unsigned char>^ buffer14 ={tmpMedian_val};  //median_val
										this->serialPort1->Write(buffer14,0,1);
										array<unsigned char>^ buffer15 ={tmpIDSonde>>8};  //IDSonde
										this->serialPort1->Write(buffer15,0,1);
										array<unsigned char>^ buffer16 ={tmpIDSonde & 0xFF};
										this->serialPort1->Write(buffer16,0,1);
									}
									if(niphVersion<=1.4)
									{
										array<unsigned char>^ buffer0 = {0x24};  //Send Hex ascii code for symbol '$'
										this->serialPort1->Write(buffer0,0,1);
										array<unsigned char>^ buffer1 = {ch2tmpYear_on};
										this->serialPort1->Write(buffer1,0,1);
										array<unsigned char>^ buffer2 = {ch2tmpMonth_on};
										this->serialPort1->Write(buffer2,0,1);
										array<unsigned char>^ buffer3 = {ch2tmpDay_on};
										this->serialPort1->Write(buffer3,0,1);
										array<unsigned char>^ buffer4 ={ch2tmpHour_on};
										this->serialPort1->Write(buffer4,0,1);
										array<unsigned char>^ buffer5 ={ch2tmpMinute_on};
										this->serialPort1->Write(buffer5,0,1);
										array<unsigned char>^ buffer6 ={ch2tmpSecond_on};
										this->serialPort1->Write(buffer6,0,1);

										array<unsigned char>^ buffer7 ={tmpInterval>>8};// interval1
										this->serialPort1->Write(buffer7,0,1);
										array<unsigned char>^ buffer8 ={tmpInterval & 0xFF};//interval2
										this->serialPort1->Write(buffer8,0,1);
										array<unsigned char>^ buffer9 ={tmpTemp_cal>>8}; //temp_cal1
										this->serialPort1->Write(buffer9,0,1);
										array<unsigned char>^ buffer10 ={tmpTemp_cal & 0xFF}; //temp_cal2
										this->serialPort1->Write(buffer10,0,1);
										array<unsigned char>^ buffer11 ={tmpCrystal_cal>>8}; //crystal_cal1
										this->serialPort1->Write(buffer11,0,1);
										array<unsigned char>^ buffer12 ={tmpCrystal_cal & 0xFF};
										this->serialPort1->Write(buffer12,0,1);
										array<unsigned char>^ buffer13 ={tmpMedian_val};  //median_val
										this->serialPort1->Write(buffer13,0,1);
										array<unsigned char>^ buffer14 ={tmpIDSonde};  //IDSonde
										this->serialPort1->Write(buffer14,0,1);								
									
									}

									areSettingsOK = this->serialPort1->ReadLine();

									if(areSettingsOK->Substring(0,2) == "OK")
									{
										MessageBox::Show("Niphargus is recording with a timestep of "+tmpInterval+" sec"," Started",MessageBoxButtons::OK,MessageBoxIcon::Information);
									}
									else
									{
										MessageBox::Show("Problem during initialization of Niphargus","ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
									}
								}
							}
							else
							{
									if(niphVersion>1.5)
									{
										array<unsigned char>^ buffer0 = {0x24};  //Send Hex ascii code for symbol '$'
										this->serialPort1->Write(buffer0,0,1);
										array<unsigned char>^ buffer1 = {ch2tmpYear_on};
										//array<unsigned char>^ buffer1 = {19};
										this->serialPort1->Write(buffer1,0,1);
										array<unsigned char>^ buffer2 = {ch2tmpMonth_on};
										//array<unsigned char>^ buffer2 = {5};
										this->serialPort1->Write(buffer2,0,1);
										array<unsigned char>^ buffer3 = {ch2tmpDay_on};
										//array<unsigned char>^ buffer3 = {20};
										this->serialPort1->Write(buffer3,0,1);
										array<unsigned char>^ buffer4 ={ch2tmpHour_on};
										//array<unsigned char>^ buffer4 ={17};
										this->serialPort1->Write(buffer4,0,1);
										array<unsigned char>^ buffer5 ={ch2tmpMinute_on};
										//array<unsigned char>^ buffer5 ={32};
										this->serialPort1->Write(buffer5,0,1);
										array<unsigned char>^ buffer6 ={ch2tmpSecond_on};
										//array<unsigned char>^ buffer6 ={0};
										this->serialPort1->Write(buffer6,0,1);

										array<unsigned char>^ buffer7 ={tmpInterval>>8};// interval1
										this->serialPort1->Write(buffer7,0,1);
										array<unsigned char>^ buffer8 ={tmpInterval & 0xFF};//interval2
										this->serialPort1->Write(buffer8,0,1);
										array<unsigned char>^ buffer9 ={tmpTemp_cal>>8}; //temp_cal1
										this->serialPort1->Write(buffer9,0,1);
										array<unsigned char>^ buffer10 ={tmpTemp_cal & 0xFF}; //temp_cal2
										this->serialPort1->Write(buffer10,0,1);
										//array<unsigned char>^ buffer11 ={tmpCrystal_cal>>8}; //crystal_cal1
										//this->serialPort1->Write(buffer11,0,1);
										array<unsigned char>^ buffer12={tmpIDSonde>>8};
										this->serialPort1->Write(buffer12,0,1);
										array<unsigned char>^ buffer13={tmpIDSonde & 0xFF};
										this->serialPort1->Write(buffer13,0,1);

										array<unsigned char>^ buffer14 ={tmpMedian_val};  //median_val
										this->serialPort1->Write(buffer14,0,1);
										array<unsigned char>^ buffer15 ={tmpIDSonde>>8};  //IDSonde
										this->serialPort1->Write(buffer15,0,1);
										array<unsigned char>^ buffer16 ={tmpIDSonde & 0xFF};
										this->serialPort1->Write(buffer16,0,1);
									}
									if(niphVersion<=1.4)
									{
										array<unsigned char>^ buffer0 = {0x24};  //Send Hex ascii code for symbol '$'
										this->serialPort1->Write(buffer0,0,1);
										array<unsigned char>^ buffer1 = {ch2tmpYear_on};
										this->serialPort1->Write(buffer1,0,1);
										array<unsigned char>^ buffer2 = {ch2tmpMonth_on};
										this->serialPort1->Write(buffer2,0,1);
										array<unsigned char>^ buffer3 = {ch2tmpDay_on};
										this->serialPort1->Write(buffer3,0,1);
										array<unsigned char>^ buffer4 ={ch2tmpHour_on};
										this->serialPort1->Write(buffer4,0,1);
										array<unsigned char>^ buffer5 ={ch2tmpMinute_on};
										this->serialPort1->Write(buffer5,0,1);
										array<unsigned char>^ buffer6 ={ch2tmpSecond_on};
										this->serialPort1->Write(buffer6,0,1);

										array<unsigned char>^ buffer7 ={tmpInterval>>8};// interval1
										this->serialPort1->Write(buffer7,0,1);
										array<unsigned char>^ buffer8 ={tmpInterval & 0xFF};//interval2
										this->serialPort1->Write(buffer8,0,1);
										array<unsigned char>^ buffer9 ={tmpTemp_cal>>8}; //temp_cal1
										this->serialPort1->Write(buffer9,0,1);
										array<unsigned char>^ buffer10 ={tmpTemp_cal & 0xFF}; //temp_cal2
										this->serialPort1->Write(buffer10,0,1);
										array<unsigned char>^ buffer11 ={tmpCrystal_cal>>8}; //crystal_cal1
										this->serialPort1->Write(buffer11,0,1);
										array<unsigned char>^ buffer12 ={tmpCrystal_cal & 0xFF};
										this->serialPort1->Write(buffer12,0,1);
										array<unsigned char>^ buffer13 ={tmpMedian_val};  //median_val
										this->serialPort1->Write(buffer13,0,1);
										array<unsigned char>^ buffer14 ={tmpIDSonde};  //IDSonde
										this->serialPort1->Write(buffer14,0,1);								
									
									}

									areSettingsOK = this->serialPort1->ReadLine();

									if(areSettingsOK->Substring(0,2) == "OK")
									{
										MessageBox::Show("Niphargus is recording with a timestep of "+tmpInterval+" sec"," Started",MessageBoxButtons::OK,MessageBoxIcon::Information);
										this->btnDownload->Enabled=false;
									}
									else
									{
										MessageBox::Show("Problem during initialization of Niphargus","ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
									}
							}
						}
						else
						{
							MessageBox::Show("Battery voltage too low -> change battery before restart new test");
						}
					}
	     			else
					{
						MessageBox::Show("COM is closed");
					}
			}
			catch(TimeoutException ^)
			{
			
			}
		}
		else
		{
			MessageBox::Show("Aborded acquisition","Abort",MessageBoxButtons::OK,MessageBoxIcon::Information);
		}
	}
private: System::Void Form1_Layout(System::Object^  sender, System::Windows::Forms::LayoutEventArgs^  e) {
			 //this->plt1->Size= new Size(Convert::ToInt32(this->Width*(674/914)),Convert::ToInt32(this->Height*(361/520)));
			 
		 }
private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
			 double wdt;
			 double hgt;
			 int a;
			 int b;

			 a=this->Width;
			 b=this->Height;
			 wdt=Convert::ToDouble(a)*(674.0/914.0);
			 hgt=Convert::ToDouble(b)*(361.0/611.0);
			 this->plt1->Size= System::Drawing::Size(Convert::ToInt32(wdt),Convert::ToInt32(hgt));

			 wdt=Convert::ToDouble(a)*(42.0/914.0);
			 hgt=Convert::ToDouble(b)*(392.0/611.0);
			 this->panel1->Location=Point(Convert::ToInt32(wdt),Convert::ToInt32(hgt));
			 wdt=Convert::ToDouble(a)*(722.0/914.0);
			 hgt=Convert::ToDouble(b)*(4.0/611.0);
			 this->panel2->Location=Point(Convert::ToInt32(wdt),Convert::ToInt32(hgt));
			 wdt=Convert::ToDouble(a)*(638.0/914.0);
			 hgt=Convert::ToDouble(b)*(67.0/611.0);
			 this->lblFileStatuts->Location=Point(Convert::ToInt32(wdt),Convert::ToInt32(hgt));
		 }
private: System::Void tboxYmin_Enter(System::Object^  sender, System::EventArgs^  e) {
				double TempTmp;

				if(Double::TryParse(tboxYmin->Text,TempTmp))
					yMin = Convert::ToDouble(tboxYmin->Text);
				else
				{
					MessageBox::Show("Invalid value","ERROR");
					tboxYmin->Text = Convert::ToString(yMin);
				}
		 }
private: System::Void tboxYmax_Enter(System::Object^  sender, System::EventArgs^  e) {
			 	double TempTmp;

				if(Double::TryParse(tboxYmax->Text,TempTmp))
					yMax = Convert::ToDouble(tboxYmax->Text);
				else
				{
					MessageBox::Show("Invalid value","ERROR");
					tboxYmax->Text = Convert::ToString(yMax);
				}
		 }
private: System::Void cBoxBaud_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cBoxCom_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void cBoxCom_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				array<String ^>^ serialPortsList= nullptr;
				serialPortsList = SerialPort::GetPortNames();
				cBoxCom->BeginUpdate();
				for each(String^ port in serialPortsList) // Loop through all existing serialPorts
				{
					this->cBoxCom->Items->Add(port);
				}
				cBoxCom->EndUpdate();

		 }
private: System::Void cBoxCom_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 	//MessageBox::Show("Here2");
				cBoxCom->Items->Clear();
 				array<String ^>^ serialPortsList= nullptr;
				serialPortsList = SerialPort::GetPortNames();
				cBoxCom->BeginUpdate();
				for each(String^ port in serialPortsList) // Loop through all existing serialPorts
				{
					this->cBoxCom->Items->Add(port);
				}
				cBoxCom->EndUpdate();
		 }
private: System::Void chBoxCom_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (chBoxCom->Checked)
			 {
				 cBoxCom->Enabled = false;
				 cBoxBaud->Enabled = false;
				 lblManualCOM->Enabled = false;
				 lblBaudRate->Enabled = false;
				 //lblNiphVersion->Enabled = false;
			 }
			 else
			 {
				cBoxCom->Enabled = true;
				cBoxBaud->Enabled = true;
				lblManualCOM->Enabled = true;
				lblBaudRate->Enabled = true;
				//lblNiphVersion->Enabled = true;
			 }
		 }
private: System::Void chkHeaderToFile_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

public: long convertByte(unsigned char cTmp)
		{
			String ^ strTmp;
			long iTmp;

			strTmp = String::Format("{0:X2}",cTmp);
			iTmp = Convert::ToInt32(strTmp);

			return(iTmp);
		
		}
public: int findNDataMax(String^ COMAnswer)
		{
			array<String^>^ Params;
			long returnValue = 0;

			Params=COMAnswer->Split(',');

			returnValue=Convert::ToInt32(Params[7]);

			return(returnValue);

		}

		public: double findNiphVersion(String^ COMAnswer)
		{
			array<String^>^ Params;
			double returnValue = 0.0;

			Params=COMAnswer->Split(',');

			returnValue=Convert::ToDouble(Params[8]);

			return(returnValue);
				
		}
private: System::Void tboxXmax_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lblNiphVersion_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
};


}

