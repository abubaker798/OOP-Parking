#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class Dimensions {
private:
	int width;
	int depth;
public:

	Dimensions() {}

	Dimensions(int width, int depth) {

		this->width = width;
		this->depth = depth;
	}

	void setDepth(int depth)
	{
		this->depth = depth;
	}

	void setWidth(int width)
	{
		this->width = width;
	}

	int getWidth()
	{
		return width;
	}

	int getDepth()
	{
		return depth;
	}

};

class Vehicle {
private:
	string modelName;
	int identificationNumber;
	int modelYear;
	Dimensions dimensions;
	friend class Slot;
public:
	Vehicle() {}
	Vehicle(string modelName, int identificationNumber, int modelYear, Dimensions dimensions) {
		this->modelName = modelName;
		this->identificationNumber = identificationNumber;
		this->modelYear = modelYear;
		this->dimensions = dimensions;
	}

	void setModelName(string modelName)
	{
		this->modelName = modelName;
	}

	string getModelName()
	{
		return modelName;
	}

	void setIdentificationNumber(int identificationNumber)
	{
		this->identificationNumber = identificationNumber;
	}

	int getIdentificationNumber()
	{
		return identificationNumber;
	}

	void setModelYear(int modelYear)
	{
		this->modelYear = modelYear;
	}

	int getModelYear()
	{
		return modelYear;
	}
};

class TimeAndDate
{
private:
	double year;
	double month;
	double day;
	double hour;
	double minute;
	double second;
public:
	TimeAndDate(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	double getYear()
	{
		return year;
	}

	double getMonth()
	{
		return month;
	}

	double getDay()
	{
		return day;
	}

	double getHour()
	{
		return hour;
	}

	double getMinute()
	{
		return minute;
	}

	double getSecond()
	{
		return second;
	}

	bool operator >= (TimeAndDate departureTime)
	{
		if (getYear() >= departureTime.getYear() && getMonth() >= departureTime.getMonth() && getDay() >= departureTime.getDay() && getHour() >= departureTime.getHour() && getMinute() >= departureTime.getMinute() && getSecond() >= departureTime.getSecond());
		{
			return true;
		}

		return false;
	}

	bool operator <= (TimeAndDate arrivalTinme)
	{
		if (getYear() <= arrivalTinme.getYear() && getMonth() <= arrivalTinme.getMonth() && getDay() <= arrivalTinme.getDay() && getHour() <= arrivalTinme.getHour() && getMinute() <= arrivalTinme.getMinute() && getSecond() <= arrivalTinme.getSecond());
		{
			return true;
		}

		return false;
	}
};

class ArrivalTime : public TimeAndDate
{

public:
	ArrivalTime(double year = 0, double month = 0, double day = 0, double hour = 0, double minute = 0, double second = 0) : TimeAndDate(year, month, day, hour, minute, second) {}
};


class DepartureTime : public TimeAndDate
{
public:
	DepartureTime(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0) : TimeAndDate(year, month, day, hour, minute, second) {}
};


class Counter {
private:
	int countIncome = 0;
	int countVehicle = 0;

public:

	void setCountIncome(int countIncome)
	{
		this->countIncome = countIncome;
	}

	void setCountVehicle(int countVehicle)
	{
		this->countVehicle = countVehicle;
	}

	int getCountIncome()
	{
		return countIncome;
	}

	int getCountVehicle()
	{
		return countVehicle;
	}
};

class Slot {

private:
	Dimensions dimensions;
	int identificationNumber = -1;
	TimeAndDate time_;
	Counter count;
public:
	Slot() {}

	Slot(Dimensions dimensions, int identificationNumber = -1)
	{
		this->dimensions = dimensions;
		this->identificationNumber = identificationNumber;
	}


	void setDimensions(Dimensions dimensions)
	{
		this->dimensions.setWidth(dimensions.getWidth());
		this->dimensions.setDepth(dimensions.getDepth());
	}

	Dimensions getDimensions()
	{
		return dimensions;
	}


	void setIdentificationNumber(int identificationNumber)
	{
		this->identificationNumber = identificationNumber;
	}


	int getIdentificationNumber()
	{
		return identificationNumber;
	}

	void setTimeAndDate(TimeAndDate time_)
	{
		this->time_ = time_;
	}

