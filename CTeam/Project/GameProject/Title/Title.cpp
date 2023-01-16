#include"Title.h"
#include"../Game.h"



Title::Title() :Base(eType_Scene)  {
	//m_title = COPY_RESOURCE("Title_text", CImage);
	m_img = COPY_RESOURCE("Title", CImage);
	m_img2 = COPY_RESOURCE("PACMAN2", CImage);
	m_title = COPY_RESOURCE("pac", CImage);
	m_title.SetSize(560 * 1.2, 86 * 1.2);
	






}

Title::~Title()
{
}

void Title::Update()
{
	if (PUSH(CInput::eButton10)) {
		SOUND("SE_Button2")->Play();
		SetKill();
		Base::KillAll();
		Base::Add(new Game());
	}
}

void Title::Draw()
{
	




	m_title.SetPos(960 - 340, 500 - 100);
	m_title.Draw();
	//m_title.Draw();
	//m_img.SetSize(1920, 1080);
	m_img2.Draw();
}
