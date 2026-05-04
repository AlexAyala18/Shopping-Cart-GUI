#pragma once
#include "Welcome.h"
#include "User.h"
#include "showMenu.h"

namespace ShoppingCart {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for total
	/// </summary>
	public ref class total : public System::Windows::Forms::Form
	{
	public:
		total(void)
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
		~total()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnView;


	private: System::Windows::Forms::Button^ btnBack;



	private: System::Windows::Forms::DataGridView^ dataGrid;
	private: System::Windows::Forms::Button^ btnBuy;



	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnView = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->btnBuy = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Your Total Amount is ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(69, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 31);
			this->label3->TabIndex = 2;
			this->label3->Text = L"CHECKOUT";
			// 
			// btnView
			// 
			this->btnView->Location = System::Drawing::Point(110, 59);
			this->btnView->Name = L"btnView";
			this->btnView->Size = System::Drawing::Size(75, 23);
			this->btnView->TabIndex = 3;
			this->btnView->Text = L"View";
			this->btnView->UseVisualStyleBackColor = true;
			this->btnView->Click += gcnew System::EventHandler(this, &total::btnView_Click);
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(186, 226);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"GO BACK";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &total::btnBack_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Location = System::Drawing::Point(41, 88);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->Size = System::Drawing::Size(220, 132);
			this->dataGrid->TabIndex = 7;
			// 
			// btnBuy
			// 
			this->btnBuy->Location = System::Drawing::Point(51, 226);
			this->btnBuy->Name = L"btnBuy";
			this->btnBuy->Size = System::Drawing::Size(75, 23);
			this->btnBuy->TabIndex = 8;
			this->btnBuy->Text = L"Buy";
			this->btnBuy->UseVisualStyleBackColor = true;
			this->btnBuy->Click += gcnew System::EventHandler(this, &total::btnBuy_Click);
			// 
			// total
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnBuy);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnView);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Name = L"total";
			this->Text = L"total";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnView_Click(System::Object^ sender, System::EventArgs^ e) {
	try 
	{
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=ShoppingCart;Integrated Security=True;Encrypt=False";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		SqlDataAdapter^ dataAD = gcnew SqlDataAdapter("SELECT [item], [des], [pri], [qua] FROM [dbo].[itemInfo]", % sqlConn);
		DataTable^ dTable = gcnew DataTable();
		dataAD->Fill(dTable);
		dataGrid->DataSource = dTable;
		
	}
	catch (Exception^ e) {
		MessageBox::Show("Failed to connect to database",
			"Purchase was unsuccessful", MessageBoxButtons::OK);
	}


}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();

}
private: System::Void btnBuy_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Purchase successful!",
		"Thanks for shopping with us!", MessageBoxButtons::OK);
	this->Close();
}
};
}