	void setCountVehicle(int count)
	{
		this->count.setCountVehicle(count);
	}

	void setCountIncome(int count)
	{
		this->count.setCountIncome(count);
	}

	TimeAndDate getTime()
	{
		return time_;
	}

	int getCountVehicle()
	{
		return count.getCountVehicle();
	}

	int getCountIncome()
	{
		return count.getCountIncome();
	}

	bool operator >= (Vehicle vehicle)
	{

		if (dimensions.getWidth() >= vehicle.dimensions.getWidth() && dimensions.getDepth() >= vehicle.dimensions.getDepth())
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool operator <= (Dimensions dimensions)
	{
		if (this->dimensions.getWidth() <= dimensions.getWidth() || this->dimensions.getDepth() <= dimensions.getDepth())
		{
			return true;
		}
		return false;
	}


};




class ParkingGarage {
private:
	Slot* slots;
	int siz;
public:
	ParkingGarage() {}

	ParkingGarage(Slot* slots, int siz)
	{
		this->siz = siz;
		this->slots = new Slot[siz];
		this->slots = slots;
	}

	void setSiz(int siz)
	{
		this->siz = siz;
	}

	int getSiz()
	{
		return siz;
	}

	Slot operator[] (int index)
	{
		return slots[index];
	}

	bool isAvailableSlot()
	{

		for (int i = 0; i < siz; i++)
		{
			if (slots[i].getIdentificationNumber() == -1)
			{
				return true;
			}
		}
		cout << "\n Sorry Parking Garage is full\n\n";
		return false;
	}

	void printListOfSlots()
	{
		cout << endl;
		for (int i = 0; i < siz; i++)
		{
			if (slots[i].getIdentificationNumber() == -1)
			{
				cout << " EmptySlot ";
			}
			else
			{
				cout << slots[i].getIdentificationNumber() << " ";
			}
		} cout << endl << endl;
	}

	void park_in(string parkinType, Vehicle vehicle) {

		if (isAvailableSlot())
		{
			if (parkinType == "first come first served")
			{

				for (int i = 0; i < siz; i++)
				{
					if (slots[i] >= vehicle && slots[i].getIdentificationNumber() == -1)
					{
						// Arrivale the Vehicle in this slot
						slots[i].setIdentificationNumber(vehicle.getIdentificationNumber());

						// Capture date and time of arrival

						time_t now;

						struct tm nowLoclal;

						now = time(0);

						nowLoclal = *localtime(&now);

						ArrivalTime arrivalTime(nowLoclal.tm_year + 1900, nowLoclal.tm_mon + 1, nowLoclal.tm_mday, nowLoclal.tm_hour, nowLoclal.tm_min, nowLoclal.tm_sec);

						slots[i].setTimeAndDate(arrivalTime);

						cout << "\n The Arrival date: " << slots[i].getTime().getDay() << "/" << slots[i].getTime().getMonth() << "/" << slots[i].getTime().getYear() << endl;
						cout << "\n The Arrival Time: " << slots[i].getTime().getHour() << ":" << slots[i].getTime().getMinute() << ":" << slots[i].getTime().getSecond() << endl;

						//Increase the number of Vehicles in this slot
						int count = slots[i].getCountVehicle();

						slots[i].setCountVehicle(++count);
						break;
					}
				}
			}

			else
			{
				cout << "\n Sorry dose not like a slot fit your vehicle\n\n";
			}
		}

		else if (parkinType == "best fit")
		{
			int min = 0;
			Dimensions minimumDimension;
			minimumDimension.setWidth(slots[min].getDimensions().getWidth());
			minimumDimension.setDepth(slots[min].getDimensions().getWidth());

			for (int i = 0; i < siz; i++)
			{
				if (slots[i] <= minimumDimension && slots[i] >= vehicle && slots[i].getIdentificationNumber() == -1)
				{
					min = i;
					minimumDimension.setWidth(slots[i].getDimensions().getWidth());
					minimumDimension.setDepth(slots[i].getDimensions().getWidth());
				}
			}

			if (slots[min].getIdentificationNumber() == -1)
			{
				// Arrivale the Vehicle in this slot
				slots[min].setIdentificationNumber(vehicle.getIdentificationNumber());

				time_t now;

				struct tm nowLoclal;

				now = time(0);

				nowLoclal = *localtime(&now);

				ArrivalTime arrivalTime(nowLoclal.tm_year + 1900, nowLoclal.tm_mon + 1, nowLoclal.tm_mday, nowLoclal.tm_hour, nowLoclal.tm_min, nowLoclal.tm_sec);

				slots[min].setTimeAndDate(arrivalTime);

				slots[min].setTimeAndDate(arrivalTime);

				cout << "\n The Arrival date: " << slots[min].getTime().getDay() << "/" << slots[min].getTime().getMonth() << "/" << slots[min].getTime().getYear() << endl;
				cout << " The Arrival Time: " << slots[min].getTime().getHour() << ":" << slots[min].getTime().getMinute() << ":" << slots[min].getTime().getSecond() << endl;


				//Increase the number of Vehicles in this slot
				int count = slots[min].getCountVehicle();

				slots[min].setCountVehicle(++count);

				return;

			}

			else
			{
				cout << "\n Sorry dose not like a slot fit your vehicle\n\n";
			}
		}
	}


