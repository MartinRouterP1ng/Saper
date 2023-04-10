#pragma once
#include "GameForm.h"

namespace start {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
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
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
		
	private: System::Windows::Forms::Button^ buttonStartGame;
	private: System::Windows::Forms::Label^ labelTitle;
	protected:

	protected:

	private: System::Windows::Forms::NumericUpDown^ numericUpDownWidth;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownHeight;
	private: System::Windows::Forms::Label^ labelWidth;
	private: System::Windows::Forms::Label^ labelHeight;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownBombCount;
	private: System::Windows::Forms::Label^ labelBombCount;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		int width = 9;
		int height = 9;
		int bombCount = 8;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->buttonStartGame = (gcnew System::Windows::Forms::Button());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->numericUpDownWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownHeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelWidth = (gcnew System::Windows::Forms::Label());
			this->labelHeight = (gcnew System::Windows::Forms::Label());
			this->numericUpDownBombCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelBombCount = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBombCount))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonStartGame
			// 
			this->buttonStartGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonStartGame->Location = System::Drawing::Point(127, 248);
			this->buttonStartGame->Name = L"buttonStartGame";
			this->buttonStartGame->Size = System::Drawing::Size(104, 57);
			this->buttonStartGame->TabIndex = 0;
			this->buttonStartGame->Text = L"START GAME";
			this->buttonStartGame->UseVisualStyleBackColor = true;
			this->buttonStartGame->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::ButtonStartGame_Clicked);
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelTitle->ForeColor = System::Drawing::SystemColors::Control;
			this->labelTitle->Location = System::Drawing::Point(102, 34);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(153, 52);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"SAPER";
			// 
			// numericUpDownWidth
			// 
			this->numericUpDownWidth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->numericUpDownWidth->Location = System::Drawing::Point(112, 138);
			this->numericUpDownWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownWidth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numericUpDownWidth->Name = L"numericUpDownWidth";
			this->numericUpDownWidth->Size = System::Drawing::Size(56, 22);
			this->numericUpDownWidth->TabIndex = 2;
			this->numericUpDownWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numericUpDownWidth->ValueChanged += gcnew System::EventHandler(this, &StartForm::numericUpDownWidth_ValueChanged);
			// 
			// numericUpDownHeight
			// 
			this->numericUpDownHeight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->numericUpDownHeight->Location = System::Drawing::Point(111, 166);
			this->numericUpDownHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownHeight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numericUpDownHeight->Name = L"numericUpDownHeight";
			this->numericUpDownHeight->Size = System::Drawing::Size(56, 22);
			this->numericUpDownHeight->TabIndex = 3;
			this->numericUpDownHeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numericUpDownHeight->ValueChanged += gcnew System::EventHandler(this, &StartForm::numericUpDownHeight_ValueChanged);
			// 
			// labelWidth
			// 
			this->labelWidth->AutoSize = true;
			this->labelWidth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelWidth->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->labelWidth->Location = System::Drawing::Point(12, 140);
			this->labelWidth->Name = L"labelWidth";
			this->labelWidth->Size = System::Drawing::Size(88, 16);
			this->labelWidth->TabIndex = 4;
			this->labelWidth->Text = L"Szerokoœæ: ";
			// 
			// labelHeight
			// 
			this->labelHeight->AutoSize = true;
			this->labelHeight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelHeight->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->labelHeight->Location = System::Drawing::Point(12, 168);
			this->labelHeight->Name = L"labelHeight";
			this->labelHeight->Size = System::Drawing::Size(87, 16);
			this->labelHeight->TabIndex = 5;
			this->labelHeight->Text = L"Wysokoœæ: ";
			// 
			// numericUpDownBombCount
			// 
			this->numericUpDownBombCount->Location = System::Drawing::Point(282, 140);
			this->numericUpDownBombCount->Name = L"numericUpDownBombCount";
			this->numericUpDownBombCount->Size = System::Drawing::Size(60, 22);
			this->numericUpDownBombCount->TabIndex = 6;
			this->numericUpDownBombCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { width* height - 1, 0, 0, 0 });
			this->numericUpDownBombCount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { (width * height) / 10, 0, 0, 0 });
			this->numericUpDownBombCount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownBombCount->ValueChanged += gcnew System::EventHandler(this, &StartForm::NumericUpDownBombCount_ValueChanged);
			// 
			// labelBombCount
			// 
			this->labelBombCount->AutoSize = true;
			this->labelBombCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelBombCount->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->labelBombCount->Location = System::Drawing::Point(180, 142);
			this->labelBombCount->Name = L"labelBombCount";
			this->labelBombCount->Size = System::Drawing::Size(87, 16);
			this->labelBombCount->TabIndex = 7;
			this->labelBombCount->Text = L"Ilosc bomb:";
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(354, 348);
			this->Controls->Add(this->labelBombCount);
			this->Controls->Add(this->numericUpDownBombCount);
			this->Controls->Add(this->labelHeight);
			this->Controls->Add(this->labelWidth);
			this->Controls->Add(this->numericUpDownHeight);
			this->Controls->Add(this->numericUpDownWidth);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->buttonStartGame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
		
			this->Name = L"StartForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rozpocznij Grê";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBombCount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void numericUpDownHeight_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	height = safe_cast<int>(numericUpDownHeight->Value);
	this->numericUpDownBombCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { width* height - 1, 0, 0, 0 });
	this->numericUpDownBombCount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { (width * height) / 10, 0, 0, 0 });
}
private: System::Void numericUpDownWidth_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	width = safe_cast<int>(numericUpDownWidth->Value);
	this->numericUpDownBombCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { width* height - 1, 0, 0, 0 });
	this->numericUpDownBombCount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { (width * height) / 10, 0, 0, 0 });
}

private: System::Void NumericUpDownBombCount_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	bombCount = safe_cast<int>(numericUpDownBombCount->Value);
};
private: System::Void ButtonStartGame_Clicked(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
		this->Hide();
		game::GameForm^ gameForm = gcnew game::GameForm(width, height, bombCount);
		
		
}
};
}
