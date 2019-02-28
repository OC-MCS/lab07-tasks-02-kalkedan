#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>
#include <sstream>

using namespace std;

class retailItem
{
private:
	string description;
	int unitonHand;
	double price;
public:
	retailItem()
	{
		description = "";
		unitonHand = 0;
		price = 0;
	}
	
	void setDescription(string d)
	{
		description = d;

	}
	void setUnits(int u)
	{
		unitonHand = u;
	}

	void setPrice(double p)
		{
		price = p;
		}
	string getDescription()
	{
		return description;
	}
	int getUnitonHand()
	{
		return unitonHand;
	}
	double getPrice()
	{
		return price;
	}
	double getStockValue()
	{
		return (unitonHand*price);
	}
};
// code to test your RetailItem class goes here
void LoadItem(vector<retailItem> &vec);

int parseInt(string sval, int& val);
double parsedouble(string sval, double& val);



int main()
{
	vector<retailItem> vec;
	LoadItem(vec);
	double total = 0;
	cout << "Description" << "    " << "On Hand" << "  " << "price" <<"  "<<"value"<< endl;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].getDescription()<<"   ";
		cout << vec[i].getUnitonHand()<<"   ";

		cout << vec[i].getPrice() << "  ";
		cout << vec[i].getStockValue() << endl;
		total += vec[i].getStockValue();
	}
	cout <<"The total is"<< total << endl;


	return 0;
}
void LoadItem(vector<retailItem> &vec)
{ 
	fstream inputfile;
	string des;
	string units;
	string price;
	int tempunits,u;
	double tempprice,p;
	inputfile.open("excell.csv");
	if (!inputfile)
	{
		cout << "error" << endl;
	}

	while (getline (inputfile,  des, ','))
	{
		getline(inputfile, units ,',');
		
		getline (inputfile, price);
		
		
			retailItem retail1;
			
			tempunits = parseInt(units, u);
			tempprice = parsedouble(price, p);
			retail1.setDescription(des);
			retail1.setUnits(u);
			retail1.setPrice(p);
			
		vec.push_back(retail1);
	
	}

}
int parseInt(string sval, int& val)
{
	int num;
	
	try
	{
		num = stoi(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		num = -1;
	}
	return  num;
}

double parsedouble(string sval, double& val)
{
	double num;

	try
	{
		num = stod(sval);   
		val = num;
	}
	catch (const std::exception&)
	{
		num = -1;
	}
	return num;
}