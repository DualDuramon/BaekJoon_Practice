#pragma once
#include<vector>

class Problem
{
protected:
	virtual void Solving() {};
public:
	virtual void Solution() = 0;
};
/*
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

class Problem_11659 : public Problem {
public:
	void Solution() override;
};

class Problem_2638 : public Problem {

public:
	void Solution() override;
};

class Problem_2579 : public Problem {
public :
	void Solution() override;
};

class Problem_11053 : public Problem {
public:
	void Solution() override;
};

class Problem_11726 : public Problem {
public:
	void Solution() override;
};

class Problem_11727 : public Problem {
public:
	void Solution() override;
};
*/
class Problem_9020 : public Problem {
private:
	void Solving() override;
public:
	void Solution() override;
};

class Problem_1153 : public Problem {
public : 
	void Solution() override;
};