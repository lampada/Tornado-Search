#include <iostream>
using namespace std;
#include <string>
#include <fstream>

void tofile();
char readin;
char check;
fstream out;
fstream in;
bool flag;
void correct();
void deletewhite();

int main()
{

	out.open("D:/Tornado Search/crawl/items.json");
	in.open("D:/Tornado Search/URL Server/temp1.txt", ios::app);
	while (!out.eof())
	{
		out >> readin;
		if (readin == 'h')
		{
			flag = true;
			tofile();
		}
	}
	out.close();
	in.close();
	correct();
	deletewhite();
	return 0;
}
void tofile()
{
	while (flag == true)
	{
		out >> readin;
		if (readin != ',')
		{
			in << readin;
		}
		else
		{
			flag = false;
			in << endl;
		}
	}
}
void correct()
{
	in.open("D:/Tornado Search/URL Server/temp1.txt");
	fstream rewrite;
	rewrite.open("D:/Tornado Search/URL Server/temp2.txt");
	char rw;
	while (!in.eof())
	{
		in >> rw;
		if (rw != '"' && rw != ']')
			rewrite << rw;
		if (rw == '"' || rw == ']')
		{
			rewrite << endl;
			rewrite << "h";
		}
	}
	in.close();
	rewrite.close();
}
void deletewhite()
{
	char buffer[256];
	memset(buffer, 0, 256);
	in.open("D:/Tornado Search/URL Server/temp2.txt");
	fstream deletew;
	deletew.open("D:/Tornado Search/URL Server/url_list.txt",ios::app);
	while (in.getline(buffer, 256))
	{
		//in.getline(buffer, 256, '\n');
		if (buffer[1] == 't')
			deletew << buffer << endl;
		memset(buffer, 0, 256);
	}
}
