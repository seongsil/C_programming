#ifndef ScoreWin_H
#define ScoreWin_H

class ScoreWin
{ 
private:
	int score;   
public:
	ScoreWin() //�������Լ� �ʱ�ȭ
		:score(0)
	{
	}
	ScoreWin(int score) //����â ���
		:score(score)
	{
	}
	
	int GetScore() { return score; }      // ������ȯ
	void PrintWin();               
	     
};

#endif