	void park_out(int getIdentificationNumbe)
	{

		for (int i = 0; i < siz; i++)
		{
			if (slots[i].getIdentificationNumber() == getIdentificationNumbe)
			{
				time_t now;

				struct tm nowLoclal;

				now = time(0);

				nowLoclal = *localtime(&now);

				DepartureTime departureTime(nowLoclal.tm_year + 1900, nowLoclal.tm_mon + 1, nowLoclal.tm_mday, nowLoclal.tm_hour, nowLoclal.tm_min, nowLoclal.tm_sec);

				slots[i].setTimeAndDate(departureTime);

				slots[i].setTimeAndDate(departureTime);



				cout << "\n The departure date: " << slots[i].getTime().getDay() << "/" << slots[i].getTime().getMonth() << "/" << slots[i].getTime().getYear() << endl;
				cout << " The departure Time: " << slots[i].getTime().getHour() << ":" << slots[i].getTime().getMinute() << ":" << slots[i].getTime().getSecond() << endl;

				calculateFees(i);

				slots[i].setIdentificationNumber(-1);

				return;
			}
		}

		try
		{
			throw "\n This vehicle is not parkin the garage\n\n";
		}
		catch (const char* msg)
		{
			cout << msg;
		}

	}


	void calculateFees(int index)
	{


		double years = slots[index].getTime().getYear() - slots[index].getTime().getYear();

		double months = slots[index].getTime().getMonth() - slots[index].getTime().getMonth();


		double days = slots[index].getTime().getDay() - slots[index].getTime().getDay();


		double hours = slots[index].getTime().getHour() - slots[index].getTime().getHour();


		double minutes = slots[index].getTime().getMinute() - slots[index].getTime().getMinute();


		double seconds = slots[index].getTime().getSecond() - slots[index].getTime().getSecond();


		double DurationByHours = (years * 12 * 30 * 24) + (months * 30) + (days * 24) + hours + (minutes / 60) + (seconds / 360);


		int count = slots[index].getCountIncome();

		slots[index].setCountIncome((DurationByHours * 5) + count);

		cout << "\n the fees is: " << DurationByHours * 5;

	}


	void displayAvilableParkingSlot()
	{
		cout << "\n available Parking Slot: ";
		for (int i = 0; i < siz; i++)
		{
			if (slots[i].getIdentificationNumber() == -1)
			{
				cout << "<" << i << ">" << " ";
			}

		}cout << endl; cout << endl;
	}

	void totalIncome(TimeAndDate arrivalTinme, TimeAndDate departureTime)
	{
		int totalIncome = 0;
		for (int i = 0; i < siz; i++)
		{
			if (slots[i].getTime() >= arrivalTinme && slots[i].getTime() <= departureTime)
			{
				totalIncome += slots[i].getCountIncome();
			}
		}

		cout << "\n the total Income in this time is " << totalIncome << " EGP\n\n";

	}

	void totalVehicle(ArrivalTime arrivalTinme, DepartureTime departureTime)
	{
		int totalVehicle = 0;
		for (int i = 0; i < siz; i++)
		{
			if (slots[i].getTime() >= arrivalTinme && slots[i].getTime() <= departureTime)
			{
				totalVehicle += slots[i].getCountVehicle();
			}
		}
	}

