#include <time.h>
#include <cmath>
#include "MyForm.h"

using namespace ODEV;

//de�i�kenler
#define PI 3.14159265
#define kok_iki 1.41421356
const int maxVector = 20; //maksimum nokta say�s�
double* W; //do�ru denkleminin katsay�lar�
double* vector = new double[maxVector * 3]; //noktalar� tutan dizi
int vectorCount = 0; //anl�k nokta say�s�
int classCount = 0; //anl�k class say�s�
int numberofNeurons = 0; //n�ron say�s�

//koordinat d�zleminin �izdirilmesi
Void MyForm::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{

	Graphics^ g = e->Graphics;
	int axisThickness = 2; //eksenlerin kal�nl���
	int spaceThickness = 1; //ara eksenlerin kal�nl���
	Pen^ bluePen = gcnew Pen(Color::Blue, axisThickness);
	Pen^ grayPen = gcnew Pen(Color::Gray, spaceThickness);
	int precision = 25; //aral�klar�n boyutu

	for (int i = precision; i <= pictureBox1->Height - precision; i += precision) //yatay ara �izgilerin �izilmesi
		g->DrawLine(grayPen, 0, i, pictureBox1->Width, i);
	for (int i = precision; i <= pictureBox1->Width + precision; i += precision) //dikey ara �izgilerin �izilmesi
		g->DrawLine(grayPen, i, 0, i, pictureBox1->Height);


	g->DrawLine(bluePen, 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2); //yatay eksenin �izilmesi
	g->DrawLine(bluePen, pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height); //dikey eksenin �izilmesi

}

//noktalar�n �izilip kaydedilmesi
Void MyForm::pictureBox1_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	Graphics^ g;
	g = pictureBox1->CreateGraphics();
	int thickness = 10; //kalemin kal�nl���
	int size = 5; //+ i�aretinin boyutu (�izilecek �izgilerin uzunlu�unun yar�s�)
	Pen^ pinkPen = gcnew Pen(Color::Pink, thickness);
	Pen^ brownPen = gcnew Pen(Color::Brown, thickness);
	Pen^ redPen = gcnew Pen(Color::Red, thickness);
	Pen^ orangePen = gcnew Pen(Color::Orange, thickness);
	Pen^ greenPen = gcnew Pen(Color::Green, thickness);
	Pen^ blackPen = gcnew Pen(Color::Black, thickness);

	//noktalar�n diziye aktar�lmas�
	switch (comboBox1->SelectedIndex)
	{
	default:
		MessageBox::Show("No class selected !");
		break;
	case 0:
		if (vectorCount == maxVector)
		{
			MessageBox::Show("You can't add no more vectors !");
			break;
		}
		else
		{
			g->DrawLine(pinkPen, e->X - size, e->Y, e->X + size, e->Y);
			g->DrawLine(pinkPen, e->X, e->Y - size, e->X, e->Y + size);

			vector[vectorCount * 3] = (e->X) - 200;
			vector[vectorCount * 3 + 1] = 200 - (e->Y);
			vector[vectorCount * 3 + 2] = comboBox1->SelectedIndex + 1;
			vectorCount++;


			break;
		}

	case 1:
		if (vectorCount == maxVector)
		{
			MessageBox::Show("You can't add no more vectors !");
			break;
		}
		else
		{
			g->DrawLine(brownPen, e->X - size, e->Y, e->X + size, e->Y);
			g->DrawLine(brownPen, e->X, e->Y - size, e->X, e->Y + size);

			vector[vectorCount * 3] = (e->X) - 200;
			vector[vectorCount * 3 + 1] = 200 - (e->Y);
			vector[vectorCount * 3 + 2] = comboBox1->SelectedIndex + 1;
			vectorCount++;


			break;
		}

	case 2:
		if (vectorCount == maxVector)
		{
			MessageBox::Show("You can't add no more vectors !");
			break;
		}
		else
		{
			g->DrawLine(redPen, e->X - size, e->Y, e->X + size, e->Y);
			g->DrawLine(redPen, e->X, e->Y - size, e->X, e->Y + size);

			vector[vectorCount * 3] = (e->X) - 200;
			vector[vectorCount * 3 + 1] = 200 - (e->Y);
			vector[vectorCount * 3 + 2] = comboBox1->SelectedIndex + 1;
			vectorCount++;


			break;
		}

	case 3:
		if (vectorCount == maxVector)
		{
			MessageBox::Show("You can't add no more vectors !");
			break;
		}
		else
		{
			g->DrawLine(orangePen, e->X - size, e->Y, e->X + size, e->Y);
			g->DrawLine(orangePen, e->X, e->Y - size, e->X, e->Y + size);

			vector[vectorCount * 3] = (e->X) - 200;
			vector[vectorCount * 3 + 1] = 200 - (e->Y);
			vector[vectorCount * 3 + 2] = comboBox1->SelectedIndex + 1;
			vectorCount++;


			break;
		}

	case 4:
		if (vectorCount == maxVector)
		{
			MessageBox::Show("You can't add no more vectors !");
			break;
		}
		else
		{
			g->DrawLine(greenPen, e->X - size, e->Y, e->X + size, e->Y);
			g->DrawLine(greenPen, e->X, e->Y - size, e->X, e->Y + size);

			vector[vectorCount * 3] = (e->X) - 200;
			vector[vectorCount * 3 + 1] = 200 - (e->Y);
			vector[vectorCount * 3 + 2] = comboBox1->SelectedIndex + 1;
			vectorCount++;


			break;
		}

	case 5:
		if (vectorCount == maxVector)
		{
			MessageBox::Show("You can't add no more vectors !");
			break;
		}
		else
		{
			g->DrawLine(blackPen, e->X - size, e->Y, e->X + size, e->Y);
			g->DrawLine(blackPen, e->X, e->Y - size, e->X, e->Y + size);

			vector[vectorCount * 3] = (e->X) - 200;
			vector[vectorCount * 3 + 1] = 200 - (e->Y);
			vector[vectorCount * 3 + 2] = comboBox1->SelectedIndex + 1;
			vectorCount++;


			break;
		}

	}

	classCount = classCounter(vector); //her t�klama sonucu mevcut s�n�f say�s�n�n say�lmas�

	label5->Text = Convert::ToString(vectorCount); //her t�klama sonucu mevcut nokta say�s�n�n g�ncellenmesi
	label7->Text = Convert::ToString(classCount); //her t�klama sonucu mevcut s�n�f say�s�n�n g�ncellenmesi

	//MessageBox::Show(vector[vectorCount - 1] + " " + vector[vectorCount] + " " + vector[vectorCount + 1] + "\n"); //show the values of added vector
}

