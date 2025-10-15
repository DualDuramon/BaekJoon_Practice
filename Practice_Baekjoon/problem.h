#pragma once
#include<vector>
#include<set>
#include<queue>

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

class Problem_11054 : public Problem {
public:
	void Solution() override;
};

class Problem_1103 : public Problem {
private:
	bool CheckBound(const std::vector<std::vector<char>>& map, int row, int col);
	int DFS(const std::vector<std::vector<char>>& map, std::vector<std::vector<int>>& lengthMap, std::vector<std::vector<bool>>& visited,  int row, int col);
public :
	void Solution() override;
};


class Problem_4883 :public Problem {
private:
	bool CheckBoundary(const std::vector<std::vector<int>>& graph,int row, int col);
	int CalculateCost(int n);
public:
	void Solution() override;
};

class Problem_14842 :public Problem {
public:
	void Solution() override;
};

class Problem_1535 : public Problem {
public :
	void Solution() override;

};

class Problem_1966 : public Problem {
private :
	void Solving() override;
public:
	void Solution() override;
};

class Problem_1080 :public Problem {
private :
	bool CheckAnswer(const std::vector<std::vector<bool>>& map, const std::vector<std::vector<bool>>& answer);
	void Calculate(const std::vector<std::vector<bool>>& map, const std::vector<std::vector<bool>>& answer, int startRow, int startCol);
	void ChangeMap(std::vector<std::vector<bool>>& map, int row, int col);
public:
	void Solution() override;
};

class Problem_2839 :public Problem {
public :
	void Solution() override;
};


class Problem_21736 : public Problem {
private:
	bool canMove(const std::vector<std::vector<char>>& map, const std::vector<std::vector<bool>>& visited, int r, int c);
	int DFS(const std::vector<std::vector<char>>& map, std::vector<std::vector<bool>>& visited, int r, int c);
public:
	void Solution() override;
};

class Problem_7576 :public Problem {
private:
	bool CheckCoord(const std::vector<std::vector<int>>& map, size_t row, size_t col);
public :
	void Solution() override;
};

class Problem_9019 : public Problem {
private :
	void Solving() override;
	int OperD(int);
	int OperS(int);
	int OperL(int);
	int OperR(int);
public :
	void Solution() override;
};

class Problem_11866 :public Problem {
public:
	void Solution() override;
};

class Problem_7662 :public Problem {
private :
	void Solving() override;
public:
	void Solution() override;
};

class Problem_1149 : public Problem {
public:
	void Solution() override;
};

class Problem_1038 :public Problem {
private:
	void BackTracking(long long, int);
public:
	void Solution() override;
};

class Problem_14500 :public Problem {
private :
	bool CheckBound(const std::vector<std::vector<int>>&, int, int);
	void CheckTiles(const std::vector<std::vector<int>>&, std::pair<int,int>);
public:
	void Solution() override;

};

class Problem_12865 : public Problem {
public:
	void Solution() override;
};

class Problem_15650 : public Problem {
private:
	void Backtracking(std::vector<int>&, int startNum, int maxNum, int maxLength);
public:
	void Solution() override;
};

class Problem_15652 : public Problem {
private:
	void Backtracking(std::vector<int>& nowSet, int nowNum, int maxNum, int maxLength);
public:
	void Solution() override;
};

class Problem_1463 : public Problem {
public:
	void Solution() override;
};

class Problem_14888 :public Problem {
public:
	void Solution() override;
};
*/
class Problem_15654 : public Problem {
private:
	void backtracking(const std::vector<int>& list, std::vector<int>& nowSet, std::vector<bool>& selected, int nowIdx, int maxLength);
public:
	void Solution() override;
};

class Problem_9663 : public Problem {
private:
	void backtracking(int mapSize, std::vector<std::pair<int,int>>& queensLoc, int nowDepth, int maxDepth, int& cases);
public:
	void Solution() override;
};

class Problem_9251 : public Problem {
public: 
	void Solution() override;
};

class Problem_14501 :public Problem {
public:
	void Solution() override;
};

class Problem_17070 :public Problem {
public:
	void Solution() override;
};

class Problem_1504 : public Problem {
public :
	void Solution() override;	
};

class Problem_1991 : public Problem {
	public:
		void Solution() override;
};