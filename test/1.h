#include <string>		// for string

class Student {
public:
	Student(std::string fN, std::string mN, std::string sN, char sex, int yob, 
			std::string regNumber, std::string email) {

		setFirstName(fN);
		setMiddleName(mN);
		setSurName(sN);
		setSex(sex);
		setYearOfBirth(yob);
		setRegNumber(regNumber);
		setEmail(email);
	}

	void setFirstName(std::string firstName) {
		this->firstName = firstName;
	}

	void setMiddleName(std::string middleName) {
		this->middleName = middleName;
	}

	void setSurName(std::string surName) {
		this->surName = surName;
	}

	void setSex(char sex) {
		this->sex = sex;
	}

	void setYearOfBirth(int yearOfBirth) {
		this->yearOfBirth = yearOfBirth;
	}

	void setRegNumber(std::string regNumber) {
		
		this->regNumber = regNumber;
	}

	void setEmail(std::string email) {
		
		this->email = email;
	}

	std::string getFirstName() {
		return firstName;
	}

	char getSex() {
		return sex;
	}

	std::string getRegNumber() {
		return regNumber;
	}

	std::string getEmail() {
		return email;
	}

private:
	std::string firstName;
	std::string middleName;
	std::string surName;
	char sex;
	int yearOfBirth;
	std::string regNumber;
	std::string email;
};