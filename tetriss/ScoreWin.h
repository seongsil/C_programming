#ifndef ScoreWin_H
#define ScoreWin_H

class ScoreWin
{ 
private:
	int score;   
public:
	ScoreWin() //생성자함수 초기화
		:score(0)
	{
	}
	ScoreWin(int score) //점수창 출력
		:score(score)
	{
	}
	
	int GetScore() { return score; }      // 점수반환
	void PrintWin();               
	     
};

#endif