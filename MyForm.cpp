#include <time.h>
#include <cmath>
#include "MyForm.h"

using namespace ODEV;

//deðiþkenler
#define PI 3.14159265
#define kok_iki 1.41421356
const int maxVector = 20; //maksimum nokta sayýsý
double* W; //doðru denkleminin katsayýlarý
double* vector = new double[maxVector * 3]; //noktalarý tutan dizi
int vectorCount = 0; //anlýk nokta sayýsý
int classCount = 0; //anlýk class sayýsý
int numberofNeurons = 0; //nöron sayýsý

//koordinat düzleminin çizdirilmesi
Void MyForm::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{

	Graphics^ g = e->Graphics;
	int axisThickness = 2; //eksenlerin kalýnlýðý
	int spaceThickness = 1; //ara eksenlerin kalýnlýðý
	Pen^ bluePen = gcnew Pen(Color::Blue, axisThickness);
	Pen^ grayPen = gcnew Pen(Color::Gray, spaceThickness);
	int precision = 25; //aralýklarýn boyutu

	for (int i = precision; i <= pictureBox1->Height - precision; i += precision) //yatay ara çizgilerin çizilmesi
		g->DrawLine(grayPen, 0, i, pictureBox1->Width, i);
	for (int i = precision; i <= pictureBox1->Width + precision; i += precision) //dikey ara çizgilerin çizilmesi
		g->DrawLine(grayPen, i, 0, i, pictureBox1->Height);


	g->DrawLine(bluePen, 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2); //yatay eksenin çizilmesi
	g->DrawLine(bluePen, pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height); //dikey eksenin çizilmesi

}

//noktalarýn çizilip kaydedilmesi
Void MyForm::pictureBox1_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	Graphics^ g;
	g = pictureBox1->CreateGraphics();
	int thickness = 10; //kalemin kalýnlýðý
	int size = 5; //+ iþaretinin boyutu (çizilecek çizgilerin uzunluðunun yarýsý)
	Pen^ pinkPen = gcnew Pen(Color::Pink, thickness);
	Pen^ brownPen = gcnew Pen(Color::Brown, thickness);
	Pen^ redPen = gcnew Pen(Color::Red, thickness);
	Pen^ orangePen = gcnew Pen(Color::Orange, thickness);
	Pen^ greenPen = gcnew Pen(Color::Green, thickness);
	Pen^ blackPen = gcnew Pen(Color::Black, thickness);

	//noktalarýn diziye aktarýlmasý
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

	classCount = classCounter(vector); //her týklama sonucu mevcut sýnýf sayýsýnýn sayýlmasý

	label5->Text = Convert::ToString(vectorCount); //her týklama sonucu mevcut nokta sayýsýnýn güncellenmesi
	label7->Text = Convert::ToString(classCount); //her týklama sonucu mevcut sýnýf sayýsýnýn güncellenmesi

	//MessageBox::Show(vector[vectorCount - 1] + " " + vector[vectorCount] + " " + vector[vectorCount + 1] + "\n"); //show the values of added vector
}

