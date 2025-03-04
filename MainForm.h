#pragma once
#include "MainForm.h"
#include <SDL.h>
#include <SDL_video.h>
#include <iostream>
#include <map>
#include <SDL_iostream.h>
#include <stdio.h>
#include <string>
#include <array>
#include <Math.h>
#define SDL_MAIN_HANDLED
// Remove the semicolon at the end of the macro definition


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for MainForm
/// </summary>
public ref class MainForm : public System::Windows::Forms::Form
{
public:
	MainForm(void)
	{
		InitializeComponent();
	}

protected:
	~MainForm()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
private: System::Windows::Forms::Button^ button2;

protected:

private: System::Windows::Forms::Button^ button1;

private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->tableLayoutPanel1->SuspendLayout();
		this->SuspendLayout();
		// 
		// tableLayoutPanel1
		// 
		this->tableLayoutPanel1->ColumnCount = 1;
		this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			50)));
		this->tableLayoutPanel1->Controls->Add(this->button1, 0, 0);
		this->tableLayoutPanel1->Controls->Add(this->button2, 0, 1);
		this->tableLayoutPanel1->Location = System::Drawing::Point(419, 157);
		this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
		this->tableLayoutPanel1->RowCount = 2;
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51)));
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 49)));
		this->tableLayoutPanel1->Size = System::Drawing::Size(200, 221);
		this->tableLayoutPanel1->TabIndex = 0;
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(3, 115);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(194, 103);
		this->button2->TabIndex = 1;
		this->button2->Text = L"EXIT";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(3, 3);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(194, 106);
		this->button1->TabIndex = 0;
		this->button1->Text = L"PLAY";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
		// 
		// MainForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1040, 826);
		this->Controls->Add(this->tableLayoutPanel1);
		this->Name = L"MainForm";
		this->Text = L"MainForm";
		this->tableLayoutPanel1->ResumeLayout(false);
		this->ResumeLayout(false);

	}
#pragma endregion
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Void GameMain(int argc, char* argv[]); {
		// Add game main logic 
		SDL_Window* window;
		SDL_Renderer* renderer;
		MessageBox::Show("Game Start.");
		window = SDL_CreateWindow("Alien War", 1920, 720, 0);

		renderer = SDL_CreateRenderer(window, "Alien War");

		if (SDL_Init(SDL_INIT_VIDEO) == 0) {
			SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
			return;
		}

		if (window == NULL) {
			SDL_Log("Could not create window: %s\n", SDL_GetError());
			return;
		}

		SDL_Log("SDL3 INITIATED");
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);

		bool running = true;
		while (running) {
			SDL_Event event;
			if (SDL_EVENT_MOUSE_MOTION * event.type) {
				float x, y;
				SDL_GetMouseState(&x, &y);
				//std::cout << x << ":" << y << std::endl;
				SDL_Log("Mouse position: (%f, %f)", x, abs(y - 719));
			}

			while (SDL_PollEvent(&event)); {
				if (SDL_EVENT_KEY_DOWN == event.type) {
					switch (event.type) {
					case SDL_EVENT_QUIT:
					SDL_EVENT_WINDOW_CLOSE_REQUESTED:
						SDL_Log("SDL3 Quit Event");
						running = false;
						break;




						//SDL_Log("Game shut down");
						//SDL_DestroyRenderer(renderer);
						//SDL_DestroyWindow(window);


						return;
					}
				}
			}
		}

		/*private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		GameMain();

		Form^ newForm = gcnew Form();
		newForm->Show();
		this->Hide();
		GameMain()*/


	}
};
};