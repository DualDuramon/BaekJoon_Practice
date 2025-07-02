#pragma once
#include<vector>

class Problem abstract
{
protected:
	virtual void Solving() {};
public:
	virtual void Solution() = 0;
};

class Problem_1009 :public Problem {
private:
	void Solving() override;
public:
	void Solution() override;
};

class Problem_10773 : public Problem {
public:
	void Solution() override;
};

class Problem_10808 : public Problem {
private:
public:
	void Solution() override;
};

class Problem_11724 : public Problem {
public :
	void Solution() override;
};

class Problem_1012 :public Problem {
private:
	void Solving() override;
public:
	void Solution() override;
};

class Problem_1181 : public Problem {
public:
	void Solution() override;
};

class Problem_1018 : public Problem {
private:
	int CalCulate_Board_Coloring(std::vector<std::vector<bool>>* board, int startRow, int startCol, int nowMin);
public:
	void Solution() override;
};

class Problem_10814 : public Problem {
public:
	void Solution() override;
};