//initialize
Void MyForm::init_Click(System::Object^ sender, System::EventArgs^ e)
{
	//nöron sayýsýnýn belirlenmesi
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

	//nöronlara ait aðýrlýklarýn rastgele -1 ve 1 arasýnda 10^(-5) hassasiyetinde atanmasý
	srand(time(0));
	for (int i = 0; i < numberofNeurons; i++)
	{
		W[i * 4] = ((rand() % 20000) - 10000) / 10000., W[i * 4 + 1] = ((rand() % 20000) - 10000) / 10000., W[i * 4 + 2] = ((rand() % 20000) - 10000) / 10000.;
	}

	//hangi nöronun hangi sýnýf için çalýþtýðýnýn belirlenmesi
	//Aðýrlýklar dizisindeki her 4. eleman o aðýrlýðýn hangi classa ait olduðunu belirtir
	//Aðýrlýklar dizisindeki indisler ise nöronlarýn sýrasýyla ilerler
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


	//çizdirme
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
	double* temp = new double[maxVector * 3]; //normalizasyon sonucunda geri döndürülecek dizinin tanýmlanmasý
	long totalX = 0, totalY = 0; //tüm noktalarýn x'lerinin ve y'lerinin toplamýný tutacak deðiþkenlerin tanýmlanmasý
	double deviationX, deviationY, meanX, meanY; //deðerlere ait ortalamalarý ve standart sapmalarý tutacak olan deðiþkenlerin tanýmlanmasý
	double temp1 = 0, temp2 = 0; //ara deðer (her noktanýn x'i nin tüm x'lerden farkýnýn karelerinin toplamý ve ayný þekilde y için)

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
	double* values = vector; //normalize edilmemiþ deðerlerin alýnmasý
	if (checkBox1->Checked) values = normalization(vector); //normalize edilmiþ deðerlerin alýnmasý

	double net; //nöron giriþ deðeri
	int fnet; //nöron çýkýþ deðeri
	int expVal; //beklenen deðer

	bool err = true; //hata iþareti (en az bir kez döngüye girmesi için true)
	float c = 0.5; //düzeltme artýþý (öðrenme sabitinin karesi)
	int step = 0; //deneme sayýsý
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
				values[i * 3 + 2] == W[j * 4 + 3] ? expVal = 1 : expVal = -1; //gelen noktanýn sýnýfýna göre beklenen deðerin belirlenmesi
				net = (W[j * 4] * values[i * 3]) + (W[j * 4 + 1] * values[i * 3 + 1]) + (W[j * 4 + 2] * bias);
				net > 0 ? fnet = 1 : fnet = -1;

				W[j * 4] += (c * (expVal - fnet) * values[i * 3]);
				W[j * 4 + 1] += (c * (expVal - fnet) * values[i * 3 + 1]);
				W[j * 4 + 2] += (c * (expVal - fnet) * bias);
				if (expVal - fnet) err = true;
			}

			//values[i * 3 + 2] == 1 ? expVal[j] = 1 : expVal = -1; //noktanýn sýnýfýna göre beklenen deðerin belirlenmesi

			/*net = (W[0] * values[i * 3]) + (W[1] * values[i * 3 + 1]) + W[2] * bias;
			net > 0 ? fnet = 1 : fnet = -1;
			W[0] += (c * (expVal - fnet)) * values[i * 3];
			W[1] += (c * (expVal - fnet)) * values[i * 3 + 1];
			W[2] += (c * (expVal - fnet)) * bias;
			if (fnet != expVal) err = true;*/

		}

		//çizdirme
		pictureBox1->Refresh();

		//noktalarýn tekrar çizdirilmesi
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
	double* values = vector; //normalize edilmemiþ deðerlerin alýnmasý
	if (checkBox1->Checked) values = normalization(vector); //normalize edilmiþ deðerlerin alýnmasý

	double net; //nöron giriþ deðeri
	double fnet; //nöron çýkýþ deðeri
	int expVal; //beklenen deðer

	double err; //hata miktarý
	float c = 0.5; //düzeltme artýþý (öðrenme sabitinin karesi)
	int step = 0; //deneme sayýsý
	int bias = 1;

	double fnetDer; //fonksiyon çýkýþ deðerinin türevi
	double ErrMax = 0.5; //hata kabul miktarý
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
				values[i * 3 + 2] == W[j * 4 + 3] ? expVal = 1 : expVal = -1; //gelen noktanýn sýnýfýna göre beklenen deðerin belirlenmesi
				net = (W[j * 4] * values[i * 3]) + (W[j * 4 + 1] * values[i * 3 + 1]) + (W[j * 4 + 2] * bias);
				fnet = (2 / (1 + Math::Exp(-net * lambda))) - 1;
				fnetDer = lambda * (1 - Math::Pow(fnet, 2));

				W[j * 4] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3];
				W[j * 4 + 1] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3 + 1];
				W[j * 4 + 2] += 0.5 * c * (expVal - fnet) * fnetDer * bias;

				err += 0.5 * (Math::Pow((expVal - fnet), 2));
			}

			//values[i * 3 + 2] == 1 ? expVal = 1 : expVal = -1; //noktanýn sýnýfýna göre beklenen deðerin belirlenmesi

			//net = (W[0] * values[i * 3]) + (W[1] * values[i * 3 + 1]) + W[2] * bias;
			//fnet = (2 / (1 + Math::Exp(-net * lambda))) - 1;
			//fnetDer = lambda * (1 - Math::Pow(fnet, 2));

			//W[0] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3];
			//W[1] += 0.5 * c * (expVal - fnet) * fnetDer * values[i * 3 + 1];
			//W[2] += 0.5 * c * (expVal - fnet) * fnetDer * bias;

			//err += 0.5 * (Math::Pow((expVal - fnet), 2));

			//çizdirme
			pictureBox1->Refresh();

			//noktalarýn tekrar çizdirilmesi
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
	//doðruyu öteleme

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

	//	//çizdirme
	//	pictureBox1->Refresh();

	//	//noktalarýn tekrar çizdirilmesi
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

