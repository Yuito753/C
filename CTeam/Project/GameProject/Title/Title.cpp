#include"Title.h"
#include"../Game.h"



Title::Title() :Base(eType_Scene)  {

	m_img = COPY_RESOURCE("Title", CImage);
	//m_title_text = COPY_RESOURCE("PACMAN2", CImage);
	







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

	//m_title_text.SetPos(640-340,360-100);
	//m_title_text.Draw();
	m_img.SetSize(1920, 1080);
	m_img.Draw();
}