//initialize
Void MyForm::init_Click(System::Object^ sender, System::EventArgs^ e)
{
	//n�ron say�s�n�n belirlenmesi
	if (classCount < 2) MessageBox::Show("Class count must be at least 2 !");
	else if (classCount == 2)
	{
		W = new double[4];
		numberofNeurons = 1;
	}
	else
	{
		W = new double[classCount * 4];
		numberofNeurons = classCount;
	}

	//n�ronlara ait a��rl�klar�n rastgele -1 ve 1 aras�nda 10^(-5) hassasiyetinde atanmas�
	srand(time(0));
	for (int i = 0; i < numberofNeurons; i++)
	{
		W[i * 4] = ((rand() % 20000) - 10000) / 10000., W[i * 4 + 1] = ((rand() % 20000) - 10000) / 10000., W[i * 4 + 2] = ((rand() % 20000) - 10000) / 10000.;
	}

	//hangi n�ronun hangi s�n�f i�in �al��t���n�n belirlenmesi
	//A��rl�klar dizisindeki her 4. eleman o a��rl���n hangi classa ait oldu�unu belirtir
	//A��rl�klar dizisindeki indisler ise n�ronlar�n s�ras�yla ilerler
	if (numberofNeurons == 1)
	{
		int minClass = 7;
		for (int i = 0; i < vectorCount; i++)
		{
			if (vector[i * 3 + 2] < minClass) minClass = vector[i * 3 + 2];
		}
		W[3] = minClass;
	}

	else
	{
		int min = 0, max = 7;
		for (int i = 0; i < numberofNeurons; i++)
		{
			for (int j = 0; j < vectorCount; j++)
			{
				if (vector[j * 3 + 2] > min&& vector[j * 3 + 2] <= max) max = vector[j * 3 + 2];
			}
			W[i * 4 + 3] = max;
			min = max;
			max = 7;
		}
	}


	//MessageBox::Show(W[3] + " " + W[7] + " " + W[11] + " " + W[15] + " " + W[19] + " " + W[23]);


	//�izdirme
	Graphics^ g;
	g = pictureBox1->CreateGraphics();
	int thickness = 2;
	Pen^ bluePen = gcnew Pen(Color::Blue, thickness);

	MyForm::myDrawLine(g, bluePen, W);

	/*for (int i = 0; i < numberofNeurons; i++)
	{
		MessageBox::Show("w" + (i + 1) + " " + W[i * 3] + " " + W[i * 3 + 1] + " " + W[i * 3 + 2] + "\n");
	}*/
}

