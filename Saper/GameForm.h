#pragma once
#include <random>
#include <time.h>
namespace game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		
		int height;
		int width;
		int bombCount;
		int bombsLeft;
		int** board;
		bool** updatedTiles;
		clock_t start, stop;
		double timeCounter;
		int discoveredTiles = 0;


	private: System::Windows::Forms::Label^ labelBombsLeft;
	
		
	


	public:
		
		GameForm(const int w, const int h , const int b)
		{
			height = h;
			width = w;
			bombCount = b;
			bombsLeft = b;
			
			InitializeComponent();
			this->Show();
			gameStart(w, h, b);
			
			
			//
		}
		void gameStart(int w, int h, int b)
		{
			
			start = clock();
			updatedTiles = new bool* [w];
			for(int i = 0; i < w; i++)
			{
				updatedTiles[i] = new bool[h];
			}
			for(int x = 0; x < w; x++)
			{
				for (int y = 0; y < h; y++)
				{
					updatedTiles[x][y] = false;
				}
			}
			createBoard(w, h, b);
			drawBoard(board, w, h);
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
		
        void reveal(int x, int y, int w, int h)
		{
			
			if (x < 0 || x > w - 1 || y < 0 || y > h - 1) return;
			if (board[x][y] == 0)
			{
				updateTileText(x, y);
				board[x][y] = -1;
				reveal(x - 1, y - 1, w, h);
				reveal(x, y - 1, w, h);
				reveal(x + 1, y - 1, w, h);
				reveal(x - 1, y, w, h);
				reveal(x + 1, y, w, h);
				reveal(x - 1, y + 1, w, h);
				reveal(x, y + 1, w, h);
				reveal(x + 1, y + 1, w, h);
			}
			if (board[x][y] != -1 && board[x][y] != 9)
			{
				updateTileText(x, y);
				board[x][y] = -1;
			}
		}
		//create board
		void createBoard(int w, int h, int b)
		{
			int count = 0;
			board = new int* [w];
			for (int i = 0; i < w; i++)
			{
				board[i] = new int[h];
			}
			for (int x = 0; x < w; x++)
			{
				for (int y = 0; y < h; y++)
				{
					board[x][y] = 0;
				}
			}
			//generate bombs
			srand(time(NULL));
			while (count < b)
			{
				int x = rand() % w;
				int y = rand() % h;
				if (board[x][y] != 9)
				{
					board[x][y] = 9;
					count++;
				}
			}
			//mark fields
			for (int x = 0; x < w; x++)
			{
				for (int y = 0; y < h; y++)
				{
					if (board[x][y] != 9)
					{
						int num = 0;
						if (x > 0 && y > 0)
						{
							if (board[x - 1][y - 1] == 9)
							{
								num++;
							}
						}
						if (y > 0)
						{
							if (board[x][y - 1] == 9)
							{
								num++;
							}
						}
						if (x < w - 1 && y > 0)
						{
							if (board[x + 1][y - 1] == 9)
							{
								num++;
							}
						}
						if (x > 0)
						{
							if (board[x - 1][y] == 9)
							{
								num++;
							}
						}
						if (x < w - 1)
						{
							if (board[x + 1][y] == 9)
							{
								num++;
							}
						}
						if (x > 0 && y < h - 1)
						{
							if (board[x - 1][y + 1] == 9)
							{
								num++;
							}
						}
						if (y < h - 1)
						{
							if (board[x][y + 1] == 9)
							{
								num++;
							}
						}
						if (x < w - 1 && y < h - 1)
						{
							if (board[x + 1][y + 1] == 9)
							{
								num++;
							}
						}
						board[x][y] = num;
					}
				}
			}
		}
		//update tile text
        void updateTileText(const int x, const int y)
		{
			if(updatedTiles[x][y]) return;
			String^ bomb = u8"\U0001f4a3";
			String^ explosion = u8"\U0001f4a5";
			int num = board[x][y];
			String^ s = Convert::ToString(num);
			Control^ c = this->Controls["button" + x +"_" + y];
			Button^ b = safe_cast<Button^>(c);
			b->BackColor = System::Drawing::Color::White;
			updatedTiles[x][y] = true;
			
			switch (num)
			{
			case 0:
				b->Text = "";
				reveal(x, y, width, height);
				discoveredTiles++;
				break;
			case 1:
				b->ForeColor = System::Drawing::Color::Blue;
				b->Text = s;
				discoveredTiles++;
				break;
			case 2:
				b->ForeColor = System::Drawing::Color::Green;
				b->Text = s;
				discoveredTiles++;
				break;
			case 3:
				b->ForeColor = System::Drawing::Color::Red;
				b->Text = s;
				discoveredTiles++;
				break;
			case 4:
				b->ForeColor = System::Drawing::Color::DarkBlue;
				b->Text = s;
				discoveredTiles++;
				break;
			case 5:
				b->ForeColor = System::Drawing::Color::Maroon;
				b->Text = s;
				discoveredTiles++;
				break;
			case 6:
				b->ForeColor = System::Drawing::Color::DarkMagenta;
				b->Text = s;
				discoveredTiles++;
				break;
			case 7:
				b->ForeColor = System::Drawing::Color::Orange;
				b->Text = s;
				discoveredTiles++;
				break;
			case 8:
				b->ForeColor = System::Drawing::Color::Purple;
				b->Text = s;
				discoveredTiles++;
				break;
			case 9:
				b->ForeColor = System::Drawing::Color::Black;
				b->Text = bomb;
				endGameLose(width, height);
				break;
			default:
				break;
			}
			if (discoveredTiles >= (width * height) - bombCount)
				endGameVictory();

		}
		
        void endGameLose(int w, int h)
		{
			for (int x = 0; x < w; x++)
			{
				for (int y = 0; y < h; y++)
				{
					if(board[x][y]==9)
						updateTileText(x, y);
				}
			}
			stop=clock();
			int time = static_cast<int>(stop - start) / CLOCKS_PER_SEC;
			int seconds = time%60;
			int minuty = time / 60;
			String^ s = "Czas gry: " + minuty.ToString()+"m"+seconds.ToString()+"s";
			MessageBox::Show("PRZEGRANA\n"+s);
			exit(0);


		}
		void endGameVictory()
		{
			stop = clock();
			int time = static_cast<int>(stop - start) / CLOCKS_PER_SEC;
			int seconds = time % 60;
			int minutes = time / 60;
			String^ s = "Czas gry: " + minutes.ToString() + "m" + seconds.ToString()+"s";
			MessageBox::Show("WYGRANA\n"+s);
			exit(0);
		}
		
		
       
		//draw board function
		void drawBoard(int** board, int w, int h)
		{
			int x = 0;
			int y = 0;
			for (int i = 0; i < w; i++)
			{
				for (int j = 0; j < h; j++)
				{
					Button^ button = gcnew Button();
					button->ForeColor = System::Drawing::Color::Black;
					button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(238)));
					button->Location = System::Drawing::Point(x, y+25);
					button->Name = L"button" + i +"_" + j;
					button->Size = System::Drawing::Size(25, 25);
					button->TabIndex = 0;
					button->Text = L"";
					button->UseVisualStyleBackColor = true;
					button->Click += gcnew System::EventHandler(this, &GameForm::button_Click);
					button->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::button_RightClick);
					button->BackColor = System::Drawing::Color::Gray;
					this->Controls->Add(button);
					x += 25;
				}
				x = 0;
				y += 25;
			}
		}
		

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		//button_Click event handler
		System::Void button_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			String^ explosion = u8"\U0001f4a5";
			Button^ b = safe_cast<Button^>(sender);
			String^ s = b->Name;
			int offsetPosition = 0;
			for(int i = 0; i < s->Length; i++)
			{
				if(s->Substring(i, 1) == "_")
				{
					offsetPosition = i;
				}
			}
			const int x = Convert::ToInt32(s->Substring(6, offsetPosition-6));
			const int y = Convert::ToInt32(s->Substring(offsetPosition+1, s->Length-offsetPosition-1));
			
			if (board[x][y] == 9)
			{
				b->ForeColor = System::Drawing::Color::Orange;
				b->Text = explosion;
				updatedTiles[x][y] = true;
				endGameLose(width, height);
			}
			else
			{
				updateTileText(x, y);
			}
			updateTileText(x, y);
		}
		//button right click event handler
		System::Void button_RightClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
        {
			
	        String^ flag = u8"\U0001f6a9";
        	Button^ b = safe_cast<Button^>(sender);
			String^ s = b->Name;
			int offsetPosition = 0;
			for (int i = 0; i < s->Length; i++)
			{
				if (s->Substring(i, 1) == "_")
				{
					offsetPosition = i;
				}
			}
			const int x = Convert::ToInt32(s->Substring(6, offsetPosition - 6));
			const int y = Convert::ToInt32(s->Substring(offsetPosition + 1, s->Length - offsetPosition -1));
			if (e->Button == System::Windows::Forms::MouseButtons::Right)
			{
				if (b->Text == "")
				{
					b->BackColor = Color::White;
					b->ForeColor = Color::Red;
					b->Text = flag;
					if (bombsLeft > 0)
						bombsLeft--;
					this->labelBombsLeft->Text = bombsLeft.ToString();
				}
				else if (b->Text == flag)
				{
					b->BackColor = Color::Gray;
					b->Text = "";
					bombsLeft++;
					this->labelBombsLeft->Text = bombsLeft.ToString();

				}
			}
		}
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelBombsLeft = gcnew System::Windows::Forms::Label;
			this->SuspendLayout();

			
			this->labelBombsLeft->AutoSize = true;
			this->labelBombsLeft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelBombsLeft->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->labelBombsLeft->Location = System::Drawing::Point((height*25)/2-7, 5);
			this->labelBombsLeft->Name = L"labelBombsLeft";
			this->labelBombsLeft->Size = System::Drawing::Size(87, 16);
			this->labelBombsLeft->TabIndex = 7;
			this->labelBombsLeft->Text = bombCount.ToString();
			this->Controls->Add(labelBombsLeft);
			
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(25*height, 25*width+25);
			
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GameForm";
			this->Text = L"game";
			this->TopMost = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
