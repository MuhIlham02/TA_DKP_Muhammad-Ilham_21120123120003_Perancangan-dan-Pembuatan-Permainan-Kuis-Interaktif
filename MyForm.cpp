#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Membuat dan menjalankan objek dari kelas MyForm (form utama)
    Application::Run(gcnew KuisInteraktif::MyForm());

    return 0;
}