//Normalizasyon
Double* MyForm::normalization(double* v)
{
	double* temp = new double[maxVector * 3]; //normalizasyon sonucunda geri d�nd�r�lecek dizinin tan�mlanmas�
	long totalX = 0, totalY = 0; //t�m noktalar�n x'lerinin ve y'lerinin toplam�n� tutacak de�i�kenlerin tan�mlanmas�
	double deviationX, deviationY, meanX, meanY; //de�erlere ait ortalamalar� ve standart sapmalar� tutacak olan de�i�kenlerin tan�mlanmas�
	double temp1 = 0, temp2 = 0; //ara de�er (her noktan�n x'i nin t�m x'lerden fark�n�n karelerinin toplam� ve ayn� �ekilde y i�in)

	for (int i = 0; i < vectorCount; i++)
	{
		totalX += v[i * 3];
		totalY += v[i * 3 + 1];
	}

	meanX = double(totalX) / vectorCount;
	meanY = double(totalY) / vectorCount;

	for (int i = 0; i < vectorCount; i++)
	{
		temp1 += pow(v[i * 3] - meanX, 2);
		temp2 += pow(v[i * 3 + 1] - meanY, 2);
	}

	deviationX = sqrt(temp1 / (vectorCount - 1));
	deviationY = sqrt(temp2 / (vectorCount - 1));

	for (int i = 0; i < vectorCount; i++)
	{
		temp[i * 3] = (v[i * 3] - meanX) / deviationX;
		temp[i * 3 + 1] = (v[i * 3 + 1] - meanY) / deviationY;
		temp[i * 3 + 2] = v[i * 3 + 2];
	}

	return temp;
}

