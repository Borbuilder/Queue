#pragma once

#include<string>
#include<msclr\marshal_cppstd.h>
#include"../Queue/TQueue.h"

namespace QAnimation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		double p;
		double q;
		int PushCount = 0;
		int PopCount = 0;;
		TQueue<int>* CircleQueue;

		int CenterX = 80;
		int CenterY = 80;
		int W = 150;
		int H = 150;

		Random^ rnd = gcnew Random();
		int startflag = 0; //Если начали рисовать, то флаг меняется, так мы поймём, что очередь уже создана
		int exflag = 0;
		void Draw()
		{
			int Start = 360 * CircleQueue->GetHeadIndex() / CircleQueue->GetMaxSize();
			int Finish = 360 * CircleQueue->GetCurrentSize() / CircleQueue->GetMaxSize();
			Pen^ MyDrawPen = gcnew Pen(Color::Green);
			MyDrawPen->Width = 10.0F;
			Graphics^ gr = this->CreateGraphics();
			gr->DrawArc(MyDrawPen, CenterX, CenterY, W, H, Start, Finish);
		}
		void Clear()
		{
			int Start = 360 * CircleQueue->GetHeadIndex() / CircleQueue->GetMaxSize();
			int Finish = 360 * CircleQueue->GetCurrentSize() / CircleQueue->GetMaxSize();
			Pen^ MyClearPen = gcnew Pen(Color::Snow);
			MyClearPen->Width = 10.0F;
			Graphics^ gr = this->CreateGraphics();
			gr->DrawArc(MyClearPen, CenterX, CenterY, W, H, Start, Finish);
		}
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button3;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Coral;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::DarkGreen;
			this->button1->Location = System::Drawing::Point(374, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"▶";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Coral;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::DarkGreen;
			this->button2->Location = System::Drawing::Point(441, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(61, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"❚❚";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Coral;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::DarkGreen;
			this->button3->Location = System::Drawing::Point(508, 43);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(61, 33);
			this->button3->TabIndex = 2;
			this->button3->Text = L"◼";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(370, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(247, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Максимальная длина очереди:\r\n";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Chartreuse;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(626, 104);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(74, 25);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(370, 144);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(247, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Вероятность добавления:\r\n";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Chartreuse;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(626, 144);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(74, 25);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(370, 187);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(247, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Вероятность исключения:\r\n";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(370, 230);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(247, 20);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Добавлено в очередь:\r\n";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(370, 274);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(247, 20);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Удалено из очереди:\r\n";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Chartreuse;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(626, 187);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(74, 25);
			this->textBox4->TabIndex = 10;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::Gold;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(626, 230);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(74, 20);
			this->label10->TabIndex = 11;
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::Color::Gold;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Location = System::Drawing::Point(626, 274);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(74, 20);
			this->label11->TabIndex = 12;
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::Color::CornflowerBlue;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label12->Location = System::Drawing::Point(370, 374);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(247, 20);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Элементов в очереди:\r\n";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::Gold;
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label13->Location = System::Drawing::Point(626, 374);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(74, 20);
			this->label13->TabIndex = 14;
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(44, 374);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 25);
			this->label14->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Snow;
			this->ClientSize = System::Drawing::Size(712, 485);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		label14->Text = " ";
		p = Convert::ToDouble(textBox2->Text);
	    q = Convert::ToDouble(textBox4->Text);
		if (startflag == 0)
		{
			int MaxSize = Convert::ToInt32(textBox1->Text);
			CircleQueue = new TQueue<int>(MaxSize);
			startflag = 1;
			for (int i = 0; i < 10; i++)
		    {
				CircleQueue->Push(1);
			}
			
		}
		
		
		timer1->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			
            if (!CircleQueue->empty())
		    {
			     Clear();
		    }

			if (rnd->NextDouble() < p)
			{
				CircleQueue->Push(1);
				PushCount++;

			}
			if (rnd->NextDouble() < q)
			{
				CircleQueue->Pop();
				PopCount++;
			}
		    Draw();

		   label10->Text = Convert::ToString(PushCount);
		   label11->Text = Convert::ToString(PopCount);
		   label13->Text = Convert::ToString(CircleQueue->NumberOfElements());
		}
		catch (const std::exception& ex)
		{
			label14->Text = "Error!";
			timer1->Enabled = false;
			Clear();
			delete CircleQueue;
			startflag = 0;
			PushCount = 0;
			PopCount = 0;
			label10->Text = Convert::ToString(0);
			label11->Text = Convert::ToString(0);
			label13->Text = Convert::ToString(0);
			exflag = 1;
		}
		
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		timer1->Enabled = false;
	}
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		
		timer1->Enabled = false;
		if (exflag == 0)
		{
		    Clear();
		    delete CircleQueue;
		    startflag = 0;
		    PushCount = 0;
		    PopCount = 0;
		    label10->Text = Convert::ToString(0);
		    label11->Text = Convert::ToString(0);
		    label13->Text = Convert::ToString(0);
		}
    }
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

};
}
