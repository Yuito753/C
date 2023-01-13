#pragma once
#include"../Base/Base.h"

class Title :public Base {
private:
	CImage m_img;
	CImage m_img2;
	CImage m_title_text;
	CImage m_title;
	
public:
	Title();
	~Title();
	void Update();
	void Draw();
	
};