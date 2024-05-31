#pragma once

namespace KuisInteraktif {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;


    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            InitializeQuiz();
            DisplayCurrentQuestion();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::RadioButton^ radioButton1;
        System::Windows::Forms::RadioButton^ radioButton2;
        System::Windows::Forms::RadioButton^ radioButton3;
        System::Windows::Forms::RadioButton^ radioButton4;
        System::Windows::Forms::Button^ buttonNext;
        System::Windows::Forms::Button^ buttonFinish;
        System::ComponentModel::Container^ components;

        array<String^>^ questions;
        array<array<String^>^>^ answers;
        array<int>^ correctAnswers;
        array<bool>^ isAnswered;
        int currentQuestionIndex;
        int correctAnswerCount;

        void InitializeQuiz(void)
        {
            // Inisialisasi pertanyaan dan jawaban
            questions = gcnew array<String^> {
                "Siapakah penemu telepon?",
                    "Planet terbesar di tata surya?",
                    "Ibu kota dari negara Jepang?"
            };

            answers = gcnew array<array<String^>^> {
                gcnew array<String^> { "Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Guglielmo Marconi" },
                    gcnew array<String^> { "Bumi", "Mars", "Jupiter", "Venus" },
                    gcnew array<String^> { "Beijing", "Seoul", "Bangkok", "Tokyo" }
            };

            correctAnswers = gcnew array<int> { 0, 2, 3 };
            isAnswered = gcnew array<bool>(questions->Length);
            currentQuestionIndex = 0;
            correctAnswerCount = 0;
        }

        void DisplayCurrentQuestion(void)
        {
            // Menampilkan pertanyaan dan jawaban
            label1->Text = questions[currentQuestionIndex];
            radioButton1->Text = answers[currentQuestionIndex][0];
            radioButton2->Text = answers[currentQuestionIndex][1];
            radioButton3->Text = answers[currentQuestionIndex][2];
            radioButton4->Text = answers[currentQuestionIndex][3];

            // Reset pilihan jawaban
            radioButton1->Checked = false;
            radioButton2->Checked = false;
            radioButton3->Checked = false;
            radioButton4->Checked = false;

            // Cek apakah pertanyaan sudah dijawab sebelumnya
            if (isAnswered[currentQuestionIndex])
            {
                // Tentukan jawaban yang benar
                int correctAnswerIndex = correctAnswers[currentQuestionIndex];
                if (correctAnswerIndex == 0)
                    radioButton1->Checked = true;
                else if (correctAnswerIndex == 1)
                    radioButton2->Checked = true;
                else if (correctAnswerIndex == 2)
                    radioButton3->Checked = true;
                else if (correctAnswerIndex == 3)
                    radioButton4->Checked = true;
            }
        }