//discrete
Void MyForm::dis_Click(System::Object^ sender, System::EventArgs^ e)
{
	double* values = vector; //normalize edilmemi� de�erlerin al�nmas�
	if (checkBox1->Checked) values = normalization(vector); //normalize edilmi� de�erlerin al�nmas�

	double net; //n�ron giri� de�eri
	int fnet; //n�ron ��k�� de�eri
	int expVal; //beklenen de�er

	bool err = true; //hata i�areti (en az bir kez d�ng�ye girmesi i�in true)
	float c = 0.5; //d�zeltme art��� (��renme sabitinin karesi)
	int step = 0; //deneme say�s�
	int bias = 1;

	Graphics^ g;
	g = pictureBox1->CreateGraphics();
	int thickness = 2;
	int size = 5;
	Pen^ bluePen = gcnew Pen(Color::Blue, thickness);

	while (err)
	{
		err = false;
		for (int i = 0; i < vectorCount; i++)
		{
			for (int j = 0; j < numberofNeurons; j++)
			{
				values[i * 3 + 2] == W[j * 4 + 3] ? expVal = 1 : expVal = -1; //gelen noktan�n s�n�f�na g�re beklenen de�erin belirlenmesi
				net = (W[j * 4] * values[i * 3]) + (W[j * 4 + 1] * values[i * 3 + 1]) + (W[j * 4 + 2] * bias);
				net > 0 ? fnet = 1 : fnet = -1;

				W[j * 4] += (c * (expVal - fnet) * values[i * 3]);
				W[j * 4 + 1] += (c * (expVal - fnet) * values[i * 3 + 1]);
				W[j * 4 + 2] += (c * (expVal - fnet) * bias);
				if (expVal - fnet) err = true;
			}

			//values[i * 3 + 2] == 1 ? expVal[j] = 1 : expVal = -1; //noktan�n s�n�f�na g�re beklenen de�erin belirlenmesi

			/*net = (W[0] * values[i * 3]) + (W[1] * values[i * 3 + 1]) + W[2] * bias;
			net > 0 ? fnet = 1 : fnet = -1;
			W[0] += (c * (expVal - fnet)) * values[i * 3];
			W[1] += (c * (expVal - fnet)) * values[i * 3 + 1];
			W[2] += (c * (expVal - fnet)) * bias;
			if (fnet != expVal) err = true;*/

		}

		//�izdirme
		pictureBox1->Refresh();

		//noktalar�n tekrar �izdirilmesi
		for (int i = 0; i < vectorCount; i++)
		{
			if (vector[i * 3 + 2] == 1)
			{
				thickness = 10;
				Pen^ pinkPen = gcnew Pen(Color::Pink, thickness);
				g->DrawLine(pinkPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
				g->DrawLine(pinkPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
			}
			else if (values[i * 3 + 2] == 2)
			{
				thickness = 10;
				Pen^ brownPen = gcnew Pen(Color::Brown, thickness);
				g->DrawLine(brownPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
				g->DrawLine(brownPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
			}
			else if (values[i * 3 + 2] == 3)
			{
				thickness = 10;
				Pen^ redPen = gcnew Pen(Color::Red, thickness);
				g->DrawLine(redPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
				g->DrawLine(redPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
			}
			else if (values[i * 3 + 2] == 4)
			{
				thickness = 10;
				Pen^ orangePen = gcnew Pen(Color::Orange, thickness);
				g->DrawLine(orangePen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
				g->DrawLine(orangePen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
			}
			else if (values[i * 3 + 2] == 5)
			{
				thickness = 10;
				Pen^ greenPen = gcnew Pen(Color::Green, thickness);
				g->DrawLine(greenPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
				g->DrawLine(greenPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
			}
			else if (values[i * 3 + 2] == 6)
			{
				thickness = 10;
				Pen^ blackPen = gcnew Pen(Color::Black, thickness);
				g->DrawLine(blackPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
				g->DrawLine(blackPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
			}
		}

		myDrawLine(g, bluePen, W);

		step++;
		label3->Text = Convert::ToString(step);
	}
}

//continuous
Void MyForm::con_Click(System::Object^ sender, System::EventArgs^ e)
{
	double* values = vector; //normalize edilmemi� de�erlerin al�nmas�
	if (checkBox1->Checked) values = normalization(vector); //normalize edilmi� de�erlerin al�nmas�

	double net; //n�ron giri� de�eri
	double fnet; //n�ron ��k�� de�eri
	int expVal; //beklenen de�er

	double err; //hata miktar�
	float c = 0.5; //d�zeltme art��� (��renme sabitinin karesi)
	int step = 0; //deneme say�s�
	int bias = 1;

	double fnetDer; //fonksiyon ��k�� de�erinin t�revi
	double ErrMax = 0.5; //hata kabul miktar�
	double lambda = 1;

	Graphics^ g;
	g = pictureBox1->CreateGraphics();
	int thickness = 2;
	int size = 5;
	Pen^ bluePen = gcnew Pen(Color::Blue, thickness);

	err = ErrMax;
	while (err >= ErrMax)
	{
		err = 0;
		for (int i = 0; i < vectorCount; i++)
		{
			for (int j = 0; j < numberofNeurons; j++)
			{
				values[i * 3 + 2] == W[j * 4 + 3] ? expVal = 1 : expVal = -1; //gelen noktan�n s�n�f�na g�re beklenen de�erin belirlenmesi
				net = (W[j * 4] * values[i * 3]) + (W[j * 4 + 1] * values[i * 3 + 1]) + (W[j * 4 + 2] * bias);
				fnet = (2 / (1 + Math::Exp(-net * lambda))) - 1;
				fnetDer = lambda * (1 - Math::Pow(fnet, 2));

				W[j * 4] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3];
				W[j * 4 + 1] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3 + 1];
				W[j * 4 + 2] += 0.5 * c * (expVal - fnet) * fnetDer * bias;

				err += 0.5 * (Math::Pow((expVal - fnet), 2));
			}

			//values[i * 3 + 2] == 1 ? expVal = 1 : expVal = -1; //noktan�n s�n�f�na g�re beklenen de�erin belirlenmesi

			//net = (W[0] * values[i * 3]) + (W[1] * values[i * 3 + 1]) + W[2] * bias;
			//fnet = (2 / (1 + Math::Exp(-net * lambda))) - 1;
			//fnetDer = lambda * (1 - Math::Pow(fnet, 2));

			//W[0] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3];
			//W[1] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3 + 1];
			//W[2] += 0.5 * c * (expVal - fnet) * fnetDer * bias;

			//err += 0.5 * (Math::Pow((expVal - fnet), 2));

			//�izdirme
			pictureBox1->Refresh();

			//noktalar�n tekrar �izdirilmesi
			for (int i = 0; i < vectorCount; i++)
			{
				if (vector[i * 3 + 2] == 1)
				{
					thickness = 10;
					Pen^ pinkPen = gcnew Pen(Color::Pink, thickness);
					g->DrawLine(pinkPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
					g->DrawLine(pinkPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
				}
				else if (values[i * 3 + 2] == 2)
				{
					thickness = 10;
					Pen^ brownPen = gcnew Pen(Color::Brown, thickness);
					g->DrawLine(brownPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
					g->DrawLine(brownPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
				}
				else if (values[i * 3 + 2] == 3)
				{
					thickness = 10;
					Pen^ redPen = gcnew Pen(Color::Red, thickness);
					g->DrawLine(redPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
					g->DrawLine(redPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
				}
				else if (values[i * 3 + 2] == 4)
				{
					thickness = 10;
					Pen^ orangePen = gcnew Pen(Color::Orange, thickness);
					g->DrawLine(orangePen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
					g->DrawLine(orangePen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
				}
				else if (values[i * 3 + 2] == 5)
				{
					thickness = 10;
					Pen^ greenPen = gcnew Pen(Color::Green, thickness);
					g->DrawLine(greenPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
					g->DrawLine(greenPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
				}
				else if (values[i * 3 + 2] == 6)
				{
					thickness = 10;
					Pen^ blackPen = gcnew Pen(Color::Black, thickness);
					g->DrawLine(blackPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
					g->DrawLine(blackPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
				}
			}

			myDrawLine(g, bluePen, W);

			step++;
			label3->Text = Convert::ToString(step);
		}
	}
	//do�ruyu �teleme

	//if (checkBox1->Checked)
	//{
	//	double* normalizedVector = new double[vectorCount];
	//	normalizedVector = normalization(vector);

	//	double* avgVec = new double[12];
	//	double* avgNormalized = new double[12];
	//	double* avgVecLength = new double[6];
	//	double* avgNormalizedLength = new double[6];


	//	for (int i = 0; i < 6; i++)
	//	{
	//		avgVec[i] = 0;
	//		avgNormalized[i] = 0;
	//	}

	//	for (int i = 0; i < vectorCount; i++)
	//	{
	//		if (vector[i * 3 + 2] == 1)
	//		{
	//			avgVec[0] += vector[i * 3] / vectorCount;
	//			avgVec[1] += vector[i * 3 + 1] / vectorCount;
	//			avgNormalized[0] += normalizedVector[i * 3] / vectorCount;
	//			avgNormalized[1] += normalizedVector[i * 3 + 1] / vectorCount;
	//		}
	//		else if (vector[i * 3 + 2] == 2)
	//		{
	//			avgVec[2] += vector[i * 3] / vectorCount;
	//			avgVec[3] += vector[i * 3 + 1] / vectorCount;
	//			avgNormalized[2] += normalizedVector[i * 3] / vectorCount;
	//			avgNormalized[3] += normalizedVector[i * 3 + 1] / vectorCount;
	//		}
	//		else if (vector[i * 3 + 2] == 3)
	//		{
	//			avgVec[4] += vector[i * 3] / vectorCount;
	//			avgVec[5] += vector[i * 3 + 1] / vectorCount;
	//			avgNormalized[4] += normalizedVector[i * 3] / vectorCount;
	//			avgNormalized[5] += normalizedVector[i * 3 + 1] / vectorCount;
	//		}
	//		else if (vector[i * 3 + 2] == 4)
	//		{
	//			avgVec[6] += vector[i * 3] / vectorCount;
	//			avgVec[7] += vector[i * 3 + 1] / vectorCount;
	//			avgNormalized[6] += normalizedVector[i * 3] / vectorCount;
	//			avgNormalized[7] += normalizedVector[i * 3 + 1] / vectorCount;
	//		}
	//		else if (vector[i * 3 + 2] == 5)
	//		{
	//			avgVec[8] += vector[i * 3] / vectorCount;
	//			avgVec[9] += vector[i * 3 + 1] / vectorCount;
	//			avgNormalized[8] += normalizedVector[i * 3] / vectorCount;
	//			avgNormalized[9] += normalizedVector[i * 3 + 1] / vectorCount;
	//		}
	//		else
	//		{
	//			avgVec[10] += vector[i * 3] / vectorCount;
	//			avgVec[11] += vector[i * 3 + 1] / vectorCount;
	//			avgNormalized[10] += normalizedVector[i * 3] / vectorCount;
	//			avgNormalized[11] += normalizedVector[i * 3 + 1] / vectorCount;
	//		}
	//	}

	//	for (int i = 0; i < 6; i++)
	//	{
	//		avgVecLength[i] = sqrt(pow(avgVec[i * 2], 2) + pow(avgVec[i * 2 + 1], 2));
	//		avgNormalizedLength[i] = sqrt(pow(avgNormalized[i * 2], 2) + pow(avgNormalized[i * 2 + 1], 2));
	//	}

	//	double move;
	//	for (int i = 0; i < numberofNeurons; i++)
	//	{
	//		int temp = W[i * 4 + 3];
	//		move = avgVecLength[temp - 1] / avgNormalizedLength[temp - 1];
	//		//move = abs(move);
	//		W[i * 3 + 2] -= move / W[i * 3 + 1];
	//	}

	//	MessageBox::Show("aaa");

	//	//�izdirme
	//	pictureBox1->Refresh();

	//	//noktalar�n tekrar �izdirilmesi
	//	for (int i = 0; i < vectorCount; i++)
	//	{
	//		if (vector[i * 3 + 2] == 1)
	//		{
	//			thickness = 10;
	//			Pen^ pinkPen = gcnew Pen(Color::Pink, thickness);
	//			g->DrawLine(pinkPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
	//			g->DrawLine(pinkPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
	//		}
	//		else if (values[i * 3 + 2] == 2)
	//		{
	//			thickness = 10;
	//			Pen^ brownPen = gcnew Pen(Color::Brown, thickness);
	//			g->DrawLine(brownPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
	//			g->DrawLine(brownPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
	//		}
	//		else if (values[i * 3 + 2] == 3)
	//		{
	//			thickness = 10;
	//			Pen^ redPen = gcnew Pen(Color::Red, thickness);
	//			g->DrawLine(redPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
	//			g->DrawLine(redPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
	//		}
	//		else if (values[i * 3 + 2] == 4)
	//		{
	//			thickness = 10;
	//			Pen^ orangePen = gcnew Pen(Color::Orange, thickness);
	//			g->DrawLine(orangePen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
	//			g->DrawLine(orangePen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
	//		}
	//		else if (values[i * 3 + 2] == 5)
	//		{
	//			thickness = 10;
	//			Pen^ greenPen = gcnew Pen(Color::Green, thickness);
	//			g->DrawLine(greenPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
	//			g->DrawLine(greenPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
	//		}
	//		else if (values[i * 3 + 2] == 6)
	//		{
	//			thickness = 10;
	//			Pen^ blackPen = gcnew Pen(Color::Black, thickness);
	//			g->DrawLine(blackPen, (int)vector[i * 3] + 200 - size, 200 - (int)vector[i * 3 + 1], (int)vector[i * 3] + 200 + size, 200 - (int)vector[i * 3 + 1]);
	//			g->DrawLine(blackPen, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] - size, (int)vector[i * 3] + 200, 200 - (int)vector[i * 3 + 1] + size);
	//		}
	//	}

	//	myDrawLine(g, bluePen, W);
	//}

}

//�izdirme
Void MyForm::myDrawLine(Graphics^ g, Pen^ p, double* w)
{
	for (int i = 0; i < numberofNeurons; i++)
	{
		//�izilecek do�runun s�n�fa g�re renklendirilmesi
		if (W[i * 4 + 3] == 1) p->Color = Color::Pink;
		if (W[i * 4 + 3] == 2) p->Color = Color::Brown;
		if (W[i * 4 + 3] == 3) p->Color = Color::Red;
		if (W[i * 4 + 3] == 4) p->Color = Color::Orange;
		if (W[i * 4 + 3] == 5) p->Color = Color::Green;
		if (W[i * 4 + 3] == 6) p->Color = Color::Black;

		double r = pictureBox1->Height / 2 * kok_iki; //picturebox'� �evreleyen �emberin yar��ap�
		double a, b, delta, x1, y1, x2, y2; //do�ruya ve do�runun �emberle kesi�ti�i noktalara ait katsay� ve de�erler

		if (!w[i * 4] && w[i * 4 + 1])
		{
			b = -w[i * 4 + 2] / w[i * 4 + 1]; //y=b ve x^2+y^2-r^2=0 --> x^2+b^2-r^2 = 0 --> x^2+0x+(b^2-r^2) = 0 denklemlerden kesi�im denklemi
			delta = -4 * (pow(b, 2) - pow(r, 2)); //b^2-4*a*c
			x1 = (-sqrt(delta)) / 2; //-b-k�k(delta)/2*a
			x2 = (sqrt(delta)) / 2;	//-b+k�k(delta)/2*a
			y1 = b; //noktay� sa�layan y1 de�eri
			y2 = b; //noktay� sa�layan y2 de�eri
		}
		else if (!w[i * 4 + 1] && w[i * 4])
		{
			b = -w[i * 4 + 2] / w[i * 4]; //x=b ve x^2+y^2-r^2=0 --> b^2+y^2-r^2 = 0 -->y^2+0y+(b^2-r^2) = 0 denklemlerden kesi�im denklemi
			delta = -4 * (pow(b, 2) - pow(r, 2));
			y1 = (-sqrt(delta)) / 2;
			y2 = (sqrt(delta)) / 2;
			x1 = b;
			x2 = b;
		}
		else if (!w[i * 4 + 1] && !w[i * 4])
		{
			MessageBox::Show("It's not possible to draw a line with these values !");
		}
		else
		{
			a = -w[i * 4] / w[i * 4 + 1];
			b = -w[i * 4 + 2] / w[i * 4 + 1]; //y=ax+b ve x^2+y^2-r^2=0 --> x^2+(ax+b)^2-r^2 = 0 -->(a^2+1)x^2+2abx+(b^2-r^2) = 0 denklemlerden kesi�im denklemi
			delta = pow(2 * a * b, 2) - 4 * (pow(a, 2) + 1) * (pow(b, 2) - pow(r, 2));
			x1 = (-2 * a * b - sqrt(delta)) / (2 * (pow(a, 2) + 1));
			x2 = (-2 * a * b + sqrt(delta)) / (2 * (pow(a, 2) + 1));
			y1 = a * x1 + b;
			y2 = a * x2 + b;
		}

		g->DrawLine(p, (int)x1 + pictureBox1->Width / 2, -(int)y1 + pictureBox1->Height / 2, (int)x2 + pictureBox1->Width / 2, -(int)y2 + pictureBox1->Height / 2);


		//Norm vekt�r�n�n �izilmesi
		double center[2]; //do�ru par�as�n�n merkez noktas�
		center[0] = (x1 + x2) / 2; //do�ru par�as�n�n x'i
		center[1] = (y1 + y2) / 2; //do�ru par�as�n�n y'si
		double Norm[2]; //Norm vekt�r�
		Norm[0] = w[i * 4]; //norm vekt�r�n�n x'i
		Norm[1] = w[i * 4 + 1]; //norm vekt�r�n�n y'si
		double length = sqrt(pow(Norm[0], 2) + pow(Norm[1], 2)); //Norm vekt�r�n�n uzunlu�u
		int desire = 30; //Norm vekt�r�n�n istenen uzunlu�u
		Norm[0] *= desire / length; //norm vekt�r�n�n x'inin uzat�lmas�
		Norm[1] *= desire / length; //norm vekt�r�n�n y'sinin uzat�lmas�
		Norm[0] += center[0]; //norm vekt�r�n�n x'inin do�runun merkezine �telenmesi
		Norm[1] += center[1]; //norm vekt�r�n�n y'sinin do�runun merkezine �telenmesi

		g->DrawLine(p, (int)center[0] + pictureBox1->Width / 2, -(int)center[1] + pictureBox1->Height / 2, (int)Norm[0] + pictureBox1->Width / 2, -(int)Norm[1] + pictureBox1->Height / 2);

	}

}

//classlar� sayd�rma
Int32 MyForm::classCounter(double* v)
{
	int result = 1;
	for (int i = 1; i < vectorCount; i++)
	{
		int j = 0;
		for (j; j < i; j++)
			if (v[i * 3 + 2] == v[j * 3 + 2]) break;

		if (i == j) //indisteki de�er, arkadan gelen di�er indikteki de�erde tekrarlanmam��sa ilk kez gelmi�tir bu durumda sonu� 1 artt�r�l�r 
			result++;
	}

	return result;
}

//restart
Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::Application::Restart();
}