//çizdirme
Void MyForm::myDrawLine(Graphics^ g, Pen^ p, double* w)
{
	for (int i = 0; i < numberofNeurons; i++)
	{
		//çizilecek doðrunun sýnýfa göre renklendirilmesi
		if (W[i * 4 + 3] == 1) p->Color = Color::Pink;
		if (W[i * 4 + 3] == 2) p->Color = Color::Brown;
		if (W[i * 4 + 3] == 3) p->Color = Color::Red;
		if (W[i * 4 + 3] == 4) p->Color = Color::Orange;
		if (W[i * 4 + 3] == 5) p->Color = Color::Green;
		if (W[i * 4 + 3] == 6) p->Color = Color::Black;

		double r = pictureBox1->Height / 2 * kok_iki; //picturebox'ý çevreleyen çemberin yarýçapý
		double a, b, delta, x1, y1, x2, y2; //doðruya ve doðrunun çemberle kesiþtiði noktalara ait katsayý ve deðerler

		if (!w[i * 4] && w[i * 4 + 1])
		{
			b = -w[i * 4 + 2] / w[i * 4 + 1]; //y=b ve x^2+y^2-r^2=0 --> x^2+b^2-r^2 = 0 --> x^2+0x+(b^2-r^2) = 0 denklemlerden kesiþim denklemi
			delta = -4 * (pow(b, 2) - pow(r, 2)); //b^2-4*a*c
			x1 = (-sqrt(delta)) / 2; //-b-kök(delta)/2*a
			x2 = (sqrt(delta)) / 2;	//-b+kök(delta)/2*a
			y1 = b; //noktayý saðlayan y1 deðeri
			y2 = b; //noktayý saðlayan y2 deðeri
		}
		else if (!w[i * 4 + 1] && w[i * 4])
		{
			b = -w[i * 4 + 2] / w[i * 4]; //x=b ve x^2+y^2-r^2=0 --> b^2+y^2-r^2 = 0 -->y^2+0y+(b^2-r^2) = 0 denklemlerden kesiþim denklemi
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
			b = -w[i * 4 + 2] / w[i * 4 + 1]; //y=ax+b ve x^2+y^2-r^2=0 --> x^2+(ax+b)^2-r^2 = 0 -->(a^2+1)x^2+2abx+(b^2-r^2) = 0 denklemlerden kesiþim denklemi
			delta = pow(2 * a * b, 2) - 4 * (pow(a, 2) + 1) * (pow(b, 2) - pow(r, 2));
			x1 = (-2 * a * b - sqrt(delta)) / (2 * (pow(a, 2) + 1));
			x2 = (-2 * a * b + sqrt(delta)) / (2 * (pow(a, 2) + 1));
			y1 = a * x1 + b;
			y2 = a * x2 + b;
		}

		g->DrawLine(p, (int)x1 + pictureBox1->Width / 2, -(int)y1 + pictureBox1->Height / 2, (int)x2 + pictureBox1->Width / 2, -(int)y2 + pictureBox1->Height / 2);


		//Norm vektörünün çizilmesi
		double center[2]; //doðru parçasýnýn merkez noktasý
		center[0] = (x1 + x2) / 2; //doðru parçasýnýn x'i
		center[1] = (y1 + y2) / 2; //doðru parçasýnýn y'si
		double Norm[2]; //Norm vektörü
		Norm[0] = w[i * 4]; //norm vektörünün x'i
		Norm[1] = w[i * 4 + 1]; //norm vektörünün y'si
		double length = sqrt(pow(Norm[0], 2) + pow(Norm[1], 2)); //Norm vektörünün uzunluðu
		int desire = 30; //Norm vektörünün istenen uzunluðu
		Norm[0] *= desire / length; //norm vektörünün x'inin uzatýlmasý
		Norm[1] *= desire / length; //norm vektörünün y'sinin uzatýlmasý
		Norm[0] += center[0]; //norm vektörünün x'inin doðrunun merkezine ötelenmesi
		Norm[1] += center[1]; //norm vektörünün y'sinin doðrunun merkezine ötelenmesi

		g->DrawLine(p, (int)center[0] + pictureBox1->Width / 2, -(int)center[1] + pictureBox1->Height / 2, (int)Norm[0] + pictureBox1->Width / 2, -(int)Norm[1] + pictureBox1->Height / 2);

	}

}

//classlarý saydýrma
Int32 MyForm::classCounter(double* v)
{
	int result = 1;
	for (int i = 1; i < vectorCount; i++)
	{
		int j = 0;
		for (j; j < i; j++)
			if (v[i * 3 + 2] == v[j * 3 + 2]) break;

		if (i == j) //indisteki deðer, arkadan gelen diðer indikteki deðerde tekrarlanmamýþsa ilk kez gelmiþtir bu durumda sonuç 1 arttýrýlýr 
			result++;
	}

	return result;
}

//restart
Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::Application::Restart();
}