        void CheckAnswer(void)
        {
            // Check if any radio button is checked
            if (radioButton1->Checked || radioButton2->Checked || radioButton3->Checked || radioButton4->Checked)
            {
                // Check if the correct answer is selected
                int correctAnswerIndex = correctAnswers[currentQuestionIndex];
                if ((radioButton1->Checked && correctAnswerIndex == 0) ||
                    (radioButton2->Checked && correctAnswerIndex == 1) ||
                    (radioButton3->Checked && correctAnswerIndex == 2) ||
                    (radioButton4->Checked && correctAnswerIndex == 3))
                {
                    MessageBox::Show("Jawaban Anda benar!", "Hasil", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    correctAnswerCount++;
                }
                else
                {
                    MessageBox::Show("Jawaban Anda salah.", "Hasil", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }

                // Tandai pertanyaan sebagai telah dijawab
                isAnswered[currentQuestionIndex] = true;

                // Go to next question
                currentQuestionIndex++;
                if (currentQuestionIndex < questions->Length)
                {
                    DisplayCurrentQuestion();
                }
                else
                {
                    MessageBox::Show("Kuis selesai!", "Hasil", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    buttonNext->Enabled = false;
                    buttonFinish->Enabled = true;
                }
            }
            else
            {
                MessageBox::Show("Harap pilih salah satu jawaban.", "Peringatan", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
            this->buttonNext = (gcnew System::Windows::Forms::Button());
            this->buttonFinish = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(56, 24);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(286, 26);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Siapakah penemu telepon\?";
            // 
            // radioButton1
            // 
            this->radioButton1->AutoSize = true;
            this->radioButton1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->radioButton1->Location = System::Drawing::Point(31, 68);
            this->radioButton1->Name = L"radioButton1";
            this->radioButton1->Size = System::Drawing::Size(223, 26);
            this->radioButton1->TabIndex = 1;
            this->radioButton1->TabStop = true;
            this->radioButton1->Text = L"Alexander Graham Bell";
            this->radioButton1->UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this->radioButton2->AutoSize = true;
            this->radioButton2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->radioButton2->Location = System::Drawing::Point(31, 100);
            this->radioButton2->Name = L"radioButton2";
            this->radioButton2->Size = System::Drawing::Size(157, 26);
            this->radioButton2->TabIndex = 2;
            this->radioButton2->TabStop = true;
            this->radioButton2->Text = L"Thomas Edison";
            this->radioButton2->UseVisualStyleBackColor = true;
            // 
            // radioButton3
            // 
            this->radioButton3->AutoSize = true;
            this->radioButton3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->radioButton3->Location = System::Drawing::Point(31, 132);
            this->radioButton3->Name = L"radioButton3";
            this->radioButton3->Size = System::Drawing::Size(137, 26);
            this->radioButton3->TabIndex = 3;
            this->radioButton3->TabStop = true;
            this->radioButton3->Text = L"Nikola Tesla";
            this->radioButton3->UseVisualStyleBackColor = true;
            // 
            // radioButton4
            // 
            this->radioButton4->AutoSize = true;
            this->radioButton4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->radioButton4->Location = System::Drawing::Point(31, 164);
            this->radioButton4->Name = L"radioButton4";
            this->radioButton4->Size = System::Drawing::Size(190, 26);
            this->radioButton4->TabIndex = 4;
            this->radioButton4->TabStop = true;
            this->radioButton4->Text = L"Guglielmo Marconi";
            this->radioButton4->UseVisualStyleBackColor = true;
            // 
            // buttonNext
            // 
            this->buttonNext->Location = System::Drawing::Point(334, 260);
            this->buttonNext->Name = L"buttonNext";
            this->buttonNext->Size = System::Drawing::Size(92, 27);
            this->buttonNext->TabIndex = 5;
            this->buttonNext->Text = L"Next";
            this->buttonNext->UseVisualStyleBackColor = true;
            this->buttonNext->Click += gcnew System::EventHandler(this, &MyForm::buttonNext_Click);
            // 
            // buttonFinish
            // 
            this->buttonFinish->Enabled = false;
            this->buttonFinish->Location = System::Drawing::Point(334, 293);
            this->buttonFinish->Name = L"buttonFinish";
            this->buttonFinish->Size = System::Drawing::Size(92, 27);
            this->buttonFinish->TabIndex = 6;
            this->buttonFinish->Text = L"Finish";
            this->buttonFinish->UseVisualStyleBackColor = true;
            this->buttonFinish->Click += gcnew System::EventHandler(this, &MyForm::buttonFinish_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(457, 346);
            this->Controls->Add(this->buttonFinish);
            this->Controls->Add(this->buttonNext);
            this->Controls->Add(this->radioButton4);
            this->Controls->Add(this->radioButton3);
            this->Controls->Add(this->radioButton2);
            this->Controls->Add(this->radioButton1);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm";
            this->Text = L"Kuis Interaktif";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        System::Void buttonNext_Click(System::Object^ sender, System::EventArgs^ e)
        {
            CheckAnswer();
        }

        System::Void buttonFinish_Click(System::Object^ sender, System::EventArgs^ e)
        {
            MessageBox::Show("Kuis selesai!\nJumlah jawaban benar: " + correctAnswerCount + " dari " + questions->Length, "Hasil", MessageBoxButtons::OK, MessageBoxIcon::Information);
            // Optionally, you could reset the quiz here
            currentQuestionIndex = 0;
            correctAnswerCount = 0;
            for (int i = 0; i < isAnswered->Length; i++)
            {
                isAnswered[i] = false;
            }
            DisplayCurrentQuestion();
            buttonNext->Enabled = true;
            buttonFinish->Enabled = false;
        }

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}