	~ParkingGarage()
	{
		delete[]slots;
	}

};

int main()
{
	cout << "\n Please enter the number of slots in garage: ";

	int siz; cin >> siz;

	Slot* slots;

	slots = new Slot[siz];

	cout << "\n\n Please enter the dimensions of each slot (width, depth): \n";

	int width, Depth;

	Dimensions dimensions;

	for (int i = 0; i < siz; i++)
	{
		cout << "\n Width of slot #" << i << ": ";

		cin >> width;

		dimensions.setWidth(width);

		cout << "\n Depth of slot #" << i << ": ";

		cin >> Depth;

		dimensions.setWidth(Depth);

		slots[i].setDimensions(dimensions);

		cout << endl;
	}

	ParkingGarage park(slots, siz);

	string parkType;

	int select;


	while (true)
	{
		cout << "\n please select the configuration of park_in:\n\n 1.first come first served\n 2.best fit\n"; cin >> select;

		if (select == 1)
		{
			parkType = "first come first served";

			break;
		}

		if (select == 2)
		{
			parkType = "best fit";

			break;
		}

		try
		{
			throw " \n invalide selected number please try agin\n\n";
		}
		catch (const char* msg)
		{
			cout << msg;
		}
	}

	while (true)
	{

		cout << "\n select number of fowlling:\n\n 1.park_in\n 2.park_out\n 3.display list of slots\n 4.Display the available parking slots\n";
		cout << "\n 5.Calculate the total income\n 6.Calculate the total number of vehicles that used the parking garage\n 7.exit from applection\n ";

		cin >> select;

		if (select == 1)
		{
			string modelName;
			int plateNumber;
			int modelYear;
			Dimensions dimensions;

			cout << "\n enter the vehicle model name: "; cin >> modelName;

			cout << "\n enter the vehicle plate Number: "; cin >> plateNumber;

			while (plateNumber < 0)
			{
				cout << "\nInvalid plate Number \n inter the vehicle plate Number agin: "; cin >> plateNumber;
			}

			cout << "\n enter the vehicle model year: "; cin >> modelYear;

			while (modelYear < 0)
			{
				cout << "\nInvalid vehicle model \n inter the vehicle model year agin: "; cin >> modelYear;
			}

			cout << "\n enter the width of the vehicle: "; cin >> width;

			while (width < 0)
			{
				cout << "\nInvalid width \n enter the width of the vehicle agin: "; cin >> width;
			}

			cout << "\n enter the depth of the vehicle: "; cin >> Depth;

			while (Depth < 0)
			{
				cout << "\nInvalid Depth \n enter the Depth of the vehicle agin: "; cin >> Depth;
			}

			dimensions.setWidth(width);

			dimensions.setDepth(Depth);

			Vehicle vehicle(modelName, plateNumber, modelYear, dimensions);

			park.park_in(parkType, vehicle);
		}

		else if (select == 2)

		{
			int plateNumber;

			cout << "\n enter the vehicle plate Number to park out it: "; cin >> plateNumber;

			while (plateNumber < 0)
			{
				cout << "\nInvalid plate Number \n inter the vehicle plate Number agin: "; cin >> plateNumber;
			}

			park.park_out(plateNumber);
		}

		else if (select == 3)
		{
			park.printListOfSlots();
		}

		else if (select == 4)
		{
			park.displayAvilableParkingSlot();
		}

		else if (select == 5)
		{

			int year, month, day, hour, minute, second;

			cout << "\n please inter the start time: \n year: ";
			cin >> year;

			while (year < 0)
			{
				cout << "\nInvalid year Number \n please inter the year Number agin: "; cin >> year;
			}

			cout << "\n month: "; cin >> month;

			while (month < 0)
			{
				cout << "\nInvalid month Number \n please inter the month Number agin: "; cin >> month;
			}

			cout << "\n day: "; cin >> day;

			while (day < 0)
			{
				cout << "\nInvalid day Number \n please inter the day Number agin: "; cin >> day;
			}

			cout << "\n hour: "; cin >> hour;

			while (hour < 0)
			{
				cout << "\nInvalid hour Number \n please inter the hour Number agin: "; cin >> hour;
			}

			cout << "\n minute: "; cin >> minute;

			while (minute < 0)
			{
				cout << "\nInvalid minute Number \n please inter the minute Number agin: "; cin >> minute;
			}

			cout << "\n second: "; cin >> second;

			while (second < 0)
			{
				cout << "\nInvalid second Number \n please inter the second Number agin: "; cin >> second;
			}

			ArrivalTime arrival(year, month, day, hour, minute, second);


			cout << "\n please inter the end time: \n year: ";
			cin >> year;

			while (year < 0)
			{
				cout << "\nInvalid year Number \n please inter the year Number agin: "; cin >> year;
			}

			cout << "\n month: "; cin >> month;

			while (month < 0)
			{
				cout << "\nInvalid month Number \n please inter the month Number agin: "; cin >> month;
			}

			cout << "\n day: "; cin >> day;

			while (day < 0)
			{
				cout << "\nInvalid day Number \n please inter the day Number agin: "; cin >> day;
			}

			cout << "\n hour: "; cin >> hour;

			while (hour < 0)
			{
				cout << "\nInvalid hour Number \n please inter the hour Number agin: "; cin >> hour;
			}

			cout << "\n minute: "; cin >> minute;

			while (minute < 0)
			{
				cout << "\nInvalid minute Number \n please inter the minute Number agin: "; cin >> minute;
			}

			cout << "\n second: "; cin >> second;

			while (second < 0)
			{
				cout << "\nInvalid second Number \n please inter the second Number agin: "; cin >> second;
			}

			DepartureTime departure(year, month, day, hour, minute, second);

			park.totalIncome(arrival, departure);
		}

		else if (select == 6)
		{
			int year, month, day, hour, minute, second;

			cout << "\n please inter the start time: \n year: ";
			while (year < 0)
			{
				cout << "\nInvalid year Number \n please inter the year Number agin: "; cin >> year;
			}

			cout << "\n month: "; cin >> month;

			while (month < 0)
			{
				cout << "\nInvalid month Number \n please inter the month Number agin: "; cin >> month;
			}

			cout << "\n day: "; cin >> day;

			while (day < 0)
			{
				cout << "\nInvalid day Number \n please inter the day Number agin: "; cin >> day;
			}

			cout << "\n hour: "; cin >> hour;

			while (hour < 0)
			{
				cout << "\nInvalid hour Number \n please inter the hour Number agin: "; cin >> hour;
			}

			cout << "\n minute: "; cin >> minute;

			while (minute < 0)
			{
				cout << "\nInvalid minute Number \n please inter the minute Number agin: "; cin >> minute;
			}

			cout << "\n second: "; cin >> second;

			while (second < 0)
			{
				cout << "\nInvalid second Number \n please inter the second Number agin: "; cin >> second;
			}

			ArrivalTime arrival(year, month, day, hour, minute, second);


			while (year < 0)
			{
				cout << "\nInvalid year Number \n please inter the year Number agin: "; cin >> year;
			}

			cout << "\n month: "; cin >> month;

			while (month < 0)
			{
				cout << "\nInvalid month Number \n please inter the month Number agin: "; cin >> month;
			}

			cout << "\n day: "; cin >> day;

			while (day < 0)
			{
				cout << "\nInvalid day Number \n please inter the day Number agin: "; cin >> day;
			}

			cout << "\n hour: "; cin >> hour;

			while (hour < 0)
			{
				cout << "\nInvalid hour Number \n please inter the hour Number agin: "; cin >> hour;
			}

			cout << "\n minute: "; cin >> minute;

			while (minute < 0)
			{
				cout << "\nInvalid minute Number \n please inter the minute Number agin: "; cin >> minute;
			}

			cout << "\n second: "; cin >> second;

			while (second < 0)
			{
				cout << "\nInvalid second Number \n please inter the second Number agin: "; cin >> second;
			}

			DepartureTime departure(year, month, day, hour, minute, second);

			park.totalIncome(arrival, departure);
		}

		else if (select == 7)
		{
			return 0;
		}

		else
		{
			cout << "\nInvalide select\n\n";
		}

	}

}
